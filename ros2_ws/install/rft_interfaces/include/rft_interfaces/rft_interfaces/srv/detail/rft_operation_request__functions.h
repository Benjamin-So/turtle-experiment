// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from rft_interfaces:srv/RftOperationRequest.idl
// generated code does not contain a copyright notice

#ifndef RFT_INTERFACES__SRV__DETAIL__RFT_OPERATION_REQUEST__FUNCTIONS_H_
#define RFT_INTERFACES__SRV__DETAIL__RFT_OPERATION_REQUEST__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/visibility_control.h"
#include "rft_interfaces/msg/rosidl_generator_c__visibility_control.h"

#include "rft_interfaces/srv/detail/rft_operation_request__struct.h"

/// Initialize srv/RftOperationRequest message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * rft_interfaces__srv__RftOperationRequest_Request
 * )) before or use
 * rft_interfaces__srv__RftOperationRequest_Request__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_rft_interfaces
bool
rft_interfaces__srv__RftOperationRequest_Request__init(rft_interfaces__srv__RftOperationRequest_Request * msg);

/// Finalize srv/RftOperationRequest message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_rft_interfaces
void
rft_interfaces__srv__RftOperationRequest_Request__fini(rft_interfaces__srv__RftOperationRequest_Request * msg);

/// Create srv/RftOperationRequest message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * rft_interfaces__srv__RftOperationRequest_Request__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_rft_interfaces
rft_interfaces__srv__RftOperationRequest_Request *
rft_interfaces__srv__RftOperationRequest_Request__create();

