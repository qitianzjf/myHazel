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

		virtual void OnAttach() override; //layer调用layerstack中的push操作时候会进行初始化操作，会初始化imguilayer的所有窗口属性
		virtual void OnDetach() override;//layer被移除的时候会进行消除上下文等操作
		virtual void OnImGuiRender() override;

		void Begin();//
		void End();//

	private:
		float m_Time = 0.0f;
	};
}