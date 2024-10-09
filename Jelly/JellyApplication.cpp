#include "JellyApplication.h"

namespace Jelly
{
	void JellyApplication::Run()
	{
		Initialize();

		while (ShouldContinue)
		{
			Update();
		}

		Shutdown();
	}


	void JellyApplication::Initialize()
	{
	}


	void JellyApplication::Update()
	{
	}


	void JellyApplication::Shutdown()
	{
	}


}