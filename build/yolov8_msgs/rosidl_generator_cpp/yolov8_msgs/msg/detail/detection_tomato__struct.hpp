// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from yolov8_msgs:msg/DetectionTomato.idl
// generated code does not contain a copyright notice

#ifndef YOLOV8_MSGS__MSG__DETAIL__DETECTION_TOMATO__STRUCT_HPP_
#define YOLOV8_MSGS__MSG__DETAIL__DETECTION_TOMATO__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__yolov8_msgs__msg__DetectionTomato __attribute__((deprecated))
#else
# define DEPRECATED__yolov8_msgs__msg__DetectionTomato __declspec(deprecated)
#endif

namespace yolov8_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct DetectionTomato_
{
  using Type = DetectionTomato_<ContainerAllocator>;

  explicit DetectionTomato_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->shelf = false;
      this->pay = false;
    }
  }

  explicit DetectionTomato_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->shelf = false;
      this->pay = false;
    }
  }

  // field types and members
  using _shelf_type =
    bool;
  _shelf_type shelf;
  using _pay_type =
    bool;
  _pay_type pay;

  // setters for named parameter idiom
  Type & set__shelf(
    const bool & _arg)
  {
    this->shelf = _arg;
    return *this;
  }
  Type & set__pay(
    const bool & _arg)
  {
    this->pay = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    yolov8_msgs::msg::DetectionTomato_<ContainerAllocator> *;
  using ConstRawPtr =
    const yolov8_msgs::msg::DetectionTomato_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<yolov8_msgs::msg::DetectionTomato_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<yolov8_msgs::msg::DetectionTomato_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      yolov8_msgs::msg::DetectionTomato_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<yolov8_msgs::msg::DetectionTomato_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      yolov8_msgs::msg::DetectionTomato_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<yolov8_msgs::msg::DetectionTomato_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<yolov8_msgs::msg::DetectionTomato_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<yolov8_msgs::msg::DetectionTomato_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__yolov8_msgs__msg__DetectionTomato
    std::shared_ptr<yolov8_msgs::msg::DetectionTomato_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__yolov8_msgs__msg__DetectionTomato
    std::shared_ptr<yolov8_msgs::msg::DetectionTomato_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const DetectionTomato_ & other) const
  {
    if (this->shelf != other.shelf) {
      return false;
    }
    if (this->pay != other.pay) {
      return false;
    }
    return true;
  }
  bool operator!=(const DetectionTomato_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct DetectionTomato_

// alias to use template instance with default allocator
using DetectionTomato =
  yolov8_msgs::msg::DetectionTomato_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace yolov8_msgs

#endif  // YOLOV8_MSGS__MSG__DETAIL__DETECTION_TOMATO__STRUCT_HPP_
