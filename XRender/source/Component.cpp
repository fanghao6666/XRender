#pragma once

// Component.cpp
// Created by Haony 2023/3/28

#include "Component.h"

namespace XRender
{

Component::Component()
	: mEngine(nullptr),
	  mEnabled(true)
{

}

Component::Component(XRenderEngine* engine)
	: mEngine(engine),
	  mEnabled(true)
{

}

Component::~Component()
{

}

bool Component::Init()
{
	return true;
}

void Component::Update()
{

}

}