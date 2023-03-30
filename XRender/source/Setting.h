#pragma once
// Setting.h
// Created by Haony 2023/3/29
#include <string>

namespace XRender
{
	class Setting
	{
	public:
		// window
		static std::wstring WindowClassName;
		static std::wstring WindowTitleName;
		static bool FullScreen;
		static UINT ScreenWidth;
		static UINT ScreenHeight;
	};


	std::wstring Setting::WindowClassName = L"XRender Main Window";
	std::wstring Setting::WindowTitleName = L"XRender Engine";
	bool Setting::FullScreen = false;
	UINT Setting::ScreenWidth = 1920;
	UINT Setting::ScreenHeight = 1080;
}