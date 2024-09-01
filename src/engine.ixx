module;

#include <GLFW/glfw3.h>
#define GLFW_EXPOSE_NATIVE_WIN32
#include <GLFW/glfw3native.h>

#include <iostream>

#include <EngineFactoryVk.h>

export module engine;

using namespace Diligent;

export void init_engine(const NativeWindow* pWindow)
{
	std::cout << "Initializing engine" << std::endl;

}
