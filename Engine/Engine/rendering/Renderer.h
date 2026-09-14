#pragma once
#include <cstdint>
#include "Color.h"

struct SDL_Renderer;

class Window;

class Renderer
{
public:
	bool Create(Window& window);
	void Destroy();

	void BeginFrame();
	void EndFrame();

	void DrawRect(
		float x,
		float y,
		float width,
		float height,
		const ColorRGB& color
		);

private:
	SDL_Renderer* m_Renderer = nullptr;
};

