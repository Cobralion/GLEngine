#pragma once
#include <string>

typedef struct GLEError
{
	unsigned int internalError;
	std::string errorMessage;

	static GLEError From(uint32_t error, const std::string& message)
	{
		return GLEError{ error, message };
	}
	
	static GLEError From(uint32_t error)
	{
		return GLEError{ error, "No error message available!" };
	}

	static GLEError From(const std::string& message)
	{
		return GLEError{ 0, message };
	}
} GLEError;
