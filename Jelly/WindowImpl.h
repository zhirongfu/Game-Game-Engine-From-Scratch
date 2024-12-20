#pragma once

#include "pch.h"
#include"JellyEvents.h"

namespace Jelly
{
	class WindowImpl
	{
	public:
		virtual void Create(int width, int height, std::string windowName) = 0;
		virtual int GetWidth() const = 0;
		virtual int GetHeight() const = 0;
		virtual void SetKeyEventHandler(const std::function<void(const KeyEvent&)>& newHandler) = 0;
		virtual void SetWindowEventHandler(std::function<void(const WindowEvent&)> newHandler) = 0;
		virtual void SwapBuffers() = 0;
		virtual void PollEvents() = 0;
	};
}