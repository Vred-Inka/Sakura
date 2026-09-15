#pragma once
#include "C:\Projects\Sakura_Engine\Engine\Engine\framework\IState.h"
class GameOverState :
    public IState
{
	void Enter() override;
	void Exit() override;

	void Update(float dt) override;
	void Render(Renderer& renderer) override;
};

