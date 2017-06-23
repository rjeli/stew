#include <iostream>
#include <Python.h>
#include "native/s2.h"

static PyObject *
stew_test(PyObject *self, PyObject *args)
{
  const char *s;
  if (!PyArg_ParseTuple(args, "s", &s))
    return NULL;
  std::cout << "test!: " << s << std::endl;
  Py_RETURN_NONE;
}

static PyObject *
stew_origin(PyObject *self)
{
  S2Point *p = new S2::Origin();
  return PyCapsule_New(p, "S2Point", NULL);
}

static PyMethodDef stew_methods[] = {
  {"test", stew_test, METH_VARARGS, NULL},
  {"origin", stew_origin, METH_NOARGS, NULL}
  {NULL, NULL, 0, NULL}
};

PyMODINIT_FUNC
initstew(void)
{
  printf("initializing stew\n");
  (void) Py_InitModule("stew", stew_methods);
}
