#include "Renderer.h"

#include <SDL3/SDL.h>
#include <iostream>

#include "Texture.h"
#include "../platform/Window.h"

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
	SDL_SetRenderDrawColor(m_Renderer, 20, 40, 40, 255);
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

void Renderer::DrawTexture(const Texture& texture, float x, float y)
{
	SDL_FRect dst
	{
		x, y, texture.GetWidth(), texture.GetHeight()
	};

	SDL_RenderTexture(m_Renderer, texture.GetNativeTexture(), nullptr, &dst);
}

void Renderer::DrawTexture(const Texture& texture, float x, float y, float width, float height)
{
	SDL_FRect dst
	{
		x, y, width, height
	};

	SDL_RenderTexture(m_Renderer, texture.GetNativeTexture(), nullptr, &dst);
}

void Renderer::DrawTextureRotated(const Texture& texture, float x, float y, float width, float height, double angle)
{
	SDL_FRect dst
	{
		x, y, width, height
	};

	SDL_FPoint center
	{
		width / 2.0f,
		height / 2.0f
	};

	SDL_RenderTextureRotated(m_Renderer, texture.GetNativeTexture(), nullptr, &dst, angle, &center, SDL_FLIP_NONE);
}
