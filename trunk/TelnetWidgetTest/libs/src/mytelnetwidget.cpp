#include "mytelnetwidget.h"


MyTelnetWidget::MyTelnetWidget(QWidget *parent) : QPlainTextEdit(parent), t(NULL), cur(NULL)
{
    QPlainTextEdit::setUndoRedoEnabled(false);
    QPlainTextEdit::setEnabled(false);


    // TODO utiliser l'algorithm qui cherche une police qui correspond au caractère set au QFont
    QFont font = QFont("Bitstream Vera Sans Mono");
    this->setFont(font);


    // TODO virer certaine options du menu popup

}

void MyTelnetWidget::connectToHost(const QString &host, const quint16 port)
{
    delete t;
    t = new QTelnetPerso(this);

    t->connectToHost(host,port);
    connect(t, SIGNAL(sockConnected()), this, SLOT(sockConnected()));
}

void MyTelnetWidget::disconnectTelnet()
{
    t->disconnectTelnet();
}

// SLOT called by QTelnetPerso
void MyTelnetWidget::sockConnected()
{
    connect(t, SIGNAL(message(const QString &)), this, SLOT(processIncomingData(const QString &)));
    connect(t, SIGNAL(sockDisconnected()), this, SLOT(sockDisconnected()));
    QPlainTextEdit::setEnabled(true);
    emit connected();
}

// SLOT called by QTelnetPerso
void MyTelnetWidget::sockDisconnected()
{
    qDebug() << "Disconnected";
    QPlainTextEdit::appendPlainText("\n");
    QPlainTextEdit::setEnabled(false);
    emit connected();
}

void MyTelnetWidget::processIncomingData(const QString &text)
{
    QString reformatedText;

    if (text == NULL)
        return;

    if (cur)
    {
        this->setTextCursor(*cur);
        delete cur;
        cur = NULL;
    }

    reformatedText = text;
    reformatedText.remove('\r');

    // '\a' == 0x07 (bell)
    if (reformatedText.contains('\a'))
    {
        reformatedText.remove('\a');
        emit bellReceived();
    }

    // '\b' == 0x08 (backspace)     but for telnet it s go left
    if ( reformatedText.contains('\b') )
    {
        if (reformatedText == "\b")
        {
            this->moveCursor(QTextCursor::Left);
            return;
        }
    }

    if ( reformatedText.startsWith("\n") )
    {
        this->moveCursor(QTextCursor::End);
        this->insertPlainText("\n");
        reformatedText.remove(0,1);
    }

    simulateOverWriteMode(reformatedText);

    // AutoScroll
    this->verticalScrollBar()->setValue(this->verticalScrollBar()->maximum());
}

void MyTelnetWidget::simulateOverWriteMode(QString text)    // simulate overwrite mode + interpret '\b'
{
    for (int i=0; i<text.length(); i++)
    {
        if (text.at(i) == '\b')
            this->moveCursor(QTextCursor::Left);
        else
        {
            this->textCursor().deleteChar();
            this->insertPlainText(text.at(i));
        }
    }
}

void MyTelnetWidget::keyPressEvent(QKeyEvent * ke)
{
    if( t==NULL || !t->isConnected() )
    {
        ke->ignore();
        return;
    }

    qDebug("%d",ke->key());

    if (ke->modifiers() == Qt::NoModifier)
    {
        switch (ke->key())
        {
            case Qt::Key_Return:
            case Qt::Key_Enter:
                t->sendData("\r\n");
                break;
            case Qt::Key_Left:
                t->sendData("\033[D");
                break;
            case Qt::Key_Right:
                t->sendData("\033[C");
                break;
            case Qt::Key_Up:
                t->sendData("\033[A");
                break;
            case Qt::Key_Down:
                t->sendData("\033[B");
                break;
            case Qt::Key_Delete:
                t->sendData2(QByteArray(1,0x04));
                break;
            case Qt::Key_Home:
                t->sendData2(QByteArray(1,0x01));
                break;
            case Qt::Key_End:
                t->sendData2(QByteArray(1,0x05));
                break;
            default:
                t->sendData(ke->text());
        }
    }
    else if (ke->modifiers() & Qt::ControlModifier)
    {
        switch (ke->key())
        {
            default:
                t->sendData(ke->text());
        }
    }
    else
        // Send Event I didn't know ... for the moment !
        //QPlainTextEdit::keyPressEvent(ke);
        t->sendData(ke->text());
}
/*
bool MyTelnetWidget::eventFilter(QObject *obj, QEvent *event)
{
    qDebug("Event type : %d",event->type());
    switch (event->type())
    {
        case QEvent::MouseButtonPress:
        case QEvent::MouseButtonRelease:
            return true;
        default:
            return QObject::eventFilter(obj, event);
    }
}
*/

// Obliger de faire ces 3 surcharges puisque le event filter veut pas aller
void MyTelnetWidget::mousePressEvent(QMouseEvent *me)
{
    if (cur)
        delete cur;

    qDebug("coucou");
 //   me->accept();
    cur = new QTextCursor(this->textCursor());
  //  QPlainTextEdit::mousePressEvent(me);
}

void MyTelnetWidget::mouseReleaseEvent(QMouseEvent *me)
{
    if (cur)
    {
        this->setTextCursor(*cur);
        delete cur;
        cur = NULL;
    }
    qDebug("byebye");
//    me->accept();
    //QPlainTextEdit::mouseReleaseEvent(me);
}

void MyTelnetWidget::mouseDoubleClickEvent(QMouseEvent *me)
{
    qDebug("dblClick");
}
