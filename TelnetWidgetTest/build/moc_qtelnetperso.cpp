/****************************************************************************
** Meta object code from reading C++ file 'qtelnetperso.h'
**
** Created: Sat Dec 13 19:02:44 2008
**      by: The Qt Meta Object Compiler version 59 (Qt 4.4.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../libs/src/qtelnetperso.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qtelnetperso.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 59
#error "This file was generated using the moc from 4.4.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_QTelnetPerso[] = {

 // content:
       1,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   10, // methods
       0,    0, // properties
       0,    0, // enums/sets

 // signals: signature, parameters, type, tag, flags
      19,   14,   13,   13, 0x05,
      36,   13,   13,   13, 0x05,
      52,   13,   13,   13, 0x05,

 // slots: signature, parameters, type, tag, flags
      71,   13,   13,   13, 0x0a,
      89,   13,   13,   13, 0x0a,
     114,   13,   13,   13, 0x0a,
     138,  132,   13,   13, 0x0a,
     180,   13,   13,   13, 0x0a,
     201,   14,   13,   13, 0x0a,
     219,   14,   13,   13, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_QTelnetPerso[] = {
    "QTelnetPerso\0\0data\0message(QString)\0"
    "sockConnected()\0sockDisconnected()\0"
    "socketConnected()\0socketConnectionClosed()\0"
    "socketReadyRead()\0error\0"
    "socketError(QAbstractSocket::SocketError)\0"
    "socketException(int)\0sendData(QString)\0"
    "sendData2(QByteArray)\0"
};

const QMetaObject QTelnetPerso::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_QTelnetPerso,
      qt_meta_data_QTelnetPerso, 0 }
};

const QMetaObject *QTelnetPerso::metaObject() const
{
    return &staticMetaObject;
}

void *QTelnetPerso::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_QTelnetPerso))
        return static_cast<void*>(const_cast< QTelnetPerso*>(this));
    return QObject::qt_metacast(_clname);
}

int QTelnetPerso::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: message((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 1: sockConnected(); break;
        case 2: sockDisconnected(); break;
        case 3: socketConnected(); break;
        case 4: socketConnectionClosed(); break;
        case 5: socketReadyRead(); break;
        case 6: socketError((*reinterpret_cast< QAbstractSocket::SocketError(*)>(_a[1]))); break;
        case 7: socketException((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 8: sendData((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 9: sendData2((*reinterpret_cast< const QByteArray(*)>(_a[1]))); break;
        }
        _id -= 10;
    }
    return _id;
}

// SIGNAL 0
void QTelnetPerso::message(const QString & _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void QTelnetPerso::sockConnected()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}

// SIGNAL 2
void QTelnetPerso::sockDisconnected()
{
    QMetaObject::activate(this, &staticMetaObject, 2, 0);
}
QT_END_MOC_NAMESPACE
