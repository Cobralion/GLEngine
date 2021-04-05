#pragma once

#include <spdlog/spdlog.h>

namespace gle::Tools
{
	class GLENGINE_API Logger
	{
	private:
	
	public:

		template<typename T>
		static void Info(const T& string)
		{
			spdlog::info(string);
		}

		template<typename T>
		static void Warning(const T& string)
		{
			spdlog::warn(string);
		}

		template<typename T>
		static void Error(const T& string)
		{
			spdlog::error(string);
		}

		//template<typename T, typename... Args>
		//static void Info(const T& string, Args&& args)
		//{
		//	spdlog::info(string, std::forward<Args>(args)...);
		//}

		//template<typename FormatString, typename... Args>
		//static void Warning(const FormatString& string, Args&& args)
		//{
		//	spdlog::warn(string, std::forward<Args>(args)...);
		//}

		//template<typename FormatString, typename... Args>
		//static void Error(const FormatString& string, Args&& args)
		//{
		//	spdlog::error(string, std::forward<Args>(args)...);
		//}

	};
}
