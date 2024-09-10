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