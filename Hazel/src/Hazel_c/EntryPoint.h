#pragma once

#ifdef HZ_PLATFORM_WINDOWS

extern Hazel::Application* Hazel::CreateApplication();

int main(int argc, char** argv) {
	Hazel::Log::Init();
	HZ_CORE_WARN("Initialize");
	int a = 5;
	HZ_INFO("Var={0}", a);

	auto app = Hazel::CreateApplication();
	app->run();
	delete app;
}

#endif