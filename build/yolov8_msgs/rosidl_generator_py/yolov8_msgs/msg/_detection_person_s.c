// generated from rosidl_generator_py/resource/_idl_support.c.em
// with input from yolov8_msgs:msg/DetectionPerson.idl
// generated code does not contain a copyright notice
#define NPY_NO_DEPRECATED_API NPY_1_7_API_VERSION
#include <Python.h>
#include <stdbool.h>
#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-function"
#endif
#include "numpy/ndarrayobject.h"
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif
#include "rosidl_runtime_c/visibility_control.h"
#include "yolov8_msgs/msg/detail/detection_person__struct.h"
#include "yolov8_msgs/msg/detail/detection_person__functions.h"

ROSIDL_GENERATOR_C_IMPORT
bool std_msgs__msg__string__convert_from_py(PyObject * _pymsg, void * _ros_message);
ROSIDL_GENERATOR_C_IMPORT
PyObject * std_msgs__msg__string__convert_to_py(void * raw_ros_message);

ROSIDL_GENERATOR_C_EXPORT
bool yolov8_msgs__msg__detection_person__convert_from_py(PyObject * _pymsg, void * _ros_message)
{
  // check that the passed message is of the expected Python class
  {
    char full_classname_dest[50];
    {
      char * class_name = NULL;
      char * module_name = NULL;
      {
        PyObject * class_attr = PyObject_GetAttrString(_pymsg, "__class__");
        if (class_attr) {
          PyObject * name_attr = PyObject_GetAttrString(class_attr, "__name__");
          if (name_attr) {
            class_name = (char *)PyUnicode_1BYTE_DATA(name_attr);
            Py_DECREF(name_attr);
          }
          PyObject * module_attr = PyObject_GetAttrString(class_attr, "__module__");
          if (module_attr) {
            module_name = (char *)PyUnicode_1BYTE_DATA(module_attr);
            Py_DECREF(module_attr);
          }
          Py_DECREF(class_attr);
        }
      }
      if (!class_name || !module_name) {
        return false;
      }
      snprintf(full_classname_dest, sizeof(full_classname_dest), "%s.%s", module_name, class_name);
    }
    assert(strncmp("yolov8_msgs.msg._detection_person.DetectionPerson", full_classname_dest, 49) == 0);
  }
  yolov8_msgs__msg__DetectionPerson * ros_message = _ros_message;
  {  // inside
    PyObject * field = PyObject_GetAttrString(_pymsg, "inside");
    if (!field) {
      return false;
    }
    assert(PyBool_Check(field));
    ros_message->inside = (Py_True == field);
    Py_DECREF(field);
  }
  {  // steal
    PyObject * field = PyObject_GetAttrString(_pymsg, "steal");
    if (!field) {
      return false;
    }
    assert(PyBool_Check(field));
    ros_message->steal = (Py_True == field);
    Py_DECREF(field);
  }
  {  // count_people
    PyObject * field = PyObject_GetAttrString(_pymsg, "count_people");
    if (!field) {
      return false;
    }
    if (!std_msgs__msg__string__convert_from_py(field, &ros_message->count_people)) {
      Py_DECREF(field);
      return false;
    }
    Py_DECREF(field);
  }

  return true;
}

ROSIDL_GENERATOR_C_EXPORT
PyObject * yolov8_msgs__msg__detection_person__convert_to_py(void * raw_ros_message)
{
  /* NOTE(esteve): Call constructor of DetectionPerson */
  PyObject * _pymessage = NULL;
  {
    PyObject * pymessage_module = PyImport_ImportModule("yolov8_msgs.msg._detection_person");
    assert(pymessage_module);
    PyObject * pymessage_class = PyObject_GetAttrString(pymessage_module, "DetectionPerson");
    assert(pymessage_class);
    Py_DECREF(pymessage_module);
    _pymessage = PyObject_CallObject(pymessage_class, NULL);
    Py_DECREF(pymessage_class);
    if (!_pymessage) {
      return NULL;
    }
  }
  yolov8_msgs__msg__DetectionPerson * ros_message = (yolov8_msgs__msg__DetectionPerson *)raw_ros_message;
  {  // inside
    PyObject * field = NULL;
    field = PyBool_FromLong(ros_message->inside ? 1 : 0);
    {
      int rc = PyObject_SetAttrString(_pymessage, "inside", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // steal
    PyObject * field = NULL;
    field = PyBool_FromLong(ros_message->steal ? 1 : 0);
    {
      int rc = PyObject_SetAttrString(_pymessage, "steal", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // count_people
    PyObject * field = NULL;
    field = std_msgs__msg__string__convert_to_py(&ros_message->count_people);
    if (!field) {
      return NULL;
    }
    {
      int rc = PyObject_SetAttrString(_pymessage, "count_people", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }

  // ownership of _pymessage is transferred to the caller
  return _pymessage;
}
