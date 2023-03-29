// Timer.cpp
// Created by Haony 2023/3/29

#include "Timer.h"

namespace XRender
{

Timer::Timer()
	: mStartTime(), mCurrentTime(), mLastTime(),
	  mTotalTime(0.0),mElapsedTime(0.0)
{
	mFrequency = GetFrequency();
	ResetTime();
}

Timer::~Timer()
{

}

void Timer::GetTime(LARGE_INTEGER& time) const
{
	QueryPerformanceCounter(&time);
}

double Timer::GetFrequency() const
{
	LARGE_INTEGER frequency;
	QueryPerformanceFrequency(&frequency);

	return static_cast<double>(frequency.QuadPart);
}

void Timer::ResetTime()
{
	GetTime(mStartTime);
	mCurrentTime = mStartTime;
	mLastTime = mCurrentTime;
}

void Timer::UpdateTime()
{
	GetTime(mCurrentTime);
	mTotalTime = static_cast<double>(mCurrentTime.QuadPart - mStartTime.QuadPart) / mFrequency;
	mElapsedTime = static_cast<double>(mCurrentTime.QuadPart - mLastTime.QuadPart) / mFrequency;
	mLastTime = mCurrentTime;
}

}