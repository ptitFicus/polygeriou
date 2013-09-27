/****************************************************************************
** Meta object code from reading C++ file 'dictionnarymanagerdialogcontroller.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.0.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../src_Qt5/dictionnarymanagerdialogcontroller.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'dictionnarymanagerdialogcontroller.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.0.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_DictionnaryManagerDialogController_t {
    QByteArrayData data[18];
    char stringdata[264];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_DictionnaryManagerDialogController_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_DictionnaryManagerDialogController_t qt_meta_stringdata_DictionnaryManagerDialogController = {
    {
QT_MOC_LITERAL(0, 0, 34),
QT_MOC_LITERAL(1, 35, 21),
QT_MOC_LITERAL(2, 57, 0),
QT_MOC_LITERAL(3, 58, 21),
QT_MOC_LITERAL(4, 80, 21),
QT_MOC_LITERAL(5, 102, 4),
QT_MOC_LITERAL(6, 107, 14),
QT_MOC_LITERAL(7, 122, 3),
QT_MOC_LITERAL(8, 126, 6),
QT_MOC_LITERAL(9, 133, 14),
QT_MOC_LITERAL(10, 148, 11),
QT_MOC_LITERAL(11, 160, 21),
QT_MOC_LITERAL(12, 182, 13),
QT_MOC_LITERAL(13, 196, 15),
QT_MOC_LITERAL(14, 212, 23),
QT_MOC_LITERAL(15, 236, 6),
QT_MOC_LITERAL(16, 243, 4),
QT_MOC_LITERAL(17, 248, 14)
    },
    "DictionnaryManagerDialogController\0"
    "slotImportDictionnary\0\0slotDeleteDictionnary\0"
    "slotSelectDictionnary\0dict\0slotModifyWord\0"
    "row\0column\0slotDeleteWord\0slotAddWord\0"
    "slotCreateDictionnary\0slotActualize\0"
    "slotSaveChanges\0slotImportDictionnaryDM\0"
    "string\0name\0slotSearchWord\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_DictionnaryManagerDialogController[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   69,    2, 0x0a,
       3,    0,   70,    2, 0x0a,
       4,    1,   71,    2, 0x0a,
       6,    2,   74,    2, 0x0a,
       9,    0,   79,    2, 0x0a,
      10,    0,   80,    2, 0x0a,
      11,    0,   81,    2, 0x0a,
      12,    0,   82,    2, 0x0a,
      13,    0,   83,    2, 0x0a,
      14,    1,   84,    2, 0x0a,
      17,    1,   87,    2, 0x0a,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    5,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    7,    8,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 15,   16,
    QMetaType::Void, QMetaType::QString,   15,

       0        // eod
};

void DictionnaryManagerDialogController::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        DictionnaryManagerDialogController *_t = static_cast<DictionnaryManagerDialogController *>(_o);
        switch (_id) {
        case 0: _t->slotImportDictionnary(); break;
        case 1: _t->slotDeleteDictionnary(); break;
        case 2: _t->slotSelectDictionnary((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 3: _t->slotModifyWord((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 4: _t->slotDeleteWord(); break;
        case 5: _t->slotAddWord(); break;
        case 6: _t->slotCreateDictionnary(); break;
        case 7: _t->slotActualize(); break;
        case 8: _t->slotSaveChanges(); break;
        case 9: _t->slotImportDictionnaryDM((*reinterpret_cast< string(*)>(_a[1]))); break;
        case 10: _t->slotSearchWord((*reinterpret_cast< QString(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject DictionnaryManagerDialogController::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_DictionnaryManagerDialogController.data,
      qt_meta_data_DictionnaryManagerDialogController,  qt_static_metacall, 0, 0}
};


const QMetaObject *DictionnaryManagerDialogController::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *DictionnaryManagerDialogController::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_DictionnaryManagerDialogController.stringdata))
        return static_cast<void*>(const_cast< DictionnaryManagerDialogController*>(this));
    return QObject::qt_metacast(_clname);
}

int DictionnaryManagerDialogController::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 11)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 11;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
