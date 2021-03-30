#pragma once

#ifdef GLENGINE_PLATFORM_WINDOWS
	#ifdef GLENGINE_DLL_EXPORT
		#define GLENGINE_API __declspec(dllexport)
	#else
		#define GLENGINE_API __declspec(dllimport)
	#endif
#else
	#error This does only support windows-x64
#endif

#define GLENGINE_ERROR(x) std::cout << "[ERROR] " << "[IMPORTANT] " << x << std::endl;
