/****************************************************************************
** Meta object code from reading C++ file 'DictionnaryManager.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.0.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../src_Qt5/DictionnaryManager.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'DictionnaryManager.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.0.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_DictionnaryManager_t {
    QByteArrayData data[6];
    char stringdata[68];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_DictionnaryManager_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_DictionnaryManager_t qt_meta_stringdata_DictionnaryManager = {
    {
QT_MOC_LITERAL(0, 0, 18),
QT_MOC_LITERAL(1, 19, 9),
QT_MOC_LITERAL(2, 29, 0),
QT_MOC_LITERAL(3, 30, 16),
QT_MOC_LITERAL(4, 47, 6),
QT_MOC_LITERAL(5, 54, 12)
    },
    "DictionnaryManager\0wordAdded\0\0"
    "dictionnaryAdded\0string\0dictionnaire\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_DictionnaryManager[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   24,    2, 0x05,
       3,    1,   25,    2, 0x05,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 4,    5,

       0        // eod
};

void DictionnaryManager::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        DictionnaryManager *_t = static_cast<DictionnaryManager *>(_o);
        switch (_id) {
        case 0: _t->wordAdded(); break;
        case 1: _t->dictionnaryAdded((*reinterpret_cast< string(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (DictionnaryManager::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&DictionnaryManager::wordAdded)) {
                *result = 0;
            }
        }
        {
            typedef void (DictionnaryManager::*_t)(string );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&DictionnaryManager::dictionnaryAdded)) {
                *result = 1;
            }
        }
    }
}

const QMetaObject DictionnaryManager::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_DictionnaryManager.data,
      qt_meta_data_DictionnaryManager,  qt_static_metacall, 0, 0}
};


const QMetaObject *DictionnaryManager::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *DictionnaryManager::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_DictionnaryManager.stringdata))
        return static_cast<void*>(const_cast< DictionnaryManager*>(this));
    return QObject::qt_metacast(_clname);
}

int DictionnaryManager::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 2)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 2;
    }
    return _id;
}

// SIGNAL 0
void DictionnaryManager::wordAdded()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void DictionnaryManager::dictionnaryAdded(string _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_END_MOC_NAMESPACE
