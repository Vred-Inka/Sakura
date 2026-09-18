#include "PillRenderer.h"

#include <Engine/assets/AssetsManager.h>
#include <Engine/rendering/Renderer.h>

#include "ColorHelper.h"
#include "../gameplay/Board.h"
#include "../gameplay/Pill.h"

PillRenderer::PillRenderer(AssetsManager& assets)
	:m_Assets(assets)
{}

void PillRenderer::Draw(Renderer& renderer, const Pill& pill)
{
	float x = GameConfig::BorderX + pill.GetX() * GameConfig::CellSize;
	float y = GameConfig::BorderY + pill.GetY() * GameConfig::CellSize;

	std::string firstColor = GetColorName(pill.GetFirstColor());
	std::string secondColor = GetColorName(pill.GetSecondColor());

	if (pill.GetOrientation() == Orientation::Horizontal)
	{
		renderer.DrawTexture(*m_Assets.GetTexture(firstColor + "Left"), x, y, GameConfig::CellSize, GameConfig::CellSize);
		renderer.DrawTexture(*m_Assets.GetTexture(secondColor + "Right"), x + GameConfig::CellSize, y, GameConfig::CellSize, GameConfig::CellSize);
	} 
	else
	{
		renderer.DrawTexture(*m_Assets.GetTexture(firstColor + "Down"), x, y, GameConfig::CellSize, GameConfig::CellSize);
		renderer.DrawTexture(*m_Assets.GetTexture(secondColor + "Up"), x, y - GameConfig::CellSize, GameConfig::CellSize, GameConfig::CellSize);
	}
}


