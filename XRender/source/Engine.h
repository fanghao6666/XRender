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

	private:
		bool					InitWindow();
		bool					InitRHI();
		bool					InitComponent();
		static LRESULT WINAPI	WndProc(HWND windowHanldle, UINT message, WPARAM wParam, LPARAM lParam);

	private:
		ComponentPtrArray		mComponents;

		Timer					mTimer;

	private:
		HINSTANCE				mInstance;
		int						mShowCommand;
		HWND					mWindowHandle;
		WNDCLASSEX				mWindow;
	};
}