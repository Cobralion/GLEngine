#include "Window.h"

#include "../Core.h"
#include "../Tools/Logger.h"
#include <iostream>

namespace gle::Rendering
{
	Window::Window()
	{
		if (glfwInit() != GLFW_TRUE)
			GLENGINE_ERROR("Can not initalize GLFW.");
		m_window= glfwCreateWindow(720, 480, "test", nullptr, nullptr);
		glfwMakeContextCurrent(m_window);
	}

	Window::~Window()
	{
		glfwMakeContextCurrent(nullptr);
		glfwDestroyWindow(m_window);
		glfwTerminate();
	}

	void Window::SwapBuffers() const
	{
		glfwSwapBuffers(m_window);
	}
}
