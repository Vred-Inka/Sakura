#include "DrMarioGame.h"

#include "states/GameplayState.h"
#include <memory>

bool DrMarioGame::Initialize()
{
	m_StateMachine.ChangeState(std::make_unique<GameplayState>());
	return true;
}

void DrMarioGame::Update(float dt)
{
	m_StateMachine.Update(dt);
}

void DrMarioGame::Render(Renderer& renderer)
{
	m_StateMachine.Render(renderer);
}

void DrMarioGame::Shutdown()
{
}
