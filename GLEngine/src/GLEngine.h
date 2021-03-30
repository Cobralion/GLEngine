#pragma once

#include "Core.h"
#include "Rendering/Renderer.h"
#include "Rendering/Window.h"
#include "Rendering/WindowManager.h"

namespace gle
{
	namespace Rendering {
		class WindowManager;
	}

	class GLENGINE_API GLEngine
	{
	private:
		bool m_closeWindow = false;
		Rendering::Window* m_window;
		Rendering::Renderer* m_renderer;
		Rendering::WindowManager* m_windowManager;

	protected:
		GLEngine();
		virtual ~GLEngine();

		virtual void Update(float deltaTime) = 0;
		virtual void Draw(const Rendering::Renderer* renderer) = 0;
		virtual void WindowUpdate(const Rendering::WindowManager* manager) = 0;
		
		GLEngine(const GLEngine& other) = delete;
		GLEngine(GLEngine&& other) noexcept = delete;
		GLEngine& operator=(const GLEngine& other) = delete;
		GLEngine& operator=(GLEngine&& other) noexcept = delete;

	public:
		void Run();
	};
}

