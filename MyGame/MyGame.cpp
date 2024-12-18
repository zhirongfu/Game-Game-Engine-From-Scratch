#include"Jelly.h"
#include<iostream>

class MyGameApplication : public Jelly::JellyApplication
{
	virtual void Initialize() override
	{
		JELLY_LOG("Starting...");

		Jelly::JellyWindow::Init();
		Jelly::JellyWindow::GetWindow() ->CreateWindow(800, 600, "test");
	}

	virtual void Update() override
	{

	}

};

JELLY_GAME_START(MyGameApplication)