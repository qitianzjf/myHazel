#include "hzpch.h"

#include "Application.h"

#include "Log.h"
#include<glad/glad.h>
#include "GLFW\glfw3.h"

#include "Input.h"

namespace Hazel{

#define BIND_EVENT_FN(x) std::bind(&Application::x, this, std::placeholders::_1)

	Application* Application::s_Instance = nullptr;//static��Ա�������ⶨ��һ��

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
		for (auto it = m_LayerStack.end(); it != m_LayerStack.begin();) { //�Ӻ���ǰ�������¼�
			(*--it)->OnEvent(e);
			if (e.Handled)												 //������¼�������Ϻ󣬾Ͳ����ݸ���һ��
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

			m_ImGuiLayer->Begin();//ͳһ��ʼ�µ�֡
			for (Layer* layer : m_LayerStack)
				//���е�ImGuiRender��������һ��ͳһ��begin��end֮��
				//ÿһ�㶼���ö�Ӧ��imguirender��������Ӧ����Ⱦ����
				layer->OnImGuiRender();
			m_ImGuiLayer->End();//ͳһ�����Ľ����Ⱦ��imgui����

			m_Window->OnUpdate();
		}
	}

	bool Application::OnWindowClose(WindowCloseEvent& e) {
		m_Running = false;
		return true;
	}
}
