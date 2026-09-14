#pragma once
#include <vector>

class Board;
struct CellPosition;

struct MatchResult;

class MatchingSystem
{
public:
	MatchResult FindMatches(Board& board);
};

