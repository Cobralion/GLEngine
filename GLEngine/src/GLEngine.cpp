#include "GLEngine.h"

#include <iostream>
#include "Rendering/OpenGL.h"

#include <chrono>

namespace gle
{
	GLEngine::GLEngine()
	{
		m_window = new Rendering::Window();
		m_windowManager = new Rendering::WindowManager(m_window);
		m_renderer = new Rendering::Renderer();
		
		if (glewInit() != GLEW_OK)
			GLENGINE_ERROR("Can not initalize GLEW.");

	}

	GLEngine::~GLEngine()
	{
		delete m_window;
	}

	void GLEngine::Run()
	{
		using namespace std::chrono;
		auto oldTime = high_resolution_clock::now();
		steady_clock::time_point newTime;
		
		while (!m_windowManager->GetClose())
		{
			newTime = high_resolution_clock::now();
			const auto deltaTime = duration<float, std::milli>(newTime - oldTime).count();
			oldTime = newTime;
			
			Update(deltaTime);
			Draw(m_renderer);
			m_window->SwapBuffers();
			m_windowManager->PollEvents();
			WindowUpdate(m_windowManager);
		}
	}
}
