/****************************************************************************
** Meta object code from reading C++ file 'dg_takein.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "ui/task/dg_takein.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'dg_takein.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_Dg_TakeIn_t {
    QByteArrayData data[15];
    char stringdata0[191];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Dg_TakeIn_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Dg_TakeIn_t qt_meta_stringdata_Dg_TakeIn = {
    {
QT_MOC_LITERAL(0, 0, 9), // "Dg_TakeIn"
QT_MOC_LITERAL(1, 10, 18), // "on_pB_exec_clicked"
QT_MOC_LITERAL(2, 29, 0), // ""
QT_MOC_LITERAL(3, 30, 19), // "on_pB_apply_clicked"
QT_MOC_LITERAL(4, 50, 20), // "on_pB_delete_clicked"
QT_MOC_LITERAL(5, 71, 20), // "on_pB_search_clicked"
QT_MOC_LITERAL(6, 92, 20), // "on_CB_return_clicked"
QT_MOC_LITERAL(7, 113, 8), // "ShowPage"
QT_MOC_LITERAL(8, 122, 18), // "AcceptPositionInfo"
QT_MOC_LITERAL(9, 141, 10), // "positionNo"
QT_MOC_LITERAL(10, 152, 10), // "positionId"
QT_MOC_LITERAL(11, 163, 6), // "drawer"
QT_MOC_LITERAL(12, 170, 8), // "dataTime"
QT_MOC_LITERAL(13, 179, 6), // "bottle"
QT_MOC_LITERAL(14, 186, 4) // "dose"

    },
    "Dg_TakeIn\0on_pB_exec_clicked\0\0"
    "on_pB_apply_clicked\0on_pB_delete_clicked\0"
    "on_pB_search_clicked\0on_CB_return_clicked\0"
    "ShowPage\0AcceptPositionInfo\0positionNo\0"
    "positionId\0drawer\0dataTime\0bottle\0"
    "dose"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Dg_TakeIn[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   49,    2, 0x08 /* Private */,
       3,    0,   50,    2, 0x08 /* Private */,
       4,    0,   51,    2, 0x08 /* Private */,
       5,    0,   52,    2, 0x08 /* Private */,
       6,    0,   53,    2, 0x08 /* Private */,
       7,    0,   54,    2, 0x08 /* Private */,
       8,    6,   55,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::QString, QMetaType::QString, QMetaType::QString,    9,   10,   11,   12,   13,   14,

       0        // eod
};

void Dg_TakeIn::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Dg_TakeIn *_t = static_cast<Dg_TakeIn *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_pB_exec_clicked(); break;
        case 1: _t->on_pB_apply_clicked(); break;
        case 2: _t->on_pB_delete_clicked(); break;
        case 3: _t->on_pB_search_clicked(); break;
        case 4: _t->on_CB_return_clicked(); break;
        case 5: _t->ShowPage(); break;
        case 6: _t->AcceptPositionInfo((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< QString(*)>(_a[4])),(*reinterpret_cast< QString(*)>(_a[5])),(*reinterpret_cast< QString(*)>(_a[6]))); break;
        default: ;
        }
    }
}

const QMetaObject Dg_TakeIn::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_Dg_TakeIn.data,
      qt_meta_data_Dg_TakeIn,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *Dg_TakeIn::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Dg_TakeIn::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_Dg_TakeIn.stringdata0))
        return static_cast<void*>(const_cast< Dg_TakeIn*>(this));
    return QDialog::qt_metacast(_clname);
}

int Dg_TakeIn::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
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
QT_END_MOC_NAMESPACE
