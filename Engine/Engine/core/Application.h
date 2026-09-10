#pragma once
#include "Platform/Window.h"
#include "Rendering/Renderer.h"

class Application
{
public:
	bool Initialize();
	void Run();
	void Shutdown();

	void ProcessEvents();

private:
	bool m_Running = false;

	Window m_Window;
	Renderer m_Renderer;
};

