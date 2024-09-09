# CMakeLists.txt

cmake_minimum_required(VERSION 3.10)
project(maxVertexAttributes)

# Add GLAD
add_library(glad glad.c)
target_include_directories(glad PUBLIC include)

# Add your executable
add_executable(maxAttr main.cpp)

# Link GLAD and OpenGL to your executable
target_link_libraries(maxAttr glad GL dl)
