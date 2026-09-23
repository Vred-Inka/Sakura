#include "GameplayState.h"

#include "Engine/platform/input/Input.h"

#include "../gameplay/Pill.h"
#include "../rendering/BoardRenderer.h"
#include "../rendering/ColorHelper.h"
#include "../rendering/PillRenderer.h"
#include "../systems/FallingSystem.h"
#include "../systems/MatchingSystem.h"
#include "../systems/ScoreSystem.h"
#include "../systems/MatchResult.h"


GameplayState::GameplayState(AssetsManager& assets)
	:m_Assets(assets),
	m_BackgroundRenderer(assets),
	m_BoardRenderer(assets),
	m_PillRenderer(assets)
{
	m_VirusSpawner.Spawn(m_Board, 10);
}

void GameplayState::Enter()
{
	SpawnNewPill();
}

void GameplayState::Exit()
{
	
}

void GameplayState::Update(float dt)
{
	switch (m_Phase)
	{	
	case  BoardPhase::DestroyAnimation:
		UpdateDestroyAnimation(dt);
		break;
	case BoardPhase::Control:
		UpdateControl(dt);
		break;
	case BoardPhase::GameOver:
		UpdateGameOver();
		break;
	case BoardPhase::Gravity:
		UpdateGravity();
		break;
	case BoardPhase::Match:
		UpdateMatch();
		break;
	case BoardPhase::Paused:
		UpdatePaused();
		break;
	case BoardPhase::Spawn:
		UpdateSpawn();
		break;
	case  BoardPhase::Victory:
		UpdateVictory();
		break;
	default:
		break;
	}
}

void GameplayState::UpdateDestroyAnimation(float dt)
{
	m_DestroyAnimation.Update(dt);

	if (!m_DestroyAnimation.IsFinished())
		return;

	m_ScoreSystem.Process(m_LastMatchResult);
	m_Board.RemoveMatches(m_LastMatchResult);

	m_Phase = BoardPhase::Gravity;
}

void GameplayState::UpdateSpawn()
{
	if (!m_Board.CanSpawnPill())
	{
		m_Phase = BoardPhase::GameOver;
		return;
	}

	SpawnNewPill();
	m_Phase = BoardPhase::Control;
}

void GameplayState::UpdateControl(float dt)
{
	HandleInput();

	FallResult result = m_FallingSystem.Update(dt, m_Board, m_ActivePill);

	if (result == FallResult::Locked)
	{
		m_Board.LockPill(m_ActivePill);
		m_Phase = BoardPhase::Match;
	}
}

void GameplayState::UpdateMatch()
{
	MatchResult result = m_MatchingSystem.FindMatches(m_Board);

	if (result.m_HasMatches)
	{
		m_LastMatchResult = result;
		m_DestroyAnimation.Start();
		m_Phase = BoardPhase::DestroyAnimation;
	}
	else
	{
		m_Phase = BoardPhase::Spawn;
	}	
}

void GameplayState::UpdatePaused()
{
	HandleInput();
	// print paused lbl
}

void GameplayState::UpdateGravity()
{
	bool moved = m_GravitySystem.Apply(m_Board);

	if (moved)
	{
		return;
	}


	if (m_Board.GetVirusCount() == 0)
	{
		m_Phase = BoardPhase::Victory;
	}

	m_Phase = BoardPhase::Match;
}

void GameplayState::UpdateGameOver()
{
	GameOver();
}

void GameplayState::UpdateVictory()
{
	//Win();
}

void GameplayState::TogglePause()
{
	if (m_Phase == BoardPhase::Paused)
	{
		m_Phase = m_PreviousPhase;
		return;
	}

	m_PreviousPhase = m_Phase;
	m_Phase = BoardPhase::Paused;
}

void GameplayState::Render(Renderer& renderer)
{
	m_BackgroundRenderer.Draw(renderer);
	m_BoardRenderer.Draw(renderer, m_Board, &m_LastMatchResult, m_DestroyAnimation.GetTime());
	m_PillRenderer.Draw(renderer, m_ActivePill);
	m_UIRenderer.Draw(renderer, m_Assets, m_ScoreSystem);

	if (m_Phase == BoardPhase::Paused)
	{
		m_UIRenderer.DrawText(renderer, m_Assets, "       PAUSED",
			GameConfig::BorderX, GameConfig::WindowHeight / 2.0f);
	}
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

	if (Input::IsKeyDown(Key::Up))
	{
		//m_Board.LockPill(m_ActivePill);
	}

	if (Input::IsKeyDown(Key::Space))
	{
		if (m_Board.CanRotate(m_ActivePill))
		{
			m_ActivePill.Rotate();
		}
	}

	if (Input::IsKeyDown(Key::Pause))
	{
		TogglePause();
	}
}

void GameplayState::SpawnNewPill()
{
	m_ActivePill.SetFirstColor(GetRandomColor());
	m_ActivePill.SetSecondColor(GetRandomColor());
	m_ActivePill.SetPosition(4, 0);
}

void GameplayState::GameOver()
{
}
