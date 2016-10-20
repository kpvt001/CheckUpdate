#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "CheckUpdateBaseQt.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow, CheckUpdateBaseQtSink
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    virtual void OnCheckUpdateFinished(CheckUpdateBaseQtResult *result);
    virtual void OnCheckUpdateError(CheckUpdateBaseQtError *error);
    int* LocalVersion();
    ~MainWindow();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
