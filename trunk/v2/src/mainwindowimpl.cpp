#include "mainwindowimpl.h"

#include <QLayout>

MainWindowImpl::MainWindowImpl( QWidget * parent, Qt::WFlags f) : QMainWindow(parent, f)
{
    setupUi(this);

    mtw = new MyTelnetWidget(this);
    centralWidget()->layout()->addWidget(mtw);
}

void MainWindowImpl::on_connectButton_clicked()
{
    mtw->connectToHost("localhost");
}

void MainWindowImpl::on_disconnectButton_clicked()
{
    mtw->closeSession();
}

void MainWindowImpl::alert()
{
    QApplication::beep();

}
