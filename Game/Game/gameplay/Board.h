#pragma once
#include "Cell.h"
#include "GridPosition.h"

class Pill;
struct MatchResult;

class Board
{
public:
	static constexpr int s_Width = 8;
	static constexpr int s_Height = 16;


	static constexpr float s_CellSize = 32.0f;

	static constexpr float s_BorderX = 100.0f;
	static constexpr float s_BorderY = 50.0f;


	const Cell& GetCell(int column, int row) const { return m_Cells[column][row]; }
	Cell& GetCell(int column, int row) { return m_Cells[column][row]; }
	
	bool IsCellOccupied(const GridPosition& position)const;
	bool IsCellOccupied(int column, int row) const;

	bool CanMoveLeft(const Pill& pill) const;
	bool CanMoveRight(const Pill& pill) const;
	bool CanMoveDown(const Pill& pill) const;

	void LockPill(Pill& pill);

	void RemoveMatches(const MatchResult& result);

private:
	Cell m_Cells[s_Width][s_Height];
};

