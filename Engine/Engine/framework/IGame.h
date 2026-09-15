#pragma once

class Renderer;
class AssetsManager;

class IGame
{
public:
	virtual ~IGame() = default;

	virtual bool Initialize(Renderer& renderer, AssetsManager& assets) = 0;
	virtual void Update(float dt) = 0;
	virtual void Render(Renderer& renderer) = 0;
	virtual void Shutdown() = 0;
};
