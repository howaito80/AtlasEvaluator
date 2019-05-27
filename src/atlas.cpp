#include "atlas.h"
#include <QDebug>

bool Atlas::Load(const QString& previewPath, const QString& subpath)
{  
    infos.clear();

    // use qfile to read json
    QString jsonPath = previewPath + subpath + "\\info.json";
    QFile file(jsonPath);
    if(!file.open(QIODevice::ReadOnly | QIODevice::Text))
        return false;

    QTextStream txtStream(&file);
    QString content;
    while(!txtStream.atEnd())
    {
        content += txtStream.readLine();
    }

    // use rapid json to parse
    Document doc;
    doc.Parse(content.toStdString().c_str());
    if(!doc.IsObject())
        return false;

    if(!doc.HasMember("result"))
        return false;
    Value &res = doc["result"];

    if(!res.HasMember("atlases"))
        return false;
    Value &allAtlases = res["atlases"];

    if(!allAtlases.IsArray())
        return false;

    infos.clear();
    for(int i = 0; i < static_cast<int>(allAtlases.Size()); i++)
    {
        Value& atlas = allAtlases[i];

        if(!atlas.HasMember("files"))
            return false;
        Value& allSprites = atlas["files"];
        if(!allSprites.IsArray())
            return false;

        if(!atlas.HasMember("width") || !atlas.HasMember("height"))
            return false;

        Value& totW = atlas["width"];
        Value& totH = atlas["height"];
        int totArea = totW.GetInt() * totH.GetInt();

        if(!atlas.HasMember("imagePath"))
            return false;

        int usedArea = 0;
        for(int j = 0; j < static_cast<int>(allSprites.Size()); j++)
        {
            Value& sprite = allSprites[j];
            if(!sprite.HasMember("width") || !sprite.HasMember("height"))
                return false;

            Value& w = sprite["width"];
            Value& h = sprite["height"];
            usedArea += w.GetInt() * h.GetInt();
        }

        // new atlas
        AtlasInfo *newAt = new AtlasInfo();
        newAt->util = usedArea * 1.0 / totArea;
        newAt->pacPath = subpath; //  subpath is ../../XXXX.pac
        newAt->filename = GetFileName(atlas["imagePath"].GetString());

        infos.push_back(newAt);
    }

    return true;
}

void Atlas::GenFailInfo(const QString& pacPath)
{
    vector<AtlasInfo*>::iterator atIter = infos.begin();
    for(; atIter != infos.end(); atIter++)
        delete *atIter;
    infos.clear();

    AtlasInfo* info = new AtlasInfo();
    info->util = -1;
    info->filename = GetFileName(pacPath);
    info->pacPath = GetParentPath(pacPath);
    infos.push_back(info);
}
