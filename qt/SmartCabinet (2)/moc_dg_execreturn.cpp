/****************************************************************************
** Meta object code from reading C++ file 'dg_execreturn.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "ui/exec/dg_execreturn.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'dg_execreturn.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_Dg_ExecReturn_t {
    QByteArrayData data[18];
    char stringdata0[224];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Dg_ExecReturn_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Dg_ExecReturn_t qt_meta_stringdata_Dg_ExecReturn = {
    {
QT_MOC_LITERAL(0, 0, 13), // "Dg_ExecReturn"
QT_MOC_LITERAL(1, 14, 12), // "TaskAct_Send"
QT_MOC_LITERAL(2, 27, 0), // ""
QT_MOC_LITERAL(3, 28, 3), // "DID"
QT_MOC_LITERAL(4, 32, 11), // "send_ActNum"
QT_MOC_LITERAL(5, 44, 14), // "OpenSerialPort"
QT_MOC_LITERAL(6, 59, 13), // "GetLockStatus"
QT_MOC_LITERAL(7, 73, 12), // "Unlocksignal"
QT_MOC_LITERAL(8, 86, 8), // "StopTask"
QT_MOC_LITERAL(9, 95, 12), // "QuitExecPage"
QT_MOC_LITERAL(10, 108, 18), // "on_pB_sure_clicked"
QT_MOC_LITERAL(11, 127, 20), // "on_CB_return_clicked"
QT_MOC_LITERAL(12, 148, 18), // "on_pB_jump_clicked"
QT_MOC_LITERAL(13, 167, 12), // "ErrorMessage"
QT_MOC_LITERAL(14, 180, 5), // "order"
QT_MOC_LITERAL(15, 186, 11), // "HandleReply"
QT_MOC_LITERAL(16, 198, 15), // "LockStatusSlots"
QT_MOC_LITERAL(17, 214, 9) // "ClosePage"

    },
    "Dg_ExecReturn\0TaskAct_Send\0\0DID\0"
    "send_ActNum\0OpenSerialPort\0GetLockStatus\0"
    "Unlocksignal\0StopTask\0QuitExecPage\0"
    "on_pB_sure_clicked\0on_CB_return_clicked\0"
    "on_pB_jump_clicked\0ErrorMessage\0order\0"
    "HandleReply\0LockStatusSlots\0ClosePage"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Dg_ExecReturn[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      13,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       6,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   79,    2, 0x06 /* Public */,
       5,    0,   84,    2, 0x06 /* Public */,
       6,    1,   85,    2, 0x06 /* Public */,
       7,    1,   88,    2, 0x06 /* Public */,
       8,    1,   91,    2, 0x06 /* Public */,
       9,    0,   94,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      10,    0,   95,    2, 0x08 /* Private */,
      11,    0,   96,    2, 0x08 /* Private */,
      12,    0,   97,    2, 0x08 /* Private */,
      13,    1,   98,    2, 0x08 /* Private */,
      15,    1,  101,    2, 0x08 /* Private */,
      16,    1,  104,    2, 0x08 /* Private */,
      17,    0,  107,    2, 0x08 /* Private */,

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
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   14,
    QMetaType::Void, QMetaType::Int,   14,
    QMetaType::Void, QMetaType::Int,   14,
    QMetaType::Void,

       0        // eod
};

void Dg_ExecReturn::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Dg_ExecReturn *_t = static_cast<Dg_ExecReturn *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->TaskAct_Send((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 1: _t->OpenSerialPort(); break;
        case 2: _t->GetLockStatus((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->Unlocksignal((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->StopTask((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->QuitExecPage(); break;
        case 6: _t->on_pB_sure_clicked(); break;
        case 7: _t->on_CB_return_clicked(); break;
        case 8: _t->on_pB_jump_clicked(); break;
        case 9: _t->ErrorMessage((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 10: _t->HandleReply((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 11: _t->LockStatusSlots((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 12: _t->ClosePage(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (Dg_ExecReturn::*_t)(int , int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Dg_ExecReturn::TaskAct_Send)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (Dg_ExecReturn::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Dg_ExecReturn::OpenSerialPort)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (Dg_ExecReturn::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Dg_ExecReturn::GetLockStatus)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (Dg_ExecReturn::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Dg_ExecReturn::Unlocksignal)) {
                *result = 3;
                return;
            }
        }
        {
            typedef void (Dg_ExecReturn::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Dg_ExecReturn::StopTask)) {
                *result = 4;
                return;
            }
        }
        {
            typedef void (Dg_ExecReturn::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Dg_ExecReturn::QuitExecPage)) {
                *result = 5;
                return;
            }
        }
    }
}

const QMetaObject Dg_ExecReturn::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_Dg_ExecReturn.data,
      qt_meta_data_Dg_ExecReturn,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *Dg_ExecReturn::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Dg_ExecReturn::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_Dg_ExecReturn.stringdata0))
        return static_cast<void*>(const_cast< Dg_ExecReturn*>(this));
    return QDialog::qt_metacast(_clname);
}

int Dg_ExecReturn::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 13)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 13;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 13)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 13;
    }
    return _id;
}

// SIGNAL 0
void Dg_ExecReturn::TaskAct_Send(int _t1, int _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void Dg_ExecReturn::OpenSerialPort()
{
    QMetaObject::activate(this, &staticMetaObject, 1, Q_NULLPTR);
}

// SIGNAL 2
void Dg_ExecReturn::GetLockStatus(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void Dg_ExecReturn::Unlocksignal(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void Dg_ExecReturn::StopTask(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void Dg_ExecReturn::QuitExecPage()
{
    QMetaObject::activate(this, &staticMetaObject, 5, Q_NULLPTR);
}
QT_END_MOC_NAMESPACE
