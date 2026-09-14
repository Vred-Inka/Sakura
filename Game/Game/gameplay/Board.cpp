#include "Board.h"

#include "Pill.h"
#include "../systems/MatchResult.h"

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

void Board::RemoveMatches(const MatchResult& result)
{
	if (!result.m_HasMatches)
		return;

	for (int col = 0; col < Board::s_Width; col++)
	{
		for (int row = 0; row < Board::s_Height; row++)
		{
			if (!result.m_MatchedCells[col][row])
				continue;

			m_Cells[col][row].SetOccupied(false);
			m_Cells[col][row].SetColor(Color::Green);

		}

	}
}
