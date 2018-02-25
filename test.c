#include <Python.h>


void getcurrent()
{
    PyRun_SimpleString("import sys");
    PyRun_SimpleString("sys.path.append('./')");
    return;
}

void test0()
{
	Py_Initialize();
	if(! Py_IsInitialized()) {

		return;
	}
	PyRun_SimpleString("print('hello world123')");
	Py_Finalize();
	return;
}

void test1()
{
    Py_Initialize();
    getcurrent();

    PyObject *pModule = PyImport_ImportModule("demo");
    PyObject *pFunc = PyObject_GetAttrString(pModule, "print_arg");
    PyObject *pArg = Py_BuildValue("(s)", "hello_python");
    PyEval_CallObject(pFunc, pArg);

    Py_Finalize();

    return;


}

void test2()
{
    Py_Initialize();
    getcurrent();

    //PyObject *pModule = NULL, *pDict = NULL, *pFunc = NULL, *pArg = NULL, *result = NULL;
    PyObject *pModule = PyImport_ImportModule("demo"); //引入模块
    PyObject *pDict = PyModule_GetDict(pModule); //获取模块字典属性 //相当于Python模块对象的__dict__ 属性，得到模块名称空间下的字典对象
    PyObject *pFunc = PyDict_GetItemString(pDict, "addition"); //从字典属性中获取函数
    PyObject *pArg = Py_BuildValue("(i, i)", 1, 2); //参数类型转换，传递两个整型参数
    PyObject *result = PyEval_CallObject(pFunc, pArg); //调用函数，并得到python类型的返回值
    int sum;
    PyArg_Parse(result, "i", &sum); //将python类型的返回值转换为c/c++类型
    printf("sum=%d\n", sum);

    Py_Finalize();
}

void test3()
{
    Py_Initialize();
    getcurrent();

    PyObject *pModule = PyImport_ImportModule("demo"); //引入模块
    PyObject *pDict = PyModule_GetDict(pModule); //获取模块字典属性 //相当于Python模块对象的__dict__ 属性，得到模块名称空间下的字典对象
    PyObject *pFunc = PyDict_GetItemString(pDict, "use_fun_in_class"); //从字典属性中获取函数

    PyObject *pClass = PyDict_GetItemString(pDict, "A");

    PyObject *temp = Py_BuildValue("(i)", 12345);

    PyObject *pAObj = PyObject_CallObject(pClass, temp);
    PyObject *fFun1 = PyObject_GetAttrString(pAObj, "foo1");
    //PyEval_CallObject(fFun1, NULL);
    //PyEval_CallObject(fFun1, Py_BuildValue("(s)", "dsf"));

    PyEval_CallObject(pFunc, Py_BuildValue("(O)", pAObj));



    //PyObject *pArgs = PyTuple_New(1);
    //PyTuple_SetItem(pArgs, 0, Py_BuildValue("i", 100));
    //PyObject *pInstance = PyInstance_New(pClass, pArgs, NULL);

    //PyObject *pInstance = PyObject_PyEval_CallMethod(pModule, pClass, Py_BuildValue("i", 5));
    //PyObject *pArg = Py_BuildValue("(i, i)", 1, 2); //参数类型转换，传递两个整型参数

    //PyEval_CallObject(pFunc, Py_BuildValue("(s)", "hefs"));



    //PyObject *result = PyObject_CallMethod(pInstance, "foo", "(s)", "1234");
    //char *st = NULL;
    //int s = 999;
    //PyArg_Parse(result, "i", &s);
    //printf("----%d\n", s);

    //PyObject_CallFunction(pFunc, "i", 123);

    //PyObject *result = PyEval_CallObject(pFunc, pArg); //调用函数，并得到python类型的返回值
    //int sum;
    //PyArg_Parse(result, "i", &sum); //将python类型的返回值转换为c/c++类型
    //printf("sum=%d\n", sum);

    Py_Finalize();



}

int main(int argc, char *argv[]) {
    //test0();
    //test1();
    test2();
    //test3();
    return 0;
} 



