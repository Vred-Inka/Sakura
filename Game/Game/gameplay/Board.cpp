#include "Board.h"
#include "Pill.h"

bool Board::IsCellOccupied(const GridPosition& position) const
{
	return m_Cells[position.m_Column][position.m_Row].IsOccupied();
}

bool Board::IsCellOccupied(int column, int row) const
{
	return m_Cells[column][row].IsOccupied();
}

bool Board::CanMoveLeft(const Pill& pill) const
{
	if (pill.GetX() == 0)
		return false;

	if (IsCellOccupied(pill.GetX() - 1, pill.GetY()))
		return false;

	return true;
}

bool Board::CanMoveRight(const Pill& pill) const
{
	if (pill.GetX() == s_Width)
		return false;

	if (IsCellOccupied(pill.GetX() + 1, pill.GetY()))
		return false;

	return true;
}

bool Board::CanMoveDown(const Pill& pill) const
{
	if (pill.GetY() == s_Height)
		return false;

	if (IsCellOccupied(pill.GetX(), pill.GetY() + 1))
		return false;

	return true;
}

void Board::LockPill()
{
}
