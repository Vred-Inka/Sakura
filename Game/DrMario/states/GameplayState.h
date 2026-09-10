#pragma once
#include <Engine/framework/IState.h>

#include "../gameplay/Pill.h"

class Renderer;

class GameplayState : public IState
{
public:
	void Enter() override;
	void Exit() override;

	void Update(float dt) override;
	void Render(Renderer& renderer) override;

private:
	Pill m_Pill;
};

