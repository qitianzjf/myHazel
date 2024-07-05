#pragma once

//�ܽ�õ���һ��RendererӦ�þ������¹��ܣ�
//���û�����ص���Ϣ
//���ܱ���Ⱦ�����壬��������Ӧ�����ݣ�����Vertex Array�����õ�Material��Shader
//��Ⱦ���壬����DrawCall
//������Ϊ���Ż����ܣ�����ͬ���ʵ�����һ����Ⱦ��
//
//���԰�Rendererÿִ֡�е������Ϊ�ĸ����裺
//BeginScene : ����ÿ֡��Ⱦǰ�Ļ�������
//Submit���ռ��������ݣ�ͬʱ�ռ���Ⱦ����ύ��Ⱦ���������
//EndScene�����ռ����ĳ������ݽ����Ż�
//Render��������Ⱦ���У�������Ⱦ
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