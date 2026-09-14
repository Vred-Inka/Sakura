#pragma once
#include <map>
#include "Engine/rendering/Color.h"

class Renderer;
class Pill;


class PillRenderer
{
public:
	static void Draw(Renderer& renderer, const Pill& pill);
	static void DrawPill(Renderer& renderer, Pill& pill);	


	ColorRGB& GetColorRGBFromColor(const Color& color) { return Colors[color]; }

private:
	std::map<Color, ColorRGB> Colors =
	{
		{Color::Red, ColorRGB{232, 48, 48}},
		{Color::Blue, ColorRGB{48,104,232} },
		{Color::Yellow, ColorRGB{248,216,64}},
		{Color::Black, ColorRGB{75,75,75}},
		{Color::Green, ColorRGB{0,255,0}}
	};
};

