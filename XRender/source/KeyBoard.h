#pragma once
// KeyBoard.h
// Created by Haony 2023/4/1

#include "Component.h"
#include <dinput.h>

static const int KeyCount = 256;

namespace XRender
{
	class XRenderEngine;

	class KeyBoard : public Component
	{
	public:
		KeyBoard(XRenderEngine* engine,LPDIRECTINPUT8 input);
		KeyBoard(const KeyBoard& other) = delete;
		KeyBoard& operator=(const KeyBoard& other) = delete;
		virtual ~KeyBoard();


		virtual bool			Init() override;
		virtual void			Update() override;

		bool					CurrentKeyDown(char key) const;
		bool					CurrentKeyUp(char key) const;
		bool					LastKeyDown(char key) const;
		bool					LastKeyUp(char key) const;
		bool					IsKeyPressed(char key) const;
		bool					IsKeyReleased(char key) const;
		bool					IsKeyHold(char key) const;

	private:
		XRenderEngine*			mEngine;

		char					mCurrentState[KeyCount];
		char					mLastState[KeyCount];

		LPDIRECTINPUT8			mDirectInput;
		LPDIRECTINPUTDEVICE8	mDirectDevice;
	};

}