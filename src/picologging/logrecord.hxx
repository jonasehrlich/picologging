#include <Python.h>
#include <structmember.h>
#include <cstddef>
#include "compat.hxx"

#ifndef PICOLOGGING_LOGRECORD_H
#define PICOLOGGING_LOGRECORD_H

typedef struct {
    PyObject_HEAD
    PyObject *name;
    PyObject *msg;
    PyObject *args;
    int levelno;
    PyObject *levelname;
    PyObject *pathname;
    PyObject *filename;
    PyObject *module;
    int lineno;
    PyObject *funcName;
    double created;
    long msecs;
    PyObject *relativeCreated;
    unsigned long thread;
    PyObject *threadName;
    int process;
    PyObject *processName;
    PyObject *excInfo;
    PyObject *excText;
    PyObject *stackInfo;
    PyObject *message;
    bool hasArgs;
    PyObject *asctime;
    PyObject *dict;
} LogRecord;

int LogRecord_init(LogRecord *self, PyObject *args, PyObject *kwds);
PyObject* LogRecord_dealloc(LogRecord *self);
PyObject* LogRecord_getMessage(LogRecord *self);
PyObject* LogRecord_repr(LogRecord *self);
PyObject* LogRecord_getDict(PyObject *, void *);
_PyTime_t current_time();

extern "C" {
PyAPI_DATA(PyTypeObject) LogRecordType;
#define LogRecord_CheckExact(op) Py_IS_TYPE(op, &LogRecordType)
}

#endif // PICOLOGGING_LOGRECORD_H