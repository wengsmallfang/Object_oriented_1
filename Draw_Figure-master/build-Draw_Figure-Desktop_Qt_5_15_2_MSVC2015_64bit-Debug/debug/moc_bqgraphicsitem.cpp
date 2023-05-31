/****************************************************************************
** Meta object code from reading C++ file 'bqgraphicsitem.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../Draw_Figure-master/bqgraphicsitem.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QList>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'bqgraphicsitem.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_BGraphicsItem_t {
    QByteArrayData data[1];
    char stringdata0[14];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_BGraphicsItem_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_BGraphicsItem_t qt_meta_stringdata_BGraphicsItem = {
    {
QT_MOC_LITERAL(0, 0, 13) // "BGraphicsItem"

    },
    "BGraphicsItem"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_BGraphicsItem[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

       0        // eod
};

void BGraphicsItem::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject BGraphicsItem::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_BGraphicsItem.data,
    qt_meta_data_BGraphicsItem,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *BGraphicsItem::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *BGraphicsItem::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_BGraphicsItem.stringdata0))
        return static_cast<void*>(this);
    if (!strcmp(_clname, "QAbstractGraphicsShapeItem"))
        return static_cast< QAbstractGraphicsShapeItem*>(this);
    return QObject::qt_metacast(_clname);
}

int BGraphicsItem::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    return _id;
}
struct qt_meta_stringdata_BEllipse_t {
    QByteArrayData data[1];
    char stringdata0[9];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_BEllipse_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_BEllipse_t qt_meta_stringdata_BEllipse = {
    {
QT_MOC_LITERAL(0, 0, 8) // "BEllipse"

    },
    "BEllipse"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_BEllipse[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

       0        // eod
};

void BEllipse::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject BEllipse::staticMetaObject = { {
    QMetaObject::SuperData::link<BGraphicsItem::staticMetaObject>(),
    qt_meta_stringdata_BEllipse.data,
    qt_meta_data_BEllipse,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *BEllipse::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *BEllipse::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_BEllipse.stringdata0))
        return static_cast<void*>(this);
    return BGraphicsItem::qt_metacast(_clname);
}

int BEllipse::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = BGraphicsItem::qt_metacall(_c, _id, _a);
    return _id;
}
struct qt_meta_stringdata_BPolygon_t {
    QByteArrayData data[7];
    char stringdata0[51];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_BPolygon_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_BPolygon_t qt_meta_stringdata_BPolygon = {
    {
QT_MOC_LITERAL(0, 0, 8), // "BPolygon"
QT_MOC_LITERAL(1, 9, 9), // "pushPoint"
QT_MOC_LITERAL(2, 19, 0), // ""
QT_MOC_LITERAL(3, 20, 1), // "p"
QT_MOC_LITERAL(4, 22, 14), // "QList<QPointF>"
QT_MOC_LITERAL(5, 37, 4), // "list"
QT_MOC_LITERAL(6, 42, 8) // "isCenter"

    },
    "BPolygon\0pushPoint\0\0p\0QList<QPointF>\0"
    "list\0isCenter"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_BPolygon[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    3,   19,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void, QMetaType::QPointF, 0x80000000 | 4, QMetaType::Bool,    3,    5,    6,

       0        // eod
};

void BPolygon::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<BPolygon *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->pushPoint((*reinterpret_cast< QPointF(*)>(_a[1])),(*reinterpret_cast< QList<QPointF>(*)>(_a[2])),(*reinterpret_cast< bool(*)>(_a[3]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 0:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 1:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QList<QPointF> >(); break;
            }
            break;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject BPolygon::staticMetaObject = { {
    QMetaObject::SuperData::link<BGraphicsItem::staticMetaObject>(),
    qt_meta_stringdata_BPolygon.data,
    qt_meta_data_BPolygon,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *BPolygon::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *BPolygon::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_BPolygon.stringdata0))
        return static_cast<void*>(this);
    return BGraphicsItem::qt_metacast(_clname);
}

int BPolygon::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = BGraphicsItem::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
