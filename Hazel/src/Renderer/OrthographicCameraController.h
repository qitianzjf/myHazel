#pragma once
#include "Renderer\OrthographicCamera.h"
#include "Core\Timestep.h"

#include "Hazel_c\Events\ApplicationEvent.h"
#include "Hazel_c\Events\MouseEvent.h"

namespace Hazel {
	class OrthographicCameraController {
	public:
		OrthographicCameraController(float aspectRatio, bool rotation = false);

		void OnUpdate(Timestep ts);
		void OnEvent(Event& e);

		OrthographicCamera& GetCamera() { return m_Cam; }
		const OrthographicCamera& GetCamera() const { return m_Cam; }

	private:
		bool OnMouseScrolled(MouseScrolledEvent& e);
		bool OnWindowResized(WindowResizeEvent& e);
	private:
		float m_AspectRatio;
		float m_ZoomLevel = 1.0f;
		OrthographicCamera m_Cam;

		bool m_Rotation;

		glm::vec3 m_CamPos = { 0.0f, 0.0f,0.0f };
		float m_CamRotation = 0.0f;
		float m_CamTranslateSpeed = 5.0f, m_CamRotationSpeed = 180.f;
	};
}