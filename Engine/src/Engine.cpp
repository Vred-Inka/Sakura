#include "../include/Engine/Engine.h"
#include <iostream>

bool Engine::Init()
{
    if (!SDL_Init(SDL_INIT_VIDEO))
    {
        std::cout << "SDL_Init failed: " << SDL_GetError() << std::endl;
        return false;
    }

    m_Window = SDL_CreateWindow("Engine Window", 800, 600, SDL_WINDOW_RESIZABLE);
    if (!m_Window) 
    {
        std::cout << "SDL_CreateWindow failed: " << SDL_GetError() << std::endl;
        SDL_Quit();
        return false;
    }

	m_Renderer = SDL_CreateRenderer(m_Window, nullptr);
	if (!m_Renderer) 
    {
        std::cout << "SDL_CreateRenderer failed: " << SDL_GetError() << std::endl;
        return false;
		return false;
	}

	m_Running = true;
	return true;
}

void Engine::Run()
{
    while (m_Running) {
        SDL_Event event;
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_EVENT_QUIT) {
                m_Running = false;
            }
        }

		SDL_SetRenderDrawColor(m_Renderer, 50, 50, 50, 255);
        SDL_RenderClear(m_Renderer);
		SDL_RenderPresent(m_Renderer);
    }
}

void Engine::Shutdown()
{
	SDL_DestroyRenderer(m_Renderer);
	SDL_DestroyWindow(m_Window);
	SDL_Quit();
}
