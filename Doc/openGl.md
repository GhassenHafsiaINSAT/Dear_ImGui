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


## Shaders 
- Shaders are little programs that rest on the GPU, run on for each specefic section of the graphics pipline.  
- Shaders are programs transforming inputs to outputs, isolated in that they're not allowed to communicate with each other

### GLSL (OpenGL Shading language)

- Shaders are written in the C-like language GLSL.
- Shaders always begin with a version declaration, followed by a list of input and output variables, uniform and its `main` function.  

```c
#version version_number
in type in_variable_name;
in type in_variable_name;

out type out_variable_name;
  
uniform type uniform_name;
  
void main()
{
  // process input(s) and do some weird graphics stuff
  ...
  // output processed stuff to output variable
  out_variable_name = weird_stuff_we_processed;
}
```

- Each input variable is also known as a vertex attribute, there is a maximum number of vertex attribute allowed to declare limited by hardware 
