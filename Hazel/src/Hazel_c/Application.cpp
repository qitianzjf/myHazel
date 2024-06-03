#include "hzpch.h"

#include "Application.h"

#include "Log.h"
#include<glad/glad.h>
#include "GLFW\glfw3.h"

#include "Input.h"

namespace Hazel{

#define BIND_EVENT_FN(x) std::bind(&Application::x, this, std::placeholders::_1)

	Application* Application::s_Instance = nullptr;//static成员变量类外定义一次

	Application::Application() {
		HZ_CORE_ASSERT(!s_Instance, "Application already exists!");
		s_Instance = this;

		m_Window = std::unique_ptr<Window>(Window::Create());
		m_Window->SetEventCallBack(BIND_EVENT_FN(OnEvent));

		m_ImGuiLayer = new ImGuiLayer();
		PushOverlay(m_ImGuiLayer);
	}

	Application::~Application() {

	}

	void Application::PushLayer(Layer* layer) {
		m_LayerStack.PushLayer(layer);
		layer->OnAttach();
	}

	void Application::PushOverlay(Layer* overlay) {
		m_LayerStack.PushOverlay(overlay);
		overlay->OnAttach();
	}

	void Application::OnEvent(Event& e) {
		EventDispatcher dispacher(e);
		dispacher.Dispatch<WindowCloseEvent>(BIND_EVENT_FN(OnWindowClose));
		//HZ_CORE_TRACE("{0}", e);
		for (auto it = m_LayerStack.end(); it != m_LayerStack.begin();) { //从后往前处理处理事件
			(*--it)->OnEvent(e);
			if (e.Handled)												 //当这个事件处理完毕后，就不传递给下一层
				break;
		}
	}

	void Application::run() {
		//WindowResizeEvent e(1280, 720);
		/*if (e.IsInCategory(EventCategoryApplication))
		{
			HZ_TRACE(e);
		}
		if (e.IsInCategory(EventCategoryInput))
		{
			HZ_TRACE(e);
		}*/
		while (m_Running) {
			for (Layer* layer : m_LayerStack)
				layer->OnUpdate();

			//auto [x, y] = Input::GetMousePos();
			//HZ_CORE_TRACE("{0}, {1}", x, y);

			m_ImGuiLayer->Begin();//统一开始新的帧
			for (Layer* layer : m_LayerStack)
				//所有的ImGuiRender都包含在一个统一的begin和end之间
				//每一层都调用对应的imguirender，进行相应的渲染操作
				layer->OnImGuiRender();
			m_ImGuiLayer->End();//统一把最后的结果渲染到imgui界面

			m_Window->OnUpdate();
		}
	}

	bool Application::OnWindowClose(WindowCloseEvent& e) {
		m_Running = false;
		return true;
	}
}
