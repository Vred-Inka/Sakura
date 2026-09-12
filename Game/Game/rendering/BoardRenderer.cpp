#include "BoardRenderer.h"

#include "../gameplay/Board.h"

void BoardRenderer::Draw(Renderer& renderer, const Board& board)
{
	for (int column = 0; column < board.s_Width; ++column)
	{
		for (int row = 0; row < board.s_Height; ++row)
		{
			float x = Board::s_BorderX + column * Board::s_CellSize;
			float y = Board::s_BorderY + row * Board::s_CellSize;
			
			Cell cell = board.GetCell(column, row);
			renderer.DrawRect(x, y, Board::s_CellSize, Board::s_CellSize, cell.GetColor());
		}
	}
}
