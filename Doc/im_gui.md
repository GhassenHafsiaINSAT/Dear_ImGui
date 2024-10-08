## ImGui

- ImGui short for Immediate Mode Gui is a popular C++ library for creating graphical user interfaces in applications

- The project is an open-source project, licensed under MIT.  
- Unlike traditional GUI libraries that rely one event-driven programming (like QT or GTK), imGui uses an immediate mode paradigm, this means that GUI is redrawn every frame
- The library is lightweight and designed to be easily integrated into existing codebases
- ImGui is platform-agnostic and can work on any graphic API, such as OpenGL, DirectX, Vulkan, etc
- ImGui doesn't depend on any external GUI framework, simple to integrate
- ImGui operates by having you describe the interface directly in rendering loop, easy to create and modify interfaces dynamically

## Using ImGui with openGL and GLFW
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
