cmake_minimum_required(VERSION 3.10)
project(HelloWindow)

# Set the policy to prefer GLVND
if(POLICY CMP0072)
  cmake_policy(SET CMP0072 NEW)
endif()

find_package(glfw3 REQUIRED)
find_package(OpenGL REQUIRED)
set(OpenGL_GL_PREFERENCE GLVND)


add_library(GLAD ${CMAKE_SOURCE_DIR}/glad.c)
target_include_directories(GLAD PUBLIC ${CMAKE_SOURCE_DIR}/include)

add_executable(main ${CMAKE_SOURCE_DIR}/main.cpp)

target_link_libraries(main PRIVATE glfw GLAD OpenGL::GL dl)