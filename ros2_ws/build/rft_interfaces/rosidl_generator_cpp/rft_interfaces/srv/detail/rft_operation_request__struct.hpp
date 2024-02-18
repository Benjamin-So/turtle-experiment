// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from rft_interfaces:srv/RftOperationRequest.idl
// generated code does not contain a copyright notice

#ifndef RFT_INTERFACES__SRV__DETAIL__RFT_OPERATION_REQUEST__STRUCT_HPP_
#define RFT_INTERFACES__SRV__DETAIL__RFT_OPERATION_REQUEST__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__rft_interfaces__srv__RftOperationRequest_Request __attribute__((deprecated))
#else
# define DEPRECATED__rft_interfaces__srv__RftOperationRequest_Request __declspec(deprecated)
#endif

namespace rft_interfaces
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct RftOperationRequest_Request_
{
  using Type = RftOperationRequest_Request_<ContainerAllocator>;

  explicit RftOperationRequest_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->op_type = 0;
      this->param1 = 0;
      this->param2 = 0;
      this->param3 = 0;
    }
  }

  explicit RftOperationRequest_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->op_type = 0;
      this->param1 = 0;
      this->param2 = 0;
      this->param3 = 0;
    }
  }

  // field types and members
  using _op_type_type =
    uint8_t;
  _op_type_type op_type;
  using _param1_type =
    uint8_t;
  _param1_type param1;
  using _param2_type =
    uint8_t;
  _param2_type param2;
  using _param3_type =
    uint8_t;
  _param3_type param3;

  // setters for named parameter idiom
  Type & set__op_type(
    const uint8_t & _arg)
  {
    this->op_type = _arg;
    return *this;
  }
  Type & set__param1(
    const uint8_t & _arg)
  {
    this->param1 = _arg;
    return *this;
  }
  Type & set__param2(
    const uint8_t & _arg)
  {
    this->param2 = _arg;
    return *this;
  }
  Type & set__param3(
    const uint8_t & _arg)
  {
    this->param3 = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    rft_interfaces::srv::RftOperationRequest_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const rft_interfaces::srv::RftOperationRequest_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<rft_interfaces::srv::RftOperationRequest_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<rft_interfaces::srv::RftOperationRequest_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      rft_interfaces::srv::RftOperationRequest_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<rft_interfaces::srv::RftOperationRequest_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      rft_interfaces::srv::RftOperationRequest_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<rft_interfaces::srv::RftOperationRequest_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<rft_interfaces::srv::RftOperationRequest_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<rft_interfaces::srv::RftOperationRequest_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__rft_interfaces__srv__RftOperationRequest_Request
    std::shared_ptr<rft_interfaces::srv::RftOperationRequest_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__rft_interfaces__srv__RftOperationRequest_Request
    std::shared_ptr<rft_interfaces::srv::RftOperationRequest_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const RftOperationRequest_Request_ & other) const
  {
    if (this->op_type != other.op_type) {
      return false;
    }
    if (this->param1 != other.param1) {
      return false;
    }
    if (this->param2 != other.param2) {
      return false;
    }
    if (this->param3 != other.param3) {
      return false;
    }
    return true;
  }
  bool operator!=(const RftOperationRequest_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct RftOperationRequest_Request_

// alias to use template instance with default allocator
using RftOperationRequest_Request =
  rft_interfaces::srv::RftOperationRequest_Request_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace rft_interfaces


#ifndef _WIN32
# define DEPRECATED__rft_interfaces__srv__RftOperationRequest_Response __attribute__((deprecated))
#else
# define DEPRECATED__rft_interfaces__srv__RftOperationRequest_Response __declspec(deprecated)
#endif

namespace rft_interfaces
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct RftOperationRequest_Response_
{
  using Type = RftOperationRequest_Response_<ContainerAllocator>;

  explicit RftOperationRequest_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->result = 0;
    }
  }

  explicit RftOperationRequest_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->result = 0;
    }
  }

  // field types and members
  using _result_type =
    uint8_t;
  _result_type result;

  // setters for named parameter idiom
  Type & set__result(
    const uint8_t & _arg)
  {
    this->result = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    rft_interfaces::srv::RftOperationRequest_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const rft_interfaces::srv::RftOperationRequest_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<rft_interfaces::srv::RftOperationRequest_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<rft_interfaces::srv::RftOperationRequest_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      rft_interfaces::srv::RftOperationRequest_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<rft_interfaces::srv::RftOperationRequest_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      rft_interfaces::srv::RftOperationRequest_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<rft_interfaces::srv::RftOperationRequest_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<rft_interfaces::srv::RftOperationRequest_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<rft_interfaces::srv::RftOperationRequest_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__rft_interfaces__srv__RftOperationRequest_Response
    std::shared_ptr<rft_interfaces::srv::RftOperationRequest_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__rft_interfaces__srv__RftOperationRequest_Response
    std::shared_ptr<rft_interfaces::srv::RftOperationRequest_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const RftOperationRequest_Response_ & other) const
  {
    if (this->result != other.result) {
      return false;
    }
    return true;
  }
  bool operator!=(const RftOperationRequest_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct RftOperationRequest_Response_

// alias to use template instance with default allocator
using RftOperationRequest_Response =
  rft_interfaces::srv::RftOperationRequest_Response_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace rft_interfaces

namespace rft_interfaces
{

namespace srv
{

struct RftOperationRequest
{
  using Request = rft_interfaces::srv::RftOperationRequest_Request;
  using Response = rft_interfaces::srv::RftOperationRequest_Response;
};

}  // namespace srv

}  // namespace rft_interfaces

#endif  // RFT_INTERFACES__SRV__DETAIL__RFT_OPERATION_REQUEST__STRUCT_HPP_
