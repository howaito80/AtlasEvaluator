#ifndef EVALUATOR_H
#define EVALUATOR_H

#include <sys/stat.h>
#include <vector>
#include <QtAlgorithms>
#include <QDebug>
#include <QTextCodec>
#include <QThread>
#include <QtCore>
#include "atlas.h"

class Evaluator: public QObject
{
    Q_OBJECT
public:
    Evaluator();
    ~Evaluator();

    bool StartEvaluator(float thr, const QString& path);
    void Cancel();

    vector<AtlasInfo*> quaAtlas; // qualified atlases whose utilization is higher than threshold
    vector<AtlasInfo*> unquaAtlas;  // unqualified atlases
    vector<AtlasInfo*> failAtlas;  // failure due to: 1. fail to load file. 2.atlas in cocos has no preview. 3.others

    bool* cancel; // shared by evaluator

private:
    float m_thr; //  threshold
    vector<AtlasInfo*> m_atlasList;
    vector<QString> m_pacInAsset;

    bool ReadFolder(const QString& path); // read file name of input src path.
    void Divide();
    void Reset();

signals:
    void SendCurProgress(float);
};

class EvalThread: public QThread
{
    Q_OBJECT
public:
    explicit EvalThread(QObject *parent = 0);
    ~EvalThread();

    QString path;
    int thres;
    int curProgress;
    bool isStop;
    bool* cancel; // shared by evaluator
    Evaluator* evaluator;

private:
    void run();

private slots:
    void OnProgressChanged(float value);

signals:
    void ProgressChanged(int);
    void FinishEval();
};

#endif // EVALUATOR_H
