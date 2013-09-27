/****************************************************************************
** Meta object code from reading C++ file 'newgamedialogcontroller.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.0.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../src_Qt5/newgamedialogcontroller.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'newgamedialogcontroller.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.0.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_NewGameDialogController_t {
    QByteArrayData data[10];
    char stringdata[136];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_NewGameDialogController_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_NewGameDialogController_t qt_meta_stringdata_NewGameDialogController = {
    {
QT_MOC_LITERAL(0, 0, 23),
QT_MOC_LITERAL(1, 24, 17),
QT_MOC_LITERAL(2, 42, 0),
QT_MOC_LITERAL(3, 43, 22),
QT_MOC_LITERAL(4, 66, 15),
QT_MOC_LITERAL(5, 82, 16),
QT_MOC_LITERAL(6, 99, 4),
QT_MOC_LITERAL(7, 104, 11),
QT_MOC_LITERAL(8, 116, 6),
QT_MOC_LITERAL(9, 123, 11)
    },
    "NewGameDialogController\0slotCreateNewGrid\0"
    "\0slotCancelGridCreation\0slotItemChecked\0"
    "QListWidgetItem*\0item\0slotAddWord\0"
    "string\0dictionnary\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_NewGameDialogController[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   34,    2, 0x0a,
       3,    0,   35,    2, 0x0a,
       4,    1,   36,    2, 0x0a,
       7,    1,   39,    2, 0x0a,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 5,    6,
    QMetaType::Void, 0x80000000 | 8,    9,

       0        // eod
};

void NewGameDialogController::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        NewGameDialogController *_t = static_cast<NewGameDialogController *>(_o);
        switch (_id) {
        case 0: _t->slotCreateNewGrid(); break;
        case 1: _t->slotCancelGridCreation(); break;
        case 2: _t->slotItemChecked((*reinterpret_cast< QListWidgetItem*(*)>(_a[1]))); break;
        case 3: _t->slotAddWord((*reinterpret_cast< string(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject NewGameDialogController::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_NewGameDialogController.data,
      qt_meta_data_NewGameDialogController,  qt_static_metacall, 0, 0}
};


const QMetaObject *NewGameDialogController::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *NewGameDialogController::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_NewGameDialogController.stringdata))
        return static_cast<void*>(const_cast< NewGameDialogController*>(this));
    return QObject::qt_metacast(_clname);
}

int NewGameDialogController::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 4;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
