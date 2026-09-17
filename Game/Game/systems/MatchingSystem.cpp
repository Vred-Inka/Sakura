#include "MatchingSystem.h"

#include "MatchResult.h"
#include "../gameplay/Board.h"

MatchResult MatchingSystem::FindMatches(Board& board)
{
    MatchResult result;

    //Vertical
    for (int col = 0; col < GameConfig::BoardWidth; col++)
    {
        int start = 0;
        int length = 1;

        for (int row = 1; row <= GameConfig::BoardHeight; row++)
        {
            bool sameColor = false;

            if (row < GameConfig::BoardHeight)
            {
                const Cell& previus = board.GetCell(col, row - 1);
                const Cell& current = board.GetCell(col, row);

                sameColor = previus.IsOccupied() && current.IsOccupied()
                    && previus.GetColor() == current.GetColor();
            }

            if (sameColor)
            {
                length++;

                if (length >= 4)
                {
                    result.m_HasMatches = true;

                    for (int i = 0; i < length; i++)
                    {
                        result.m_MatchedCells[col][start + i] = true;
                    }
                }
            }
            else
            {
                start = row;
                length = 1;
            }
        }
    }

    for (int row = 0; row < GameConfig::BoardHeight; row++)
    {
        int start = 0;
        int length = 1;

        for (int col = 1; col <= GameConfig::BoardWidth; col++)
        {
            bool sameColor = false;

            if (col < GameConfig::BoardWidth)
            {
                const Cell& previus = board.GetCell(col - 1 , row);
                const Cell& current = board.GetCell(col, row);

                sameColor = previus.IsOccupied() && current.IsOccupied()
                    && previus.GetColor() == current.GetColor();
            }

            if (sameColor)
            {
                length++;

                if (length >= 4)
                {
                    result.m_HasMatches = true;

                    for (int i = 0; i < length; i++)
                    {
                        result.m_MatchedCells[start + i][row] = true;
                    }
                }
            }
            else
            {
                start = col;
                length = 1;
            }
        }
    }

    return result;
}
