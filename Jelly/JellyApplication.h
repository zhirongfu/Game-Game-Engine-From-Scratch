#pragma once

#include "JellyUtilities.h"

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
		bool ShouldContinue{ true };

	};
}