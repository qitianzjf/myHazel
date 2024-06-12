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

namespace Hazel {

	class Renderer {
	public:
		static void BeginScene();
		static void EndScene();

		static void Submit(const std::shared_ptr<VertexArray>& vertexArray);
		
		inline static RendererAPI::API GetAPI() { return RendererAPI::GetAPI(); }
	};
}