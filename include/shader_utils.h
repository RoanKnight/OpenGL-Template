#ifndef SHADER_UTILS_H
#define SHADER_UTILS_H

#include <glad/glad.h>
#include <string>

// Read shader source from file
std::string readShaderFile(const std::string& filename);

// Create and compile shader
GLuint compileShader(GLenum type, const std::string& source);

// Create shader program from vertex and fragment shaders
GLuint createShaderProgram(const std::string& vertexPath, const std::string& fragmentPath);

#endif