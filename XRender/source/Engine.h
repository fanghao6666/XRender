#pragma once
// XRenderEngine.h
// Created by Haony 2023/3/28

#include "Component.h"
#include <dinput.h>

namespace XRender
{
	class KeyBoard;
	class Mouse;
	class Timer;
	class Camera;
	class Level;

	class XRenderEngine
	{
	public:
		XRenderEngine(HINSTANCE instance,int showCommand);
		~XRenderEngine();
		
		bool					Init();
		void					Run();
		void					Update();
		void					Exit();

		void					SetLevel(const std::string& levelName);

	public:
		HINSTANCE				GetInstance() const { return mInstance; }
		HWND					GetWindowHandle() const { return mWindowHandle; }
		WNDCLASSEX				GetWindow() const { return mWindow; }
		KeyBoard*				GetKeyBoard() const { return mKeyBoard; }
		Mouse*					GetMouse() const { return mMouse; }
		Timer*					GetTimer() const { return mTimer; }
		
	private:
		bool					InitWindow();
		bool					InitRHI();
		bool					InitComponent();
		bool					InitLevel();
		static LRESULT WINAPI	WndProc(HWND windowHanldle, UINT message, WPARAM wParam, LPARAM lParam);

	private:
		ComponentPtrArray		mComponents;
		LPDIRECTINPUT8			mDirectInput;
		KeyBoard*				mKeyBoard;
		Mouse*					mMouse;
		Camera*					mCamera;
		Level*					mGameLevel;
		Timer*					mTimer;


		std::string				mCurrentLevel;

	private:
		HINSTANCE				mInstance;
		int						mShowCommand;
		HWND					mWindowHandle;
		WNDCLASSEX				mWindow;
	};
}