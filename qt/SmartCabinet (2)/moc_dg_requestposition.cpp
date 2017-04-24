/****************************************************************************
** Meta object code from reading C++ file 'dg_requestposition.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "ui/common/dg_requestposition.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'dg_requestposition.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_Dg_RequestPosition_t {
    QByteArrayData data[11];
    char stringdata0[123];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Dg_RequestPosition_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Dg_RequestPosition_t qt_meta_stringdata_Dg_RequestPosition = {
    {
QT_MOC_LITERAL(0, 0, 18), // "Dg_RequestPosition"
QT_MOC_LITERAL(1, 19, 13), // "ReplyNeedInfo"
QT_MOC_LITERAL(2, 33, 0), // ""
QT_MOC_LITERAL(3, 34, 10), // "positionNo"
QT_MOC_LITERAL(4, 45, 10), // "positionId"
QT_MOC_LITERAL(5, 56, 6), // "drawer"
QT_MOC_LITERAL(6, 63, 8), // "dataTime"
QT_MOC_LITERAL(7, 72, 6), // "bottle"
QT_MOC_LITERAL(8, 79, 4), // "dose"
QT_MOC_LITERAL(9, 84, 18), // "on_pB_back_clicked"
QT_MOC_LITERAL(10, 103, 19) // "on_pB_apply_clicked"

    },
    "Dg_RequestPosition\0ReplyNeedInfo\0\0"
    "positionNo\0positionId\0drawer\0dataTime\0"
    "bottle\0dose\0on_pB_back_clicked\0"
    "on_pB_apply_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Dg_RequestPosition[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    6,   29,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       9,    0,   42,    2, 0x08 /* Private */,
      10,    0,   43,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::QString, QMetaType::QString, QMetaType::QString,    3,    4,    5,    6,    7,    8,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void Dg_RequestPosition::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Dg_RequestPosition *_t = static_cast<Dg_RequestPosition *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->ReplyNeedInfo((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< QString(*)>(_a[4])),(*reinterpret_cast< QString(*)>(_a[5])),(*reinterpret_cast< QString(*)>(_a[6]))); break;
        case 1: _t->on_pB_back_clicked(); break;
        case 2: _t->on_pB_apply_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (Dg_RequestPosition::*_t)(int , int , int , QString , QString , QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Dg_RequestPosition::ReplyNeedInfo)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject Dg_RequestPosition::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_Dg_RequestPosition.data,
      qt_meta_data_Dg_RequestPosition,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *Dg_RequestPosition::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Dg_RequestPosition::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_Dg_RequestPosition.stringdata0))
        return static_cast<void*>(const_cast< Dg_RequestPosition*>(this));
    return QDialog::qt_metacast(_clname);
}

int Dg_RequestPosition::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 3;
    }
    return _id;
}

// SIGNAL 0
void Dg_RequestPosition::ReplyNeedInfo(int _t1, int _t2, int _t3, QString _t4, QString _t5, QString _t6)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)), const_cast<void*>(reinterpret_cast<const void*>(&_t5)), const_cast<void*>(reinterpret_cast<const void*>(&_t6)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
