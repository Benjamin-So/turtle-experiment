// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from rft_interfaces:srv/RftOperationRequest.idl
// generated code does not contain a copyright notice

#ifndef RFT_INTERFACES__SRV__DETAIL__RFT_OPERATION_REQUEST__STRUCT_H_
#define RFT_INTERFACES__SRV__DETAIL__RFT_OPERATION_REQUEST__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in srv/RftOperationRequest in the package rft_interfaces.
typedef struct rft_interfaces__srv__RftOperationRequest_Request
{
  uint8_t op_type;
  uint8_t param1;
  uint8_t param2;
  uint8_t param3;
} rft_interfaces__srv__RftOperationRequest_Request;

// Struct for a sequence of rft_interfaces__srv__RftOperationRequest_Request.
typedef struct rft_interfaces__srv__RftOperationRequest_Request__Sequence
{
  rft_interfaces__srv__RftOperationRequest_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} rft_interfaces__srv__RftOperationRequest_Request__Sequence;


// Constants defined in the message

/// Struct defined in srv/RftOperationRequest in the package rft_interfaces.
typedef struct rft_interfaces__srv__RftOperationRequest_Response
{
  uint8_t result;
} rft_interfaces__srv__RftOperationRequest_Response;

// Struct for a sequence of rft_interfaces__srv__RftOperationRequest_Response.
typedef struct rft_interfaces__srv__RftOperationRequest_Response__Sequence
{
  rft_interfaces__srv__RftOperationRequest_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} rft_interfaces__srv__RftOperationRequest_Response__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // RFT_INTERFACES__SRV__DETAIL__RFT_OPERATION_REQUEST__STRUCT_H_
