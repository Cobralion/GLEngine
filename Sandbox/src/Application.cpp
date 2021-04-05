#include "Application.h"

#include <iostream>

void Application::Update(float deltaTime)
{
	m_elapsed_time += floor(deltaTime);
	++m_frames;
	
	if(m_elapsed_time >= 1000)
	{
		gle::Tools::Logger::Info("Average delta time was " + std::to_string((int)m_elapsed_time / m_frames) + " ms.");
		gle::Tools::Logger::Info("Average frame rate was " + std::to_string((int)m_frames) + " fps.");
		m_elapsed_time = 0;
		m_frames = 0;
	}
}

void Application::Draw(const gle::Rendering::Renderer* renderer)
{
}

void Application::WindowUpdate(const gle::Rendering::WindowManager* manager)
{
}

Application::Application() : gle::GLEngine()
{
}
