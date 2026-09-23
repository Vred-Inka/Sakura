#pragma once
#include "Animation.h"

class DestroyAnimation : public Animation
{
public:
	void Start();

	void Update(float st) override;
	bool IsFinished() const override;
	float GetTime() const;


private:
	float m_Time = 0.0f;
	float m_Duration = 0.3f;
};

