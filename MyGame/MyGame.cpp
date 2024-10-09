#include"Jelly.h"
#include<iostream>

class MyGameApplication : public Jelly::JellyApplication
{
	virtual void Initialize() override
	{
		std::cout << "Starting..." << std::endl;
	}

	virtual void Update() override
	{

	}

};

JELLY_GAME_START(MyGameApplication)