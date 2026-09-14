#include "Renderer.h"
#include <SDL3/SDL.h>
#include <iostream>

#include "platform/Window.h"

bool Renderer::Create(Window& window)
{	
	m_Renderer = SDL_CreateRenderer(window.GetNativeWindow(), nullptr);
	if (!m_Renderer)
	{
		std::cout << "SDL_CreateRenderer failed: " << SDL_GetError() << std::endl;
		return false;
	}

	return true;
}

void Renderer::Destroy()
{
	SDL_DestroyRenderer(m_Renderer);
	m_Renderer = nullptr;
}

void Renderer::BeginFrame()
{
	SDL_SetRenderDrawColor(m_Renderer, 50, 50, 50, 255);
	SDL_RenderClear(m_Renderer);
}

void Renderer::EndFrame()
{
	SDL_RenderPresent(m_Renderer);
}

void Renderer::DrawRect(float x, float y, float width, float height, const ColorRGB& color)
{
	SDL_FRect rect{ x,y,width,height };
	SDL_SetRenderDrawColor(m_Renderer, color.r, color.g, color.b, 255);

	SDL_RenderFillRect(m_Renderer, &rect);
}
