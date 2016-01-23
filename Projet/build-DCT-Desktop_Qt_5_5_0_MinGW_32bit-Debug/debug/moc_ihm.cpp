/****************************************************************************
** Meta object code from reading C++ file 'ihm.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../DCT/ihm.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ihm.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_IHM_t {
    QByteArrayData data[10];
    char stringdata0[101];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_IHM_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_IHM_t qt_meta_stringdata_IHM = {
    {
QT_MOC_LITERAL(0, 0, 3), // "IHM"
QT_MOC_LITERAL(1, 4, 10), // "startClick"
QT_MOC_LITERAL(2, 15, 0), // ""
QT_MOC_LITERAL(3, 16, 10), // "clearClick"
QT_MOC_LITERAL(4, 27, 10), // "focusClick"
QT_MOC_LITERAL(5, 38, 13), // "openFileClick"
QT_MOC_LITERAL(6, 52, 13), // "saveFileClick"
QT_MOC_LITERAL(7, 66, 10), // "aboutClick"
QT_MOC_LITERAL(8, 77, 17), // "updateProgressBar"
QT_MOC_LITERAL(9, 95, 5) // "value"

    },
    "IHM\0startClick\0\0clearClick\0focusClick\0"
    "openFileClick\0saveFileClick\0aboutClick\0"
    "updateProgressBar\0value"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_IHM[] = {

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
       8,    1,   55,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    9,

       0        // eod
};

void IHM::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        IHM *_t = static_cast<IHM *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->startClick(); break;
        case 1: _t->clearClick(); break;
        case 2: _t->focusClick(); break;
        case 3: _t->openFileClick(); break;
        case 4: _t->saveFileClick(); break;
        case 5: _t->aboutClick(); break;
        case 6: _t->updateProgressBar((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject IHM::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_IHM.data,
      qt_meta_data_IHM,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *IHM::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *IHM::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_IHM.stringdata0))
        return static_cast<void*>(const_cast< IHM*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int IHM::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
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
