#include "pch.h"
#include "JellyWindow.h"
#include "codeGLFW/WindowGLFW.h"
namespace Jelly
{
	JellyWindow::JellyWindow()
	{
		//create an impl obj and point "implementation" pointer to it
#ifdef JELLY_GLFW
		implementation = std::unique_ptr<WindowImpl>{ new WindowGLFW };
#else
#window_implementation_isnt_chosen
#endif
	}

	void JellyWindow::Init()
	{
		if(instance == nullptr)
			instance = std::unique_ptr<JellyWindow>{ new JellyWindow };
	}

	std::unique_ptr<JellyWindow>& JellyWindow::GetWindow()
	{
		return instance; 
		// TODO: insert return statement here
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
	void JellyWindow::SetKeyEventHandler(const std::function<void(const KeyEvent&)>& newHandler)
	{
		implementation->SetKeyEventHandler(newHandler);
	}
	void JellyWindow::SetWindowEventHandler(std::function<void(const WindowEvent&)> newHandler)
	{
		implementation->SetWindowEventHandler(newHandler);
	}
	void JellyWindow::SwapBuffers()
	{
		implementation->SwapBuffers();
	}
	void JellyWindow::PollEvents()
	{
		implementation->PollEvents();
	}
}