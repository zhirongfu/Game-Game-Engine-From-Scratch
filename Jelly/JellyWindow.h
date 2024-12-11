#pragma once
#include"pch.h"
#include"WindowImpl.h"
#include"JellyUtilities.h"

namespace Jelly
{
	class JELLY_API JellyWindow
	{
	public:
		JellyWindow();

		void CreateWindow(int width, int height, std::string windowName);
		int GetWidth() const;
		int GetHeight() const;
	private:
		WindowImpl* implementation{nullptr};
	};
}
