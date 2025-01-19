// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from yolov8_msgs:msg/DetectionPerson.idl
// generated code does not contain a copyright notice

#ifndef YOLOV8_MSGS__MSG__DETAIL__DETECTION_PERSON__STRUCT_HPP_
#define YOLOV8_MSGS__MSG__DETAIL__DETECTION_PERSON__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


// Include directives for member types
// Member 'count_people'
#include "std_msgs/msg/detail/string__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__yolov8_msgs__msg__DetectionPerson __attribute__((deprecated))
#else
# define DEPRECATED__yolov8_msgs__msg__DetectionPerson __declspec(deprecated)
#endif

namespace yolov8_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct DetectionPerson_
{
  using Type = DetectionPerson_<ContainerAllocator>;

  explicit DetectionPerson_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : count_people(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->inside = false;
      this->steal = false;
    }
  }

  explicit DetectionPerson_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : count_people(_alloc, _init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->inside = false;
      this->steal = false;
    }
  }

  // field types and members
  using _inside_type =
    bool;
  _inside_type inside;
  using _steal_type =
    bool;
  _steal_type steal;
  using _count_people_type =
    std_msgs::msg::String_<ContainerAllocator>;
  _count_people_type count_people;

  // setters for named parameter idiom
  Type & set__inside(
    const bool & _arg)
  {
    this->inside = _arg;
    return *this;
  }
  Type & set__steal(
    const bool & _arg)
  {
    this->steal = _arg;
    return *this;
  }
  Type & set__count_people(
    const std_msgs::msg::String_<ContainerAllocator> & _arg)
  {
    this->count_people = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    yolov8_msgs::msg::DetectionPerson_<ContainerAllocator> *;
  using ConstRawPtr =
    const yolov8_msgs::msg::DetectionPerson_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<yolov8_msgs::msg::DetectionPerson_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<yolov8_msgs::msg::DetectionPerson_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      yolov8_msgs::msg::DetectionPerson_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<yolov8_msgs::msg::DetectionPerson_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      yolov8_msgs::msg::DetectionPerson_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<yolov8_msgs::msg::DetectionPerson_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<yolov8_msgs::msg::DetectionPerson_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<yolov8_msgs::msg::DetectionPerson_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__yolov8_msgs__msg__DetectionPerson
    std::shared_ptr<yolov8_msgs::msg::DetectionPerson_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__yolov8_msgs__msg__DetectionPerson
    std::shared_ptr<yolov8_msgs::msg::DetectionPerson_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const DetectionPerson_ & other) const
  {
    if (this->inside != other.inside) {
      return false;
    }
    if (this->steal != other.steal) {
      return false;
    }
    if (this->count_people != other.count_people) {
      return false;
    }
    return true;
  }
  bool operator!=(const DetectionPerson_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct DetectionPerson_

// alias to use template instance with default allocator
using DetectionPerson =
  yolov8_msgs::msg::DetectionPerson_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace yolov8_msgs

#endif  // YOLOV8_MSGS__MSG__DETAIL__DETECTION_PERSON__STRUCT_HPP_
