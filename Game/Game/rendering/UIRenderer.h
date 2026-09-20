#pragma once
#include <Engine/Rendering/TextRenderer.h>

class Renderer;
class AssetsManager;
class ScoreSystem;

class UIRenderer
{
public:
	void Draw(Renderer& renderer, AssetsManager& assets, const ScoreSystem& score);

private:
	TextRenderer m_TextRenderer;

};

