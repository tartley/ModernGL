#ifdef _WIN64
#ifndef MS_WIN64
#define MS_WIN64
#endif
#endif

#define GET_OBJECT_TYPENAME(var) \
((PyTypeObject *)PyObject_Type((PyObject *)var))->tp_name

#define GET_TYPE_TYPENAME(type) \
((PyTypeObject *)&type)->tp_name

#define CHECK_TYPE_ERROR(var, type) \
PyObject_TypeCheck((PyObject *)var, &type)

#define CHECK_AND_REPORT_ARG_VALUE_ERROR(condition, arg, value) \
if (condition) { \
	PyErr_Format(PyExc_TypeError, __FUNCTION__ "() argument `" arg "` = %d is invalid", value); \
	return 0; \
}

#define CHECK_AND_REPORT_ARG_TYPE_ERROR(arg, var, type) \
if (!PyObject_TypeCheck((PyObject *)var, &type)) { \
	PyErr_Format(PyExc_TypeError, __FUNCTION__ "() argument `" arg "` must be %s, not %s", GET_TYPE_TYPENAME(type), GET_OBJECT_TYPENAME(var)); \
	return 0; \
}

#define REPORT_ELEMENT_TYPE_ERROR(arg, var, type, at) \
PyErr_Format(PyExc_TypeError, __FUNCTION__ "() " arg "[%d] must be %s, not %s", at, GET_TYPE_TYPENAME(type), GET_OBJECT_TYPENAME(var)); \
return 0;


#define CHECK_AND_REPORT_ELEMENT_TYPE_ERROR(arg, var, type, at) \
if (!PyObject_TypeCheck((PyObject *)var, &type)) { \
	PyErr_Format(PyExc_TypeError, __FUNCTION__ "() " arg "[%d] must be %s, not %s", at, GET_TYPE_TYPENAME(type), GET_OBJECT_TYPENAME(var)); \
	return 0; \
}
