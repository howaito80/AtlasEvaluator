#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QProgressDialog>
#include <QString>
#include <QTextCodec>
#include <QListWidget>
#include <string>
#include "evaluator.h"

using namespace std;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QString m_lastDir;

    EvalThread* m_evalThread;
    QProgressDialog* m_pgDialog;

    void ShowRes();
    void OpenFile(const QString& fn);
    void ShowMsgBox(const QString& msg);

private slots:
    void ChooseSrcFolder();
    void StartEvaluate();

    void EnableQuaOpenBtn();
    void EnableUnquaOpenBtn();
    void EnableFailOpenBtn();

    void OpenQuaAtlas();
    void OpenUnquaAtlas();

    void OpenQuaDir();
    void OpenUnquaDir();
    void OpenFailDir();

    void OnFinishEval();// <- eval thread
    void OnProgressCancel(); // <- eval dialog
};

#endif // MAINWINDOW_H
