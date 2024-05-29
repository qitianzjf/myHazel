#include "Hazel.h"

class ExampleLayer : public Hazel::Layer {
public:
	ExampleLayer() : Layer("Example") {}

	void OnUpdate() override {
		HZ_INFO("ExampleLayer::OnUpdate");
	}

	void OnEvent(Hazel::Event& event) override {
		HZ_TRACE("{0}", event);
	}
};

class Sandbox : public Hazel::Application {
public:
	Sandbox() {
		PushLayer(new ExampleLayer());
		PushOverlay(new Hazel::ImGuiLayer());//要加上类型说明符Hazel::
	}

	~Sandbox() {

	}
};

Hazel::Application* Hazel::CreateApplication() {
	return new Sandbox();
}
