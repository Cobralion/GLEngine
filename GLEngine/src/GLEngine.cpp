#include "GLEngine.h"

#include <iostream>
#include "Rendering/OpenGL.h"
#include "Tools/Logger.h"

namespace gle
{
	using namespace Tools;
	GLEngine::GLEngine()
	{
		m_window = new Rendering::Window();
		m_windowManager = new Rendering::WindowManager(m_window);
		m_renderer = new Rendering::Renderer();

		m_timer = Tools::Timer();

		Logger::Info("GLEngine initialized!");
		
		if (glewInit() != GLEW_OK)
			GLENGINE_ERROR("Can not initalize GLEW.");

	}

	GLEngine::~GLEngine()
	{
		delete m_window;
	}

	void GLEngine::Run()
	{
		m_timer.Start();
		while (!m_windowManager->GetClose())
		{
			m_timer.Stop();
			const auto deltaTime = m_timer.ElapsedTime();
			m_timer.Reset();
			m_timer.Start();
			
			Update(deltaTime);
			Draw(m_renderer);
			m_window->SwapBuffers();
			m_windowManager->PollEvents();
			WindowUpdate(m_windowManager);
		}
	}
}
