cmake_minimum_required (VERSION 3.30)
project(ayadep)

set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_STANDARD 23)

set(DILIGENT_NO_DIRECT3D11 YES)
set(DILIGENT_NO_DIRECT3D12 YES)
set(DILIGENT_NO_METAL YES)
set(DILIGENT_NO_OPENGL YES)

set(GLFW_BUILD_EXAMPLES OFF)
set(GLFW_BUILD_TESTS OFF)
set(GLFW_BUILD_DOCS OFF)
set(GLFW_BUILD_INSTALL OFF)

add_subdirectory(glfw)
add_subdirectory(DiligentCore)
add_subdirectory(DiligentTools)

