#include "SandBox2D.h"
#include "imgui\imgui.h"
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "Platform\OpenGL\OpenGLShader.h"

SandBox2D::SandBox2D()
	:Layer("SandBox2D"), m_CamController(1280.0f / 720.0f)
{
}

SandBox2D::~SandBox2D()
{
}

void SandBox2D::OnAttach()
{
	m_CheckerboardTexture = Hazel::Texture2D::Create("assets/textures/Checkerboard.png");
}

void SandBox2D::OnDetach()
{

}

void SandBox2D::OnUpdate(Hazel::Timestep ts)
{
	m_CamController.OnUpdate(ts);

	Hazel::RenderCommand::SetClearColor({ 0.1f, 0.1f, 0.1f, 1 });
	Hazel::RenderCommand::Clear();

	Hazel::Renderer2D::BeginScene(m_CamController.GetCamera());
	Hazel::Renderer2D::DrawQuad({ 0.0f, 0.0f }, { 1.0f, 1.0f }, { 0.8f, 0.2f, 0.3f, 1.0f });
	Hazel::Renderer2D::DrawQuad({ 0.5f, -0.5f }, { 0.5f, 0.75f }, { 0.2f, 0.3f, 0.8f, 1.0f });
	Hazel::Renderer2D::DrawQuad({ 0.0f, 0.0f, -0.1f }, { 10.0f, 10.0f }, m_CheckerboardTexture);
	Hazel::Renderer2D::EndScene();
}

void SandBox2D::OnEvent(Hazel::Event& event)
{
	m_CamController.OnEvent(event);
}

void SandBox2D::OnImGuiRender()
{
	ImGui::Begin("Settings");
	ImGui::ColorEdit3("Square Color", glm::value_ptr(m_SquareColor));
	ImGui::End();
}
