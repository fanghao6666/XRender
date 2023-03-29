#pragma once
// Setting.h
// Created by Haony 2023/3/29
#include <string>

namespace XRender
{
	class Setting
	{
		// window
		static std::wstring WindowClassName;
		static std::wstring WindowTitleName;
		static bool FullScreen;
	};


	std::wstring Setting::WindowClassName = L"XRender Main Window";
	std::wstring Setting::WindowTitleName = L"XRender Engine";
	bool Setting::FullScreen = false;
}