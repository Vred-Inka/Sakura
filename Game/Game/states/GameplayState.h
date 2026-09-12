#pragma once
#include <Engine/framework/IState.h>

#include <random>

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

	Color GetRandomColor()
	{
		static std::mt19937 rng(std::random_device{}());
		std::uniform_int_distribution<int> dist(0, 2);
		return static_cast<Color>(dist(rng));
	}

private:
	Pill m_ActivePill{};
	Board m_Board{};

	FallingSystem m_FallingSystem{};
};

