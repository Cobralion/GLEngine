#pragma once

#include "../../Core.h"

namespace gle::Rendering::Interfaces
{
	class GLENGINE_API Bindable
	{
	public:

		virtual void Bind() const noexcept = 0;
		virtual void Unbind() const noexcept = 0;

		explicit Bindable() {};
		virtual ~Bindable() = 0;

		Bindable(const Bindable& other) = delete;
		Bindable(Bindable&& other) noexcept = delete;
		Bindable& operator=(const Bindable& other) = delete;
		Bindable& operator=(Bindable&& other) noexcept = delete;
	};

	inline Bindable::~Bindable() {};
}
