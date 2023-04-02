#pragma once

// KeyBoard.h
// Created by Haony 2023/4/1

#include "Component.h"
#include <dinput.h>

namespace XRender
{
	class XRenderEngine;

	enum MouseButtons
	{
		MouseButtonsLeft	= 0,
		MouseButtonsRight	= 1,
		MouseButtonsMiddle	= 2,
		MouseButtonsX1		= 3
	};

	class Mouse : public Component
	{
	public:
		Mouse(XRenderEngine* engine,LPDIRECTINPUT8 input);
		Mouse(const Mouse& other) = delete;
		Mouse& operator=(const Mouse& other) = delete;
		virtual ~Mouse();

		virtual bool			Init() override;
		virtual void			Update() override;

		bool					CurrentButtonUp(MouseButtons button) const;
		bool					CurrentButtonDown(MouseButtons button) const;
		bool					LastButtonUp(MouseButtons button) const;
		bool					LastButtonDown(MouseButtons button) const;
		bool					IsButtonPressed(MouseButtons button) const;
		bool					IsButtonReleased(MouseButtons button) const;
		bool					IsButtonHold(MouseButtons button) const;

		LPDIMOUSESTATE			GetCurrentState();
		LPDIMOUSESTATE			GetLastState();

	private:
		XRenderEngine*			mEngine;

		LONG					mPosX;
		LONG					mPosY;
		LONG					mWheel;
		DIMOUSESTATE			mCurrentState;
		DIMOUSESTATE			mLastState;

		LPDIRECTINPUT8			mDirectInput;
		LPDIRECTINPUTDEVICE8	mDirectDevice;
	};

}