#pragma once
#include <glm\glm.hpp>

namespace Hazel {
	class OrthographicCamera {
	public:
		OrthographicCamera(float left, float right, float  bottom, float top);
		
		const glm::vec3& GetPosition() const { return m_Position; }
		void SetPosition(const glm::vec3& pos) {
			m_Position = pos;
			RecalculateViewMatrix();
		}

		float GetRotation() const { return m_Rotation; }
		void SetRotation(float rotation) {
			m_Rotation = rotation;
			RecalculateViewMatrix();
		}

		const glm::mat4& GetProjectionMatrix() const { return m_ProjectionMatrix; }
		const glm::mat4& GetViewMatrix() const { return m_ViewMatrix; }
		const glm::mat4& GetViewProjectionMatrix() const { return m_ViewProjectionMatrix; }

	private:
		void RecalculateViewMatrix();
	private:
		//gl_Position = project * view * model * vertPos;gl_Position = project * view * model * vertPos;
		//其中，project*view，合称vp矩阵，它应该属于相机，
		// 因为同一个相机里的所有的物体的vp矩阵都是一样的，而model矩阵应该属于物体对应的对象（比如Unity的GameObject），vertPos则属于网格上的点。
		glm::mat4 m_ProjectionMatrix;
		glm::mat4 m_ViewMatrix;
		glm::mat4 m_ViewProjectionMatrix;

		glm::vec3 m_Position = { 0.0f, 0.0f, 0.0f };
		float m_Rotation = 0.0f;
	};
}