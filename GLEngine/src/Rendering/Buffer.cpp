#include "Buffer.h"

#include <exception>


#include "OpenGL.h"

namespace gle::Rendering
{
	Buffer::Buffer(BufferType type, uint32_t size) : Bindable(), m_type(type), m_size(size), m_sizePerElement(0)
	{
		glGenBuffers(1, &m_rendererId);
		glBufferData((uint32_t)m_type, m_size, nullptr, GL_DYNAMIC_DRAW);
	}

	Buffer::~Buffer()
	{
		glDeleteBuffers(1, &m_rendererId);
	}

	void Buffer::Bind() const noexcept
	{
		glBindBuffer(static_cast<uint32_t>(m_type), m_rendererId);
	}

	void Buffer::Unbind() const noexcept
	{
		glBindBuffer(static_cast<uint32_t>(m_type), 0);
	}

	void Buffer::Update(const void* data, uint32_t size, uint32_t sizePerElement)
	{
		if (m_size < size) throw std::exception("Size can not be greater than initial size");
		if (size % sizePerElement != 0) throw std::exception("Size must be a integer multiple of sizePerEntry");

		m_sizePerElement = sizePerElement;
		m_realSize = size;
		glBufferSubData(static_cast<uint32_t>(m_type), 0, m_size, data);
	}
}
