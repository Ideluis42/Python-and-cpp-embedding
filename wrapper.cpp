// This might not work--got to test somehow...
//https://www.swig.org/papers/PyTutorial98/PyTutorial98.pdf


#include </usr/include/python2.7/Python.h>
#include </home/newHomeDir/wrapper_testing/test.cpp>

using namespace std;
#include <vector>
// wrapper function
PyObject *wrapper(PyObject *self, PyObject *args)
{
    std::vector<double> result; // var to hold results from returns function
    //checks to make sure the python args the required type--if not return NULL
    if(!PyArg_ParseTuple(args, "[items]")) 
        return NULL;
    result = returns(); // get the list of returns
    return Py_BuildValue("[items]", result); //returns a new python object from the c func
}

// All extension modules need to register wrappers w/ Python
// methods table--basically a table of the methods used, which is one
static struct PyMethodDef methods[] = {
	{ "wrapper", wrapper, METH_VARARGS, ""},
	{ NULL, NULL, 0, NULL }
};
static struct PyModuleDef modDef = {
	PyModuleDef_HEAD_INIT, "wrapper", NULL, -1, methods, 
	NULL, NULL, NULL, NULL
};

// initialization function. Since we're in c++ the function must be given C linkage
extern "C" void init()
{
    PyObject *m;
    m = PyModule_Create(&modDef);
}
