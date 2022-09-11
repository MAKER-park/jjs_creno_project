cmake_minimum_required(VERSION 3.0.2)
project(ros_server_topic)

find_package(catkin REQUIRED COMPONENTS
	message_generation
	roscpp
	std_msgs
)

generate_messages(
	DEPENDENCIES
	std_msgs
)

catkin_package(
)

include_directories(
# include
	${catkin_INCLUDE_DIRS}
)

add_executable(${PROJECT_NAME} src/chat_client.cpp)
target_link_libraries(${PROJECT_NAME} ${catkin_LIBRARIES})
add_dependencies(${PROJECT_NAME} ${PROJECT_NAME}_generate_messages_cpp)
