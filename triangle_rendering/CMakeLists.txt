cmake_minimum_required(VERSION 3.10)
project(MyFirstProgram)

# Set OpenGL preference to GLVND
cmake_policy(SET CMP0072 NEW)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/thirdParty/imgui,
                    ${CMAKE_CURRENT_SOURCE_DIR}/thirdParty/imgui/backends)

add_executable(${PROJECT_NAME}  ${CMAKE_CURRENT_SOURCE_DIR}/main.cpp
                                thirdParty/imgui/backends/imgui_impl_glfw.cpp 
                                thirdParty/imgui/backends/imgui_impl_opengl3.cpp 
                                thirdParty/imgui/imgui.cpp 
                                thirdParty/imgui/imgui_draw.cpp 
                                thirdParty/imgui/imgui_tables.cpp 
                                thirdParty/imgui/imgui_widgets.cpp
                )

                find_package(glfw3 REQUIRED)
                find_package(OpenGL REQUIRED)
                
                target_link_libraries(MyFirstProgram glfw OpenGL::GL)