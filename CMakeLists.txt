cmake_minimum_required(VERSION 3.20)
project(OpenGL-Template VERSION 1.0 LANGUAGES C CXX)

# Enable testing
enable_testing()

# Set C++ standard globally
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Set C standard
set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)

# Find OpenGL
find_package(OpenGL REQUIRED)

# Set output directories
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)

# Add external libraries
add_subdirectory("lib/glfw-master" "glfw-build" EXCLUDE_FROM_ALL)
add_subdirectory("lib/glm-master" EXCLUDE_FROM_ALL)
add_subdirectory("lib/bullet3-master" "bullet-build" EXCLUDE_FROM_ALL)

# Add GLAD source
set(GLAD_DIR ${CMAKE_SOURCE_DIR}/lib/GLAD)
add_library(glad STATIC ${GLAD_DIR}/src/glad.c)
target_include_directories(glad PRIVATE ${GLAD_DIR}/include)

# Source files
set(SOURCES
    src/main.cpp
    src/glfw_utils.cpp
    src/bullet_utils.cpp
    src/shader_utils.cpp
    src/app.cpp
)

# Create executable
add_executable(${PROJECT_NAME} ${SOURCES})

# Add include directories
target_include_directories(${PROJECT_NAME} PRIVATE
    ${CMAKE_SOURCE_DIR}/include
    ${CMAKE_SOURCE_DIR}/lib/stb-master
    ${CMAKE_SOURCE_DIR}/lib/OCL_SDK_Light/include
    ${CMAKE_SOURCE_DIR}/lib/bullet3-master/src
    ${GLAD_DIR}/include
)

# Add compile definitions
target_compile_definitions(${PROJECT_NAME} PRIVATE
    GLM_FORCE_RADIANS
    BT_USE_DOUBLE_PRECISION
)

# Link libraries
target_link_libraries(${PROJECT_NAME} PRIVATE
    glfw
    glad
    glm
    BulletDynamics
    BulletCollision
    LinearMath
    OpenGL::GL
    ${CMAKE_SOURCE_DIR}/lib/OCL_SDK_Light/lib/x86_64/OpenCL.lib
)