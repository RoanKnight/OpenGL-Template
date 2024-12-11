#include "glfw_utils.h"
#include <iostream>

using namespace std;

// Window dimensions
int canvasWidth = 800;
int canvasHeight = 600;

// Window background color
float bgColor[] = {0.1f, 0.1f, 0.1f, 1.0f};

// Function to get the window width
int getWindowWidth()
{
  return canvasWidth;
}

// Function to get the window height
int getWindowHeight()
{
  return canvasHeight;
}

// Function to set the background color
void setBGColor(float r, float g, float b, float a)
{
  bgColor[0] = r;
  bgColor[1] = g;
  bgColor[2] = b;
  bgColor[3] = a;
}

// Function to get the current background color
void getBGColor(float &r, float &g, float &b, float &a)
{
  r = bgColor[0];
  g = bgColor[1];
  b = bgColor[2];
  a = bgColor[3];
}

// Function to clear the window with the current background color
void clearWindow()
{
  glClearColor(bgColor[0], bgColor[1], bgColor[2], bgColor[3]);
  glClear(GL_COLOR_BUFFER_BIT);
}

// Callback function for when the framebuffer is resized
void framebufferSizeCallback(GLFWwindow *window, int width, int height)
{
  canvasWidth = width;
  canvasHeight = height;
  glViewport(0, 0, width, height);
  clearWindow();
  glfwSwapBuffers(window);
}

// Callback function for GLFW errors
void glfwErrorCallback(int error, const char *description)
{
  cerr << "GLFW Error (" << error << "): " << description << endl;
}

// Function to initialize GLFW, create a window, and return a pointer to the window
GLFWwindow *initializeGLFW()
{
  // Set the error callback function
  glfwSetErrorCallback(glfwErrorCallback);

  // Initialize GLFW
  if (!glfwInit())
  {
    cerr << "Failed to initialize GLFW" << endl;
    return nullptr;
  }

  // Set GLFW window hints for OpenGL version and profile
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
  glfwWindowHint(GLFW_RESIZABLE, GLFW_TRUE);

  // Create a GLFW window
  GLFWwindow *window = glfwCreateWindow(canvasWidth, canvasHeight, "OpenGL Window", nullptr, nullptr);
  if (!window)
  {
    cerr << "Failed to create GLFW window" << endl;
    glfwTerminate();
    return nullptr;
  }

  // Make the OpenGL context current
  glfwMakeContextCurrent(window);

  // Initialize GLAD to load OpenGL function pointers
  if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
  {
    cerr << "Failed to initialize GLAD" << endl;
    glfwDestroyWindow(window);
    glfwTerminate();
    return nullptr;
  }

  // Set the framebuffer size callback function
  glfwSetFramebufferSizeCallback(window, framebufferSizeCallback);

  // Set the initial viewport and clear color
  glViewport(0, 0, canvasWidth, canvasHeight);
  glClearColor(bgColor[0], bgColor[1], bgColor[2], bgColor[3]);

  // Return the created window
  return window;
}