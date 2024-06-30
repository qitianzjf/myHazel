#pragma once

#include "Core\Layer.h"
#include "Hazel_c\Events\MouseEvent.h"
#include "Hazel_c\Events\KeyEvent.h"
#include "Hazel_c\Events\ApplicationEvent.h"

namespace Hazel {
	
	class HAZEL_API ImGuiLayer: public Layer{
	public:
		ImGuiLayer();
		~ImGuiLayer();

		virtual void OnAttach() override; //layer����layerstack�е�push����ʱ�����г�ʼ�����������ʼ��imguilayer�����д�������
		virtual void OnDetach() override;//layer���Ƴ���ʱ���������������ĵȲ���
		virtual void OnImGuiRender() override;

		void Begin();//
		void End();//

	private:
		float m_Time = 0.0f;
	};
}