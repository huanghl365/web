/****************************************************************************
** Meta object code from reading C++ file 'serialportcontrol.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../SmartCabinet/common/serialportcontrol.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'serialportcontrol.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_SerialPortControl_t {
    QByteArrayData data[12];
    char stringdata0[150];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_SerialPortControl_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_SerialPortControl_t qt_meta_stringdata_SerialPortControl = {
    {
QT_MOC_LITERAL(0, 0, 17), // "SerialPortControl"
QT_MOC_LITERAL(1, 18, 10), // "Task_Error"
QT_MOC_LITERAL(2, 29, 0), // ""
QT_MOC_LITERAL(3, 30, 6), // "status"
QT_MOC_LITERAL(4, 37, 25), // "ReplyCurrentAgentiaStatus"
QT_MOC_LITERAL(5, 63, 10), // "ReturnLock"
QT_MOC_LITERAL(6, 74, 3), // "DID"
QT_MOC_LITERAL(7, 78, 10), // "HandleFlow"
QT_MOC_LITERAL(8, 89, 11), // "send_ActNum"
QT_MOC_LITERAL(9, 101, 16), // "CreateSerialPort"
QT_MOC_LITERAL(10, 118, 16), // "ReturnLockStatus"
QT_MOC_LITERAL(11, 135, 14) // "DestroyProcess"

    },
    "SerialPortControl\0Task_Error\0\0status\0"
    "ReplyCurrentAgentiaStatus\0ReturnLock\0"
    "DID\0HandleFlow\0send_ActNum\0CreateSerialPort\0"
    "ReturnLockStatus\0DestroyProcess"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_SerialPortControl[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   49,    2, 0x06 /* Public */,
       4,    1,   52,    2, 0x06 /* Public */,
       5,    1,   55,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       7,    2,   58,    2, 0x0a /* Public */,
       9,    0,   63,    2, 0x0a /* Public */,
      10,    1,   64,    2, 0x0a /* Public */,
      11,    0,   67,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    6,

 // slots: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    6,    8,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    6,
    QMetaType::Void,

       0        // eod
};

void SerialPortControl::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        SerialPortControl *_t = static_cast<SerialPortControl *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->Task_Error((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->ReplyCurrentAgentiaStatus((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->ReturnLock((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->HandleFlow((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 4: _t->CreateSerialPort(); break;
        case 5: _t->ReturnLockStatus((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->DestroyProcess(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (SerialPortControl::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&SerialPortControl::Task_Error)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (SerialPortControl::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&SerialPortControl::ReplyCurrentAgentiaStatus)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (SerialPortControl::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&SerialPortControl::ReturnLock)) {
                *result = 2;
                return;
            }
        }
    }
}

const QMetaObject SerialPortControl::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_SerialPortControl.data,
      qt_meta_data_SerialPortControl,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *SerialPortControl::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *SerialPortControl::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_SerialPortControl.stringdata0))
        return static_cast<void*>(const_cast< SerialPortControl*>(this));
    return QObject::qt_metacast(_clname);
}

int SerialPortControl::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 7;
    }
    return _id;
}

// SIGNAL 0
void SerialPortControl::Task_Error(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void SerialPortControl::ReplyCurrentAgentiaStatus(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void SerialPortControl::ReturnLock(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_END_MOC_NAMESPACE
