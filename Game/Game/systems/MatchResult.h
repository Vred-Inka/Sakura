#pragma once

#include "../gameplay/Board.h"

struct MatchResult
{
	bool m_HasMatches = false;

	bool m_Cells[GameConfig::BoardWidth][GameConfig::BoardHeight] = {};

	int m_VirusCount = 0;
	int m_PillCount = 0;
};