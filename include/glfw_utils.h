#ifndef GLFW_UTILS_H
#define GLFW_UTILS_H

#include <glad/glad.h>
#include <GLFW/glfw3.h>

// Window dimension getters
int getWindowWidth();
int getWindowHeight();

// Background color getters/setters
void setBGColor(float r, float g, float b, float a);
void getBGColor(float &r, float &g, float &b, float &a);

// Clears the window with the current background color
void clearWindow();

// Callback functions
void glfwErrorCallback(int error, const char *description);

// Callback for when the framebuffer is resized, adjusts the viewport
void framebufferSizeCallback(GLFWwindow *window, int width, int height);

// Initializes GLFW, creates a window, and returns a pointer to the window
GLFWwindow *initializeGLFW();

#endif