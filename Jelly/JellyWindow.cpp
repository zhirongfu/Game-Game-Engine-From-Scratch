#include "pch.h"
#include "JellyWindow.h"
#include "codeGLFW/WindowGLFW.h"
namespace Jelly
{
	JellyWindow::JellyWindow()
	{
		//create an impl obj and point "implementation" pointer to it
#ifdef JELLY_GLFW
		implementation = new WindowGLFW;
#else
#window_implementation_isnt_chosen
#endif
	}

	void JellyWindow::CreateWindow(int width, int height, std::string windowName)
	{
		implementation->Create(width, height, windowName);
	}
	int JellyWindow::GetWidth() const
	{
		return implementation->GetWidth();
	}
	int JellyWindow::GetHeight() const
	{
		return implementation->GetHeight();
	}
}