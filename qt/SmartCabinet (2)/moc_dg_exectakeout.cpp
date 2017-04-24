/****************************************************************************
** Meta object code from reading C++ file 'dg_exectakeout.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "ui/exec/dg_exectakeout.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'dg_exectakeout.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_Dg_ExecTakeOut_t {
    QByteArrayData data[17];
    char stringdata0[206];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Dg_ExecTakeOut_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Dg_ExecTakeOut_t qt_meta_stringdata_Dg_ExecTakeOut = {
    {
QT_MOC_LITERAL(0, 0, 14), // "Dg_ExecTakeOut"
QT_MOC_LITERAL(1, 15, 12), // "TaskAct_Send"
QT_MOC_LITERAL(2, 28, 0), // ""
QT_MOC_LITERAL(3, 29, 3), // "DID"
QT_MOC_LITERAL(4, 33, 11), // "send_ActNum"
QT_MOC_LITERAL(5, 45, 14), // "OpenSerialPort"
QT_MOC_LITERAL(6, 60, 13), // "GetLockStatus"
QT_MOC_LITERAL(7, 74, 12), // "Unlocksignal"
QT_MOC_LITERAL(8, 87, 8), // "StopTask"
QT_MOC_LITERAL(9, 96, 12), // "QuitExecPage"
QT_MOC_LITERAL(10, 109, 20), // "on_CB_return_clicked"
QT_MOC_LITERAL(11, 130, 18), // "on_pB_jump_clicked"
QT_MOC_LITERAL(12, 149, 12), // "ErrorMessage"
QT_MOC_LITERAL(13, 162, 5), // "order"
QT_MOC_LITERAL(14, 168, 11), // "HandleReply"
QT_MOC_LITERAL(15, 180, 15), // "LockStatusSlots"
QT_MOC_LITERAL(16, 196, 9) // "ClosePage"

    },
    "Dg_ExecTakeOut\0TaskAct_Send\0\0DID\0"
    "send_ActNum\0OpenSerialPort\0GetLockStatus\0"
    "Unlocksignal\0StopTask\0QuitExecPage\0"
    "on_CB_return_clicked\0on_pB_jump_clicked\0"
    "ErrorMessage\0order\0HandleReply\0"
    "LockStatusSlots\0ClosePage"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Dg_ExecTakeOut[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       6,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   74,    2, 0x06 /* Public */,
       5,    0,   79,    2, 0x06 /* Public */,
       6,    1,   80,    2, 0x06 /* Public */,
       7,    1,   83,    2, 0x06 /* Public */,
       8,    1,   86,    2, 0x06 /* Public */,
       9,    0,   89,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      10,    0,   90,    2, 0x08 /* Private */,
      11,    0,   91,    2, 0x08 /* Private */,
      12,    1,   92,    2, 0x08 /* Private */,
      14,    1,   95,    2, 0x08 /* Private */,
      15,    1,   98,    2, 0x08 /* Private */,
      16,    0,  101,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    3,    4,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   13,
    QMetaType::Void, QMetaType::Int,   13,
    QMetaType::Void, QMetaType::Int,   13,
    QMetaType::Void,

       0        // eod
};

void Dg_ExecTakeOut::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Dg_ExecTakeOut *_t = static_cast<Dg_ExecTakeOut *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->TaskAct_Send((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 1: _t->OpenSerialPort(); break;
        case 2: _t->GetLockStatus((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->Unlocksignal((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->StopTask((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->QuitExecPage(); break;
        case 6: _t->on_CB_return_clicked(); break;
        case 7: _t->on_pB_jump_clicked(); break;
        case 8: _t->ErrorMessage((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 9: _t->HandleReply((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 10: _t->LockStatusSlots((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 11: _t->ClosePage(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (Dg_ExecTakeOut::*_t)(int , int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Dg_ExecTakeOut::TaskAct_Send)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (Dg_ExecTakeOut::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Dg_ExecTakeOut::OpenSerialPort)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (Dg_ExecTakeOut::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Dg_ExecTakeOut::GetLockStatus)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (Dg_ExecTakeOut::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Dg_ExecTakeOut::Unlocksignal)) {
                *result = 3;
                return;
            }
        }
        {
            typedef void (Dg_ExecTakeOut::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Dg_ExecTakeOut::StopTask)) {
                *result = 4;
                return;
            }
        }
        {
            typedef void (Dg_ExecTakeOut::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Dg_ExecTakeOut::QuitExecPage)) {
                *result = 5;
                return;
            }
        }
    }
}

const QMetaObject Dg_ExecTakeOut::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_Dg_ExecTakeOut.data,
      qt_meta_data_Dg_ExecTakeOut,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *Dg_ExecTakeOut::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Dg_ExecTakeOut::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_Dg_ExecTakeOut.stringdata0))
        return static_cast<void*>(const_cast< Dg_ExecTakeOut*>(this));
    return QDialog::qt_metacast(_clname);
}

int Dg_ExecTakeOut::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 12)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 12;
    }
    return _id;
}

// SIGNAL 0
void Dg_ExecTakeOut::TaskAct_Send(int _t1, int _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void Dg_ExecTakeOut::OpenSerialPort()
{
    QMetaObject::activate(this, &staticMetaObject, 1, Q_NULLPTR);
}

// SIGNAL 2
void Dg_ExecTakeOut::GetLockStatus(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void Dg_ExecTakeOut::Unlocksignal(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void Dg_ExecTakeOut::StopTask(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void Dg_ExecTakeOut::QuitExecPage()
{
    QMetaObject::activate(this, &staticMetaObject, 5, Q_NULLPTR);
}
QT_END_MOC_NAMESPACE
