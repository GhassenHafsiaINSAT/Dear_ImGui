#include "include/glad.h"
#include <GLFW/glfw3.h>
#include <iostream>

void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    glViewport(0, 0, width, height);
}

void processInput(GLFWwindow *window)
{
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) // Check if the user pressed the escape button, if not it returns GLFW_RELEASE
        glfwSetWindowShouldClose(window, true);
}


int main(){

    if (!glfwInit()){
        std::cout<<"Failed to initialize GLFW" <<std::endl; 
        return -1; 
    } 


    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3); 
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3); 
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE); 


GLFWwindow* window = glfwCreateWindow(480, 360, "HelloWindow", NULL, NULL); 
if(window == NULL){
    std::cout << "Failed to create GLFW window" << std::endl; 
    glfwTerminate(); 
    return -1; 
}   

glfwMakeContextCurrent(window); 

if(!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) 
{
    std::cout << "Failed to initialize GLAD" <<std::endl; 
    return -1; 
}

glViewport(0, 0, 480, 360); 

glfwSetFramebufferSizeCallback(window, framebuffer_size_callback); 


while(!glfwWindowShouldClose(window)){ // checks if glfw is intructed to close

    processInput(window); 
    glClearColor(0.2f, 0.3f, 0.3f, 1.0f); // clear screen's color buffer 
    glClear(GL_COLOR_BUFFER_BIT); // fill the background with color buffer's content
    glfwSwapBuffers(window); // swap  color buffer to the output screen
    glfwPollEvents();   // checks if any events are triggered (keyboard input, mouse movement) 

}

glfwTerminate(); 
return 0; 

}