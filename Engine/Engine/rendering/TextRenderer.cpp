#include "TextRenderer.h"

#include <SDL3/SDL.h>
#include <SDL3/SDL3_ttf/SDL_ttf.h>
#include "Renderer.h"
#include "../UI/Font.h"

void TextRenderer::DrawText(Renderer& renderer, Font& font, const std::string& text, float x, float y)
{
	SDL_Color color = { 255,255,255,255 };

	SDL_Surface* surface = TTF_RenderText_Blended(
		font.GetNativeFont(),
		text.c_str(),
		text.length(),
		color);

	if (surface == nullptr)
		return;

	SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer.GetNativeRenderer(), surface);

	if (texture == nullptr)
	{
		SDL_DestroySurface(surface);
		return;
	}

	SDL_FRect destination =
	{
		x,y,static_cast<float>(surface->w), static_cast<float>(surface->h)
	};

	SDL_RenderTexture(renderer.GetNativeRenderer(), texture, nullptr, &destination);

	SDL_DestroyTexture(texture);
	SDL_DestroySurface(surface);

}
