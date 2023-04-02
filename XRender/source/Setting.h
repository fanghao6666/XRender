#pragma once
// Setting.h
// Created by Haony 2023/3/29
#include <string>
#include <DirectXMath.h>
#include "XMath.h"

namespace XRender
{
	class Setting
	{
	public:
		// window
		static std::wstring WindowClassName;
		static std::wstring WindowTitleName;
		static bool WindowFullScreen;
		static uint32_t WindowScreenWidth;
		static uint32_t WindowScreenHeight;

		// camera
		static Vector3f CameraPosition;
		static Vector3f CameraDirection;
		static Vector3f CameraUp;
		static Vector3f CameraRight;
		static float CameraFOV;
		static float CameraAspectRatio;
		static float CameraNearPlaneDist;
		static float CameraFarPlaneDist;
		static float CameraMouseSensitivity;
		static float CameraMovementRate;
		static float CameraRotationRate;
	};
}