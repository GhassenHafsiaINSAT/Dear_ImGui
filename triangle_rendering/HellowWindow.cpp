#include <GLFW/glfw3.h>
#include <iostream>
int main()
{
    if(!glfwInit()){ // glfwint() returns false if it doesn't work
        std::cerr<<"error while creating a window\n"; 
        return -1; 
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);

    glfwTerminate(); // cleanup before exiting 
    

    
    return 0; 

}

