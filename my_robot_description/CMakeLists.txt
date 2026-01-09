cmake_minimum_required(VERSION 3.8)
project(my_robot_description)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(sensor_msgs REQUIRED)

add_executable(lidar_alert src/lidar_alert.cpp)
ament_target_dependencies(lidar_alert rclcpp sensor_msgs)
install(TARGETS lidar_alert DESTINATION lib/${PROJECT_NAME})


install(
  DIRECTORY launch assets urdf yaml worlds rviz src
  DESTINATION share/${PROJECT_NAME}/
)

ament_package()
