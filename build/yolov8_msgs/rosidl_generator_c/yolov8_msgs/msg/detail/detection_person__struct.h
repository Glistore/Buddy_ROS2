// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from yolov8_msgs:msg/DetectionPerson.idl
// generated code does not contain a copyright notice

#ifndef YOLOV8_MSGS__MSG__DETAIL__DETECTION_PERSON__STRUCT_H_
#define YOLOV8_MSGS__MSG__DETAIL__DETECTION_PERSON__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'count_people'
#include "std_msgs/msg/detail/string__struct.h"

/// Struct defined in msg/DetectionPerson in the package yolov8_msgs.
typedef struct yolov8_msgs__msg__DetectionPerson
{
  bool inside;
  bool steal;
  std_msgs__msg__String count_people;
} yolov8_msgs__msg__DetectionPerson;

// Struct for a sequence of yolov8_msgs__msg__DetectionPerson.
typedef struct yolov8_msgs__msg__DetectionPerson__Sequence
{
  yolov8_msgs__msg__DetectionPerson * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} yolov8_msgs__msg__DetectionPerson__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // YOLOV8_MSGS__MSG__DETAIL__DETECTION_PERSON__STRUCT_H_
