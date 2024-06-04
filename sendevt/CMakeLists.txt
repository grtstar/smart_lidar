cmake_minimum_required(VERSION 3.5)

project(sendevt)

find_package(lcm REQUIRED)

add_executable(${PROJECT_NAME}  src/sendevt.cpp
                                )

# Declare dependency on the absl::strings library
# lcm
target_link_libraries(${PROJECT_NAME} lcm)
target_link_libraries(${PROJECT_NAME} pthread)