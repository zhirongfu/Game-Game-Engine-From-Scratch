#include "pch.h"

#include "WindowGLFW.h"
#include "GLFW/glfw3.h"
#include "JellyUtilities.h"

namespace Jelly 
{
	WindowGLFW::WindowGLFW()
	{
		glfwInit();
		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	}
	void Jelly::WindowGLFW::Create(int width, int height, std::string windowName)
	{
		mWindowPtr = glfwCreateWindow(width, height, windowName.c_str(), NULL, NULL);

		if (!mWindowPtr)
			JELLY_ERROR("GLFW failed to create a window!!!");

		glfwMakeContextCurrent(mWindowPtr);

		glfwSetWindowUserPointer(mWindowPtr, &mCallbacks);
		glfwSetKeyCallback(mWindowPtr,
			[](GLFWwindow* window, int key, int scancode, int action, int mods) 
			{
				if (action == GLFW_PRESS)
				{
					Callbacks* callbacks{ (Callbacks*) glfwGetWindowUserPointer(window) };

					KeyEvent event{ key, KeyEvent::KeyAction::Press };
					callbacks->KeyEventHandler(event);
				}
				else if (action == GLFW_RELEASE)
				{
					Callbacks* callbacks{ (Callbacks*)glfwGetWindowUserPointer(window) };

					KeyEvent event{ key, KeyEvent::KeyAction::Release };
					callbacks->KeyEventHandler(event);
				}
				else if (action == GLFW_REPEAT)
				{
					Callbacks* callbacks{ (Callbacks*)glfwGetWindowUserPointer(window) };

					KeyEvent event{ key, KeyEvent::KeyAction::Repeat };
					callbacks->KeyEventHandler(event);
				}
			});

		glfwSetWindowCloseCallback(mWindowPtr, [](GLFWwindow* window) {
			Callbacks* callbacks{ (Callbacks*)glfwGetWindowUserPointer(window) };

			WindowEvent event{ Jelly::WindowEvent::WindowAction::Close };
			callbacks->WindowEventHandler(event);
			});
	}

	int WindowGLFW::GetWidth() const
	{
		int width{ 0 };
		int height{ 0 };

		glfwGetWindowSize(mWindowPtr, &width, &height);

		return width;
	}
	int WindowGLFW::GetHeight() const
	{
		int width{ 0 };
		int height{ 0 };

		glfwGetWindowSize(mWindowPtr, &width, &height);

		return height;
	}
	void WindowGLFW::SetKeyEventHandler(const std::function<void(const KeyEvent&)>& newHandler)
	{
		mCallbacks.KeyEventHandler = newHandler;
	}
	void WindowGLFW::SetWindowEventHandler(std::function<void(const WindowEvent&)> newHandler)
	{
		mCallbacks.WindowEventHandler = newHandler;
	}
	void WindowGLFW::SwapBuffers()
	{
		glfwSwapBuffers(mWindowPtr);
	}
	void WindowGLFW::PollEvents()
	{
		glfwPollEvents();
	}
}