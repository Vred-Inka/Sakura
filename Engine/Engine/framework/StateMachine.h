#pragma once
#include <memory>
#include "IState.h"

class Renderer;

class StateMachine
{
public:
	void ChangeState(std::unique_ptr<IState> state);

	void Update(float dt);
	void Render(Renderer& renderer);

private:
	std::unique_ptr<IState> m_CurrentState;
};

