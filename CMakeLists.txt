cmake_minimum_required(VERSION 3.24)
project(gtk4_vulkan_integration_test)

set(CMAKE_CXX_STANDARD 17)

find_package(PkgConfig REQUIRED)
find_package(OpenGL REQUIRED)
pkg_check_modules(GTK REQUIRED gtk4)

include_directories(${GTK_INCLUDE_DIRS} ${OPENGL_INCLUDE_DIRS})
link_directories(${GTK_LIBRARY_DIRS} ${OPENGL_LIBRARY_DIRS})

add_executable(gtk4_vulkan_integration_test main.cpp)
target_link_libraries(${PROJECT_NAME} ${GTK_LIBRARIES} ${OPENGL_LIBRARIES})
