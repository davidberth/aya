cmake_minimum_required (VERSION 3.30)

project (aya LANGUAGES CXX C VERSION 0.1.0)

set(EXTERNAL_BUILD_DIR "" CACHE PATH "Path to the external build directory")

set (APPNAME ${PROJECT_NAME})
set (APPVERSION ${PROJECT_VERSION})

set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_STANDARD 23)

add_subdirectory(configure)
add_subdirectory(src)

if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()



