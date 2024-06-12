#pragma once
#include "Core.h"

#include "Events/Event.h"
#include "Events/ApplicationEvent.h"
#include "LayerStack.h"
#include "Hazel_c\ImGui\ImGuiLayer.h"
#include "Window.h"
#include "Input.h"

#include "Renderer\Shader.h"
#include "Renderer\Buffer.h"
#include "Renderer\VertexArray.h"

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

		std::unique_ptr<Window>m_Window;
		bool m_Running = true;
		LayerStack m_LayerStack;
		ImGuiLayer* m_ImGuiLayer;//使imguilayer成为Hazel内在部分
		static Application* s_Instance;//Application持有的单例

		std::shared_ptr<Shader> m_Shader;
		std::shared_ptr<VertexArray> m_VertexArray;

		std::shared_ptr<Shader> m_BlueShader;
		std::shared_ptr<VertexArray> m_SquareVA;
	};

	Application* CreateApplication();
}

