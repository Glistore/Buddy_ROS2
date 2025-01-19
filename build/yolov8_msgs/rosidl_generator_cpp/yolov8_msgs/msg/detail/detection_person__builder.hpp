// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from yolov8_msgs:msg/DetectionPerson.idl
// generated code does not contain a copyright notice

#ifndef YOLOV8_MSGS__MSG__DETAIL__DETECTION_PERSON__BUILDER_HPP_
#define YOLOV8_MSGS__MSG__DETAIL__DETECTION_PERSON__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "yolov8_msgs/msg/detail/detection_person__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace yolov8_msgs
{

namespace msg
{

namespace builder
{

class Init_DetectionPerson_count_people
{
public:
  explicit Init_DetectionPerson_count_people(::yolov8_msgs::msg::DetectionPerson & msg)
  : msg_(msg)
  {}
  ::yolov8_msgs::msg::DetectionPerson count_people(::yolov8_msgs::msg::DetectionPerson::_count_people_type arg)
  {
    msg_.count_people = std::move(arg);
    return std::move(msg_);
  }

private:
  ::yolov8_msgs::msg::DetectionPerson msg_;
};

class Init_DetectionPerson_steal
{
public:
  explicit Init_DetectionPerson_steal(::yolov8_msgs::msg::DetectionPerson & msg)
  : msg_(msg)
  {}
  Init_DetectionPerson_count_people steal(::yolov8_msgs::msg::DetectionPerson::_steal_type arg)
  {
    msg_.steal = std::move(arg);
    return Init_DetectionPerson_count_people(msg_);
  }

private:
  ::yolov8_msgs::msg::DetectionPerson msg_;
};

class Init_DetectionPerson_inside
{
public:
  Init_DetectionPerson_inside()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_DetectionPerson_steal inside(::yolov8_msgs::msg::DetectionPerson::_inside_type arg)
  {
    msg_.inside = std::move(arg);
    return Init_DetectionPerson_steal(msg_);
  }

private:
  ::yolov8_msgs::msg::DetectionPerson msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::yolov8_msgs::msg::DetectionPerson>()
{
  return yolov8_msgs::msg::builder::Init_DetectionPerson_inside();
}

}  // namespace yolov8_msgs

#endif  // YOLOV8_MSGS__MSG__DETAIL__DETECTION_PERSON__BUILDER_HPP_
