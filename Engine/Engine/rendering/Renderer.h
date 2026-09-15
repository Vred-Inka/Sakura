#pragma once
#include <cstdint>
#include "Color.h"

struct SDL_Renderer;

class Window;
class Texture;

class Renderer
{
public:
	bool Create(Window& window);
	void Destroy();

	void BeginFrame();
	void EndFrame();

	void DrawRect( float x,	float y, float width, float height,	const ColorRGB& color);

	void DrawTexture(const Texture& texture, float x, float y);

	SDL_Renderer* GetNativeRenderer() { return m_Renderer; };

private:
	SDL_Renderer* m_Renderer = nullptr;
};

