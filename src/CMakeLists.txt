add_executable(aya "aya.cpp")
target_sources(aya PRIVATE FILE_SET CXX_MODULES FILES window.ixx engine.ixx)

set_target_properties(aya PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/${TargetName}/"    
)

include_directories("glfw/include")
include_directories(DiligentCore)

target_include_directories(aya PRIVATE 
			${CMAKE_BINARY_DIR})
target_link_libraries(aya
  glfw
  Diligent-GraphicsEngineVk-static
)


