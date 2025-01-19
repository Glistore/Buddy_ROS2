// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from yolov8_msgs:msg/DetectionSteal.idl
// generated code does not contain a copyright notice

#ifndef YOLOV8_MSGS__MSG__DETAIL__DETECTION_STEAL__BUILDER_HPP_
#define YOLOV8_MSGS__MSG__DETAIL__DETECTION_STEAL__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "yolov8_msgs/msg/detail/detection_steal__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace yolov8_msgs
{

namespace msg
{

namespace builder
{

class Init_DetectionSteal_steal
{
public:
  Init_DetectionSteal_steal()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::yolov8_msgs::msg::DetectionSteal steal(::yolov8_msgs::msg::DetectionSteal::_steal_type arg)
  {
    msg_.steal = std::move(arg);
    return std::move(msg_);
  }

private:
  ::yolov8_msgs::msg::DetectionSteal msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::yolov8_msgs::msg::DetectionSteal>()
{
  return yolov8_msgs::msg::builder::Init_DetectionSteal_steal();
}

}  // namespace yolov8_msgs

#endif  // YOLOV8_MSGS__MSG__DETAIL__DETECTION_STEAL__BUILDER_HPP_
