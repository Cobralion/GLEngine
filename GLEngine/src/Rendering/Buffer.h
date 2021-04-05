#pragma once
#include <cstdint>

#include "Interfaces/Bindable.h"
#include "../Core.h"

namespace gle::Rendering
{
	enum class BufferType : uint32_t;

	class GLENGINE_API Buffer final : public Interfaces::Bindable
	{
		friend class VertexArrayObject;
	private:
		uint32_t m_rendererId{};
		BufferType m_type{};
		uint32_t m_size{};
		uint32_t m_sizePerElement;
		uint32_t m_realSize;
	public:
		explicit Buffer(BufferType type, uint32_t size);
		virtual ~Buffer() override;

		virtual void Bind() const noexcept override;
		virtual void Unbind() const noexcept override;

		template<typename T>
		void Update(const T* data, uint32_t size) { Update(static_cast<void*>(data), size, sizeof(T)); }

		Buffer(const Buffer& other) = delete;
		Buffer(Buffer&& other) noexcept = delete;
		Buffer& operator=(const Buffer& other) = delete;
		Buffer& operator=(Buffer&& other) noexcept = delete;

	private:
		void Update(const void* data, uint32_t size, uint32_t sizePerElement);
	};

	// Opengl 4.5
	enum class BufferType : uint32_t
	{
		Default = 0x0,
		ArrayBuffer = 0x8892,
		ElementArrayBuffer = 0x8893
	};
}
