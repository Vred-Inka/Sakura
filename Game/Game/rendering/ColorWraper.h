#pragma once
#include "Engine/rendering/Color.h"

static std::map<Color, ColorRGB> Colors =
{
	{Color::Red, ColorRGB{232, 48, 48}},
	{Color::Blue, ColorRGB{48,104,232} },
	{Color::Yellow, ColorRGB{248,216,64}},
	{Color::Black, ColorRGB{75,75,75}},
	{Color::Green, ColorRGB{0,255,0}}
};

static ColorRGB& GetColorRGBColor(const Color& color) { return Colors[color]; }

static std::string GetColorName(const Color& color)
{
    switch (color)
    {
    case Color::Red:
        return "Red";
    case Color::Blue:
        return "Blue";
    case Color::Yellow:
        return "Yellow";
    default:
        return "Black";
    }
}
