#include "WindowManager.h"

namespace gle::Rendering
{
	WindowManager::WindowManager() : m_window(nullptr)
	{
	}

	WindowManager::WindowManager(Window* window) : m_window(window)
	{
	}

	void WindowManager::PollEvents()
	{
		m_events = 0;
		glfwPollEvents();

		if (glfwWindowShouldClose(m_window->GetWindow()))
			m_events |= (unsigned int) WindowEvents::WINDOW_CLOSE;

	}
}
