## OpenGL (Open Graphic Library) 
- OpenGL is graphics API, it allows us to acces the GPU, to create graphics in real-time

- OPenGL is Cross-Platform, works on various operating systems, including windows, linux, MacOS

## GLFW (Graphics Library Framework) 
- GLFW is a library for creating windows, managing OpenGL contexts, handling input from the mouse and keyboard.  

### Using ImGui with openGL and GLFW
1. **GLFW**
  - You create a window and an OpenGL context using GLFW, the context is necessary for OpenGL to know where to draw its output
  
  - Mnaage input (keyboard, mouseà and window events (resizing, closing) using GLFW's API.
  - The `imgui_impl_glfw` provides implementation for using ImGui with GLFW, to manage window events and inputs in an ImGui context.  

2. **OPenGL**
  - OPenGL commands are issued to handle the actual rendering of graphics to the window.
  
  - Rendering is the process of generatin an image from a model or set of data
3. **ImGui** 
  -  Build your GUI using ImGui functions `imgui.h`.  
  -  Handle input and events from GLFW, pass them to imgui to update the gui state, using the `imgui_impl_glfw.h`.  
  -  Render the GUI using ImGui's OpenGL rendring commands using `imgui_impl_opengl3`.   
