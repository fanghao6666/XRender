
// KeyBoard.cpp
// Created by Haony 2023/4/1

#include "KeyBoard.h"
#include "Log.h"
#include "Engine.h"

namespace XRender
{

KeyBoard::KeyBoard(XRenderEngine* engine, LPDIRECTINPUT8 input)
	: mEngine(engine),mDirectInput(input),mDirectDevice(nullptr)
{
	ZeroMemory(mCurrentState, sizeof(mCurrentState));
	ZeroMemory(mLastState, sizeof(mLastState));
}

KeyBoard::~KeyBoard()
{
	if (mDirectDevice)
	{
		mDirectDevice->Unacquire();
		mDirectDevice->Release();
		mDirectDevice = nullptr;
	}
}

bool KeyBoard::Init()
{
	if (FAILED(mDirectInput->CreateDevice(GUID_SysKeyboard, &mDirectDevice, nullptr)))
	{
		Log::Error("DirectInput KeyBoard Device Initialize Failed!");
		return false;
	}

	if (FAILED(mDirectDevice->SetDataFormat(&c_dfDIKeyboard)))
	{
		Log::Error("DirectInput KeyBoard Device SetDataFormat Failed!");
		return false;
	}

	if (FAILED(mDirectDevice->SetCooperativeLevel(mEngine->GetWindowHandle(), DISCL_FOREGROUND | DISCL_NONEXCLUSIVE)))
	{
		Log::Error("DirectInput KeyBoard Device SetCooperative Level Failed!");
		return false;
	}

	mDirectDevice->Acquire();

	return true;
}

void KeyBoard::Update()
{
	if (mDirectDevice)
	{
		memcpy(mLastState, mCurrentState, sizeof(mCurrentState));

		if (FAILED(mDirectDevice->GetDeviceState(sizeof(mCurrentState), (LPVOID)mCurrentState)))
		{
			if (SUCCEEDED(mDirectDevice->Acquire()))
			{
				mDirectDevice->GetDeviceState(sizeof(mCurrentState), (LPVOID)mCurrentState);
			}
		}
	}
}

bool KeyBoard::CurrentKeyDown(char key) const
{
	return ((mCurrentState[key] & 0x80) != 0);
}

bool KeyBoard::CurrentKeyUp(char key) const
{
	return ((mCurrentState[key] & 0x80) == 0);
}

bool KeyBoard::LastKeyDown(char key) const
{
	return ((mLastState[key] & 0x80) != 0);
}

bool KeyBoard::LastKeyUp(char key) const
{
	return ((mLastState[key] & 0x80) == 0);
}

bool KeyBoard::IsKeyPressed(char key) const
{
	return LastKeyUp(key) && CurrentKeyDown(key);
}

bool KeyBoard::IsKeyReleased(char key) const
{
	return LastKeyDown(key) && CurrentKeyUp(key);
}

bool KeyBoard::IsKeyHold(char key) const
{
	return LastKeyDown(key) && CurrentKeyDown(key);
}

}