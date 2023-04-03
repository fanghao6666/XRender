
// XRenderEngine.cpp
// Created by Haony 2023/3/28

#include "Engine.h"
#include "Log.h"
#include "Setting.h"
#include "KeyBoard.h"
#include "Mouse.h"
#include "Timer.h"
#include "Camera.h"
#include "Level.h"
#include <dinput.h>

namespace XRender
{

XRenderEngine::XRenderEngine(HINSTANCE instance,int showCommand)
	: mInstance(instance), mShowCommand(showCommand),mWindowHandle(),mWindow(),
	mTimer(nullptr),mKeyBoard(nullptr),mMouse(nullptr),mCamera(nullptr)
{
	
}

XRenderEngine::~XRenderEngine()
{
	for (auto& component : mComponents)
	{
		if (component)
		{
			delete component;
			component = nullptr;
		}
	}

	if (mTimer)
	{
		delete mTimer;
		mTimer = nullptr;
	}
}

bool XRenderEngine::Init()
{
	Log::Info("Engine Initialization...");

	mTimer = new Timer();

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

	if (!InitLevel())
	{
		Log::Error("Engine Init Scene Failed!");
		return false;
	}

	return true;
}

void XRenderEngine::Run()
{
	while (1)
	{

	}
}

void XRenderEngine::Update()
{

}

void XRenderEngine::Exit()
{

}

void XRenderEngine::SetLevel(const std::string& level)
{
	mCurrentLevel = level;
	mCamera->Reset();
	if (mGameLevel != nullptr)
	{
		delete mGameLevel;
		mGameLevel = nullptr;
	}

	mGameLevel = new Level(this, level);
	mGameLevel->Init();
	mComponents.push_back(mGameLevel);
}

bool XRenderEngine::InitWindow()
{
	Log::Info("Engine Initialize Window...");

	ZeroMemory(&mWindow, sizeof(mWindow));

	// window settings
	mWindow.cbSize = sizeof(WNDCLASSEX);
	mWindow.style = CS_CLASSDC;
	mWindow.lpfnWndProc = WndProc;
	mWindow.hInstance = mInstance;
	mWindow.hIcon = (HICON)LoadImage(NULL, L"IronMan.ico", IMAGE_ICON, 0, 0, LR_LOADFROMFILE);
	mWindow.hIconSm = (HICON)LoadImage(NULL, L"IronMan.ico", IMAGE_ICON, 0, 0, LR_LOADFROMFILE);
	mWindow.hCursor = LoadCursor(nullptr, IDC_ARROW);
	mWindow.hbrBackground = GetSysColorBrush(COLOR_BTNFACE);
	mWindow.lpszClassName = Setting::WindowClassName.c_str();

	DWORD dwStyle = (WS_OVERLAPPED | WS_CAPTION | WS_SYSMENU | WS_MINIMIZEBOX);
	RECT windowRect = { 0,0,static_cast<LONG>(Setting::WindowScreenWidth),static_cast<LONG>(Setting::WindowScreenHeight) };
	AdjustWindowRect(&windowRect, dwStyle, FALSE);
	
	RegisterClassEx(&mWindow);
	int screenWidth = GetSystemMetrics(SM_CXSCREEN);
	int screenHeight = GetSystemMetrics(SM_CYSCREEN);
	POINT center = { static_cast<LONG>((screenWidth - Setting::WindowScreenWidth) / 2),static_cast<LONG>((screenHeight - Setting::WindowScreenHeight) / 2) };
	mWindowHandle = CreateWindow(Setting::WindowClassName.c_str(), Setting::WindowTitleName.c_str(),
		dwStyle, center.x, center.y, windowRect.right - windowRect.left, windowRect.bottom - windowRect.top,
		nullptr, nullptr, mInstance, nullptr);

	ShowWindow(mWindowHandle, mShowCommand);
	UpdateWindow(mWindowHandle);
	SetWindowLongPtr(mWindowHandle, GWLP_USERDATA, reinterpret_cast<LONG_PTR>(this));

	return true;
}

bool XRenderEngine::InitRHI()
{
	Log::Info("Engine Initialize RHI...");

	return true;
}

bool XRenderEngine::InitComponent()
{
	Log::Info("Engine Initialize Components...");

	// Direct input
	if (FAILED(DirectInput8Create(mInstance, DIRECTINPUT_VERSION, IID_IDirectInput8, (LPVOID*)&mDirectInput, nullptr)))
	{
		Log::Error("Initialize DirectInput Failed!");
		return false;

		mKeyBoard = new KeyBoard(this, mDirectInput);
		mComponents.push_back(mKeyBoard);

		mMouse = new Mouse(this, mDirectInput);
		mComponents.push_back(mKeyBoard);
	}

	mCamera = new Camera(this);
	mComponents.push_back(mCamera);

	bool result = true;
	for (Component* component : mComponents)
	{
		result &= component->Init();
	}

	return result;
}

bool XRenderEngine::InitLevel()
{
	SetLevel(Setting::LevelStartSceneName);

	return true;
}

LRESULT WINAPI XRenderEngine::WndProc(HWND windowHandle, UINT message, WPARAM wParam, LPARAM lParam)
{
	return DefWindowProc(windowHandle, message, wParam, lParam);
}

}