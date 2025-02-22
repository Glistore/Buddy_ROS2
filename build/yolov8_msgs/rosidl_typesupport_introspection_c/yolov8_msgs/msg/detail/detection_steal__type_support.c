// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from yolov8_msgs:msg/DetectionSteal.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "yolov8_msgs/msg/detail/detection_steal__rosidl_typesupport_introspection_c.h"
#include "yolov8_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "yolov8_msgs/msg/detail/detection_steal__functions.h"
#include "yolov8_msgs/msg/detail/detection_steal__struct.h"


#ifdef __cplusplus
extern "C"
{
#endif

void yolov8_msgs__msg__DetectionSteal__rosidl_typesupport_introspection_c__DetectionSteal_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  yolov8_msgs__msg__DetectionSteal__init(message_memory);
}

void yolov8_msgs__msg__DetectionSteal__rosidl_typesupport_introspection_c__DetectionSteal_fini_function(void * message_memory)
{
  yolov8_msgs__msg__DetectionSteal__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember yolov8_msgs__msg__DetectionSteal__rosidl_typesupport_introspection_c__DetectionSteal_message_member_array[1] = {
  {
    "steal",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(yolov8_msgs__msg__DetectionSteal, steal),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers yolov8_msgs__msg__DetectionSteal__rosidl_typesupport_introspection_c__DetectionSteal_message_members = {
  "yolov8_msgs__msg",  // message namespace
  "DetectionSteal",  // message name
  1,  // number of fields
  sizeof(yolov8_msgs__msg__DetectionSteal),
  yolov8_msgs__msg__DetectionSteal__rosidl_typesupport_introspection_c__DetectionSteal_message_member_array,  // message members
  yolov8_msgs__msg__DetectionSteal__rosidl_typesupport_introspection_c__DetectionSteal_init_function,  // function to initialize message memory (memory has to be allocated)
  yolov8_msgs__msg__DetectionSteal__rosidl_typesupport_introspection_c__DetectionSteal_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t yolov8_msgs__msg__DetectionSteal__rosidl_typesupport_introspection_c__DetectionSteal_message_type_support_handle = {
  0,
  &yolov8_msgs__msg__DetectionSteal__rosidl_typesupport_introspection_c__DetectionSteal_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_yolov8_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, yolov8_msgs, msg, DetectionSteal)() {
  if (!yolov8_msgs__msg__DetectionSteal__rosidl_typesupport_introspection_c__DetectionSteal_message_type_support_handle.typesupport_identifier) {
    yolov8_msgs__msg__DetectionSteal__rosidl_typesupport_introspection_c__DetectionSteal_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &yolov8_msgs__msg__DetectionSteal__rosidl_typesupport_introspection_c__DetectionSteal_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
