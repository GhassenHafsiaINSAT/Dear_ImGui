## GLSL (OpenGL Shading language)

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

### Types 

#### Vectors

- A vector is a 2,3 or 4 component container for any of the basic types (integers, float, boolean... ) 

  - vecn: the default vector of n floats.
  - bvecn: a vector of n booleans.
  - ivecn: a vector of n integers.
  - uvecn: a vector of n unsigned integers.
  - dvecn: a vector of n double components.

- You can use .x, .y, .z and .w to access their first, second, third and fourth component respectively. 

### Ins and Outs
- The vertex shader needs input data to do its job, this data comes from vertex attributes like positions, colors, normals, etc

### vertex buffer objects 
- To send the vertex data to vertex shader, we have to create memory on the GPU where we store vertex data, configure how OpenGL should interpret the memory and specify how to send the data to the graphic card.  

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
