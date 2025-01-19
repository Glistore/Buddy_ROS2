// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from yolov8_msgs:msg/DetectionTomato.idl
// generated code does not contain a copyright notice

#ifndef YOLOV8_MSGS__MSG__DETAIL__DETECTION_TOMATO__TRAITS_HPP_
#define YOLOV8_MSGS__MSG__DETAIL__DETECTION_TOMATO__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "yolov8_msgs/msg/detail/detection_tomato__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace yolov8_msgs
{

namespace msg
{

inline void to_flow_style_yaml(
  const DetectionTomato & msg,
  std::ostream & out)
{
  out << "{";
  // member: shelf
  {
    out << "shelf: ";
    rosidl_generator_traits::value_to_yaml(msg.shelf, out);
    out << ", ";
  }

  // member: pay
  {
    out << "pay: ";
    rosidl_generator_traits::value_to_yaml(msg.pay, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const DetectionTomato & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: shelf
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "shelf: ";
    rosidl_generator_traits::value_to_yaml(msg.shelf, out);
    out << "\n";
  }

  // member: pay
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "pay: ";
    rosidl_generator_traits::value_to_yaml(msg.pay, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const DetectionTomato & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace msg

}  // namespace yolov8_msgs

namespace rosidl_generator_traits
{

[[deprecated("use yolov8_msgs::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const yolov8_msgs::msg::DetectionTomato & msg,
  std::ostream & out, size_t indentation = 0)
{
  yolov8_msgs::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use yolov8_msgs::msg::to_yaml() instead")]]
inline std::string to_yaml(const yolov8_msgs::msg::DetectionTomato & msg)
{
  return yolov8_msgs::msg::to_yaml(msg);
}

template<>
inline const char * data_type<yolov8_msgs::msg::DetectionTomato>()
{
  return "yolov8_msgs::msg::DetectionTomato";
}

template<>
inline const char * name<yolov8_msgs::msg::DetectionTomato>()
{
  return "yolov8_msgs/msg/DetectionTomato";
}

template<>
struct has_fixed_size<yolov8_msgs::msg::DetectionTomato>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<yolov8_msgs::msg::DetectionTomato>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<yolov8_msgs::msg::DetectionTomato>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // YOLOV8_MSGS__MSG__DETAIL__DETECTION_TOMATO__TRAITS_HPP_
