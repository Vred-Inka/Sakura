#pragma once
#include "Cell.h"
#include "GridPosition.h"

class Pill;

class Board
{
public:
	static constexpr int s_Width = 8;
	static constexpr int s_Height = 16;
	
	bool IsCellOccupied(const GridPosition& position)const;
	bool IsCellOccupied(int column, int row) const;

	bool CanMoveLeft(const Pill& pill) const;
	bool CanMoveRight(const Pill& pill) const;
	bool CanMoveDown(const Pill& pill) const;

	void LockPill();

private:
	Cell m_Cells[s_Height][s_Width];
};

