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

