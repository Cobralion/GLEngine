#include "BufferFactory.h"
#include "OpenGL.h"

namespace gle::Rendering
{
	void BufferFactory::CreateBuffer(const Buffer** ppBuffer, BufferType type)
	{
		uint32_t bufferID;
		glGenBuffers(1, &bufferID);
		*ppBuffer = new Buffer(bufferID, type);
	}

	void BufferFactory::DestroyBuffer(const Buffer* pBuffer)
	{
		glDeleteBuffers(1, &pBuffer->m_rendererId);
		delete pBuffer;
	}

	//Untested / should not work
	void BufferFactory::CreateBuffers(const Buffer** ppbuffers, uint32_t size)
	{
		auto* bufferIDs = static_cast<uint32_t*>(alloca(size * sizeof(uint32_t)));
		glGenBuffers(size, bufferIDs);

		for (int i = 0; i < size; ++i)
		{
			ppbuffers[i] = new Buffer(bufferIDs[i]);
		}
	}

	//Untested
	void BufferFactory::DestroyBuffers(const Buffer** ppbuffers, uint32_t size)
	{
		auto* bufferIDs = static_cast<uint32_t*>(alloca(size * sizeof(uint32_t)));

		for (int i = 0; i < size; ++i)
		{
			bufferIDs[i] = ppbuffers[i]->m_rendererId;
		}
		glDeleteBuffers(size, bufferIDs);

		delete[] ppbuffers;
	}
}
