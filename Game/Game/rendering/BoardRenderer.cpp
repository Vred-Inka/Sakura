#include "BoardRenderer.h"

#include "../gameplay/Board.h"

constexpr float CellSize = 32.0f;

constexpr float BoardX = 100.0f;
constexpr float BoardY = 50.0f;

void BoardRenderer::Draw(Renderer& renderer, const Board& board)
{
	for (int column = 0; column < board.s_Width; ++column)
	{
		for (int row = 0; row < board.s_Height; ++row)
		{
			float x = BoardX + column * CellSize;
			float y = BoardY + row * CellSize;
			
			Cell cell = board.GetCell(column, row);

			Color color = Color::Blue;
			if (cell.IsOccupied())

		}
	}
}
