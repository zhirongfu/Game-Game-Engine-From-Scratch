#pragma once

#include "pch.h"
#include "JellyUtilities.h"

constexpr int FPS_RATE{ 60 };

namespace Jelly
{
	class JELLY_API JellyApplication
	{
	public:
		void Run();
		virtual void Initialize();
		virtual void Update();
		virtual void Shutdown();

	private:
		bool mShouldContinue{ true };

		std::chrono::steady_clock::time_point mNextFrameTime;
		std::chrono::milliseconds mFrameDuration{ std::chrono::milliseconds{1000} / FPS_RATE };

	};
}