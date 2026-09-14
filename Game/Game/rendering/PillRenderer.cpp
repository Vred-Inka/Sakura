#include "PillRenderer.h"

#include <Engine/rendering/Renderer.h>
#include "ColorWraper.h"
#include "../gameplay/Board.h"
#include "../gameplay/Pill.h"

void PillRenderer::Draw(Renderer& renderer, const Pill& pill)
{
	float x = Board::s_BorderX + pill.GetX() * Board::s_CellSize;
	float y = Board::s_BorderY + pill.GetY() * Board::s_CellSize;

	if (pill.GetOrientation() == Orientation::Horizontal)
	{
		renderer.DrawRect(x, y, Board::s_CellSize, Board::s_CellSize, GetColorRGBColor(pill.GetFirstColor()));
		renderer.DrawRect(x + Board::s_CellSize, y, Board::s_CellSize, Board::s_CellSize, GetColorRGBColor(pill.GetSecondColor()));
	} 
	else
	{
		renderer.DrawRect(x, y, Board::s_CellSize, Board::s_CellSize, GetColorRGBColor(pill.GetFirstColor()));
		renderer.DrawRect(x, y - Board::s_CellSize, Board::s_CellSize, Board::s_CellSize, GetColorRGBColor(pill.GetSecondColor()));
	}
}


