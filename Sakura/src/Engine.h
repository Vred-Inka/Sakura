#pragma once
#include <SDL3/SDL.h>

class Engine
{
public:
	bool Init();
	void Run();
	void Shutdown();

private:
	SDL_Window* m_Window = nullptr;
	SDL_Renderer* m_Renderer = nullptr;
	bool m_Running = false;
};

