#include "BoardRenderer.h"

#include "Engine/rendering/Texture.h"
#include "Engine/assets/AssetsManager.h"

#include "ColorHelper.h"

#include "../gameplay/Board.h"
#include "../gameplay/Cell.h"

BoardRenderer::BoardRenderer(AssetsManager& assets)
	:m_Assets(assets)
{}

void BoardRenderer::Draw(Renderer& renderer, const Board& board)
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
				renderer.DrawTexture(*cellTexture, x, y, GameConfig::CellSize, GameConfig::CellSize);
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



