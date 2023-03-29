#include <windows.h>
#include <stdlib.h>
#include "source/Engine.h"
#include <memory>

using namespace XRender;

int WINAPI WinMain(HINSTANCE instance, HINSTANCE previousInstance, LPSTR commandLine, int showCommand)
{
	auto engine = std::make_unique<XRenderEngine>(new XRenderEngine(instance,showCommand));

	if (!engine->Init())
	{
		return 1;
	}

	engine->Run();

	return 0;
}