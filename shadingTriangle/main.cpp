#include <iostream>
#include <include/glad.h> // help manage and load OpenGL functions and extensions
// OpenGL functions arent available directly in the standard library, so you need glad to load them at runtime

#include <GLFW/glfw3.h> // creating windows, managing inputs and handling OpenGL contexts  

int main(){

    if(!glfwInit()) {
        std::cout<<"Error while initializing GLFW\n"; 
        return -1; 
    }
    GLFWwindow* window = glfwCreateWindow(640,480, "test", NULL, NULL);

    glfwWindowHint(GLFW_VERSION_MAJOR, 3); 
    glfwWindowHint(GLFW_VERSION_MINOR, 3); 
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE); 

    if (!window) {
        std::cout<<"error while creating a window\n"; 
        return -1; 
    }

    // making your window your current opengl context 
    glfwMakeContextCurrent(window); 
    
    // this function is for loading opengl pointers to your application 
    if(!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)){
        std::cout<<"error while initializing GLAD\n"; 
        return -1; 
    }
    // it defines the portion where opengl will render 
    glViewport(0, 0, 640, 480); 

    
    return 0; 
}