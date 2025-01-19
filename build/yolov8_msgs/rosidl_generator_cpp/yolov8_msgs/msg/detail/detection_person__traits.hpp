// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from yolov8_msgs:msg/DetectionPerson.idl
// generated code does not contain a copyright notice

#ifndef YOLOV8_MSGS__MSG__DETAIL__DETECTION_PERSON__TRAITS_HPP_
#define YOLOV8_MSGS__MSG__DETAIL__DETECTION_PERSON__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "yolov8_msgs/msg/detail/detection_person__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'count_people'
#include "std_msgs/msg/detail/string__traits.hpp"

namespace yolov8_msgs
{

namespace msg
{

inline void to_flow_style_yaml(
  const DetectionPerson & msg,
  std::ostream & out)
{
  out << "{";
  // member: inside
  {
    out << "inside: ";
    rosidl_generator_traits::value_to_yaml(msg.inside, out);
    out << ", ";
  }

  // member: steal
  {
    out << "steal: ";
    rosidl_generator_traits::value_to_yaml(msg.steal, out);
    out << ", ";
  }

  // member: count_people
  {
    out << "count_people: ";
    to_flow_style_yaml(msg.count_people, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const DetectionPerson & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: inside
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "inside: ";
    rosidl_generator_traits::value_to_yaml(msg.inside, out);
    out << "\n";
  }

  // member: steal
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "steal: ";
    rosidl_generator_traits::value_to_yaml(msg.steal, out);
    out << "\n";
  }

  // member: count_people
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "count_people:\n";
    to_block_style_yaml(msg.count_people, out, indentation + 2);
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const DetectionPerson & msg, bool use_flow_style = false)
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
  const yolov8_msgs::msg::DetectionPerson & msg,
  std::ostream & out, size_t indentation = 0)
{
  yolov8_msgs::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use yolov8_msgs::msg::to_yaml() instead")]]
inline std::string to_yaml(const yolov8_msgs::msg::DetectionPerson & msg)
{
  return yolov8_msgs::msg::to_yaml(msg);
}

template<>
inline const char * data_type<yolov8_msgs::msg::DetectionPerson>()
{
  return "yolov8_msgs::msg::DetectionPerson";
}

template<>
inline const char * name<yolov8_msgs::msg::DetectionPerson>()
{
  return "yolov8_msgs/msg/DetectionPerson";
}

template<>
struct has_fixed_size<yolov8_msgs::msg::DetectionPerson>
  : std::integral_constant<bool, has_fixed_size<std_msgs::msg::String>::value> {};

template<>
struct has_bounded_size<yolov8_msgs::msg::DetectionPerson>
  : std::integral_constant<bool, has_bounded_size<std_msgs::msg::String>::value> {};

template<>
struct is_message<yolov8_msgs::msg::DetectionPerson>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // YOLOV8_MSGS__MSG__DETAIL__DETECTION_PERSON__TRAITS_HPP_
