#include "Application.h"

#include<SDL3/SDL.h>
#include <iostream>

bool Application::Initialize()
{
	if (!SDL_Init(SDL_INIT_VIDEO))
	{
		std::cout << "SDL_Init failed: " << SDL_GetError() << std::endl;
		return false;
	}

	if (!m_Window.Create())
	{
		return false;
	}

	if (m_Renderer.Create(m_Window))
	{
		return false;
	}

	m_Running = true;
	return true;
}

void Application::Run()
{
	while (m_Running) {
		Time::Update();
		ProcessEvents();

		m_Renderer.BeginFrame();
		m_Renderer.EndFrame();
	}
}

void Application::Shutdown()
{
	m_Renderer.Destroy();
	m_Window.Destroy();

	SDL_Quit();
}

void Application::ProcessEvents()
{
	SDL_Event event;

	while (SDL_PollEvent(&event)) {
		
		switch (event.type)
		{
		case SDL_EVENT_QUIT:
			m_Running = false;
			break;
		default:
			break;
		}
	}
}
