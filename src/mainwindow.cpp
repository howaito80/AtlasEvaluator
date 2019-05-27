#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDesktopServices>
#include <QFileDialog>
#include <QMessageBox>
#include <QDebug>
#include <QProgressDialog>
#include <fstream>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle("AtlasEvaluator");

    // btn
    connect(ui->srcDirBtn, SIGNAL(pressed()), this, SLOT(ChooseSrcFolder()));
    connect(ui->evaBtn, SIGNAL(pressed()), this, SLOT(StartEvaluate()));

    // threshold
    connect(ui->thresSpin, SIGNAL(valueChanged(int)),ui->thresSlider, SLOT(setValue(int)));
    connect(ui->thresSlider, SIGNAL(valueChanged(int)),ui->thresSpin, SLOT(setValue(int)));

    // result list
    connect(ui->quaList, SIGNAL(currentRowChanged(int)), this, SLOT(EnableQuaOpenBtn()));
    connect(ui->unquaList, SIGNAL(currentRowChanged(int)), this, SLOT(EnableUnquaOpenBtn()));
    connect(ui->failList, SIGNAL(currentRowChanged(int)), this, SLOT(EnableFailOpenBtn()));

    // result check btn
    connect(ui->quaOpenBtn, SIGNAL(pressed()), this, SLOT(OpenQuaAtlas()));
    connect(ui->quaDirBtn, SIGNAL(pressed()), this, SLOT(OpenQuaDir()));
    connect(ui->unquaOpenBtn, SIGNAL(pressed()), this, SLOT(OpenUnquaAtlas()));
    connect(ui->unquaDirBtn, SIGNAL(pressed()), this, SLOT(OpenUnquaDir()));
    connect(ui->failOpenBtn, SIGNAL(pressed()), this, SLOT(OpenFailDir()));

    ui->inputBox->setStyleSheet(QStringLiteral("QGroupBox{background-color: #e3e3e3;}"));
    ui->evaBox->setStyleSheet(QStringLiteral("QGroupBox{background-color: #e3e3e3;}"));
    ui->evaBox->setEnabled(false);

    m_evalThread = new EvalThread(this);
    connect(m_evalThread, SIGNAL(FinishEval()) ,this,SLOT(OnFinishEval()));

    m_pgDialog = nullptr;
    ui->freshLabel->setVisible(false);
}

MainWindow::~MainWindow()
{
    delete ui;

    if(m_pgDialog != nullptr)
        delete m_pgDialog;

    m_evalThread->quit();
    delete m_evalThread;
}

void MainWindow::ChooseSrcFolder()
{
    QString fn = QFileDialog::getExistingDirectory(this, "选择源文件夹");
    ui->srcDir->setText(fn);
}

void MainWindow::StartEvaluate()
{
    QString path = ui->srcDir->text();
    if(!QFile::exists(path + "/assets"))
    {
        ShowMsgBox("Fail to open source dir: " + path + "/assets");
        return;
    }

    m_evalThread->path = path;
    m_evalThread->thres = ui->thresSpin->value();


    // progress dialog
    if(m_pgDialog == nullptr)
    {
        m_pgDialog = new QProgressDialog("Please wait...", "Cancel", 0, 100, this);
        connect(m_evalThread, SIGNAL(ProgressChanged(int)), m_pgDialog, SLOT(setValue(int)));
        connect(m_pgDialog, SIGNAL(canceled()), this, SLOT(OnProgressCancel()));
        m_pgDialog->setWindowModality(Qt::WindowModal);
        m_pgDialog->setMinimumDuration(1000);
    }
    else
        m_pgDialog->show();

    m_pgDialog->setValue(0);
    m_evalThread->start();

    ui->centralWidget->setEnabled(false);
    ui->freshLabel->setVisible(true);
}

