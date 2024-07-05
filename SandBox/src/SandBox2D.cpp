#include "SandBox2D.h"
#include "imgui\imgui.h"
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <chrono>

#include "Platform\OpenGL\OpenGLShader.h"

template <typename Fn>
class Timer {
public:
	Timer(const char* name, Fn&& fn)
		:m_Name(name), m_Fn(fn), m_Stopped(false)
	{
		m_StartTimePoint = std::chrono::high_resolution_clock::now();
	}

	~Timer() {
		if (!m_Stopped)
			Stop();
	}

	void Stop() {
		auto endTimepoint = std::chrono::high_resolution_clock::now();
		long long start = std::chrono::time_point_cast<std::chrono::microseconds>(m_StartTimePoint).time_since_epoch().count();
		long long end = std::chrono::time_point_cast<std::chrono::microseconds>(endTimepoint).time_since_epoch().count();

		m_Stopped = true;

		float duration = (end - start) * 0.001f;
		m_Fn({ m_Name, duration });//析构函数回调这个函数
	}

private:
	const char* m_Name;
	Fn m_Fn;
	std::chrono::time_point<std::chrono::steady_clock> m_StartTimePoint;
	bool m_Stopped;
};

#define PROFILE_SCOPE(name) Timer timer##__LINE__(name, [&](ProfileResult profileResult) { m_ProfileResults.push_back( profileResult ); })


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
	PROFILE_SCOPE("Sandbox2D::OnUpdate");

	{
		PROFILE_SCOPE("CameraController::OnUpdate");
		m_CamController.OnUpdate(ts);
	}

	{
		PROFILE_SCOPE("Renderer Prep");
		Hazel::RenderCommand::SetClearColor({ 0.1f, 0.1f, 0.1f, 1 });
		Hazel::RenderCommand::Clear();
	}

	{
		PROFILE_SCOPE("Renderer Draw");
		Hazel::Renderer2D::BeginScene(m_CamController.GetCamera());
		Hazel::Renderer2D::DrawQuad({ 0.0f, 0.0f }, { 1.0f, 1.0f }, { 0.8f, 0.2f, 0.3f, 1.0f });
		Hazel::Renderer2D::DrawQuad({ 2.0f, -2.0f }, { 0.5f, 0.75f }, { 0.2f, 0.3f, 0.8f, 1.0f });
		Hazel::Renderer2D::DrawQuad({ 0.0f, 0.0f, -0.1f }, { 10.0f, 10.0f }, m_CheckerboardTexture);
		Hazel::Renderer2D::EndScene();
	}
}

void SandBox2D::OnEvent(Hazel::Event& event)
{
	m_CamController.OnEvent(event);
}

void SandBox2D::OnImGuiRender()
{
	ImGui::Begin("Settings");
	ImGui::ColorEdit4("Square Color", glm::value_ptr(m_SquareColor));

	for (auto& res : m_ProfileResults) {
		char label[50];
		strcpy(label, "%.3fms ");
		strcat(label, res.Name);
		ImGui::Text(label, res.Time);
	}

	m_ProfileResults.clear();
	ImGui::End();
}
