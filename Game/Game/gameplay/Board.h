#pragma once
#include "Cell.h"
#include "GridPosition.h"

class Board
{
public:
	static constexpr int s_Width = 8;
	static constexpr int s_Height = 16;
	
	bool IsCellOccupied(const GridPosition& position);

	bool CanMoveLeft();
	bool CanMoveRight();
	bool CanMoveDown();

private:
	Cell m_Cells[s_Height][s_Width];
};

