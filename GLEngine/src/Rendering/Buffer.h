#pragma once
#include <cstdint>

#include "Interfaces/Bindable.h"

namespace gle::Rendering
{
	enum class BufferType : uint32_t;

	class Buffer final : public Interfaces::Bindable
	{
		friend class BufferFactory;
	private:
		uint32_t m_rendererId;
		BufferType m_type;
	public:

		virtual void Bind() const noexcept override;
		virtual void Unbind() const noexcept override;

		void Update() noexcept;

		Buffer(const Buffer& other) = delete;
		Buffer(Buffer&& other) noexcept;
		Buffer& operator=(const Buffer& other) = delete;
		Buffer& operator=(Buffer&& other) noexcept;
	private:
		Buffer(uint32_t rendererID, BufferType type);
		virtual ~Buffer() override;
	};

	// Opengl 4.5
	enum class BufferType : uint32_t
	{
		ArrayBuffer = 0x8892,
		ElementArrayBuffer = 0x8893
	};
}
