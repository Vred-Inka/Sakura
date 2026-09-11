#pragma once
#include <Engine/framework/IState.h>

#include "../gameplay/Board.h"
#include "../gameplay/Pill.h"
#include "../systems/FallingSystem.h"

class Renderer;

class GameplayState : public IState
{
public:
	void Enter() override;
	void Exit() override;

	void Update(float dt) override;
	void Render(Renderer& renderer) override;

	void HandleInput();

	void SpawnNewPill();

private:
	Pill m_ActivePill{};
	Board m_Board{};

	FallingSystem m_FallingSystem{};
};

