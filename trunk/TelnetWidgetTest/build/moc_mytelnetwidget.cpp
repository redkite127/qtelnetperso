/****************************************************************************
** Meta object code from reading C++ file 'mytelnetwidget.h'
**
** Created: Sat Dec 13 19:02:43 2008
**      by: The Qt Meta Object Compiler version 59 (Qt 4.4.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../libs/src/mytelnetwidget.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mytelnetwidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 59
#error "This file was generated using the moc from 4.4.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_MyTelnetWidget[] = {

 // content:
       1,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   10, // methods
       0,    0, // properties
       0,    0, // enums/sets

 // signals: signature, parameters, type, tag, flags
      16,   15,   15,   15, 0x05,
      28,   15,   15,   15, 0x05,
      43,   15,   15,   15, 0x05,

 // slots: signature, parameters, type, tag, flags
      68,   58,   15,   15, 0x0a,
     104,   99,   15,   15, 0x2a,
     127,   15,   15,   15, 0x0a,
     146,   15,   15,   15, 0x08,
     162,   15,   15,   15, 0x08,
     186,  181,   15,   15, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_MyTelnetWidget[] = {
    "MyTelnetWidget\0\0connected()\0disconnected()\0"
    "bellReceived()\0host,port\0"
    "connectToHost(QString,quint16)\0host\0"
    "connectToHost(QString)\0disconnectTelnet()\0"
    "sockConnected()\0sockDisconnected()\0"
    "text\0processIncomingData(QString)\0"
};

const QMetaObject MyTelnetWidget::staticMetaObject = {
    { &QPlainTextEdit::staticMetaObject, qt_meta_stringdata_MyTelnetWidget,
      qt_meta_data_MyTelnetWidget, 0 }
};

const QMetaObject *MyTelnetWidget::metaObject() const
{
    return &staticMetaObject;
}

void *MyTelnetWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MyTelnetWidget))
        return static_cast<void*>(const_cast< MyTelnetWidget*>(this));
    return QPlainTextEdit::qt_metacast(_clname);
}

int MyTelnetWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QPlainTextEdit::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: connected(); break;
        case 1: disconnected(); break;
        case 2: bellReceived(); break;
        case 3: connectToHost((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const quint16(*)>(_a[2]))); break;
        case 4: connectToHost((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 5: disconnectTelnet(); break;
        case 6: sockConnected(); break;
        case 7: sockDisconnected(); break;
        case 8: processIncomingData((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        }
        _id -= 9;
    }
    return _id;
}

// SIGNAL 0
void MyTelnetWidget::connected()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void MyTelnetWidget::disconnected()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}

// SIGNAL 2
void MyTelnetWidget::bellReceived()
{
    QMetaObject::activate(this, &staticMetaObject, 2, 0);
}
QT_END_MOC_NAMESPACE
