// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from yolov8_msgs:msg/DetectionSteal.idl
// generated code does not contain a copyright notice

#ifndef YOLOV8_MSGS__MSG__DETAIL__DETECTION_STEAL__STRUCT_H_
#define YOLOV8_MSGS__MSG__DETAIL__DETECTION_STEAL__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in msg/DetectionSteal in the package yolov8_msgs.
typedef struct yolov8_msgs__msg__DetectionSteal
{
  bool steal;
} yolov8_msgs__msg__DetectionSteal;

// Struct for a sequence of yolov8_msgs__msg__DetectionSteal.
typedef struct yolov8_msgs__msg__DetectionSteal__Sequence
{
  yolov8_msgs__msg__DetectionSteal * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} yolov8_msgs__msg__DetectionSteal__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // YOLOV8_MSGS__MSG__DETAIL__DETECTION_STEAL__STRUCT_H_
