#pragma once

//总结得到，一个Renderer应该具有以下功能：
//设置环境相关的信息
//接受被渲染的物体，传入它对应的数据，比如Vertex Array、引用的Material和Shader
//渲染物体，调用DrawCall
//批处理，为了优化性能，把相同材质的物体一起渲染等
//
//可以把Renderer每帧执行的任务分为四个步骤：
//BeginScene : 负责每帧渲染前的环境设置
//Submit：收集场景数据，同时收集渲染命令，提交渲染命令到队列里
//EndScene：对收集到的场景数据进行优化
//Render：按照渲染队列，进行渲染
#include "RenderCommand.h"
#include "Renderer\Shader.h"

#include "Renderer\OrthographicCamera.h"

namespace Hazel {

	class Renderer {
	public:
		static void BeginScene(OrthographicCamera &cam);
		static void EndScene();

		static void Init();

		static void OnWindowResize(uint32_t width, uint32_t height);

		static void Submit(const std::shared_ptr<Shader>& shader, const std::shared_ptr<VertexArray>& vertexArray, const glm::mat4& transform = glm::mat4(1.0f));
		
		inline static RendererAPI::API GetAPI() { return RendererAPI::GetAPI(); }

	private:
		struct SceneData
		{
			glm::mat4 ViewProjectionMatrix;
		};

		static Scope<SceneData> m_SceneData;
	};
}