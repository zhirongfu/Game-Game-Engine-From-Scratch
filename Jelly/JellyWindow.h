#pragma once
#include"pch.h"
#include"WindowImpl.h"
#include"JellyUtilities.h"

namespace Jelly
{
	class JELLY_API JellyWindow
	{
	public:
		static void Init();
		static std::unique_ptr<JellyWindow>& GetWindow();

		void CreateWindow(int width, int height, std::string windowName);
		int GetWidth() const;
		int GetHeight() const;

		void SwapBuffers();
		void PollEvents();
	private:
		std ::unique_ptr<WindowImpl> implementation{ nullptr };

		JellyWindow();

		inline static std::unique_ptr<JellyWindow> instance;
	};
}
