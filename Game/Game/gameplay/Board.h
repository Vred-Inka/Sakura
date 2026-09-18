#pragma once
#include "Cell.h"
#include "GridPosition.h"
#include "../config/GameConfig.h"

class Pill;
struct MatchResult;

class Board
{
public:
	const Cell& GetCell(int column, int row) const { return m_Cells[column][row]; }
	Cell& GetCell(int column, int row) { return m_Cells[column][row]; }
	
	bool IsCellOccupied(const GridPosition& position)const;
	bool IsCellOccupied(int column, int row) const;

	void SetVirus(int col, int row, const Color& color);
	int GetVirusCount() const { return m_VirusCount; };

	bool CanMoveLeft(const Pill& pill) const;
	bool CanMoveRight(const Pill& pill) const;
	bool CanMoveDown(const Pill& pill) const;
	bool CanRotate(const Pill& pill) const;

	bool CanSpawnPill() const;

	void MoveCell(int oldCol, int oldRow, int col, int row);

	void LockPill(Pill& pill);
	void BreakCellConnections(int col, int row);

	void RemoveMatches(const MatchResult& result);

private:
	Cell m_Cells[GameConfig::BoardWidth][GameConfig::BoardHeight];
	int m_VirusCount = 0;
};

