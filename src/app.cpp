#include "app.h"
#include "glfw_utils.h"
#include <glad/glad.h>
#include <GLFW/glfw3.h>

// Constructor: Initializes the application
App::App() = default;

// Destructor: Cleans up resources used by the application
App::~App()
{
  // Terminate GLFW to clean up any resources allocated by GLFW
  glfwTerminate();
}

// The run method: Starts the main loop of the application
int App::run()
{
  // Initialize GLFW and create a window
  GLFWwindow *window = initializeGLFW();
  if (!window)
    return -1;

  // Disable V-Sync
  glfwSwapInterval(0);

  // Get the current time to manage frame timing
  double lastTime = glfwGetTime();
  double targetFPS = 144.0;                 // Target frames per second
  double targetFrameTime = 1.0 / targetFPS; // Time per frame

  // Main loop: Runs until the window should close
  while (!glfwWindowShouldClose(window))
  {
    // Get the current time and calculate the time difference since the last frame
    double currentTime = glfwGetTime();
    double deltaTime = currentTime - lastTime;

    // If enough time has passed for the next frame
    if (deltaTime >= targetFrameTime)
    {
      // Clear the window
      clearWindow();

      // Swap the front and back buffers
      glfwSwapBuffers(window);

      // Poll for and process events
      glfwPollEvents();
      // Update the last time to the current time
      lastTime = currentTime;
    }
  }

  // Return success code
  return 0;
}