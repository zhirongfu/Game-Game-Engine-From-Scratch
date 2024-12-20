#include "pch.h"

#include "Renderer.h"
#include "codeOpenGL/OpenGLRenderer.h"

namespace Jelly
{
	Renderer::Renderer()
	{
#ifdef JELLY_OPENGL_STBI
		mImplementation = std::unique_ptr<RendererImpl>{ new OpenGLRenderer() };
#else
		#only_opengl_is_supported_so_far
#endif
	}
	void Renderer::Init()
	{
		if (mInstance == nullptr)
		{
			mInstance = std::unique_ptr<Renderer>{ new Renderer };
		}
	}
	void Renderer::Draw(Image& pic, int xCoord, int yCoord)
	{
		mInstance-> mImplementation->Draw(pic, xCoord, yCoord);
	}
	void Renderer::Draw(Image& pic, int xCoord, int yCoord, Shaders& shaders)
	{
		mInstance->mImplementation->Draw(pic, xCoord, yCoord, shaders);
	}

	void Renderer::ClearScreen()
	{
		mInstance-> mImplementation-> ClearScreen();
	} 
}