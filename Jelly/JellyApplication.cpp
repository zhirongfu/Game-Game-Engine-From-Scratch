#include"pch.h"

#include "JellyApplication.h"
#include "JellyWindow.h"
#include "Image.h"
#include "Shaders.h"

#define GLFW_INCLUDE_NONE
#include "GLFW/glfw3.h"
#include "glad/glad.h"

#include "stb_image.h"

namespace Jelly
{
	void JellyApplication::Run()
	{
		Initialize();

		Jelly::Shaders shaders{
			"../Jelly/JellyAssets/Shaders/defaultVertexShader.glsl",
			"../Jelly/JellyAssets/Shaders/defaultfragmentShader.glsl" };
		shaders.SetIntUniform("ScreenDim", { 800, 600 });

		//Jelly::Image pic{ "../Jelly/JellyAssets/Images/Jelly.jpg" };

		while (ShouldContinue)
		{
			Update();

			glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
			glClear(GL_COLOR_BUFFER_BIT);
			shaders.Bind();


			//pic.Bind();
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


}


/*
Jelly::Image pic{"Assets/image1.png"};
Jelly::Shade shader{"vert.glsl","frag.glsl"};
Jelly::Renderer::Get()->Draw(pic, 100,200);


*/