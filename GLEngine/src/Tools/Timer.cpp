#include "Timer.h"


namespace gle::Tools
{
	using namespace  std::chrono;
	
	Timer::Timer() : m_elapsedTime(0.0f)
	{
	}

	void Timer::Start()
	{
		m_start = high_resolution_clock::now();
	}

	void Timer::Stop()
	{
		m_elapsedTime += duration<float, std::milli>(high_resolution_clock::now() - m_start).count();
	}

	void Timer::Reset()
	{
		m_elapsedTime = 0;
	}


	float Timer::ElapsedTime() const
	{
		return m_elapsedTime;
	}
}
