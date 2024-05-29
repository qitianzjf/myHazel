#pragma once
#include "hzpch.h"
#include "Hazel_c/Core.h"
#include "Hazel_c/Events/Event.h"

namespace Hazel {

	struct WindowProps {//���ڳ�ʼ�����ݺ�����
		std::string Title;
		unsigned int Width;
		unsigned int Height;
		WindowProps(const std::string& title = "Hazel_Engine", unsigned int width = 1280, unsigned int height = 720)
			: Title(title), Width(width), Height(height) {}
	};

	class HAZEL_API Window {//�ӿ���,���������洰��ϵͳ
	public:
		using EventCallBackFn = std::function<void(Event&)>;
		virtual ~Window() {}

		virtual void OnUpdate() = 0;
		
		virtual unsigned int GetHeight() const = 0;
		virtual unsigned int GetWidth() const = 0;

		virtual void SetEventCallBack(const EventCallBackFn& callback) = 0;
		virtual void SetVSync(bool enabled) = 0;
		virtual bool IsVSync() const = 0;

		virtual void* GetNaiveWindow() const = 0;//���ﲻ��GLFW��ָ�룬����Ϊ�������GLFW���ڶ��ñ�Ĵ���ϵͳ�����Ժܺõ�ת��ָ��

		static Window* Create(const WindowProps& props = WindowProps());
	};
}