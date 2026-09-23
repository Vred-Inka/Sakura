#pragma once
#include <Engine/framework/IState.h>

#include "../animation/DestroyAnimation.h"
#include "../gameplay/Board.h"
#include "../gameplay/BoardPhase.h"
#include "../gameplay/Pill.h"
#include "../gameplay/VirusSpawner.h"
#include "../rendering/BackgroundRenderer.h"
#include "../rendering/BoardRenderer.h"
#include "../rendering/PillRenderer.h"
#include "../rendering/UIRenderer.h"
#include "../systems/FallingSystem.h"
#include "../systems/MatchingSystem.h"
#include "../systems/MatchResult.h"
#include "../systems/GravitySystem.h"
#include "../systems/ScoreSystem.h"

class Renderer;
class AssetsManager;

class GameplayState : public IState
{
public:
	explicit GameplayState(AssetsManager& assets);

	void Enter() override;
	void Exit() override;

	void Update(float dt) override;
	void UpdateDestroyAnimation(float dt);
	void UpdateControl(float dt);
	void UpdateGameOver();
	void UpdateGravity();	
	void UpdateMatch();
	void UpdatePaused();
	void UpdateSpawn();
	void UpdateVictory();

	void TogglePause();
	
	void Render(Renderer& renderer) override;

	void HandleInput();

	void SpawnNewPill();

	void GameOver();

private:
	Pill m_ActivePill{};
	AssetsManager& m_Assets;

	BoardPhase m_Phase = BoardPhase::Spawn;
	BoardPhase m_PreviousPhase = BoardPhase::Spawn;

	DestroyAnimation m_DestroyAnimation;

	BackgroundRenderer m_BackgroundRenderer;
	BoardRenderer m_BoardRenderer;
	PillRenderer m_PillRenderer;
	UIRenderer m_UIRenderer;
	VirusSpawner m_VirusSpawner{};

	FallingSystem m_FallingSystem{};
	MatchingSystem m_MatchingSystem{};
	GravitySystem m_GravitySystem{};
	ScoreSystem m_ScoreSystem{};

	MatchResult m_LastMatchResult;
	Board m_Board{};
};

