#pragma once
class Board;
class Pill;

enum class FallResult
{
	None,
	Locked
};

class FallingSystem
{
public:
	FallResult Update(float dt, Board& board, Pill& pill);

private:
	float m_Timer = 0.0f;
	float m_FallDelay = 1.0f;
};

