//Mouse.cpp
// Created by Haony 2023/4/1

#include "Mouse.h"
#include "Log.h"
#include "Engine.h"

namespace XRender
{

Mouse::Mouse(XRenderEngine* engine, LPDIRECTINPUT8 input)
	: mEngine(engine),mDirectInput(input),mDirectDevice(nullptr),
	mPosX(0),mPosY(0),mWheel(0)
{
	ZeroMemory(&mCurrentState, sizeof(mCurrentState));
	ZeroMemory(&mLastState, sizeof(mLastState));
}

Mouse::~Mouse()
{
	if (mDirectDevice)
	{
		mDirectDevice->Unacquire();
		mDirectDevice->Release();
		mDirectDevice = nullptr;
	}
}

bool Mouse::Init()
{
	if (FAILED(mDirectInput->CreateDevice(GUID_SysMouse, &mDirectDevice, nullptr)))
	{
		Log::Error("DirectInput Mouse Device Initialize Failed!");
		return false;
	}

	if (FAILED(mDirectDevice->SetDataFormat(&c_dfDIMouse)))
	{
		Log::Error("DirectInput Mouse Device SetDataFormat Failed!");
		return false;
	}

	if (FAILED(mDirectDevice->SetCooperativeLevel(mEngine->GetWindowHandle(), DISCL_FOREGROUND | DISCL_NONEXCLUSIVE)))
	{
		Log::Error("DirectInput Mouse Device SetCooperative Level Failed!");
		return false;
	}

	mDirectDevice->Acquire();

	return true;
}

void Mouse::Update()
{
	if (mDirectDevice)
	{
		memcpy(&mLastState, &mCurrentState, sizeof(mCurrentState));

		if (FAILED(mDirectDevice->GetDeviceState(sizeof(mCurrentState), &mCurrentState)))
		{
			if (SUCCEEDED(mDirectDevice->Acquire()))
			{
				if (FAILED(mDirectDevice->GetDeviceState(sizeof(mCurrentState), &mCurrentState)))
				{
					mPosX += mCurrentState.lX;
					mPosY += mCurrentState.lY;
					mWheel += mCurrentState.lZ;
				}
			}
		}
	}
}

bool Mouse::CurrentButtonUp(MouseButtons button) const
{
	return ((mCurrentState.rgbButtons[button] & 0x80) == 0);
}

bool Mouse::CurrentButtonDown(MouseButtons button) const
{
	return ((mCurrentState.rgbButtons[button] & 0x80) != 0);
}

bool Mouse::LastButtonUp(MouseButtons button) const
{
	return ((mLastState.rgbButtons[button] & 0x80) == 0);
}

bool Mouse::LastButtonDown(MouseButtons button) const
{
	return ((mLastState.rgbButtons[button] & 0x80) != 0);
}

bool Mouse::IsButtonPressed(MouseButtons button) const
{
	return LastButtonUp(button) && CurrentButtonDown(button);
}

bool Mouse::IsButtonReleased(MouseButtons button) const
{
	return LastButtonDown(button) && CurrentButtonUp(button);
}

bool Mouse::IsButtonHold(MouseButtons button) const
{
	return LastButtonDown(button) && CurrentButtonDown(button);
}

LPDIMOUSESTATE Mouse::GetCurrentState()
{
	return &mCurrentState;
}

LPDIMOUSESTATE Mouse::GetLastState()
{
	return &mLastState;
}

}