#pragma once

#include "OpenGL.h"
#include "WindowManager.h"

namespace gle::Rendering
{
		class Window
		{
		private:
			GLFWwindow* m_window;
		public:
			
			Window();
			~Window();
			void SwapBuffers() const;

			inline GLFWwindow* GetWindow() const { return m_window; }
			
			Window(const Window& other) = delete;
			Window(Window&& other) noexcept = delete;
			Window& operator=(const Window& other) = delete;
			Window& operator=(Window&& other) noexcept = delete;
		};
}

