#include"evaluator.h"

bool AtlasInfoLargerThan(const AtlasInfo* a1, const AtlasInfo* a2)
{
    return a1->util > a2->util;
}

Evaluator::Evaluator():
    m_thr(-1)
{

}

Evaluator::~Evaluator()
{
    vector<AtlasInfo*>::iterator iter =  m_atlasList.begin();
    for(; iter != m_atlasList.end(); iter++)
        delete *iter;
}

void Evaluator::Divide()
{
    qSort(m_atlasList.begin(), m_atlasList.end(), AtlasInfoLargerThan);

    vector<AtlasInfo*>::iterator iter = m_atlasList.begin();
    for(; iter != m_atlasList.end(); iter++)
    {
        if((*iter)->util <= 0)
        {
            failAtlas.push_back(*iter);
            continue;
        }
        else if((*iter)->util * 100 >= m_thr)
            quaAtlas.push_back(*iter);
        else
            unquaAtlas.push_back(*iter);
    }
}

bool Evaluator::StartEvaluator(float thr, const QString& path)
{
    m_thr = thr;
    bool res = ReadFolder(path);
    if(res == false)
    {
        Reset();
        emit SendCurProgress(1);
        return false;
    }

    QString previewPath = path + "\\temp\\TexturePacker\\preview\\";
    vector<QString>::iterator iter = m_pacInAsset.begin();
    Atlas newAtlas;
    int count = 0;
    for(; iter != m_pacInAsset.end(); iter++)
    {
        if(!newAtlas.Load(previewPath, *iter))
            newAtlas.GenFailInfo(*iter);
        vector<AtlasInfo*>::iterator atIter = newAtlas.infos.begin();

        for(; atIter != newAtlas.infos.end(); atIter++)
        {
            m_atlasList.push_back(*atIter);
        }

        count++;
        emit SendCurProgress(0.8 + count * 0.2/ m_pacInAsset.size());
        if(*cancel)
        {
            Reset();
            emit SendCurProgress(1);
            return false;
        }
    }

    Divide();
    emit SendCurProgress(1);
    return true;
}

void Evaluator::Reset()
{
    m_pacInAsset.clear();

    vector<AtlasInfo*>::iterator iter =  m_atlasList.begin();
    for(; iter != m_atlasList.end(); iter++)
        delete *iter;

    m_atlasList.clear();
    unquaAtlas.clear();
    quaAtlas.clear();
    failAtlas.clear();
}

bool Evaluator::ReadFolder(const QString &path)
{
    // path == project's root
    Reset();

    QString assetRoot = path + "\\assets";

    SendCurProgress(0);
    int fakeTaskNum = 10000;
    int i = 0;

    // get current pac in assets
    QDirIterator it(assetRoot , QDir::Files , QDirIterator::Subdirectories);
    while (it.hasNext())
    {
        it.next();

        i++;
        i = (i>=fakeTaskNum)? fakeTaskNum: i;
        emit SendCurProgress(i * 1.0 / fakeTaskNum * 0.8);

        if(*cancel)
            return false;

        // judge file name (must be .pac)
        QString fn = it.fileName();
        if(fn.length() < 4)
            continue;
        QString extend = fn.mid(fn.length() - 4, 4);
        if(extend != ".pac")
            continue;

        QString subPath = it.filePath().mid(assetRoot.length() + 1, fn.length() - assetRoot.length() - 1);
        m_pacInAsset.push_back(subPath);
    }

    SendCurProgress(0.8f);
    return true;
}
//-----------------------------------------------Thread
EvalThread::EvalThread(QObject *parent) :
    QThread(parent)
{
    isStop = false;
    evaluator = new Evaluator();
    cancel = new bool;
    *cancel = false;
    evaluator->cancel = cancel;

    connect(evaluator, SIGNAL(SendCurProgress(float)),this, SLOT(OnProgressChanged(float)));
}

void EvalThread::run()
{
    curProgress = 0;
    isStop = false;
    *cancel = false;
    evaluator->StartEvaluator(thres, path);
    isStop = true;
    emit FinishEval();
    this->quit();
}

void EvalThread::OnProgressChanged(float value)
{
    emit ProgressChanged(int(value*100));
}

EvalThread::~EvalThread()
{
    delete evaluator;
}
