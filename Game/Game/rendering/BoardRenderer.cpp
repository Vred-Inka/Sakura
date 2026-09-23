#include "BoardRenderer.h"

#include "Engine/rendering/Texture.h"
#include "Engine/assets/AssetsManager.h"

#include "ColorHelper.h"

#include "../gameplay/Board.h"
#include "../gameplay/Cell.h"
#include "../systems/MatchResult.h"

BoardRenderer::BoardRenderer(AssetsManager& assets)
	:m_Assets(assets)
{}

void BoardRenderer::Draw(Renderer& renderer, const Board& board, const MatchResult* matchResult, float amimationTime)
{
	for (int col = 0; col < GameConfig::BoardWidth; ++col)
	{
		for (int row = 0; row < GameConfig::BoardHeight; ++row)
		{
			float x = GameConfig::BorderX + col * GameConfig::CellSize;
			float y = GameConfig::BorderY + row * GameConfig::CellSize;
			
			Cell cell = board.GetCell(col, row);
			
			if (const Texture* cellTexture = GetTextureForCell(cell))
			{
				uint8_t alpha = 255;
				bool matched = false;

				if (matchResult != nullptr)
				{
					matched = matchResult->m_Cells[col][row];
				}				

				bool flash = std::sin(amimationTime * 30.0f) > 0.0f;
				if (matched && flash)
				{
					float t = amimationTime / 0.3f;
					alpha = static_cast<uint8_t>(255.0f * (1.0f - t));
				}

				renderer.DrawTexture(*cellTexture, x, y, GameConfig::CellSize, GameConfig::CellSize, alpha);
				//renderer.DrawTextureRotated(*cellTexture, x, y, GameConfig::CellSize, GameConfig::CellSize, cell.GetCellTextureAngle());
			}
		}
	}
}

const Texture* BoardRenderer::GetTextureForCell(const Cell& cell)
{
	std::string textureName = GetColorName(cell.GetColor());

	if (cell.GetType() == CellType::Virus)
	{
		textureName += "Virus";
	}
	else
	{
		textureName += cell.GetConnectionName();
	}

	return m_Assets.GetTexture(textureName);
}



