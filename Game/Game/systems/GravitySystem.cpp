#include "GravitySystem.h"

#include "../gameplay/Board.h"

bool GravitySystem::Apply(Board& board)
{
    bool moved = false;

    for (int row = Board::s_Height - 2; row >= 0; row--)
    {
        for (int col = 0; col < Board::s_Width; col++)
        {
            if (!board.IsCellOccupied(col, row))
                continue;

            if (board.IsCellOccupied(col, row + 1))
                continue;

            Cell& cell = board.GetCell(col, row);

            if(cell.GetConnection() == Connection::None)
            {
                board.MoveCell(col, row, col, row + 1);
                moved = true;
            }
            else if (cell.GetConnection() == Connection::Right)
            {
                if (!board.IsCellOccupied(col + 1, row))
                    continue;

                if (board.IsCellOccupied(col + 1, row + 1))
                    continue;

                board.MoveCell(col, row, col, row + 1);
                board.MoveCell(col + 1, row, col + 1, row + 1);
                moved = true;
            }
            else if (cell.GetConnection() == Connection::Down)
            {
                board.MoveCell(col, row, col, row + 1);
                board.MoveCell(col, row - 1, col, row);
                moved = true;
            }
        }

    }
    return moved;
}
