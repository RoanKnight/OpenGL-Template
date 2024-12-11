# C++ OpenGL Project Template

This is a template for C++ projects that utilize OpenGL for rendering. It provides a structured setup with commonly used libraries to help you get started quickly.

## External Libraries

In the `lib` folder, you will find the libraries you might use for these types of projects:

- **Glad**: A library that helps in loading OpenGL function pointers. It is essential for initializing OpenGL and using its functions.
- **GLFW**: A library for creating windows, contexts, and handling input. It is used to create the window where the rendering will take place.
- **GLM**: A mathematics library for graphics software based on the OpenGL Shading Language (GLSL) specifications. It provides vector and matrix operations that are useful for various graphics calculations.
- **Bullet Physics**: A physics engine that provides collision detection and rigid body dynamics. It is used to simulate physical interactions in the project.
- **Stb Master**: A collection of single-file libraries for various tasks, such as image loading and font rendering. It is used to handle image assets and text rendering in the project.
- **OpenCL SDK Light**: A lightweight version of the OpenCL SDK, which provides tools and libraries for parallel computing on heterogeneous systems. It is used to accelerate computations in the project.

## Potential Uses

With this setup, you can create a variety of projects such as:

- **Particle simulations**: Simulate and render large numbers of small particles to model phenomena like smoke, fire, water, or other fluid dynamics.
- **3D graphics and animations**: Create and animate 3D models and scenes, useful for applications like games, simulations, and visual effects.
- **Physics-based simulations**: Simulate physical interactions and dynamics, such as collisions, gravity, and other forces, to create realistic motion and behavior.
- **Interactive applications and games**: Develop applications and games that respond to user input and provide real-time feedback and interaction.
- **Visualization tools**: Create tools to visualize complex data sets, such as scientific data, engineering models, or any other data that benefits from graphical representation.

## Requirements

- CMake Tools extension for Visual Studio Code

## Getting Set Up

### Option 1: Direct Download

1. Download this repository.
2. Extract the zipped folder to a location of your choice.

### Option 2: Git Clone

1. Open Microsoft Terminal, Command Prompt, or Control Panel.
2. Navigate to the directory of your choice and run the following command to clone the repository:
   ```sh
   git clone <repository-url>

# Renaming the Project to Suit Your Specific Needs

When renaming your project, you will need to change some files and rebuild the project using CMake.

Open the CMakeLists.txt file and replace all instances of "OpenGL-Template" with the name of your project.

In Visual Studio Code, if you have the CMake Tools extension installed, you should see a small 'play' icon at the bottom of the window. Click it.

When prompted, use the default build/configuration. This will build the project using CMake.