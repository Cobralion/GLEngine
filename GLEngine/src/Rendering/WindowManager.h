#pragma once
#include <bitset>

#include "Window.h"

namespace gle::Rendering
{
#define CHECK_BIT_SET(val, n) (val & (1 << n)) != 0

	class Window;
	class WindowManager
	{
		friend class gle::Rendering::Window;
	private:
		unsigned int m_events = 0;
		Window* m_window;
	public:
		WindowManager();
		WindowManager(Window* window);
		~WindowManager() = default;

		void PollEvents();

		[[nodiscard]] inline bool GetClose() const { return CHECK_BIT_SET(m_events, 0); }
	};

	enum class WindowEvents : unsigned int
	{
		WINDOW_CLOSE = 0b00000000000000000000000000000001
	};
}

