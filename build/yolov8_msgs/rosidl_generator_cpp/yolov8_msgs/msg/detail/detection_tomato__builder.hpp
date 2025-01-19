// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from yolov8_msgs:msg/DetectionTomato.idl
// generated code does not contain a copyright notice

#ifndef YOLOV8_MSGS__MSG__DETAIL__DETECTION_TOMATO__BUILDER_HPP_
#define YOLOV8_MSGS__MSG__DETAIL__DETECTION_TOMATO__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "yolov8_msgs/msg/detail/detection_tomato__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace yolov8_msgs
{

namespace msg
{

namespace builder
{

class Init_DetectionTomato_pay
{
public:
  explicit Init_DetectionTomato_pay(::yolov8_msgs::msg::DetectionTomato & msg)
  : msg_(msg)
  {}
  ::yolov8_msgs::msg::DetectionTomato pay(::yolov8_msgs::msg::DetectionTomato::_pay_type arg)
  {
    msg_.pay = std::move(arg);
    return std::move(msg_);
  }

private:
  ::yolov8_msgs::msg::DetectionTomato msg_;
};

class Init_DetectionTomato_shelf
{
public:
  Init_DetectionTomato_shelf()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_DetectionTomato_pay shelf(::yolov8_msgs::msg::DetectionTomato::_shelf_type arg)
  {
    msg_.shelf = std::move(arg);
    return Init_DetectionTomato_pay(msg_);
  }

private:
  ::yolov8_msgs::msg::DetectionTomato msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::yolov8_msgs::msg::DetectionTomato>()
{
  return yolov8_msgs::msg::builder::Init_DetectionTomato_shelf();
}

}  // namespace yolov8_msgs

#endif  // YOLOV8_MSGS__MSG__DETAIL__DETECTION_TOMATO__BUILDER_HPP_
