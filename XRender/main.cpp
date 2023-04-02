#include <windows.h>
#include "source/Engine.h"
#include <memory>

int WINAPI WinMain(HINSTANCE instance, HINSTANCE previousInstance, LPSTR commandLine, int showCommand)
{
	std::unique_ptr<XRender::XRenderEngine> engine(new XRender::XRenderEngine(instance,showCommand));

	if (!engine->Init())
	{
		return 1;
	}

	engine->Run();

	return 0;
}