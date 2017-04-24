/****************************************************************************
** Meta object code from reading C++ file 'dg_takeoutpage.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../SmartCabinet/ui/task/dg_takeoutpage.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'dg_takeoutpage.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_Dg_TakeOutPage_t {
    QByteArrayData data[7];
    char stringdata0[118];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Dg_TakeOutPage_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Dg_TakeOutPage_t qt_meta_stringdata_Dg_TakeOutPage = {
    {
QT_MOC_LITERAL(0, 0, 14), // "Dg_TakeOutPage"
QT_MOC_LITERAL(1, 15, 18), // "on_pB_exec_clicked"
QT_MOC_LITERAL(2, 34, 0), // ""
QT_MOC_LITERAL(3, 35, 19), // "on_pB_apply_clicked"
QT_MOC_LITERAL(4, 55, 20), // "on_pB_delete_clicked"
QT_MOC_LITERAL(5, 76, 20), // "on_pB_search_clicked"
QT_MOC_LITERAL(6, 97, 20) // "on_CB_return_clicked"

    },
    "Dg_TakeOutPage\0on_pB_exec_clicked\0\0"
    "on_pB_apply_clicked\0on_pB_delete_clicked\0"
    "on_pB_search_clicked\0on_CB_return_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Dg_TakeOutPage[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   39,    2, 0x08 /* Private */,
       3,    0,   40,    2, 0x08 /* Private */,
       4,    0,   41,    2, 0x08 /* Private */,
       5,    0,   42,    2, 0x08 /* Private */,
       6,    0,   43,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void Dg_TakeOutPage::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Dg_TakeOutPage *_t = static_cast<Dg_TakeOutPage *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_pB_exec_clicked(); break;
        case 1: _t->on_pB_apply_clicked(); break;
        case 2: _t->on_pB_delete_clicked(); break;
        case 3: _t->on_pB_search_clicked(); break;
        case 4: _t->on_CB_return_clicked(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject Dg_TakeOutPage::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_Dg_TakeOutPage.data,
      qt_meta_data_Dg_TakeOutPage,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *Dg_TakeOutPage::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Dg_TakeOutPage::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_Dg_TakeOutPage.stringdata0))
        return static_cast<void*>(const_cast< Dg_TakeOutPage*>(this));
    return QDialog::qt_metacast(_clname);
}

int Dg_TakeOutPage::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 5;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