/// Destroy srv/RftOperationRequest message.
/**
 * It calls
 * rft_interfaces__srv__RftOperationRequest_Request__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_rft_interfaces
void
rft_interfaces__srv__RftOperationRequest_Request__destroy(rft_interfaces__srv__RftOperationRequest_Request * msg);

/// Check for srv/RftOperationRequest message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_rft_interfaces
bool
rft_interfaces__srv__RftOperationRequest_Request__are_equal(const rft_interfaces__srv__RftOperationRequest_Request * lhs, const rft_interfaces__srv__RftOperationRequest_Request * rhs);

/// Copy a srv/RftOperationRequest message.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source message pointer.
 * \param[out] output The target message pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer is null
 *   or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_rft_interfaces
bool
rft_interfaces__srv__RftOperationRequest_Request__copy(
  const rft_interfaces__srv__RftOperationRequest_Request * input,
  rft_interfaces__srv__RftOperationRequest_Request * output);

/// Initialize array of srv/RftOperationRequest messages.
/**
 * It allocates the memory for the number of elements and calls
 * rft_interfaces__srv__RftOperationRequest_Request__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_rft_interfaces
bool
rft_interfaces__srv__RftOperationRequest_Request__Sequence__init(rft_interfaces__srv__RftOperationRequest_Request__Sequence * array, size_t size);

/// Finalize array of srv/RftOperationRequest messages.
/**
 * It calls
 * rft_interfaces__srv__RftOperationRequest_Request__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_rft_interfaces
void
rft_interfaces__srv__RftOperationRequest_Request__Sequence__fini(rft_interfaces__srv__RftOperationRequest_Request__Sequence * array);

/// Create array of srv/RftOperationRequest messages.
/**
 * It allocates the memory for the array and calls
 * rft_interfaces__srv__RftOperationRequest_Request__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_rft_interfaces
rft_interfaces__srv__RftOperationRequest_Request__Sequence *
rft_interfaces__srv__RftOperationRequest_Request__Sequence__create(size_t size);

/// Destroy array of srv/RftOperationRequest messages.
/**
 * It calls
 * rft_interfaces__srv__RftOperationRequest_Request__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_rft_interfaces
void
rft_interfaces__srv__RftOperationRequest_Request__Sequence__destroy(rft_interfaces__srv__RftOperationRequest_Request__Sequence * array);

/// Check for srv/RftOperationRequest message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_rft_interfaces
bool
rft_interfaces__srv__RftOperationRequest_Request__Sequence__are_equal(const rft_interfaces__srv__RftOperationRequest_Request__Sequence * lhs, const rft_interfaces__srv__RftOperationRequest_Request__Sequence * rhs);

/// Copy an array of srv/RftOperationRequest messages.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source array pointer.
 * \param[out] output The target array pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer
 *   is null or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_rft_interfaces
bool
rft_interfaces__srv__RftOperationRequest_Request__Sequence__copy(
  const rft_interfaces__srv__RftOperationRequest_Request__Sequence * input,
  rft_interfaces__srv__RftOperationRequest_Request__Sequence * output);

/// Initialize srv/RftOperationRequest message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * rft_interfaces__srv__RftOperationRequest_Response
 * )) before or use
 * rft_interfaces__srv__RftOperationRequest_Response__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_rft_interfaces
bool
rft_interfaces__srv__RftOperationRequest_Response__init(rft_interfaces__srv__RftOperationRequest_Response * msg);

/// Finalize srv/RftOperationRequest message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_rft_interfaces
void
rft_interfaces__srv__RftOperationRequest_Response__fini(rft_interfaces__srv__RftOperationRequest_Response * msg);

/// Create srv/RftOperationRequest message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * rft_interfaces__srv__RftOperationRequest_Response__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_rft_interfaces
rft_interfaces__srv__RftOperationRequest_Response *
rft_interfaces__srv__RftOperationRequest_Response__create();

/// Destroy srv/RftOperationRequest message.
/**
 * It calls
 * rft_interfaces__srv__RftOperationRequest_Response__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_rft_interfaces
void
rft_interfaces__srv__RftOperationRequest_Response__destroy(rft_interfaces__srv__RftOperationRequest_Response * msg);

/// Check for srv/RftOperationRequest message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_rft_interfaces
bool
rft_interfaces__srv__RftOperationRequest_Response__are_equal(const rft_interfaces__srv__RftOperationRequest_Response * lhs, const rft_interfaces__srv__RftOperationRequest_Response * rhs);

/// Copy a srv/RftOperationRequest message.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source message pointer.
 * \param[out] output The target message pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer is null
 *   or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_rft_interfaces
bool
rft_interfaces__srv__RftOperationRequest_Response__copy(
  const rft_interfaces__srv__RftOperationRequest_Response * input,
  rft_interfaces__srv__RftOperationRequest_Response * output);

/// Initialize array of srv/RftOperationRequest messages.
/**
 * It allocates the memory for the number of elements and calls
 * rft_interfaces__srv__RftOperationRequest_Response__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_rft_interfaces
bool
rft_interfaces__srv__RftOperationRequest_Response__Sequence__init(rft_interfaces__srv__RftOperationRequest_Response__Sequence * array, size_t size);

/// Finalize array of srv/RftOperationRequest messages.
/**
 * It calls
 * rft_interfaces__srv__RftOperationRequest_Response__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_rft_interfaces
void
rft_interfaces__srv__RftOperationRequest_Response__Sequence__fini(rft_interfaces__srv__RftOperationRequest_Response__Sequence * array);

/// Create array of srv/RftOperationRequest messages.
/**
 * It allocates the memory for the array and calls
 * rft_interfaces__srv__RftOperationRequest_Response__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_rft_interfaces
rft_interfaces__srv__RftOperationRequest_Response__Sequence *
rft_interfaces__srv__RftOperationRequest_Response__Sequence__create(size_t size);

/// Destroy array of srv/RftOperationRequest messages.
/**
 * It calls
 * rft_interfaces__srv__RftOperationRequest_Response__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_rft_interfaces
void
rft_interfaces__srv__RftOperationRequest_Response__Sequence__destroy(rft_interfaces__srv__RftOperationRequest_Response__Sequence * array);

/// Check for srv/RftOperationRequest message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_rft_interfaces
bool
rft_interfaces__srv__RftOperationRequest_Response__Sequence__are_equal(const rft_interfaces__srv__RftOperationRequest_Response__Sequence * lhs, const rft_interfaces__srv__RftOperationRequest_Response__Sequence * rhs);

/// Copy an array of srv/RftOperationRequest messages.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source array pointer.
 * \param[out] output The target array pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer
 *   is null or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_rft_interfaces
bool
rft_interfaces__srv__RftOperationRequest_Response__Sequence__copy(
  const rft_interfaces__srv__RftOperationRequest_Response__Sequence * input,
  rft_interfaces__srv__RftOperationRequest_Response__Sequence * output);

#ifdef __cplusplus
}
#endif

#endif  // RFT_INTERFACES__SRV__DETAIL__RFT_OPERATION_REQUEST__FUNCTIONS_H_
