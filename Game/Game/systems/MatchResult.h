#pragma once

#include "../gameplay/Board.h"

struct MatchResult
{
	bool m_HasMatches = false;

	bool m_MatchedCells[GameConfig::BoardWidth][GameConfig::BoardHeight] = {};
};