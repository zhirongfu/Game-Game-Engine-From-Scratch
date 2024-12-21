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
		SpawnAliens();
	}


	virtual void Update() override
	{
		if (activeKeys.count(JELLY_KEY_LEFT))
		{
			player.UpdateXCoord(-speed);
		}
		if (activeKeys.count(JELLY_KEY_RIGHT))
		{
			player.UpdateXCoord(speed);
		}
		if (activeKeys.count(JELLY_KEY_UP))
		{
			player.UpdateYCoord(speed);
		}
		if (activeKeys.count(JELLY_KEY_DOWN))
		{
			player.UpdateYCoord(-speed);
		}
		//std::cout << "hello";
		auto [clampedX, clampedY] = ClampPosition(player.GetXCoord(), player.GetYCoord(), 800 - player.GetWidth(), 600 - player.GetHeight());
		player.SetCoords(clampedX,clampedY);

		for (auto& bullet : bullets)
			bullet.UpdateYCoord(10);

		bullets.erase(std::remove_if(bullets.begin(), bullets.end(),
			[](const Jelly::Unit& b) { return b.GetYCoord() > 600; }),
			bullets.end());

		for (auto& bullet : bullets)
			Jelly::Renderer::Draw(bullet);

		for (auto& alien : aliens)
			alien.UpdateYCoord(-3);

		for (auto& bullet : bullets)
		{
			for (auto it = aliens.begin(); it != aliens.end();)
			{
				if (UnitsOverlap(bullet, *it)) // Check for collision
				{
					it = aliens.erase(it); // Remove alien
					score += 10; // Increase score
				}
				else
				{
					++it;
				}
			}
		}

		for (auto& alien : aliens)
		{
			if (alien.GetYCoord() < 0 || UnitsOverlap(alien, player)) // Alien reaches bottom
			{
				
				ResetGame();
				return;
			}
		}
		if (aliens.empty()) // All aliens destroyed
		{
			SpawnAliens(); // Respawn new wave of aliens
			speed += 1;// Add speed once you've cleared a wave
		}

		Jelly::Renderer::Draw(player);

		for (auto& alien : aliens)
			Jelly::Renderer::Draw(alien);

	}
	std::pair<int, int> ClampPosition(int x, int y, int width, int height)
	{
		if (x < 0) x = 0;
		if (y < 0) y = 0;
		if (x > width) x = width;
		if (y > height) y = height;
		return { x, y };
	}
private:
	Jelly::Unit player{ "../Jelly/JellyAssets/Images/Ship.png",365 , 25 };
	std::set<int> activeKeys;
	std::vector<Jelly::Unit> bullets;
	std::vector<Jelly::Unit> aliens;
	int score = 0; // Player's score
	int speed = 10;
	void MyKeysHandler(const Jelly::KeyEvent& event)
	{
		if (event.GetKeyAction() == Jelly::KeyEvent::KeyAction::Press)
		{
			activeKeys.insert(event.GetKeyCode());
			if (event.GetKeyCode() == JELLY_KEY_SPACE) // Shoot bullet
			{
				bullets.emplace_back("../Jelly/JellyAssets/Images/Bullet.png", player.GetXCoord() + 25, player.GetYCoord() - 10);
			}
		}
		else if (event.GetKeyAction() == Jelly::KeyEvent::KeyAction::Release)
		{
			activeKeys.erase(event.GetKeyCode());
		}
	}
	void SpawnAliens()
	{
		aliens.clear();
		aliens.shrink_to_fit();
		bullets.shrink_to_fit();
		std::random_device rd;
		std::mt19937 gen(rd()); // Initialize random number generator
		std::uniform_int_distribution<> distX(50, 750); // Range for X-coordinates
		std::uniform_int_distribution<> distY(400, 550); 

		int numAliens = 5 + (score / 50);
		for (int i = 0; i < numAliens; i++)
		{
			aliens.emplace_back("../Jelly/JellyAssets/Images/EnemyShip.png", distX(gen), distY(gen));
		}
	}
	void ResetGame()
	{
		score = 0;
		speed = 10;
		bullets.clear();
		bullets.shrink_to_fit(); // Free unused memory
		aliens.clear();
		aliens.shrink_to_fit();  // Free unused memory
		player.SetCoords(365, 25); // Reset player position
		SpawnAliens();            // Spawn a new wave of aliens
		JELLY_LOG("Game Reset");
	}

};

JELLY_GAME_START(MyGameApplication)