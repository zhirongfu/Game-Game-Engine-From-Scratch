#pragma once

#include "pch.h"

namespace Jelly
{
	class WindowImpl
	{
	public:
		virtual void Create(int width, int height, std::string windowName) = 0;
		virtual int GetWidth() const = 0;
		virtual int GetHeight() const = 0;
	};
}