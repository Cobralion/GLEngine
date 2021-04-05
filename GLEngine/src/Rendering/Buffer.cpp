#include "Buffer.h"

#include "BufferFactory.h"
#include "OpenGL.h"

namespace gle::Rendering
{
	Buffer::Buffer(uint32_t rendererID, BufferType type) : Bindable(), m_rendererId(rendererID), m_type(type)
	{
		++BufferFactory::m_bufferAmount;
		glBufferData((uint32_t) type, 0, nullptr, GL_)
	}

	Buffer::~Buffer()
	{
		--BufferFactory::m_bufferAmount;
	}

	void Buffer::Bind() const noexcept
	{
		glBindBuffer((uint32_t)m_type, m_rendererId);
	}

	void Buffer::Unbind() const noexcept
	{
		glBindBuffer((uint32_t)m_type, 0);
	}

	void Buffer::Update() noexcept
	{
		glBufferData()
	}

	Buffer::Buffer(Buffer&& other) noexcept: m_rendererId(other.m_rendererId)
	{
	}

	Buffer& Buffer::operator=(Buffer&& other) noexcept
	{
		if (this == &other)
			return *this;
		m_rendererId = other.m_rendererId;
		return *this;
	}
}
