/****************************************************************************
** Meta object code from reading C++ file 'timerandupdate.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../SmartCabinet/common/timerandupdate.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'timerandupdate.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_TimerAndUpdate_t {
    QByteArrayData data[9];
    char stringdata0[108];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_TimerAndUpdate_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_TimerAndUpdate_t qt_meta_stringdata_TimerAndUpdate = {
    {
QT_MOC_LITERAL(0, 0, 14), // "TimerAndUpdate"
QT_MOC_LITERAL(1, 15, 15), // "Timer_Task_Quit"
QT_MOC_LITERAL(2, 31, 0), // ""
QT_MOC_LITERAL(3, 32, 20), // "Timer_Task_UpdateSQL"
QT_MOC_LITERAL(4, 53, 10), // "TestThread"
QT_MOC_LITERAL(5, 64, 13), // "replyFinished"
QT_MOC_LITERAL(6, 78, 14), // "QNetworkReply*"
QT_MOC_LITERAL(7, 93, 5), // "reply"
QT_MOC_LITERAL(8, 99, 8) // "dealTask"

    },
    "TimerAndUpdate\0Timer_Task_Quit\0\0"
    "Timer_Task_UpdateSQL\0TestThread\0"
    "replyFinished\0QNetworkReply*\0reply\0"
    "dealTask"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_TimerAndUpdate[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   39,    2, 0x06 /* Public */,
       3,    0,   40,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    0,   41,    2, 0x0a /* Public */,
       5,    1,   42,    2, 0x0a /* Public */,
       8,    0,   45,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 6,    7,
    QMetaType::Void,

       0        // eod
};

void TimerAndUpdate::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        TimerAndUpdate *_t = static_cast<TimerAndUpdate *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->Timer_Task_Quit(); break;
        case 1: _t->Timer_Task_UpdateSQL(); break;
        case 2: _t->TestThread(); break;
        case 3: _t->replyFinished((*reinterpret_cast< QNetworkReply*(*)>(_a[1]))); break;
        case 4: _t->dealTask(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 3:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QNetworkReply* >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (TimerAndUpdate::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&TimerAndUpdate::Timer_Task_Quit)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (TimerAndUpdate::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&TimerAndUpdate::Timer_Task_UpdateSQL)) {
                *result = 1;
                return;
            }
        }
    }
}

const QMetaObject TimerAndUpdate::staticMetaObject = {
    { &QTimer::staticMetaObject, qt_meta_stringdata_TimerAndUpdate.data,
      qt_meta_data_TimerAndUpdate,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *TimerAndUpdate::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *TimerAndUpdate::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_TimerAndUpdate.stringdata0))
        return static_cast<void*>(const_cast< TimerAndUpdate*>(this));
    return QTimer::qt_metacast(_clname);
}

int TimerAndUpdate::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QTimer::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void TimerAndUpdate::Timer_Task_Quit()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}

// SIGNAL 1
void TimerAndUpdate::Timer_Task_UpdateSQL()
{
    QMetaObject::activate(this, &staticMetaObject, 1, Q_NULLPTR);
}
QT_END_MOC_NAMESPACE
