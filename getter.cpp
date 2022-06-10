#define PY_SSIZE_T_CLEAN
#include </usr/include/python3.8/Python.h>

using namespace std;
#include <vector>
#include <stdexcept>
#include <stdio.h>
#include <curses.h>

#include </home/newHomeDir/wrapper_testing/pyhelper.hpp>


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
		} //else {
			//throw logic_error("Passed PyObject pointer was not a list or tuple!");
		//}
	}
	return data;
}



std::vector<double> test()
{	

	Py_Initialize();
	PyRun_SimpleString("import sys");
	PyRun_SimpleString("sys.path.append(\"/home/newHomeDir/wrapper_testing\")");

	CPyObject pModule = PyImport_ImportModule("test_python");


	CPyObject pFunc = PyObject_GetAttrString(pModule, (char*)"roll_pitch_yaw");
	CPyObject pValue = PyObject_CallObject(pFunc, NULL);

	std::vector<double> results = listTupleToVector_Double(pValue);
		

	return results;

}

std::vector<double> returns()
{
    std::vector<double> test = {0.1, 1.4, 5.6};
    return test;
}