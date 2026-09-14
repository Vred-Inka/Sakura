#include "BoardRenderer.h"

#include "ColorWraper.h"
#include "../gameplay/Board.h"

void BoardRenderer::Draw(Renderer& renderer, const Board& board)
{
	for (int col = 0; col < board.s_Width; ++col)
	{
		for (int row = 0; row < board.s_Height; ++row)
		{
			float x = Board::s_BorderX + col * Board::s_CellSize;
			float y = Board::s_BorderY + row * Board::s_CellSize;
			
			Cell cell = board.GetCell(col, row);
			renderer.DrawRect(x, y, Board::s_CellSize, Board::s_CellSize, GetColorRGBColor(cell.GetColor()));
		}
	}
}

/*
void DrawCell(const Cell& cell)
{
	switch (cell.Connection)
	{
	case Connection::None:
			DrawSingle();
			break;
		6

			7
	case Connection::Right:
		8
			DrawLeftHalf();
		9
			break;
		10

			11
	case Connection::Left:
		12
			DrawRightHalf();
		13
			break;
		14

			15
	case Connection::Down:
		16
			DrawTopHalf();
		17
			break;
		18

			19
	case Connection::Up:
		20
			DrawBottomHalf();
		21
			break;
		22
	}
}
*/
