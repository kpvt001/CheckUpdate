#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

#pragma comme
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    CheckUpdateBaseQt *check = CheckUpdateBaseQt::Create();
    check->SetSink(this);
    check->SetLocalVersion(LocalVersion());
    check->SetRemoteSourceVersionUrl(QUrl("https://raw.githubusercontent.com/kpvt001/WuXiaGameAssist_PreVersion0_1/master/WuXiaAnswerLite/update_version_info.json"));
    check->Start();
}

MainWindow::~MainWindow()
{
    delete ui;
}

int* MainWindow::LocalVersion()
{
    static int v[4] = {1,0,0,1};
    return v;
}

void MainWindow::OnCheckUpdateError(CheckUpdateBaseQtError *error)
{
    qDebug() << "Error";
    qDebug() << error->Code();
}

void MainWindow::OnCheckUpdateFinished(CheckUpdateBaseQtResult *result)
{
    qDebug() << "Finish";
}
