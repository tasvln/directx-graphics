cmake_minimum_required(VERSION 3.14)
project(DIRECTX3D)

# C++ standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Output directories
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG ${CMAKE_BINARY_DIR}/bin/Debug)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE ${CMAKE_BINARY_DIR}/bin/Release)

# Include directories
include_directories(
    ${PROJECT_SOURCE_DIR}/include
    ${PROJECT_SOURCE_DIR}/src
)

# Add source files
file(GLOB_RECURSE FILES
    src/*.cpp
    src/*.hpp
    include/*.hpp
)

# Add executable
add_executable(
    DIRECTX3D 
    ${FILES}
)

# Link Windows libraries
target_link_libraries(DIRECTX3D
    user32
    gdi32       # Common for window creation
    d3d12       # DirectX 12
    dxgi        # DXGI interface
    d3dcompiler # Shader compiler
)

# Define UNICODE
target_compile_definitions(DIRECTX3D PRIVATE UNICODE _UNICODE)

# (uses WinMain instead of main)
set_target_properties(DIRECTX3D PROPERTIES
    WIN32_EXECUTABLE TRUE
)