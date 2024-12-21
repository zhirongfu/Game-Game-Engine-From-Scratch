#include"Jelly.h"
#include<iostream>

class MyGameApplication : public Jelly::JellyApplication
{
	virtual void Initialize() override
	{
		JELLY_LOG("Starting...");

		//Jelly::JellyWindow::Init();
		//Jelly::JellyWindow::GetWindow() ->CreateWindow(800, 600, "test");
		SetKeyEventHandler([this](const Jelly::KeyEvent& event) { MyKeysHandler(event); });
	}

	virtual void Update() override
	{
		//std::cout << "hello";
		Jelly::Renderer::Draw(pic);

	}
private:
	Jelly::Unit pic{ "../Jelly/JellyAssets/Images/Jelly.png", 100, 100 };
	void MyKeysHandler(const Jelly::KeyEvent& event)
	{
		if (event.GetKeyAction() == Jelly::KeyEvent::KeyAction::Press)
		{
			switch (event.GetKeyCode())
			{
			case JELLY_KEY_LEFT:
				pic.UpdateXCoord(-10);
				break;
			case JELLY_KEY_RIGHT:
				pic.UpdateXCoord(10);
				break;
			}
		}
	}

};

JELLY_GAME_START(MyGameApplication)