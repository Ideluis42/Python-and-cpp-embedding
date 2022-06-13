#define PY_SSIZE_T_CLEAN
#include <stdio.h>
#include </usr/include/python3.8/Python.h>
#include <curses.h>

using namespace std;
#include <vector>
#include </home/newHomeDir/Python-and-cpp-embedding/pyhelper.hpp>


// gotten from: https://gist.github.com/rjzak/5681680
std::vector<double> listTupleToVector_Double(PyObject* incoming) {
	vector<double> data;
	if (PyTuple_Check(incoming)) {
		for(Py_ssize_t i = 0; i < PyTuple_Size(incoming); i++) {
			PyObject *value = PyTuple_GetItem(incoming, i);
			data.push_back( PyFloat_AsDouble(value) );
		}
	} else {
		if (PyList_Check(incoming)) {
			for(Py_ssize_t i = 0; i < PyList_Size(incoming); i++) {
				PyObject *value = PyList_GetItem(incoming, i);
				data.push_back( PyFloat_AsDouble(value) );
			}
		}
	}
	return data;
}

std::vector<double> get_python()
{	
	
	//printf("initializing python interpreter \n");
	Py_Initialize();

	//printf("adding module paths \n");
	PyRun_SimpleString("import sys");
	PyRun_SimpleString("sys.path.append(\"/home/newHomeDir/Python-and-cpp-embedding\")");

	//printf("importing module \n");
	CPyObject pModule = PyImport_ImportModule("py_sender");

	//printf("getting function name \n");
	CPyObject pFunc = PyObject_GetAttrString(pModule, (char*)"roll_pitch_yaw");
	//printf("calling function \n");
	CPyObject pValue = PyObject_CallObject(pFunc, NULL);

	//printf("storing results \n");
	std::vector<double> results = listTupleToVector_Double(pValue);
		
	//printf("returning results \n");
	return results;

}