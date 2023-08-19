#pragma once

#ifdef HZ_PLATFORM_WINDOWS

extern Hazel::Application* CreateApplication();

int main(int argc, char** argv) {
	auto app = Hazel::CreateApplication();
	app->run();
	delete app;
}

#endif