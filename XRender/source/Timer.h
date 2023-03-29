#pragma once
// Timer.h
// Created by Haony 2023/3/29

#include <windows.h>

namespace XRender
{
	class Timer
	{
	public:
		Timer();
		Timer(const Timer& other) = delete;
		Timer& operator=(const Timer& other) = delete;
		~Timer();

		const LARGE_INTEGER&	StartTime() const { return mStartTime; }
		const LARGE_INTEGER&	CurrentTime() const { return mCurrentTime; }
		const LARGE_INTEGER&	LastTime() const { return mLastTime; }
		double					TotalTime() const { return mTotalTime; }
		double					ElapsedTime() const { return mElapsedTime; }

		void					SetTotalTime(double time) { mTotalTime = time; }
		void					SetElapsedTime(double time) { mElapsedTime = time; }
		void					ResetTime();
		void					UpdateTime();
	
	private:
		void					GetTime(LARGE_INTEGER& time) const;
		double					GetFrequency() const;

	private:
		LARGE_INTEGER			mStartTime;
		LARGE_INTEGER			mCurrentTime;
		LARGE_INTEGER			mLastTime;

		double					mTotalTime;
		double					mElapsedTime;
		double					mFrequency;
	};

}