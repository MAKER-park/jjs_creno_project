cmake_minimum_required(VERSION 3.0.2)
project(ros_opencv)

find_package(catkin REQUIRED COMPONENTS
  message_generation
  roscpp
  std_msgs
  cv_bridge
)

find_package(OpenCV REQUIRED)

 generate_messages(
   DEPENDENCIES
   std_msgs
 )

catkin_package(
	INCLUDE_DIRS include
	LIBRARIES opencv
	CATKIN_DEPENDS roscpp cv_bridge
)

include_directories(
# include
  ${catkin_INCLUDE_DIRS}
# include 
  ${OpenCV_INCLUDE_DIRS}
)

add_executable(${PROJECT_NAME} src/opencv.cpp)
target_link_libraries(${PROJECT_NAME} ${catkin_LIBRARIES} ${OpenCV_LIBRARIES})
add_dependencies(${PROJECT_NAME} ${PROJECT_NAME}_generate_messages_cpp)
