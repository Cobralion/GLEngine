#include "Application.h"

#include <iostream>

void Application::Update(float deltaTime)
{
	m_elapsed_time += floor(deltaTime);
	++m_frames;
	
	if(m_elapsed_time >= 1000)
	{
		std::cout << "Average delta time was " << (int) m_elapsed_time / m_frames << " ms." << std::endl;
		std::cout << "Average frame rate was " << (int) m_frames << " fps." << std::endl;
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
