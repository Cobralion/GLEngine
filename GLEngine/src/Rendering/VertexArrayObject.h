#pragma once
#include <cstdint>

#include "Buffer.h"
#include "Interfaces/Bindable.h"

namespace gle::Rendering
{
	class VertexArrayObject final : public Interfaces::Bindable
	{
	private:
		uint32_t m_rendererID{};
		uint32_t m_count;
	public:

		VertexArrayObject();
		virtual  ~VertexArrayObject() override;

		virtual void Bind() const noexcept override;
		void Unbind() const noexcept override;

		template<typename T>
		void Add(const Buffer& buffer) noexcept { static_assert(false); }

		template<>
		void Add<float>(const Buffer& buffer) noexcept;

		VertexArrayObject(const VertexArrayObject& other) = delete;
		VertexArrayObject(VertexArrayObject&& other) noexcept = delete;
		VertexArrayObject& operator=(const VertexArrayObject& other) = delete;
		VertexArrayObject& operator=(VertexArrayObject&& other) noexcept = delete;
	};
}
