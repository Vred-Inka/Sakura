#pragma once
#include <Engine/framework/IState.h>

#include "../gameplay/Board.h"
#include "../gameplay/BoardPhase.h"
#include "../gameplay/Pill.h"
#include "../gameplay/VirusSpawner.h"
#include "../rendering/BackgroundRenderer.h"
#include "../rendering/BoardRenderer.h"
#include "../rendering/PillRenderer.h"
#include "../systems/FallingSystem.h"
#include "../systems/MatchingSystem.h"
#include "../systems/GravitySystem.h"

class Renderer;
class AssetsManager;

class GameplayState : public IState
{
public:
	explicit GameplayState(AssetsManager& assets);

	void Enter() override;
	void Exit() override;

	void Update(float dt) override;
	void UpdateSpawn();
	void UpdateControl(float dt);
	void UpdateMatch();
	void UpdateGravity();
	void UpdateGameOver();
	void UpdateVictory();
	
	void Render(Renderer& renderer) override;

	void HandleInput();

	void SpawnNewPill();

	void GameOver();

private:
	Pill m_ActivePill{};
	AssetsManager& m_Assets;
	Board m_Board{};
	BoardPhase m_Phase = BoardPhase::Spawn;

	VirusSpawner m_VirusSpawner{};

	BackgroundRenderer m_BackgroundRenderer;
	BoardRenderer m_BoardRenderer;
	PillRenderer m_PillRenderer;

	FallingSystem m_FallingSystem{};
	MatchingSystem m_MatchingSystem{};
	GravitySystem m_GravitySystem{};
};

