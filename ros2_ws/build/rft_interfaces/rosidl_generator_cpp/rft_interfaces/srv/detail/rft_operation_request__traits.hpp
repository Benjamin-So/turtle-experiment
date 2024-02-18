// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from rft_interfaces:srv/RftOperationRequest.idl
// generated code does not contain a copyright notice

#ifndef RFT_INTERFACES__SRV__DETAIL__RFT_OPERATION_REQUEST__TRAITS_HPP_
#define RFT_INTERFACES__SRV__DETAIL__RFT_OPERATION_REQUEST__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "rft_interfaces/srv/detail/rft_operation_request__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace rft_interfaces
{

namespace srv
{

inline void to_flow_style_yaml(
  const RftOperationRequest_Request & msg,
  std::ostream & out)
{
  out << "{";
  // member: op_type
  {
    out << "op_type: ";
    rosidl_generator_traits::value_to_yaml(msg.op_type, out);
    out << ", ";
  }

  // member: param1
  {
    out << "param1: ";
    rosidl_generator_traits::value_to_yaml(msg.param1, out);
    out << ", ";
  }

  // member: param2
  {
    out << "param2: ";
    rosidl_generator_traits::value_to_yaml(msg.param2, out);
    out << ", ";
  }

  // member: param3
  {
    out << "param3: ";
    rosidl_generator_traits::value_to_yaml(msg.param3, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const RftOperationRequest_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: op_type
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "op_type: ";
    rosidl_generator_traits::value_to_yaml(msg.op_type, out);
    out << "\n";
  }

  // member: param1
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "param1: ";
    rosidl_generator_traits::value_to_yaml(msg.param1, out);
    out << "\n";
  }

  // member: param2
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "param2: ";
    rosidl_generator_traits::value_to_yaml(msg.param2, out);
    out << "\n";
  }

  // member: param3
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "param3: ";
    rosidl_generator_traits::value_to_yaml(msg.param3, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const RftOperationRequest_Request & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace rft_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use rft_interfaces::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const rft_interfaces::srv::RftOperationRequest_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  rft_interfaces::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use rft_interfaces::srv::to_yaml() instead")]]
inline std::string to_yaml(const rft_interfaces::srv::RftOperationRequest_Request & msg)
{
  return rft_interfaces::srv::to_yaml(msg);
}

template<>
inline const char * data_type<rft_interfaces::srv::RftOperationRequest_Request>()
{
  return "rft_interfaces::srv::RftOperationRequest_Request";
}

template<>
inline const char * name<rft_interfaces::srv::RftOperationRequest_Request>()
{
  return "rft_interfaces/srv/RftOperationRequest_Request";
}

template<>
struct has_fixed_size<rft_interfaces::srv::RftOperationRequest_Request>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<rft_interfaces::srv::RftOperationRequest_Request>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<rft_interfaces::srv::RftOperationRequest_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rft_interfaces
{

namespace srv
{

inline void to_flow_style_yaml(
  const RftOperationRequest_Response & msg,
  std::ostream & out)
{
  out << "{";
  // member: result
  {
    out << "result: ";
    rosidl_generator_traits::value_to_yaml(msg.result, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const RftOperationRequest_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: result
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "result: ";
    rosidl_generator_traits::value_to_yaml(msg.result, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const RftOperationRequest_Response & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace rft_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use rft_interfaces::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const rft_interfaces::srv::RftOperationRequest_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  rft_interfaces::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use rft_interfaces::srv::to_yaml() instead")]]
inline std::string to_yaml(const rft_interfaces::srv::RftOperationRequest_Response & msg)
{
  return rft_interfaces::srv::to_yaml(msg);
}

template<>
inline const char * data_type<rft_interfaces::srv::RftOperationRequest_Response>()
{
  return "rft_interfaces::srv::RftOperationRequest_Response";
}

template<>
inline const char * name<rft_interfaces::srv::RftOperationRequest_Response>()
{
  return "rft_interfaces/srv/RftOperationRequest_Response";
}

template<>
struct has_fixed_size<rft_interfaces::srv::RftOperationRequest_Response>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<rft_interfaces::srv::RftOperationRequest_Response>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<rft_interfaces::srv::RftOperationRequest_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<rft_interfaces::srv::RftOperationRequest>()
{
  return "rft_interfaces::srv::RftOperationRequest";
}

template<>
inline const char * name<rft_interfaces::srv::RftOperationRequest>()
{
  return "rft_interfaces/srv/RftOperationRequest";
}

template<>
struct has_fixed_size<rft_interfaces::srv::RftOperationRequest>
  : std::integral_constant<
    bool,
    has_fixed_size<rft_interfaces::srv::RftOperationRequest_Request>::value &&
    has_fixed_size<rft_interfaces::srv::RftOperationRequest_Response>::value
  >
{
};

template<>
struct has_bounded_size<rft_interfaces::srv::RftOperationRequest>
  : std::integral_constant<
    bool,
    has_bounded_size<rft_interfaces::srv::RftOperationRequest_Request>::value &&
    has_bounded_size<rft_interfaces::srv::RftOperationRequest_Response>::value
  >
{
};

template<>
struct is_service<rft_interfaces::srv::RftOperationRequest>
  : std::true_type
{
};

template<>
struct is_service_request<rft_interfaces::srv::RftOperationRequest_Request>
  : std::true_type
{
};

template<>
struct is_service_response<rft_interfaces::srv::RftOperationRequest_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // RFT_INTERFACES__SRV__DETAIL__RFT_OPERATION_REQUEST__TRAITS_HPP_
