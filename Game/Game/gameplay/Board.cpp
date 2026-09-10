#include "Board.h"

bool Board::IsCellOccupied(const GridPosition& position)
{
	return m_Cells[position.m_Colomn][position.m_Row].IsOccupied();
}

bool Board::CanMoveLeft()
{
	return false;
}

bool Board::CanMoveRight()
{
	return false;
}

bool Board::CanMoveDown()
{
	return false;
}
