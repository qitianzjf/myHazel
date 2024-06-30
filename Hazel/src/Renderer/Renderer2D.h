#pragma once
#include "OrthographicCamera.h"
#include "Texture.h"

//OpenGL��ͼ��һ������״̬˳��Ĺ���
//��2D��Ⱦ����ֻ�Ǽ򵥵ĵ�������OpenGL״̬��������Ҫʵ����
//����Ҫ��һ��2D��Ⱦ�࿪ʼ��������һ��2D��Ⱦ����ƣ�ֻ��Ҫһ����̬�������
namespace Hazel {
	class Renderer2D {
	public:
		static void BeginScene(OrthographicCamera& cam);
		static void EndScene();

		static void Init();
		static void Shutdown();

		static void DrawQuad(const glm::vec2& position, const glm::vec2& size, const glm::vec4& color);
		static void DrawQuad(const glm::vec3& position, const glm::vec2& size, const glm::vec4& color);
		static void DrawQuad(const glm::vec2& position, const glm::vec2& size, const Ref<Texture2D>& tex);
		static void DrawQuad(const glm::vec3& position, const glm::vec2& size, const Ref<Texture2D>& tex);
	};
}