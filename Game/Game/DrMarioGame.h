#pragma once
#include <Engine/framework/IGame.h>
#include <Engine/framework/StateMachine.h>

class DrMarioGame : public IGame
{
public:
	bool Initialize(Renderer& renderer, AssetsManager& assets) override;
	void Update(float dt) override;
	void Render(Renderer& renderer) override;
	void Shutdown() override;

private:
	StateMachine m_StateMachine;
	AssetsManager* m_Assets{ nullptr };
};

