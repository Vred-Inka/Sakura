#include "StateMachine.h"

void StateMachine::ChangeState(std::unique_ptr<IState> state)
{
	if (m_CurrentState != nullptr)
	{
		m_CurrentState->Exit();
	}

	m_CurrentState = std::move(state);

	if (m_CurrentState != nullptr)
	{
		m_CurrentState->Enter();
	}
}

void StateMachine::Update(float dt)
{
	if (m_CurrentState != nullptr)
	{
		m_CurrentState->Update(dt);
	}
}

void StateMachine::Render(Renderer& renderer)
{
	if (m_CurrentState != nullptr)
	{
		m_CurrentState->Render(renderer);
	}
}