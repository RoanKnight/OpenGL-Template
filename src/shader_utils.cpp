#include "shader_utils.h"
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <iostream>

using namespace std;

// Function to read the contents of a shader file
// Takes the filename as a parameter and returns the file contents as a string
string readShaderFile(const string &filename)
{
  ifstream file(filename);
  if (!file.is_open())
  {
    throw runtime_error("Failed to open shader file: " + filename);
  }
  stringstream buffer;
  buffer << file.rdbuf();
  return buffer.str();
}

// Function to compile a shader
// Takes the shader type (vertex or fragment) and the source code as parameters
// Returns the compiled shader ID
GLuint compileShader(GLenum type, const string &source)
{
  // Create a shader object
  GLuint shader = glCreateShader(type);
  const char *sourcePtr = source.c_str();
  glShaderSource(shader, 1, &sourcePtr, nullptr);
  glCompileShader(shader);

  // Check compilation status
  GLint success;
  glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
  if (!success)
  {
    // Retrieve and print the error log
    GLchar infoLog[512];
    glGetShaderInfoLog(shader, sizeof(infoLog), nullptr, infoLog);
    string shaderType = (type == GL_VERTEX_SHADER) ? "vertex" : "fragment";
    throw runtime_error("Shader compilation failed (" + shaderType + "): " + infoLog);
  }

  return shader;
}

// Function to create a shader program
// Takes the paths to the vertex and fragment shader files as parameters
// Returns the created shader program ID
GLuint createShaderProgram(const string &vertexPath, const string &fragmentPath)
{
  // Read the shader source files
  string vertexSource = readShaderFile(vertexPath);
  string fragmentSource = readShaderFile(fragmentPath);

  // Compile the vertex and fragment shaders
  GLuint vertexShader = compileShader(GL_VERTEX_SHADER, vertexSource);
  GLuint fragmentShader = compileShader(GL_FRAGMENT_SHADER, fragmentSource);

  // Create a shader program and attach the shaders
  GLuint program = glCreateProgram();
  glAttachShader(program, vertexShader);
  glAttachShader(program, fragmentShader);
  glLinkProgram(program);

  // Check linking status
  GLint success;
  glGetProgramiv(program, GL_LINK_STATUS, &success);
  if (!success)
  {
    // Retrieve and print the error log
    GLchar infoLog[512];
    glGetProgramInfoLog(program, sizeof(infoLog), nullptr, infoLog);
    throw runtime_error("Shader program linking failed: " + string(infoLog));
  }

  // Cleanup: delete the shaders as they are now linked into the program
  glDeleteShader(vertexShader);
  glDeleteShader(fragmentShader);

  return program;
}