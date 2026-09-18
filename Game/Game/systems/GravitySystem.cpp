#include "GravitySystem.h"

#include "../gameplay/Board.h"

bool GravitySystem::Apply(Board& board)
{
    bool moved = false;

    for (int row = GameConfig::BoardHeight - 2; row >= 0; row--)
    {
        for (int col = 0; col < GameConfig::BoardWidth; col++)
        {
            Cell& cell = board.GetCell(col, row);
            if (cell.GetType() == CellType::Virus)
                continue;

            Cell& bottomCell = board.GetCell(col, row + 1);

            if (!cell.IsOccupied() || bottomCell.IsOccupied())
                continue;

            if(cell.GetConnection() == Connection::None)
            {
                board.MoveCell(col, row, col, row + 1);
                moved = true;
            }
            else if (cell.GetConnection() == Connection::Left)
            {
                // will chck with right part of a pill
            }
            else if (cell.GetConnection() == Connection::Right)
            {
                Cell& leftCell = board.GetCell(col + 1, row);
                Cell& leftBottomCell = board.GetCell(col + 1, row + 1);
                if (leftBottomCell.IsOccupied())
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
