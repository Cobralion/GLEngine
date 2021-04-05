#pragma once

namespace gle::Rendering::Interfaces
{
	class Bindable
	{
	public:

		virtual void Bind() const noexcept = 0;
		virtual void Unbind() const noexcept = 0;

		explicit Bindable();
		virtual ~Bindable() = default;

		Bindable(const Bindable& other) = delete;
		Bindable(Bindable&& other) noexcept = delete;
		Bindable& operator=(const Bindable& other) = delete;
		Bindable& operator=(Bindable&& other) noexcept = delete;
	};
}
