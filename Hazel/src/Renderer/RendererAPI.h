#pragma once
//RendererAPI类，除了要有标识当前使用的API类型的函数外，还需要有很多与平台无关的渲染的API，比如清空Buffer、根据Vertex Array进行调用DrawCall等函数
#include <glm\glm.hpp>

#include "VertexArray.h"

namespace Hazel {
	class RendererAPI {
	public:
		enum class API {
			None = 0, OpenGL = 1
		};
	public:
		virtual void SetClearColor( const glm::vec4& color) = 0;
		virtual void Clear() = 0;
		virtual void DrawIndexed(const std::shared_ptr<VertexArray>& vertexArray) = 0;

		inline static API GetAPI() { return s_API; }
	private:
		static API s_API;
	};
}
