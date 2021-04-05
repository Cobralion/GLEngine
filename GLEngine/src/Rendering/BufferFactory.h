#pragma once
#include <vector>

#include "Buffer.h"
#include "../GLEError.h"

namespace gle::Rendering
{
	class BufferFactory final
	{
		friend class Buffer;
	private:
		static int m_bufferAmount;
	public:
		static void CreateBuffer(const Buffer** ppBuffer, BufferType type);
		static void DestroyBuffer(const Buffer* pBuffer);

	protected:
		static void CreateBuffers(const Buffer** ppbuffers, uint32_t size);
		static void DestroyBuffers(const Buffer** ppbuffers, uint32_t size);
	
	public:
		BufferFactory() = delete;
		~BufferFactory() = delete;
		BufferFactory(const BufferFactory& other) = delete;
		BufferFactory(BufferFactory&& other) noexcept = delete;
		BufferFactory& operator=(const BufferFactory& other) = delete;
		BufferFactory& operator=(BufferFactory&& other) noexcept = delete;
	};
}