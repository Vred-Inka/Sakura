#include "GameplayState.h"

#include "Engine/platform/input/Input.h"
#include "Engine/framework/StateMachine.h"

#include "../gameplay/Pill.h"
#include "../rendering/PillRenderer.h"
#include "../systems/FallingSystem.h"


void GameplayState::Enter()
{
}

void GameplayState::Exit()
{
	
}

void GameplayState::Update(float dt)
{
	HandleInput();

	FallResult result = m_FallingSystem.Update(dt, m_Board, m_ActivePill);	

	if (result == FallResult::Locked)
	{
		m_Board.LockPill(m_ActivePill);

		SpawnNewPill();
	}
}

void GameplayState::Render(Renderer& renderer)
{
	PillRenderer::Draw(renderer, m_ActivePill);
}

void GameplayState::HandleInput()
{
	if (Input::IsKeyDown(Key::Left))
	{
		if (m_Board.CanMoveLeft(m_ActivePill))
		{
			m_ActivePill.MoveLeft();
		}
	}

	if (Input::IsKeyDown(Key::Right))
	{
		if (m_Board.CanMoveRight(m_ActivePill))
		{
			m_ActivePill.MoveRight();
		}
	}

	if (Input::IsKeyDown(Key::Down))
	{
		if (m_Board.CanMoveDown(m_ActivePill))
		{
			m_ActivePill.MoveDown();
		}
	}

	if (Input::IsKeyDown(Key::Space))
	{
		m_ActivePill.Rotate();
	}
}

void GameplayState::SpawnNewPill()
{
	m_ActivePill.SetPosition(4, 0);
}
