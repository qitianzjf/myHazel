#pragma once
#include "Core.h"

#include "Hazel_c/Events/Event.h"
#include "Hazel_c/Events/ApplicationEvent.h"
#include "LayerStack.h"
#include "Hazel_c\ImGui\ImGuiLayer.h"
#include "Window.h"
#include "Input.h"

namespace Hazel {
	class HAZEL_API Application
	{
	public:
		Application();
		virtual ~Application();
		void OnEvent(Event& e);
		void run();

		void PushLayer(Layer* layer);
		void PushOverlay(Layer* overlay);

		inline Window& GetWindow() { return *m_Window; }

		inline static Application& Get() { return *s_Instance; }
	private:
		bool OnWindowClose(WindowCloseEvent& e);
		bool OnWindowResize(WindowResizeEvent& e);

		std::unique_ptr<Window>m_Window;
		bool m_Running = true;
		bool m_Minimized = false;
		LayerStack m_LayerStack;
		ImGuiLayer* m_ImGuiLayer;//使imguilayer成为Hazel内在部分
		static Application* s_Instance;//Application持有的单例
		float m_LastFrameTime = 0.0f;
	};

	Application* CreateApplication();
}

