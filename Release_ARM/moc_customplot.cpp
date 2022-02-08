/****************************************************************************
** Meta object code from reading C++ file 'customplot.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.11.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../Regis2020_Linux_v3.0/customplot.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'customplot.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.11.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_customplot_t {
    QByteArrayData data[10];
    char stringdata0[104];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_customplot_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_customplot_t qt_meta_stringdata_customplot = {
    {
QT_MOC_LITERAL(0, 0, 10), // "customplot"
QT_MOC_LITERAL(1, 11, 16), // "slotRangeChanged"
QT_MOC_LITERAL(2, 28, 0), // ""
QT_MOC_LITERAL(3, 29, 8), // "QCPRange"
QT_MOC_LITERAL(4, 38, 8), // "newRange"
QT_MOC_LITERAL(5, 47, 12), // "slotButClick"
QT_MOC_LITERAL(6, 60, 11), // "saveGraphic"
QT_MOC_LITERAL(7, 72, 12), // "QCustomPlot*"
QT_MOC_LITERAL(8, 85, 7), // "graphic"
QT_MOC_LITERAL(9, 93, 10) // "saveToFile"

    },
    "customplot\0slotRangeChanged\0\0QCPRange\0"
    "newRange\0slotButClick\0saveGraphic\0"
    "QCustomPlot*\0graphic\0saveToFile"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_customplot[] = {

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
       1,    1,   34,    2, 0x08 /* Private */,
       5,    0,   37,    2, 0x08 /* Private */,
       6,    1,   38,    2, 0x08 /* Private */,
       9,    0,   41,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 7,    8,
    QMetaType::Void,

       0        // eod
};

void customplot::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        customplot *_t = static_cast<customplot *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->slotRangeChanged((*reinterpret_cast< const QCPRange(*)>(_a[1]))); break;
        case 1: _t->slotButClick(); break;
        case 2: _t->saveGraphic((*reinterpret_cast< QCustomPlot*(*)>(_a[1]))); break;
        case 3: _t->saveToFile(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 2:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QCustomPlot* >(); break;
            }
            break;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject customplot::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_customplot.data,
      qt_meta_data_customplot,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *customplot::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *customplot::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_customplot.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int customplot::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
