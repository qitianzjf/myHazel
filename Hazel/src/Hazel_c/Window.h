#pragma once
#include "hzpch.h"
#include "Hazel_c/Core.h"
#include "Hazel_c/Events/Event.h"

namespace Hazel {

	struct WindowProps {//窗口初始化内容和属性
		std::string Title;
		unsigned int Width;
		unsigned int Height;
		WindowProps(const std::string& title = "Hazel_Engine", unsigned int width = 1280, unsigned int height = 720)
			: Title(title), Width(width), Height(height) {}
	};

	class HAZEL_API Window {//接口类,基本的桌面窗口系统
	public:
		using EventCallBackFn = std::function<void(Event&)>;
		virtual ~Window() {}

		virtual void OnUpdate() = 0;
		
		virtual unsigned int GetHeight() const = 0;
		virtual unsigned int GetWidth() const = 0;

		virtual void SetEventCallBack(const EventCallBackFn& callback) = 0;
		virtual void SetVSync(bool enabled) = 0;
		virtual bool IsVSync() const = 0;

		virtual void* GetNaiveWindow() const = 0;//这里不是GLFW的指针，是因为如果不用GLFW窗口而用别的窗口系统，可以很好的转换指针

		static Window* Create(const WindowProps& props = WindowProps());
	};
}