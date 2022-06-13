#include </home/newHomeDir/Python-and-cpp-embedding/getter.cpp>
#include </home/newHomeDir/Python-and-cpp-embedding/main.h>

std::vector<double> stuff_to_return = {0.0, 0.0, 0.0};

// Converting from a vector to a tuple
// Method gotten from: https://gist.github.com/rjzak/5681680
// edited to be a double instead of a float
PyObject* vectorToTuple_Double(const vector<double> &data) {
	PyObject* tuple = PyTuple_New( data.size() );
	for (unsigned int i = 0; i < data.size(); i++) {
		PyObject *num = PyFloat_FromDouble( (double) data[i]);
		PyTuple_SET_ITEM(tuple, i, num);
	}

	return tuple;
}


// imports your python module--can be named whatever as long as it follows the format
// moduleName_methodName
// so in this case the module is called py and the method is called mod
// Will return whatever is needed to use in the python program--for now just returning an tuple
static PyObject* py_mod(PyObject* self, PyObject* args)
{
    return vectorToTuple_Double(stuff_to_return);
}

// next we declare a method table of methods used/imported
// follows the format: 
// {name of the method that the python code will use to call our native code, 
// C++ function pointer, METH_VARARGS which basically means the function can take arguments,
// a help string--describes what the function does}
static struct PyMethodDef methods[] = {
	{ "mod", py_mod, METH_VARARGS, "Returns an tuple"},
	{ NULL, NULL, 0, NULL }
};

// define the module
// follows the format:
// {PyModuleDef_HEAD_INIT, module name to be used in python code, NULL, -1, 
// whatever we defined our method table to be, NULL for the rest}
static struct PyModuleDef modDef = {
	PyModuleDef_HEAD_INIT, "py", NULL, -1, methods, 
	NULL, NULL, NULL, NULL
};

// create the module
static PyObject* PyInit_py(void)
{
	return PyModule_Create(&modDef);
}

void wrapper()
{
    // get the module
	PyImport_AppendInittab("py", &PyInit_py);

	Py_Initialize(); // initialize the python interpreter

	// read the file you're going to be sending the c++ values to
	const char pFile[] = "py_receiver.py";
	FILE* fp = _Py_fopen(pFile, "r");

	// run that file
	PyRun_AnyFile(fp, pFile);

	Py_Finalize();
}

int main()
{

    for(int i = 0; i <= 2; i++)
    {
        //printf("wrapping \n");
        //wrapping 
        wrapper();

        //printf("getting \n");
        // getting
        stuff_to_return = get_python();
    }

}