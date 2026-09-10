#include "Application.h"

#include<SDL3/SDL.h>
#include <iostream>

#include "Time.h"
#include "platform/input/Input.h"

Application::Application(IGame& game)
	: m_Game(game)
{}

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

	if (!m_Renderer.Create(m_Window))
	{
		return false;
	}

	m_Game.Initialize();

	m_Running = true;
	return true;

}

void Application::Run()
{
	while (m_Running)
	{
		Time::Update();
		Input::Update();
		ProcessEvents();

		const float dt = Time::GetDeltaTime();
		m_Game.Update(dt);

		m_Renderer.BeginFrame();
		m_Game.Render(m_Renderer);
		m_Renderer.EndFrame();
	}
}

void Application::Shutdown()
{
	m_Game.Shutdown();
	m_Renderer.Destroy();
	m_Window.Destroy();

	SDL_Quit();
}

void Application::ProcessEvents()
{
	SDL_Event event;

	while (SDL_PollEvent(&event))
	{		
		if (event.type == SDL_EVENT_QUIT)
		{
			m_Running = false;
		}

		if (event.key.key == SDLK_ESCAPE)
		{
			Shutdown();
		}

		Input::ProcessEvent(event);
	}
}
