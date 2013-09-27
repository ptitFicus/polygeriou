/****************************************************************************
** Meta object code from reading C++ file 'squarescene.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.0.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../src_Qt5/squarescene.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'squarescene.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.0.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_SquareScene_t {
    QByteArrayData data[12];
    char stringdata[92];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_SquareScene_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_SquareScene_t qt_meta_stringdata_SquareScene = {
    {
QT_MOC_LITERAL(0, 0, 11),
QT_MOC_LITERAL(1, 12, 5),
QT_MOC_LITERAL(2, 18, 0),
QT_MOC_LITERAL(3, 19, 4),
QT_MOC_LITERAL(4, 24, 7),
QT_MOC_LITERAL(5, 32, 12),
QT_MOC_LITERAL(6, 45, 2),
QT_MOC_LITERAL(7, 48, 11),
QT_MOC_LITERAL(8, 60, 1),
QT_MOC_LITERAL(9, 62, 14),
QT_MOC_LITERAL(10, 77, 1),
QT_MOC_LITERAL(11, 79, 11)
    },
    "SquareScene\0enter\0\0exit\0clicked\0"
    "SquareScene*\0sq\0leftClicked\0p\0"
    "letterkeypress\0s\0delkeypress\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_SquareScene[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       6,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   44,    2, 0x05,
       3,    1,   47,    2, 0x05,
       4,    1,   50,    2, 0x05,
       7,    2,   53,    2, 0x05,
       9,    2,   58,    2, 0x05,
      11,    1,   63,    2, 0x05,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, 0x80000000 | 5,    6,
    QMetaType::Void, 0x80000000 | 5, QMetaType::QPoint,    6,    8,
    QMetaType::Void, 0x80000000 | 5, QMetaType::QString,    6,   10,
    QMetaType::Void, 0x80000000 | 5,    6,

       0        // eod
};

void SquareScene::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        SquareScene *_t = static_cast<SquareScene *>(_o);
        switch (_id) {
        case 0: _t->enter((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->exit((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->clicked((*reinterpret_cast< SquareScene*(*)>(_a[1]))); break;
        case 3: _t->leftClicked((*reinterpret_cast< SquareScene*(*)>(_a[1])),(*reinterpret_cast< QPoint(*)>(_a[2]))); break;
        case 4: _t->letterkeypress((*reinterpret_cast< SquareScene*(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 5: _t->delkeypress((*reinterpret_cast< SquareScene*(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 2:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< SquareScene* >(); break;
            }
            break;
        case 3:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< SquareScene* >(); break;
            }
            break;
        case 4:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< SquareScene* >(); break;
            }
            break;
        case 5:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< SquareScene* >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (SquareScene::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&SquareScene::enter)) {
                *result = 0;
            }
        }
        {
            typedef void (SquareScene::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&SquareScene::exit)) {
                *result = 1;
            }
        }
        {
            typedef void (SquareScene::*_t)(SquareScene * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&SquareScene::clicked)) {
                *result = 2;
            }
        }
        {
            typedef void (SquareScene::*_t)(SquareScene * , QPoint );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&SquareScene::leftClicked)) {
                *result = 3;
            }
        }
        {
            typedef void (SquareScene::*_t)(SquareScene * , QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&SquareScene::letterkeypress)) {
                *result = 4;
            }
        }
        {
            typedef void (SquareScene::*_t)(SquareScene * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&SquareScene::delkeypress)) {
                *result = 5;
            }
        }
    }
}

const QMetaObject SquareScene::staticMetaObject = {
    { &QGraphicsScene::staticMetaObject, qt_meta_stringdata_SquareScene.data,
      qt_meta_data_SquareScene,  qt_static_metacall, 0, 0}
};


const QMetaObject *SquareScene::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *SquareScene::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_SquareScene.stringdata))
        return static_cast<void*>(const_cast< SquareScene*>(this));
    return QGraphicsScene::qt_metacast(_clname);
}

int SquareScene::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QGraphicsScene::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    }
    return _id;
}

// SIGNAL 0
void SquareScene::enter(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void SquareScene::exit(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void SquareScene::clicked(SquareScene * _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void SquareScene::leftClicked(SquareScene * _t1, QPoint _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void SquareScene::letterkeypress(SquareScene * _t1, QString _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void SquareScene::delkeypress(SquareScene * _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}
QT_END_MOC_NAMESPACE
