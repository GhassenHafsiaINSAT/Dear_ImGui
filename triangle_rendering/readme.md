```cpp 
#include "thirdPart/imgui/imgui.h" // includes the core Dear ImGui library, which provides the functionality for creating user interfaces
#include "thirParty/imgui/imgui_impl_glfw.h" // includes the implementation file that connects Dear ImGui with GLFW
#include "imgui_impl_opengl3.h" // includes the implementation file that connects Dear Imgui with OpenGL
#include <GLFW/glfw3.h> // includes the GLFW library
```

- `glfwinit()`: initializes the GLFW library, if it fails, it returns false and the program returns with -1

- `glfwCreateWindow()`: Creates a window and openGL context

- `ImGuiIO& io = ImGui::GetIO();`: Retrieves the ImGui IO structure, which is used to configure the library.

### Rendering Loop 

- `glfwPollEvents()`: It processes all pending events (keyboard and mouse input, window resize) and calls the corresponding callbacks

- `glClearColor()`: It specifys the color for the background, it clears the color buffer

- `glClear(GL_COLOR_BUFFER_BIT)`: When called, it clear the screen using the color defined by `glClearColor()`



