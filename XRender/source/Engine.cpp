
// XRenderEngine.cpp
// Created by Haony 2023/3/28


#include "Engine.h"
#include "Log.h"

namespace XRender
{

XRenderEngine::XRenderEngine(HINSTANCE instance,int showCommand)
	: mInstance(instance), mShowCommand(showCommand)
{

}

XRenderEngine::~XRenderEngine()
{

}

bool XRenderEngine::Init()
{
	Log::Info("Engine Initialization...");

	if (!InitWindow())
	{
		Log::Error("Engine Init Window Failed!");
		return false;
	}

	if (!InitRHI())
	{
		Log::Error("Engine Init RHI Failed!");
		return false;
	}

	if (!InitComponent())
	{
		Log::Error("Engine Init Components Failed!");
		return false;
	}

	return true;
}

void XRenderEngine::Run()
{

}

void XRenderEngine::Update()
{

}

void XRenderEngine::Exit()
{

}

bool XRenderEngine::InitWindow()
{

}

bool XRenderEngine::InitRHI()
{

}

bool XRenderEngine::InitComponent()
{

}

}