#pragma once
class Board;
class Pill;

class FallingSystem
{
public:
	void Update(float dt, Board& board, Pill& pill);

private:
	float m_Timer = 0.0f;
	float m_FallDelay = 1.0f;
};

