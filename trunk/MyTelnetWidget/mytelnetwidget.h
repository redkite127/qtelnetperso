#ifndef MYTELNETWIDGET_H
#define MYTELNETWIDGET_H

#include <QWidget>
#include <QPlainTextEdit>
#include "qtelnetperso.h"
#include <QEvent>
#include <QKeyEvent>
#include <QMouseEvent>
#include <QString>
#include <QByteArray>
#include <QTextCursor>
#include <QScrollBar>

#include <QtDebug>

class MyTelnetWidget : public QPlainTextEdit
{
    Q_OBJECT

public:
    MyTelnetWidget(QWidget *parent = 0);

protected:
    void keyPressEvent(QKeyEvent *e);
    //bool eventFilter(QObject *obj, QEvent *event);
    void mousePressEvent(QMouseEvent *e);
    void mouseReleaseEvent(QMouseEvent *e);
    void mouseDoubleClickEvent(QMouseEvent *e);

public slots:
    void connectToHost(const QString &host, const quint16 port = 23);
    void disconnectTelnet();

private slots:
    void sockConnected();
    void sockDisconnected();
    void processIncomingData(const QString &text);

signals:
    void connected();
    void disconnected();
    void bellReceived();

private:
    void simulateOverWriteMode(QString text);

    QTelnetPerso *t;
    QTextCursor *cur;
};

#endif // MYTELNETWIDGET_H
