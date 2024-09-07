#include "thirdParty/imgui/imgui.h"
#include "thirdParty/imgui/backends/imgui_impl_glfw.h"
#include "thirdParty/imgui/backends/imgui_impl_opengl3.h"
#include <GLFW/glfw3.h> // Include OpenGL and GLFW


int main(){
    if(!glfwInit()){
        return -1; 
    }

// Create a Windowed Mode Window and Its OpenGL Context
    GLFWwindow* window = glfwCreateWindow(640,480,"triangle", NULL, NULL); 
    if (!window){
        glfwTerminate(); 
        return -1; 
    }
// Make the window's context current
    glfwMakeContextCurrent(window); 
    glfwSwapInterval(1); 

    //if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) { /* handle error */ }

// Setup Dear imgui context
    IMGUI_CHECKVERSION(); 
    ImGui::CreateContext(); 
    ImGuiIO& io = ImGui::GetIO();

    ImGui_ImplGlfw_InitForOpenGL(window, true);
    ImGui_ImplOpenGL3_Init("#version 130");

    ImGui::StyleColorsDark(); 
    while (!glfwWindowShouldClose(window))
    {
        glfwPollEvents();
        glClearColor(0.45f, 0.55f, 0.60f, 1.00f);
        glClear(GL_COLOR_BUFFER_BIT);

        // feed inputs to dear imgui, start new frame
        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplGlfw_NewFrame();
        ImGui::NewFrame();

        // rendering our geometries
        triangle_shader.use();
        glBindVertexArray(vao);
        glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_INT, 0);
        glBindVertexArray(0);

        // render your GUI
        ImGui::Begin("Demo window");
        ImGui::Button("Hello!");
        ImGui::End();

        // Render dear imgui into screen
        ImGui::Render();
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

        int display_w, display_h;
        glfwGetFramebufferSize(window, &display_w, &display_h);
        glViewport(0, 0, display_w, display_h);
        glfwSwapBuffers(window);
    }
// cleanup
    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();
}
