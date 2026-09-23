#pragma once
#include <Engine/Rendering/TextRenderer.h>

class Renderer;
class AssetsManager;
class ScoreSystem;

class UIRenderer
{
public:
	void Draw(Renderer& renderer, AssetsManager& assets, const ScoreSystem& score);
	void DrawText(Renderer& renderer, AssetsManager& assets, const char* text, float x, float y);

private:
	TextRenderer m_TextRenderer;

};

