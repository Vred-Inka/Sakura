#pragma once

#include <string>

class Renderer;
class Font;

class TextRenderer
{
public:
	void DrawText(Renderer& renderer, Font& font, const std::string& text, float x, float y);
};