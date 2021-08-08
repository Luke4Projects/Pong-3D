#include "header/shaders.h"
#include <glad/glad.h>
#include <iostream>


// -------------- Shader sources ---------------
// Normaly, I would make a file loader for the shader, and put shader sources
// in their own file, but for this quick project I think it is fine to just
// put the source in here
const char* vertexShaderSource = "#version 330 core\n"
"layout (location = 0) in vec3 aPos;\n"
"uniform mat4 model;\n"
"uniform mat4 proj;\n"
"uniform mat4 view;\n"
"void main() {\n"
"   gl_Position = proj * view * model * vec4(aPos, 1.0);\n"
"}\0";

const char* fragShaderSource = "#version 330 core\n"
"out vec4 FragColor;\n"
"void main() {\n"
"   FragColor = vec4(1.0, 1.0, 1.0, 1.0);\n"
"}\0";


// ------------- shader functions ---------------- 

// creates a vertex shader (vs) and a fragment shader (fs) and puts
// them in a shader program, which is returned. 
unsigned int setupShaders() {

    unsigned int vs = glCreateShader(GL_VERTEX_SHADER);
    unsigned int fs = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(vs, 1, &vertexShaderSource, NULL);
    glShaderSource(fs, 1, &fragShaderSource, NULL);
    glCompileShader(vs);
    glCompileShader(fs);
    unsigned int program = glCreateProgram();
    glAttachShader(program, vs);
    glAttachShader(program, fs);
    glLinkProgram(program);

    glDeleteShader(vs); // we can delete the shaders after putting them in the program
    glDeleteShader(fs);

    return program;

}