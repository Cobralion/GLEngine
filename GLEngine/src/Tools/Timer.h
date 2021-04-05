#pragma once

#include <chrono>

#include "../Core.h"
#include <chrono>

namespace gle::Tools
{
	using namespace  std::chrono;

	class GLENGINE_API Timer
	{
	private:
		steady_clock::time_point m_start;
		float m_elapsedTime;

	public:
		Timer();

		void Start();
		void Stop();
		void Reset();

		float ElapsedTime() const;
	};
}
