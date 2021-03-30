#pragma once

#include <GLE.h>

class Application : public gle::GLEngine
{
private:
	uint32_t m_elapsed_time = 0;
	uint32_t m_frames = 0;
protected:
	void Update(float deltaTime) override;
	void Draw(const gle::Rendering::Renderer* renderer) override;
	void WindowUpdate(const gle::Rendering::WindowManager* manager) override;
public:
	Application();

	
};
