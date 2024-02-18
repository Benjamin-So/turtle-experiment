// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from rft_interfaces:srv/RftOperationRequest.idl
// generated code does not contain a copyright notice

#ifndef RFT_INTERFACES__SRV__DETAIL__RFT_OPERATION_REQUEST__BUILDER_HPP_
#define RFT_INTERFACES__SRV__DETAIL__RFT_OPERATION_REQUEST__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "rft_interfaces/srv/detail/rft_operation_request__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace rft_interfaces
{

namespace srv
{

namespace builder
{

class Init_RftOperationRequest_Request_param3
{
public:
  explicit Init_RftOperationRequest_Request_param3(::rft_interfaces::srv::RftOperationRequest_Request & msg)
  : msg_(msg)
  {}
  ::rft_interfaces::srv::RftOperationRequest_Request param3(::rft_interfaces::srv::RftOperationRequest_Request::_param3_type arg)
  {
    msg_.param3 = std::move(arg);
    return std::move(msg_);
  }

private:
  ::rft_interfaces::srv::RftOperationRequest_Request msg_;
};

class Init_RftOperationRequest_Request_param2
{
public:
  explicit Init_RftOperationRequest_Request_param2(::rft_interfaces::srv::RftOperationRequest_Request & msg)
  : msg_(msg)
  {}
  Init_RftOperationRequest_Request_param3 param2(::rft_interfaces::srv::RftOperationRequest_Request::_param2_type arg)
  {
    msg_.param2 = std::move(arg);
    return Init_RftOperationRequest_Request_param3(msg_);
  }

private:
  ::rft_interfaces::srv::RftOperationRequest_Request msg_;
};

class Init_RftOperationRequest_Request_param1
{
public:
  explicit Init_RftOperationRequest_Request_param1(::rft_interfaces::srv::RftOperationRequest_Request & msg)
  : msg_(msg)
  {}
  Init_RftOperationRequest_Request_param2 param1(::rft_interfaces::srv::RftOperationRequest_Request::_param1_type arg)
  {
    msg_.param1 = std::move(arg);
    return Init_RftOperationRequest_Request_param2(msg_);
  }

private:
  ::rft_interfaces::srv::RftOperationRequest_Request msg_;
};

class Init_RftOperationRequest_Request_op_type
{
public:
  Init_RftOperationRequest_Request_op_type()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_RftOperationRequest_Request_param1 op_type(::rft_interfaces::srv::RftOperationRequest_Request::_op_type_type arg)
  {
    msg_.op_type = std::move(arg);
    return Init_RftOperationRequest_Request_param1(msg_);
  }

private:
  ::rft_interfaces::srv::RftOperationRequest_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::rft_interfaces::srv::RftOperationRequest_Request>()
{
  return rft_interfaces::srv::builder::Init_RftOperationRequest_Request_op_type();
}

}  // namespace rft_interfaces


namespace rft_interfaces
{

namespace srv
{

namespace builder
{

class Init_RftOperationRequest_Response_result
{
public:
  Init_RftOperationRequest_Response_result()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::rft_interfaces::srv::RftOperationRequest_Response result(::rft_interfaces::srv::RftOperationRequest_Response::_result_type arg)
  {
    msg_.result = std::move(arg);
    return std::move(msg_);
  }

private:
  ::rft_interfaces::srv::RftOperationRequest_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::rft_interfaces::srv::RftOperationRequest_Response>()
{
  return rft_interfaces::srv::builder::Init_RftOperationRequest_Response_result();
}

}  // namespace rft_interfaces

#endif  // RFT_INTERFACES__SRV__DETAIL__RFT_OPERATION_REQUEST__BUILDER_HPP_
