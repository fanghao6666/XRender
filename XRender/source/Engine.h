#pragma once

// XRenderEngine.h
// Created by Haony 2023/3/28
#include "Component.h"
#include "Timer.h"

namespace XRender
{
	class XRenderEngine
	{
	public:
		XRenderEngine(HINSTANCE instance,int showCommand);
		~XRenderEngine();

		
		bool					Init();
		void					Run();
		void					Update();
		void					Exit();

	protected:
		bool					InitWindow();
		bool					InitRHI();
		bool					InitComponent();

	private:
		ComponentPtrArray		mComponents;

	private:
		Timer					mTimer;

	private:
		HINSTANCE				mInstance;
		int						mShowCommand;
		HWND					mWindowHandle;
		WNDCLASSEX				mWindow;
	};
}