cmake_minimum_required (VERSION 3.30)
include(FetchContent)

# Enable Hot Reload for MSVC compilers if supported.
if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()

project ("aya")

add_subdirectory(external/glfw)
add_subdirectory(external/DiligentCore)
add_subdirectory(external/DiligentTools)

add_executable(aya "aya.cpp" )
set_property(TARGET aya PROPERTY CXX_STANDARD 23)

