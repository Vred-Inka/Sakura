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

	if (pill.GetOrientation() == Orientation::Horizontal)
	{
		if (IsCellOccupied(pill.GetX() - 1, pill.GetY()))
			return false;
	}
	else
	{
		if (IsCellOccupied(pill.GetX() - 1, pill.GetY()))
			return false;

		if (IsCellOccupied(pill.GetX() - 1, pill.GetY() - 1))
			return false;
	}

	return true;
}

bool Board::CanMoveRight(const Pill& pill) const
{
	if (pill.GetX() + 2 == s_Width)
		return false;

	if (pill.GetOrientation() == Orientation::Horizontal)
	{
		if (IsCellOccupied(pill.GetX() + 2, pill.GetY()))
			return false;
	}
	else
	{
		if (IsCellOccupied(pill.GetX() + 1, pill.GetY()))
			return false;

		if (IsCellOccupied(pill.GetX() + 1, pill.GetY() - 1))
			return false;
	}

	return true;
}

bool Board::CanMoveDown(const Pill& pill) const
{
	if (pill.GetY() + 1 >= s_Height)
		return false;

	if (pill.GetOrientation() == Orientation::Horizontal)
	{
		if (IsCellOccupied(pill.GetX(), pill.GetY() + 1))
			return false;

		if (IsCellOccupied(pill.GetX() + 1, pill.GetY() + 1))
			return false;
	}
	else
	{
		if (IsCellOccupied(pill.GetX(), pill.GetY() + 1))
			return false;
	}

	return true;
}

void Board::LockPill(Pill& pill)
{
	if (pill.GetOrientation() == Orientation::Horizontal)
	{
		m_Cells[pill.GetX()][pill.GetY()].SetOccupied();
		m_Cells[pill.GetX()][pill.GetY()].SetColor(pill.GetLeftColor());
		m_Cells[pill.GetX()][pill.GetY()].SetRelatedCell(&m_Cells[pill.GetX() + 1][pill.GetY()]);

		m_Cells[pill.GetX() + 1][pill.GetY()].SetOccupied();
		m_Cells[pill.GetX() + 1][pill.GetY()].SetColor(pill.GetRightColor());
		m_Cells[pill.GetX() + 1][pill.GetY()].SetRelatedCell(&m_Cells[pill.GetX()][pill.GetY()]);
	}
	else
	{
		m_Cells[pill.GetX()][pill.GetY()].SetOccupied();
		m_Cells[pill.GetX()][pill.GetY()].SetColor(pill.GetLeftColor());
		m_Cells[pill.GetX()][pill.GetY()].SetRelatedCell(&m_Cells[pill.GetX()][pill.GetY() - 1]);

		m_Cells[pill.GetX()][pill.GetY() - 1].SetOccupied();
		m_Cells[pill.GetX()][pill.GetY() - 1].SetColor(pill.GetRightColor());
		m_Cells[pill.GetX()][pill.GetY() - 1].SetRelatedCell(&m_Cells[pill.GetX()][pill.GetY()]);
	}
}
