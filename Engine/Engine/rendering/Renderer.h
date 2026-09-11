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
		const Color& color
		);


	ColorRGB& GetColorRGBFromColor(const Color& color) { return Colors[color]; }

private:
	SDL_Renderer* m_Renderer = nullptr;

	std::map<Color, ColorRGB> Colors =
	{
		{Color::Magenta, ColorRGB{200, 0, 165}},
		{Color::Blue, ColorRGB{0,0,255} },
		{Color::Yellow, ColorRGB{255,255,0}},
		{Color::Black, ColorRGB{75,75,75}}
	};
};

