add_executable(aya "aya.cpp")
target_sources(aya PRIVATE FILE_SET CXX_MODULES FILES window.ixx engine.ixx)

set_target_properties(aya PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/${TargetName}/"    
)

include_directories(${CMAKE_SOURCE_DIR}/external/glfw/include)
include_directories(${CMAKE_SOURCE_DIR}/external/DiligentCore)
include_directories(${CMAKE_SOURCE_DIR}/external/DiligentTools)

set(CMAKE_PREFIX_PATH "${CMAKE_SOURCE_DIR}/external/build")
add_definitions(-DPLATFORM_WIN32=1)

if(CMAKE_BUILD_TYPE STREQUAL "Debug")
    set(engineVkbase "GraphicsEngineVk_64d")
else(CMAKE_BUILD_TYPE STREQUAL "Release")
    set(engineVkbase "GraphicsEngineVk_64r")
endif()
set(engineVklib "${engineVkbase}.lib")
set(engineVkdll "${engineVkbase}.dll")

set(glfw_lib "${EXTERNAL_BUILD_DIR}/glfw/src/${CMAKE_BUILD_TYPE}/glfw3.lib")
set(diligentcore_lib "${EXTERNAL_BUILD_DIR}/DiligentCore/${CMAKE_BUILD_TYPE}/DiligentCore.lib")
set(diligentvkstatic_lib "${EXTERNAL_BUILD_DIR}/DiligentCore/Graphics/GraphicsEngineVulkan/${CMAKE_BUILD_TYPE}/${engineVklib}")
set(diligentimgui_lib "${EXTERNAL_BUILD_DIR}/DiligentTools/Imgui/${CMAKE_BUILD_TYPE}/Diligent-Imgui.lib")


set(diligentvk_dll "${EXTERNAL_BUILD_DIR}/DiligentCore/Graphics/GraphicsEngineVulkan/${CMAKE_BUILD_TYPE}/${engineVkdll}")

target_link_libraries(aya ${glfw_lib} ${diligentvkstatic_lib} ${diligentimgui_lib} ${diligentcore_lib}) 

target_include_directories(aya PRIVATE 
    ${CMAKE_BINARY_DIR}
)

add_custom_command(TARGET aya POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
    $<$<CONFIG:Debug>:${diligentvk_dll}>
    $<$<CONFIG:Release>:${diligentvk_dll}>
    $<TARGET_FILE_DIR:aya>
)



