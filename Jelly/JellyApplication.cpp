#include"pch.h"

#include "JellyApplication.h"
#include "JellyWindow.h"
#include "Image.h"
#include "Shaders.h"
#include "Renderer.h"	

#define GLFW_INCLUDE_NONE
#include "GLFW/glfw3.h"
#include "glad/glad.h"

#include "stb_image.h"
#include "filesystem"

namespace Jelly
{
	void JellyApplication::Run()
	{
		Jelly::JellyWindow::Init();
		Jelly::JellyWindow::GetWindow()->CreateWindow(800, 600, "test");

		Renderer::Init();

		SetWindowEventHandler(
			[this](const WindowEvent& event){ DefaultWindowEventHandler(event); });

		//Initialize();

				//		shaders		//

		Jelly::Shaders shaders{
			"../Jelly/JellyAssets/Shaders/defaultVertexShader.glsl",
			"../Jelly/JellyAssets/Shaders/defaultFragmentShader.glsl" };
		shaders.SetIntUniform("ScreenDim", { 800, 600 });

				//		Texture		//
		Jelly::Image pic{ "../Jelly/JellyAssets/Images/Jelly.png" };
		int x{ 100 };

		mNextFrameTime = std::chrono::steady_clock::now() + mFrameDuration;

		while (mShouldContinue)
		{
			Update();

			Renderer::ClearScreen();
			
			Renderer::Draw(pic, x, 200);
			x += 2;

			std::this_thread::sleep_until(mNextFrameTime);
			mNextFrameTime = std::chrono::steady_clock::now() + mFrameDuration;

			Jelly::JellyWindow::GetWindow()->SwapBuffers();
			Jelly::JellyWindow::GetWindow()->PollEvents();
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


	void JellyApplication::SetKeyEventHandler(const std::function<void(const KeyEvent&)>& newHandler)
	{
		Jelly::JellyWindow::GetWindow()->SetKeyEventHandler(newHandler);
	}
	void JellyApplication::SetWindowEventHandler(std::function<void(const WindowEvent&)> newHandler)
	{
		Jelly::JellyWindow::GetWindow()->SetWindowEventHandler(newHandler);
	}
	void JellyApplication::DefaultWindowEventHandler(const WindowEvent& event)
	{
		if(event.GetWindowAction()==WindowEvent::WindowAction::Close)
			mShouldContinue = false;
	}
}


/*
Jelly::Image pic{"Assets/image1.png"};
Jelly::Shade shader{"vert.glsl","frag.glsl"};
Jelly::Renderer::Get()->Draw(pic, 100,200);


*/