// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from yolov8_msgs:msg/DetectionSteal.idl
// generated code does not contain a copyright notice

#ifndef YOLOV8_MSGS__MSG__DETAIL__DETECTION_STEAL__STRUCT_HPP_
#define YOLOV8_MSGS__MSG__DETAIL__DETECTION_STEAL__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__yolov8_msgs__msg__DetectionSteal __attribute__((deprecated))
#else
# define DEPRECATED__yolov8_msgs__msg__DetectionSteal __declspec(deprecated)
#endif

namespace yolov8_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct DetectionSteal_
{
  using Type = DetectionSteal_<ContainerAllocator>;

  explicit DetectionSteal_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->steal = false;
    }
  }

  explicit DetectionSteal_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->steal = false;
    }
  }

  // field types and members
  using _steal_type =
    bool;
  _steal_type steal;

  // setters for named parameter idiom
  Type & set__steal(
    const bool & _arg)
  {
    this->steal = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    yolov8_msgs::msg::DetectionSteal_<ContainerAllocator> *;
  using ConstRawPtr =
    const yolov8_msgs::msg::DetectionSteal_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<yolov8_msgs::msg::DetectionSteal_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<yolov8_msgs::msg::DetectionSteal_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      yolov8_msgs::msg::DetectionSteal_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<yolov8_msgs::msg::DetectionSteal_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      yolov8_msgs::msg::DetectionSteal_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<yolov8_msgs::msg::DetectionSteal_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<yolov8_msgs::msg::DetectionSteal_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<yolov8_msgs::msg::DetectionSteal_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__yolov8_msgs__msg__DetectionSteal
    std::shared_ptr<yolov8_msgs::msg::DetectionSteal_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__yolov8_msgs__msg__DetectionSteal
    std::shared_ptr<yolov8_msgs::msg::DetectionSteal_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const DetectionSteal_ & other) const
  {
    if (this->steal != other.steal) {
      return false;
    }
    return true;
  }
  bool operator!=(const DetectionSteal_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct DetectionSteal_

// alias to use template instance with default allocator
using DetectionSteal =
  yolov8_msgs::msg::DetectionSteal_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace yolov8_msgs

#endif  // YOLOV8_MSGS__MSG__DETAIL__DETECTION_STEAL__STRUCT_HPP_
