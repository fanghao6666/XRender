#pragma once

// Component.h
// Created by Haony 2023/3/28

#include <vector>

namespace XRender
{
	class XRenderEngine;

	class Component
	{
	public:
		Component();
		Component(XRenderEngine* engine);
		Component(const Component& other) = delete;
		Component& operator=(const Component& other) = delete;
		virtual ~Component();

		virtual bool	Init();
		virtual void	Update();

		void			SetEngine(XRenderEngine* engine) { mEngine = engine; }
		XRenderEngine*	GetEngine() { return mEngine; }
		void			SetEnable(bool enable) { mEnabled = enable; }
		bool			IsEnabled() const { return mEnabled; };
		
	private:
		XRenderEngine*	mEngine;
		bool			mEnabled;
	};

	using ComponentPtrArray = std::vector<Component*>;
}