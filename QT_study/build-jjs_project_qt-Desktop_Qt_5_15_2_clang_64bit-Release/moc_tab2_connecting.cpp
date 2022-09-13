/****************************************************************************
** Meta object code from reading C++ file 'tab2_connecting.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../QT_SRC/jjs_project_qt/tab2_connecting.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'tab2_connecting.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_tab2_connecting_t {
    QByteArrayData data[12];
    char stringdata0[135];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_tab2_connecting_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_tab2_connecting_t qt_meta_stringdata_tab2_connecting = {
    {
QT_MOC_LITERAL(0, 0, 15), // "tab2_connecting"
QT_MOC_LITERAL(1, 16, 11), // "sendRespone"
QT_MOC_LITERAL(2, 28, 0), // ""
QT_MOC_LITERAL(3, 29, 10), // "sigsend_IP"
QT_MOC_LITERAL(4, 40, 19), // "slotConnectToServer"
QT_MOC_LITERAL(5, 60, 13), // "connectToHost"
QT_MOC_LITERAL(6, 74, 4), // "host"
QT_MOC_LITERAL(7, 79, 4), // "port"
QT_MOC_LITERAL(8, 84, 12), // "disconToHost"
QT_MOC_LITERAL(9, 97, 14), // "send_test_Data"
QT_MOC_LITERAL(10, 112, 9), // "send_Data"
QT_MOC_LITERAL(11, 122, 12) // "recvice_Data"

    },
    "tab2_connecting\0sendRespone\0\0sigsend_IP\0"
    "slotConnectToServer\0connectToHost\0"
    "host\0port\0disconToHost\0send_test_Data\0"
    "send_Data\0recvice_Data"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_tab2_connecting[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   54,    2, 0x06 /* Public */,
       3,    1,   57,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    0,   60,    2, 0x08 /* Private */,
       5,    2,   61,    2, 0x08 /* Private */,
       8,    0,   66,    2, 0x08 /* Private */,
       9,    0,   67,    2, 0x08 /* Private */,
      10,    1,   68,    2, 0x08 /* Private */,
      11,    1,   71,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QString,    2,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Bool, QMetaType::QString, QMetaType::QString,    6,    7,
    QMetaType::Void,
    QMetaType::Bool,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QString,    2,

       0        // eod
};

void tab2_connecting::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<tab2_connecting *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sendRespone((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->sigsend_IP((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->slotConnectToServer(); break;
        case 3: { bool _r = _t->connectToHost((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 4: _t->disconToHost(); break;
        case 5: { bool _r = _t->send_test_Data();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 6: _t->send_Data((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 7: _t->recvice_Data((*reinterpret_cast< QString(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (tab2_connecting::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&tab2_connecting::sendRespone)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (tab2_connecting::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&tab2_connecting::sigsend_IP)) {
                *result = 1;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject tab2_connecting::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_tab2_connecting.data,
    qt_meta_data_tab2_connecting,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *tab2_connecting::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *tab2_connecting::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_tab2_connecting.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int tab2_connecting::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 8;
    }
    return _id;
}

// SIGNAL 0
void tab2_connecting::sendRespone(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void tab2_connecting::sigsend_IP(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
