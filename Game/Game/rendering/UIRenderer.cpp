#include "UIRenderer.h"

#include <string>

#include <Engine/assets/AssetsManager.h>

#include "../systems/ScoreSystem.h"

void UIRenderer::Draw(Renderer& renderer, AssetsManager& assets, const ScoreSystem& score)
{
	m_TextRenderer.DrawText(renderer, *assets.GetFont("Score"),
		"Score: " + std::to_string(score.GetScore()), 20.0f, 20.0f);
}

void UIRenderer::DrawText(Renderer& renderer, AssetsManager& assets, const char* text, float x, float y)
{
	m_TextRenderer.DrawText(renderer, *assets.GetFont("Score"),	text, x, y);
}
