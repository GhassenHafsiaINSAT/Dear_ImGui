#include "include/glad.h"
#include <GLFW/glfw3.h>
#include <iostream>
/*
void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    glViewport(0, 0, width, height);
}
*/

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

// glViewport(0, 0, 480, 360); 

//glfwSetFramebufferSizeCallback(window, framebuffer_size_callback); 


while(!glfwWindowShouldClose(window)){ // checks if glfw is intructed to close

    glfwSwapBuffers(window); // swap  color buffer to the output screen
    glfwPollEvents();   // checks if any events are triggered (keyboard input, mouse movement) 

}

glfwTerminate(); 
return 0; 

}