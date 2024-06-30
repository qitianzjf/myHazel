#pragma once
#include "OrthographicCamera.h"
#include "Texture.h"

//OpenGL绘图是一个设置状态顺序的过程
//在2D渲染类中只是简单的调用设置OpenGL状态，并不需要实例化
//不需要让一个2D渲染类开始场景，另一个2D渲染类绘制，只需要一个静态类就行了
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