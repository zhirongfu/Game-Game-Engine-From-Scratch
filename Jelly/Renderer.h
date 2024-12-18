#pragma once

#include "pch.h"
#include "JellyUtilities.h"
#include "Image.h"
#include "Shaders.h"
#include "RendererImpl.h"

namespace Jelly
{
	class JELLY_API Renderer
	{
	public:
		static void Init();

		static void Draw(Image& pic, int xCoord, int yCoord);
		static void Draw(Image& pic, int xCoord, int yCoord, Shaders shaders);

		static void ClearScreen();
	private:
		Renderer();
		std::unique_ptr<RendererImpl> mImplementation;
		inline static std::unique_ptr<Renderer> mInstance;
	};
}