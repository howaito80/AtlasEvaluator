#ifndef ATLAS_H
#define ATLAS_H

#include <string>
#include <QDebug>
#include <iostream>
#include <fstream>
#include <sstream>
#include <filesystem>
#include <QFile>
#include "rapidjson/document.h"
#include "rapidjson/writer.h"
#include "rapidjson/stringbuffer.h"

using namespace std;
using namespace rapidjson;
namespace fs = std::experimental::filesystem;

struct AtlasInfo
{
    QString pacPath;
    QString filename;
    float util; // utilization of this atlas
};

class Atlas
{
public:
    Atlas() {}
    ~Atlas(){}

    vector<AtlasInfo*> infos;
    bool Load(const QString& previewPath, const QString& subpath);
    void GenFailInfo(const QString& pacPath);
};

inline static QString GetFileName(const QString& path)
{
    int idx = static_cast<int>(path.lastIndexOf("\\"));
    if(idx < 0 || idx >= path.length())
        idx = -1;
    QString fn = path.mid(idx + 1, path.length() - idx - 1);
    return fn;
}

inline static QString GetParentPath(const QString& path)
{
    int idx = static_cast<int>(path.lastIndexOf("\\"));
    if(idx < 0 || idx >= path.length())
        idx = 0;
    QString p = path.mid(0, idx);
    return p;
}

#endif // ATLAS_H
