#include "FallingSystem.h"

#include "../gameplay/Board.h"
#include "../gameplay/Pill.h"

FallResult FallingSystem::Update(float dt, Board& board, Pill& pill)
{
	m_Timer += dt;

	if (m_Timer < m_FallDelay)
		return FallResult::None;

	m_Timer = 0.0f;

	if (board.CanMoveDown(pill))
	{
		pill.MoveDown();
		return FallResult::None;
	}
	
	return FallResult::Locked;
}
