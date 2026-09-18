#include "VirusSpawner.h"

#include "../rendering/ColorHelper.h"

#include "Board.h"

void VirusSpawner::Spawn(Board& board, int virusCount)
{
	int created = 0;

	while (created < virusCount)
	{
		int col = rand() % GameConfig::BoardWidth;
		int row = GameConfig::BoardHeight / 2 + rand() % (GameConfig::BoardHeight /2);

		if (board.IsCellOccupied(col, row))
		{
			continue;
		}

		board.SetVirus(col, row, GetRandomColor());

		++created;
	}
}