void MainWindow::ShowRes()
{
    m_lastDir = ui->srcDir->text();
    m_lastDir = m_lastDir.replace('/',"\\");

    ui->evaBox->setEnabled(true);
    ui->quaOpenBtn->setEnabled(false);
    ui->quaDirBtn->setEnabled(false);

    ui->unquaOpenBtn->setEnabled(false);
    ui->unquaDirBtn->setEnabled(false);

    ui->failOpenBtn->setEnabled(false);

    Evaluator* eval = m_evalThread->evaluator;
    //--------------------------------qua list
    ui->quaList->clear();
    vector<AtlasInfo*>::iterator iter = eval->quaAtlas.begin();
    for(; iter != eval->quaAtlas.end(); iter++)
    {
        int util = int((*iter)->util * 100);
        QString u = QString::number(util) + "% ";
        ui->quaList->addItem(u + (*iter)->filename);
    }
    ui->quaNum->setText(to_string(eval->quaAtlas.size()).c_str());

    //--------------------------------unqua list
    ui->unquaList->clear();
    iter = eval->unquaAtlas.begin();
    for(; iter != eval->unquaAtlas.end(); iter++)
    {
        int util = int((*iter)->util * 100);
        QString u = QString::number(util) + "% ";
        ui->unquaList->addItem(u + (*iter)->filename);
    }
    ui->unquaNum->setText(to_string(eval->unquaAtlas.size()).c_str());

    //--------------------------------fail list
    ui->failList->clear();
    iter = eval->failAtlas.begin();
    for(; iter != eval->failAtlas.end(); iter++)
    {
        QString str = (*iter)->filename;
        ui->failList->addItem(str);

    }
    ui->failNum->setText(QString::number(eval->failAtlas.size()));

    ui->centralWidget->setEnabled(true);
    ui->freshLabel->setVisible(false);
}

//--------------------enable and diable btns
void MainWindow::EnableQuaOpenBtn()
{
    int row = ui->quaList->currentRow();
    if(row < 0 || row >ui->quaList->count())
        return;
    ui->quaOpenBtn->setEnabled(true);
    ui->quaDirBtn->setEnabled(true);
}

void MainWindow::EnableUnquaOpenBtn()
{
    int row = ui->unquaList->currentRow();
    if(row < 0 || row >ui->unquaList->count())
        return;
    ui->unquaOpenBtn->setEnabled(true);
    ui->unquaDirBtn->setEnabled(true);
}

void MainWindow::EnableFailOpenBtn()
{
    int row = ui->failList->currentRow();
    if(row < 0 || row >ui->failList->count())
        return;
    ui->failOpenBtn->setEnabled(true);
}


//------------------------------------open result file
void MainWindow::OpenQuaAtlas()
{
    QString fn = m_lastDir + "\\temp\\TexturePacker\\preview\\";

    Evaluator* eval = m_evalThread->evaluator;
    int idx = ui->quaList->currentRow();
    AtlasInfo* cur = eval->quaAtlas[idx];
    fn = fn + cur->pacPath + "\\" + cur->filename;
    OpenFile(fn);
}

void MainWindow::OpenQuaDir()
{
    QString fn = m_lastDir + "\\assets\\";

    Evaluator* eval = m_evalThread->evaluator;
    int idx = ui->quaList->currentRow();
    AtlasInfo* cur = eval->quaAtlas[idx];
    fn = fn + GetParentPath(cur->pacPath);
    OpenFile(fn);
}

void MainWindow::OpenUnquaAtlas()
{
    QString fn = m_lastDir + "\\temp\\TexturePacker\\preview\\";

    Evaluator* eval = m_evalThread->evaluator;
    int idx = ui->unquaList->currentRow();
    AtlasInfo* cur = eval->unquaAtlas[idx];
    fn = fn + cur->pacPath + "\\" + cur->filename;
    OpenFile(fn);
}

void MainWindow::OpenUnquaDir()
{
    QString fn = m_lastDir + "\\assets\\";

    Evaluator* eval = m_evalThread->evaluator;
    int idx = ui->unquaList->currentRow();
    AtlasInfo* cur = eval->unquaAtlas[idx];
    fn = fn + GetParentPath(cur->pacPath);
    OpenFile(fn);
}

void MainWindow::OpenFailDir()
{
    QString fn = m_lastDir + "\\assets\\";

    Evaluator* eval = m_evalThread->evaluator;
    int idx = ui->failList->currentRow();
    AtlasInfo* cur = eval->failAtlas[idx];
    fn = fn + cur->pacPath;

    OpenFile(fn);
}

void MainWindow::OpenFile(const QString& fn)
{
    bool res = QDesktopServices::openUrl(QUrl::fromLocalFile(fn));
    if(!res)
        ShowMsgBox("Fail to open: " + fn);
}

//-----------------------------------SLOTs
void MainWindow::OnFinishEval()
{
      ShowRes();
}

void MainWindow::OnProgressCancel()
{
    *(m_evalThread->cancel) = true;
}

void MainWindow::ShowMsgBox(const QString& msg)
{
    QMessageBox msgBox;
    msgBox.setText(msg);
    msgBox.exec();
}
