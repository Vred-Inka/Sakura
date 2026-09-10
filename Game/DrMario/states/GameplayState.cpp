#include "GameplayState.h"

#include "Engine/platform/input/Input.h"
#include "Engine/framework/StateMachine.h"

#include "../gameplay/Pill.h"
#include "../rendering/PillRenderer.h"


void GameplayState::Enter()
{
}

void GameplayState::Exit()
{
	
}

void GameplayState::Update(float dt)
{
	constexpr float Step = 1.0f;

	if (Input::IsKeyDown(Key::Left))
	{
		m_Pill.Move(-Step, 0.0f);
	}

	if (Input::IsKeyDown(Key::Right))
	{
		m_Pill.Move(Step, 0.0f);
	}

	if (Input::IsKeyDown(Key::Up))
	{
		m_Pill.Move(0.0f, -Step);
	}

	if (Input::IsKeyDown(Key::Down))
	{
		m_Pill.Move(0.0f, Step);
	}

	if (Input::IsKeyDown(Key::Space))
	{
		m_Pill.Rotate();
	}
}

void GameplayState::Render(Renderer& renderer)
{
	PillRenderer::Draw(renderer, m_Pill);
}
