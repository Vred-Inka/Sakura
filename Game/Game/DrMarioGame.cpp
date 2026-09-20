#include "DrMarioGame.h"

#include "config/AssetsConfig.h"

#include "states/GameplayState.h"
#include "Engine/assets/AssetsManager.h"
#include "Engine/rendering/Renderer.h"
#include <memory>

bool DrMarioGame::Initialize(Renderer& renderer, AssetsManager& assets)
{
	m_Assets = &assets;

	for (int i = 0; i < AssetsConfig::TextureCount; ++i)
	{
		const TexturePathConfig& config = AssetsConfig::Textures[i];

		assets.LoadTexture(renderer.GetNativeRenderer(), config.id, config.Path);
	}

	assets.LoadFont("Score", "\\Game\\assets\\fonts\\Roboto-Bold.ttf", 32.0f);

	m_StateMachine.ChangeState(std::make_unique<GameplayState>(assets));
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
