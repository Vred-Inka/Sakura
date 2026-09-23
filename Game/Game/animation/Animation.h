#pragma once
class Animation
{
public: 
	virtual ~Animation() = default;
	virtual void Update(float dt) = 0;

	virtual bool IsFinished() const = 0;
};

