## OpenGL (Open Graphic Library) 
- OpenGL is graphics API, it allows us to acces the GPU, to create graphics in real-time

- OPenGL is Cross-Platform, works on various operating systems, including windows, linux, MacOS

- In OpenGL, everything is in 3D space, but the screen or window is 2D array of pixels, so the work of openGL is transforming all 3D coordinates to 2D pixels that fit on your screen, this process is managed by the **graphics pipeline** of OpenGL.  

- The graphics pipeline takes as input a set of 3D coordinates and transforms these to colored 2D coordinates.

- The graphics pipeline can be divided into several steps where each step requires the output of the previous step as its input, these steps are highly specialized (they have one specific function).

- These steps can easily be executed in parallel, so graphic cards have thousands of small processing cores to quickly process your data within the graphic pipeline, these small programs are called **shaders**.   


## Shaders 
- Shaders are little programs that rest on the GPU, run on for each specefic section of the graphics pipline.  

- Vertex shader transforms vertex positions and other attributes (color, texture) from model space to screen space.  

- Shaders are programs transforming inputs to outputs, isolated in that they're not allowed to communicate with each other

- Shaders are written in the **C-like language GLSL**.

## Graphics pipeline 

- The graphics pipeline contains a larfe number of sections that each handle one specefic part of converting you vertex daat to fully rendered pixel.  

- As input to graphics pipeline we pass a list of 3D coordinates that should form a triangle in an array called **vertex data**.  

- A vertex data is a collection of vertice, a collection of data per 3D coordinates.  

- The first part of a pipeline is the **vertex shader** that takes as input a single vertex

- The output of the vertex shader is optionally passed to the **geometry shader** 

- The **primitive assembly** stage takes as input all the vertices from the vertex of geometry shader and assemble all the points.  

- The output of **primitive assembly** is then passed to the **resterization stage**, where it maps the reselting primitives to the corresponding pixels on the final screen.  

- The **fragment shader** is to calculate the final color of a pixel.  

### Vertex input 
- To start drawing, we have to first give OpenGL some input vertex data.  
- OpenGL is a 3D graphics library so all coordinates that we specify in OpenGL are in 3D
- OpenGL only processes 3D coordinates when they are in specific range between -1.0 and 1.0 on all 3 axes (x,y and z), called **normalized device coordinates**.  

- So firstly, you want to send vertex data (positions of your shape) to the GPU, so it can be processed by the vertex shader

#### Vertex buffer Object (VBO): 
- A block of memory on the GPU where you can store vertex data.  

- The main advantage of VBO is that you can send many vertex data at once to the GPU and sotre it there, avoiding the slow process of constantly sending data one by one from CPU to GPU.  

- First, you create a VBO and get a unique ID to refer to it: 

  ```c
  unsigned int VBO;
  glGenBuffers(1, &VBO);
  ```

- Then, you bind the VBO so that OpenGL knows you are working with it:  

  ```c
  glBindBuffer(GL_ARRAY_BUFFER, VBO);  
  ```

- Once the VBO is bound, you copy you vertex data into the VBO's memoy, you tell OpenGL how large you data is, and how it should manage it: 

  ```c 
  glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
  ```

### Vertex Array Object (VAO)
- VAO stores the state of VBOs and how the vertew data is laid out.  

- Instead of setting the VBO every time before drawing, the VOA remembers how the data is linked, making rendering faster and easier to manage.  

- First, you create a VAO and get a unique ID to refer to it: 

  ```c
  unsigned int VBO;
  glGenVertexArrays(1, &VAO); 
  ```  
- Then, you bind the VBO so that OpenGL knows you are working with it:  
  
  ```c
  glBindVertexArray(VAO);
  ```
  
### Vertex Shader 
- Vertex Shader is a small program that runs on the GPU, responsible for processing each vertex and passing the result to the next stages of the rendering pipeline.  
- We have to write the vertex shader and compile the shader so we can use it in our application: 

    ```c
    #version 330 core // specefies GLSL version (330 corresponds to OpenGL version 3.3)
    layout (location = 0) in vec3 aPos; // input of the vertex shader 

    void main()
    {
        gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);
    }
    ```

- We take then the source code for the vertex shader and store it in a const C string: 
    ```c
    const char *vertexShaderSource = "#version 330 core\n"
        "layout (location = 0) in vec3 aPos;\n"
        "void main()\n"
        "{\n"
        "   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
        "}\0";
    ```
- In order for OpenGL to use the shader it has dynammically compile it at run-time from its source code, so we have to create a shader object, referenced by an ID: 
    ```c 
    unsigned int vertexShader;
    vertexShader = glCreateShader(GL_VERTEX_SHADER);
    ```

- Then, we attach source code to the shader object and compile the shader: 
    ```c
    glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
    glCompileShader(vertexShader);
    ```