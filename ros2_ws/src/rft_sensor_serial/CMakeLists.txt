cmake_minimum_required(VERSION 3.8)
project(rft_sensor_serial)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(std_msgs REQUIRED)
find_package(rft_com_library REQUIRED)
find_package(geometry_msgs REQUIRED)
find_package(rft_interfaces REQUIRED)



add_executable(main src/main.cpp)
ament_target_dependencies(main rclcpp std_msgs geometry_msgs rft_com_library rft_interfaces)

install(TARGETS
  main
  DESTINATION lib/${PROJECT_NAME})

ament_package()
