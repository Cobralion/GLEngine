#pragma once

namespace gle::Rendering
{
	class Renderer
	{
	public:
		void Draw(const VertexArray& vertexArray, const Program& program);
	};
}
