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

int Board::GetVirusCount() const
{
	return -1;
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
	if (pill.GetY() + 1 >= GameConfig::BoardHeight)
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

bool Board::CanSpawnPill() const
{
	return !IsCellOccupied(3, 0) && !IsCellOccupied(4, 0);
}

void Board::MoveCell(int oldCol, int oldRow, int col, int row)
{
	std::swap(GetCell(oldCol, oldRow), GetCell(col, row));
}

void Board::LockPill(Pill& pill)
{
	if (pill.GetOrientation() == Orientation::Horizontal)
	{
		Cell& leftHalf = m_Cells[pill.GetX()][ pill.GetY()];
		Cell& rightHalf = m_Cells[pill.GetX() + 1][ pill.GetY()];

		leftHalf.SetCellType(CellType::Pill);
		leftHalf.SetConnection(Connection::Left);
		leftHalf.SetColor(pill.GetFirstColor());

		rightHalf.SetCellType(CellType::Pill);
		rightHalf.SetConnection(Connection::Right);
		rightHalf.SetColor(pill.GetSecondColor());

	}
	else
	{
		Cell& downHalf = m_Cells[pill.GetX()][ pill.GetY()];
		Cell& upHalf = m_Cells[pill.GetX()][ pill.GetY() - 1];

		upHalf.SetCellType(CellType::Pill);
		upHalf.SetConnection(Connection::Up);
		upHalf.SetColor(pill.GetSecondColor());

		downHalf.SetCellType(CellType::Pill);
		downHalf.SetConnection(Connection::Down);
		downHalf.SetColor(pill.GetFirstColor());
	}
}

void Board::RemoveMatches(const MatchResult& result)
{
	if (!result.m_HasMatches)
		return;

	for (int col = 0; col < GameConfig::BoardWidth; col++)
	{
		for (int row = 0; row < GameConfig::BoardHeight; row++)
		{
			if (!result.m_MatchedCells[col][row])
				continue;

			BreakCellConnections(col, row);
			m_Cells[col][row].SetCellType(CellType::Empty);
			m_Cells[col][row].SetColor(Color::Black);
		}

	}
}

void Board::BreakCellConnections(int col, int row)
{
	Cell& cell = m_Cells[col][row];

	switch (cell.GetConnection())
	{
	case Connection::Left:
		m_Cells[col + 1][row].SetConnection(Connection::None);
		break;

	case Connection::Right:
		m_Cells[col - 1][row].SetConnection(Connection::None);
		break;

	case Connection::Up:
		m_Cells[col][row + 1].SetConnection(Connection::None);
		break;

	case Connection::Down:
		m_Cells[col][row - 1].SetConnection(Connection::None);
		break;

	default:
		break;
	}
}
