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

void Board::SetVirus(int col, int row, const Color& color)
{
	Cell& cell = GetCell(col, row);
	cell.SetCellType(CellType::Virus);
	cell.SetConnection(Connection::None);
	cell.SetColor(color);
	m_VirusCount++;
}

bool Board::CanMoveLeft(const Pill& pill) const
{
	// ensure we don't go out of bounds on the left
	if (pill.GetX() == 0)
		return false;

	// check the cells to the left for occupation
	if (pill.GetOrientation() == Orientation::Horizontal)
	{
		if (IsCellOccupied(pill.GetX() - 1, pill.GetY()))
			return false;
	}
	else
	{
		// vertical pill: left movement affects both halves; ensure row bounds
		if (IsCellOccupied(pill.GetX() - 1, pill.GetY()))
			return false;

		if (pill.GetY() > 0)
		{
			if (IsCellOccupied(pill.GetX() - 1, pill.GetY() - 1))
				return false;
		}
	}

	return true;
}

bool Board::CanMoveRight(const Pill& pill) const
{
	// Horizontal: moving right checks x+2 (both halves shift right)
	if (pill.GetOrientation() == Orientation::Horizontal)
	{
		if (pill.GetX() + 2 >= GameConfig::BoardWidth)
			return false;

		if (IsCellOccupied(pill.GetX() + 2, pill.GetY()))
			return false;
	}
	else
	{
		// Vertical: moving right checks x+1 for both halves
		if (pill.GetX() + 1 >= GameConfig::BoardWidth)
			return false;

		if (IsCellOccupied(pill.GetX() + 1, pill.GetY()))
			return false;

		if (pill.GetY() > 0)
		{
			if (IsCellOccupied(pill.GetX() + 1, pill.GetY() - 1))
				return false;
		}
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

bool Board::CanRotate(const Pill& pill) const
{
	if (pill.GetOrientation() == Orientation::Horizontal)
	{
		// rotating from horizontal to vertical needs space above
		if (pill.GetY() == 0)
			return false;

		if (IsCellOccupied(pill.GetX(), pill.GetY() - 1))
			return false;
	}
	else
	{
		// rotating from vertical to horizontal needs space to the right
		if (pill.GetX() + 1 >= GameConfig::BoardWidth)
			return false;

		if (IsCellOccupied(pill.GetX() + 1, pill.GetY()))
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
			Cell& cell = GetCell(col, row);
			if (cell.GetType() == CellType::Virus)
			{
				--m_VirusCount;
			}

			cell = Cell{};
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
