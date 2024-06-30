#include "hzpch.h"
#include "OrthographicCameraController.h"

#include "Core/Input.h"
#include "Core/KeyCodes.h"

namespace Hazel {
	OrthographicCameraController::OrthographicCameraController(float aspectRatio, bool rotation)
		//��ʼ��˳�����Ҫ���ȳ�ʼ��m_cam�ᵼ��-m_AspectRatio * m_ZoomLevelʱ��ʹ��û��ʼ����m_AspectRatio���Ӷ������￴����ͼ�Σ�ͬʱҪ��֤��Ա������˳��ͳ�ʼ��˳�򱣳�һ��
		: m_AspectRatio(aspectRatio), m_Cam(-m_AspectRatio * m_ZoomLevel, m_AspectRatio* m_ZoomLevel, -m_ZoomLevel, m_ZoomLevel), m_Rotation(rotation)
	{

	}

	void OrthographicCameraController::OnUpdate(Timestep ts)
	{
		if (Input::IsKeyPressed(HZ_KEY_A)) {
			m_CamPos.x -= m_CamTranslateSpeed * ts;
		}
		else if (Input::IsKeyPressed(HZ_KEY_D)) {
			m_CamPos.x += m_CamTranslateSpeed * ts;
		}
		
		if (Input::IsKeyPressed(HZ_KEY_W)) {
			m_CamPos.y += m_CamTranslateSpeed * ts;
		}
		else if (Input::IsKeyPressed(HZ_KEY_S)) {
			m_CamPos.y -= m_CamTranslateSpeed * ts;
		}

		if (m_Rotation) {
			if (Input::IsKeyPressed(HZ_KEY_Q)) {
				m_CamRotation += m_CamRotationSpeed * ts;
			}
			else if (Input::IsKeyPressed(HZ_KEY_E)) {
				m_CamRotation -= m_CamRotationSpeed * ts;
			}

			m_Cam.SetRotation(m_CamRotation);
		}
		m_Cam.SetPosition(m_CamPos);
		m_CamTranslateSpeed = m_ZoomLevel;//���ţ��ŵ�Խ���ٶ�Խ�죬�ŵ�ԽС�ٶ�Խ��
	}

	void OrthographicCameraController::OnEvent(Event& e)
	{
		EventDispatcher dispacher(e);
		dispacher.Dispatch<MouseScrolledEvent>(HZ_BIND_EVENT_FN(OrthographicCameraController::OnMouseScrolled));
		dispacher.Dispatch<WindowResizeEvent>(HZ_BIND_EVENT_FN(OrthographicCameraController::OnWindowResized));
	}

	bool OrthographicCameraController::OnMouseScrolled(MouseScrolledEvent& e)
	{
		m_ZoomLevel -= e.GetYOffset() * 0.25f;
		m_ZoomLevel = std::max(m_ZoomLevel, 0.25f);
		m_Cam.SetProjection(-m_AspectRatio * m_ZoomLevel, m_AspectRatio * m_ZoomLevel, -m_ZoomLevel, m_ZoomLevel);
		return false;
	}

	bool OrthographicCameraController::OnWindowResized(WindowResizeEvent& e)
	{
		m_AspectRatio = (float)e.GetWidth() / (float)e.GetHeight();
		m_Cam.SetProjection(-m_AspectRatio * m_ZoomLevel, m_AspectRatio * m_ZoomLevel, -m_ZoomLevel, m_ZoomLevel);
		return false;
	}
}


