#include "qtelnetperso.h"

#include <QtDebug>

QTelnetPerso::QTelnetPerso(QObject *parent) : QObject(parent), socket(0), notifier(0), connected(false)
{
    setSocket(new QTcpSocket(this));
}

QTelnetPerso::~QTelnetPerso()
{
    delete socket;
    delete notifier;
}

void QTelnetPerso::setSocket(QTcpSocket *s)
{
    delete socket;

    connected = false;
    socket = s;
    if (socket)
    {
        connect(socket, SIGNAL(connected()), this, SLOT(socketConnected()));
        connect(socket, SIGNAL(disconnected()), this, SLOT(socketConnectionClosed()));
        connect(socket, SIGNAL(readyRead()), this, SLOT(socketReadyRead()));
        connect(socket, SIGNAL(error(QAbstractSocket::SocketError)), this, SLOT(socketError(QAbstractSocket::SocketError)));
    }
}

void QTelnetPerso::connectToHost(const QString &host, quint16 port)
{
    if (connected)
        return;
    socket->connectToHost(host, port);
}

void QTelnetPerso::disconnectTelnet()
{
    socket->disconnectFromHost();
}

bool QTelnetPerso::isConnected() const
{
    return connected;
}

void QTelnetPerso::consume()
{
    const QByteArray data = buffer;
    buffer.clear();
    int currpos = 0;
    int prevpos = -1;;
    while (prevpos < currpos && currpos < data.size())
    {
        prevpos = currpos;
        const uchar c = uchar(data[currpos]);
        if (c == Common::DM)
            ++currpos;
        else if (c == Common::IAC)
            currpos += 3;//parseIAC(data.mid(currpos));
        else // Assume plain text
            currpos += parsePlaintext(data.mid(currpos));
    }
    if (currpos < data.size())
        buffer.push_back(data.mid(currpos));
}

void QTelnetPerso::socketConnected()
{
    delete notifier;

    connected = true;
    notifier = new QSocketNotifier(socket->socketDescriptor(), QSocketNotifier::Exception, this);
    connect(notifier, SIGNAL(activated(int)), this, SLOT(socketException(int)));
    emit sockConnected();
    //sendOptions();
}

void QTelnetPerso::socketConnectionClosed()
{
    delete notifier;
    notifier = 0;
    connected = false;
    emit sockDisconnected();
}

void QTelnetPerso::socketReadyRead()
{
    buffer.append(socket->readAll());
    consume();
}

void QTelnetPerso::socketError(QAbstractSocket::SocketError error)
{
    //emit q->connectionError(error);
}

void QTelnetPerso::socketException(int)
{
    qDebug("socketException :: out-of-band data received, should handle that here!");
}

int QTelnetPerso::parsePlaintext(const QByteArray &data)
{
    int consumed = 0;
    int length = data.indexOf('\0');
    if (length == -1) {
        length = data.size();
        consumed = length;
    } else {
        consumed = length + 1; // + 1 for removing '\0'
    }

    const QString text = QString::fromLocal8Bit(data.constData(), length);

    if (!text.isEmpty())
        emit message(text);

    return consumed;
}

void QTelnetPerso::sendData(const QString &data)
{
    if (!connected)
        return;

    QByteArray str = data.toLocal8Bit();

    if (str.size()>0)
        socket->write(str);
}

void QTelnetPerso::sendData2(const QByteArray &data)
{
    if (!connected)
        return;

    if (data.size()>0)
        socket->write(data);
}
