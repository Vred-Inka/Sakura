#pragma once

class Renderer;

class IState
{
public:
	virtual ~IState() = default;

	virtual void Enter() = 0;
	virtual void Exit() = 0;

	virtual void Update(float dt) = 0;
	virtual void Render(Renderer& renderer) = 0;
};
