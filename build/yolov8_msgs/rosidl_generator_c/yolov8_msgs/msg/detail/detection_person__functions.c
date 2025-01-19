// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from yolov8_msgs:msg/DetectionPerson.idl
// generated code does not contain a copyright notice
#include "yolov8_msgs/msg/detail/detection_person__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `count_people`
#include "std_msgs/msg/detail/string__functions.h"

bool
yolov8_msgs__msg__DetectionPerson__init(yolov8_msgs__msg__DetectionPerson * msg)
{
  if (!msg) {
    return false;
  }
  // inside
  // steal
  // count_people
  if (!std_msgs__msg__String__init(&msg->count_people)) {
    yolov8_msgs__msg__DetectionPerson__fini(msg);
    return false;
  }
  return true;
}

void
yolov8_msgs__msg__DetectionPerson__fini(yolov8_msgs__msg__DetectionPerson * msg)
{
  if (!msg) {
    return;
  }
  // inside
  // steal
  // count_people
  std_msgs__msg__String__fini(&msg->count_people);
}

bool
yolov8_msgs__msg__DetectionPerson__are_equal(const yolov8_msgs__msg__DetectionPerson * lhs, const yolov8_msgs__msg__DetectionPerson * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // inside
  if (lhs->inside != rhs->inside) {
    return false;
  }
  // steal
  if (lhs->steal != rhs->steal) {
    return false;
  }
  // count_people
  if (!std_msgs__msg__String__are_equal(
      &(lhs->count_people), &(rhs->count_people)))
  {
    return false;
  }
  return true;
}

bool
yolov8_msgs__msg__DetectionPerson__copy(
  const yolov8_msgs__msg__DetectionPerson * input,
  yolov8_msgs__msg__DetectionPerson * output)
{
  if (!input || !output) {
    return false;
  }
  // inside
  output->inside = input->inside;
  // steal
  output->steal = input->steal;
  // count_people
  if (!std_msgs__msg__String__copy(
      &(input->count_people), &(output->count_people)))
  {
    return false;
  }
  return true;
}

yolov8_msgs__msg__DetectionPerson *
yolov8_msgs__msg__DetectionPerson__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  yolov8_msgs__msg__DetectionPerson * msg = (yolov8_msgs__msg__DetectionPerson *)allocator.allocate(sizeof(yolov8_msgs__msg__DetectionPerson), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(yolov8_msgs__msg__DetectionPerson));
  bool success = yolov8_msgs__msg__DetectionPerson__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
yolov8_msgs__msg__DetectionPerson__destroy(yolov8_msgs__msg__DetectionPerson * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    yolov8_msgs__msg__DetectionPerson__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
yolov8_msgs__msg__DetectionPerson__Sequence__init(yolov8_msgs__msg__DetectionPerson__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  yolov8_msgs__msg__DetectionPerson * data = NULL;

  if (size) {
    data = (yolov8_msgs__msg__DetectionPerson *)allocator.zero_allocate(size, sizeof(yolov8_msgs__msg__DetectionPerson), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = yolov8_msgs__msg__DetectionPerson__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        yolov8_msgs__msg__DetectionPerson__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
yolov8_msgs__msg__DetectionPerson__Sequence__fini(yolov8_msgs__msg__DetectionPerson__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      yolov8_msgs__msg__DetectionPerson__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

yolov8_msgs__msg__DetectionPerson__Sequence *
yolov8_msgs__msg__DetectionPerson__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  yolov8_msgs__msg__DetectionPerson__Sequence * array = (yolov8_msgs__msg__DetectionPerson__Sequence *)allocator.allocate(sizeof(yolov8_msgs__msg__DetectionPerson__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = yolov8_msgs__msg__DetectionPerson__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
yolov8_msgs__msg__DetectionPerson__Sequence__destroy(yolov8_msgs__msg__DetectionPerson__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    yolov8_msgs__msg__DetectionPerson__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
yolov8_msgs__msg__DetectionPerson__Sequence__are_equal(const yolov8_msgs__msg__DetectionPerson__Sequence * lhs, const yolov8_msgs__msg__DetectionPerson__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!yolov8_msgs__msg__DetectionPerson__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
yolov8_msgs__msg__DetectionPerson__Sequence__copy(
  const yolov8_msgs__msg__DetectionPerson__Sequence * input,
  yolov8_msgs__msg__DetectionPerson__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(yolov8_msgs__msg__DetectionPerson);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    yolov8_msgs__msg__DetectionPerson * data =
      (yolov8_msgs__msg__DetectionPerson *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!yolov8_msgs__msg__DetectionPerson__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          yolov8_msgs__msg__DetectionPerson__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!yolov8_msgs__msg__DetectionPerson__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
