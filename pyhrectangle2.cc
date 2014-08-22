// Autogenerated file for halcon type HRectangle2

#include "pyhirsch.h"

static void
PyHirschRectangle2_dealloc(PyHirschRectangle2* self)
{
    PyObject_Del(self);
}

static int
PyHirschRectangle2_init(PyHirschRectangle2 *self, PyObject *args, PyObject */*kwds*/)
{
    double centerX,centerY,ra,rb,phi=0;
    PyHirschRectangle2 *rect;

    if (PyArg_ParseTuple(args,"(dd)dd|d",&centerX,&centerY,&ra,&rb,&phi)) 
        self->Rectangle2 = Halcon::HRectangle2(Halcon::HPoint2D(centerX,centerY),
                                               ra,rb,phi);
                                               
    else if (PyArg_ParseTuple(args,"O",&rect)
             && PyHirschRectangle2_Check(rect)
             ) {
        self->Rectangle2 = Halcon::HRectangle2(rect->Rectangle2);
    }
    else
        // Empty rectangle
        self->Rectangle2 = Halcon::HRectangle2();

    PyErr_Clear();

    return 0;
}

#include "hrectangle2_autogen_methods_declarations.i"

static PyMethodDef PyHirschRectangle2_methods[] = {
#include "hrectangle2_autogen_methods_list.i"
    {NULL}  /* Sentinel */
};

PyObject *PyHirschRectangle2_FromHRectangle2(Halcon::HRectangle2 Rectangle2)
{
    PyHirschRectangle2 *v = (PyHirschRectangle2*)PyObject_New(PyHirschRectangle2, &PyHirschRectangle2Type);
    v->Rectangle2 = Halcon::HRectangle2(Rectangle2);
    return (PyObject*)v;
}

static PyObject *
PyHirschRectangle2_str(PyObject *ob)
{
    PyHirschRectangle2 *self = (PyHirschRectangle2 *)ob;
    Halcon::HPoint2D Center = self->Rectangle2.Center();
    double ra = self->Rectangle2.Ra();
    double rb = self->Rectangle2.Rb();
    double phi = self->Rectangle2.Phi();
    PyObject *Tuple = Py_BuildValue("Oddd",
                                    PyHirschPoint2D_FromHPoint2D(Center),
                                    ra,rb,phi);
    PyObject *Ret = PyObject_Str(Tuple);
    Py_DECREF(Tuple);

    return Ret;
}


PyTypeObject PyHirschRectangle2Type = {
    PyObject_HEAD_INIT(NULL)
    0,                         /*ob_size*/
    "Hirsch.Rectangle2",      /*tp_name*/
    sizeof(PyHirschRectangle2), /*tp_basicsize*/
    0,                         /*tp_itemsize*/
    (destructor)PyHirschRectangle2_dealloc,       /*tp_dealloc*/
    0,                         /*tp_print*/
    0,                         /*tp_getattr*/
    0,                         /*tp_setattr*/
    0,                         /*tp_compare*/
    PyHirschRectangle2_str,                         /*tp_str*/
    0,                         /*tp_as_number*/
    0,        /*tp_as_sequence*/
    0,                         /*tp_as_mapping*/
    0,                         /*tp_hash */
    0,                         /*tp_call*/
    PyHirschRectangle2_str,                         /*tp_str*/
    0,                         /*tp_getattro*/
    0,                         /*tp_setattro*/
    0,                         /*tp_as_buffer*/
    Py_TPFLAGS_DEFAULT,        /*tp_flags*/
    "PyHirschRectangle2",        /* tp_doc */
    0,		               /* tp_traverse */
    0,		               /* tp_clear */
    0,		               /* tp_richcompare */
    0,		               /* tp_weaklistoffset */
    0,		 /* tp_iter */
    0,         /* tp_iternext */
    PyHirschRectangle2_methods,  /* tp_methods */
    0,                         /* tp_members */
    0,                         /* tp_getset */
    0,                         /* tp_base */
    0,                         /* tp_dict */
    0,                         /* tp_descr_get */
    0,                         /* tp_descr_set */
    0,                         /* tp_dictoffset */
    (initproc)PyHirschRectangle2_init,          /* tp_init */
    0,                         /* tp_alloc */
    PyType_GenericNew,         /* tp_new */
};


void PyHirschRectangle2AddToModule(PyObject *m)
{
    Py_INCREF(&PyHirschRectangle2Type);
    if (PyType_Ready(&PyHirschRectangle2Type) < 0)
        return;
    PyModule_AddObject(m, "HRectangle2", (PyObject *)&PyHirschRectangle2Type);
}

