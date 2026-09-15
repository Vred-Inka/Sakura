#include "BoardRenderer.h"

#include "Engine/rendering/Texture.h"
#include "Engine/assets/AssetsManager.h"

#include "ColorWraper.h"

#include "../gameplay/Board.h"
#include "../gameplay/Cell.h"

BoardRenderer::BoardRenderer(AssetsManager& assets)
	:m_Assets(assets)
{}

void BoardRenderer::Draw(Renderer& renderer, const Board& board)
{
	for (int col = 0; col < board.s_Width; ++col)
	{
		for (int row = 0; row < board.s_Height; ++row)
		{
			float x = Board::s_BorderX + col * Board::s_CellSize;
			float y = Board::s_BorderY + row * Board::s_CellSize;
			
			Cell cell = board.GetCell(col, row);
			//renderer.DrawRect(x, y, Board::s_CellSize, Board::s_CellSize, GetColorRGBColor(cell.GetColor()));
			renderer.DrawTexture(GetTextureForCell(cell), x, y);
		}
	}
}

const Texture& BoardRenderer::GetTextureForCell(const Cell& cell)
{
	std::string textureName = cell.GetCellTextureName();
	return m_Assets.GetTexture(textureName);
}



