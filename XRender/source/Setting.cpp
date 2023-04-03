#pragma once
// Setting.h
// Created by Haony 2023/3/29
#include "Setting.h"
#include <DirectXMath.h>


namespace XRender
{
	// Window
	std::wstring Setting::WindowClassName = L"XRender Main Window";
	std::wstring Setting::WindowTitleName = L"XRender Engine";
	bool Setting::WindowFullScreen = false;
	uint32_t Setting::WindowScreenWidth = 1920;
	uint32_t Setting::WindowScreenHeight = 1080;

	// Camera
	float Setting::CameraFOV = DirectX::XM_PIDIV2;
	float Setting::CameraAspectRatio = 1920.0f / 1080.0f;
	float Setting::CameraNearPlaneDist = 0.01f;
	float Setting::CameraFarPlaneDist = 1000.0f;
	float Setting::CameraMouseSensitivity = 50.0f;
	float Setting::CameraMovementRate = DirectX::XMConvertToRadians(1.0f);
	float Setting::CameraRotationRate = 10.0f;

	// Level
	std::string Setting::LevelStartSceneName = "";
}