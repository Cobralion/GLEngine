#include "VertexArrayObject.h"

#include "OpenGL.h"


namespace gle::Rendering
{
	VertexArrayObject::VertexArrayObject() : m_count(0)
	{
		glCreateVertexArrays(1, &m_rendererID);
		glBindVertexArray(m_rendererID);
	}

	VertexArrayObject::~VertexArrayObject()
	{
		glBindVertexArray(0);
		glDeleteVertexArrays(1, &m_rendererID);
	}

	void VertexArrayObject::Bind() const noexcept
	{
		glBindVertexArray(m_rendererID);
	}

	void VertexArrayObject::Unbind() const noexcept
	{
		glBindVertexArray(0);
	}

	template <>
	void VertexArrayObject::Add<float>(const Buffer& buffer) noexcept
	{
		Bind();
		glEnableVertexAttribArray(m_count);
		glBindBuffer((uint32_t)buffer.m_type, buffer.m_rendererId);
		glVertexAttribPointer(m_count++, buffer.m_size / buffer.m_sizePerElement / sizeof(float), GL_FLOAT, GL_FALSE, buffer.m_sizePerElement, reinterpret_cast<const void*>(0));
	}
}
