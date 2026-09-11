#pragma once
#include <Engine/rendering/Color.h>
#include "GridPosition.h"

enum class Orientation
{
	Horizontal,
	Vertical
};

struct Pill
{
public:
	void MoveLeft();
	void MoveRight();
	void MoveDown();

	void Rotate();

	const GridPosition& GetPosition() const { return m_Position; }
	float GetX() const { return m_Position.m_Column; }
	float GetY() const { return m_Position.m_Row; }
	
	float GetWidth() const{ return s_Width; }
	float GetHeight() const{ return s_Height; }

	const Color& GetLeftColor() const { return m_LeftColor; }
	const Color& GetRightColor() const { return m_RightColor; }

	Orientation GetOrientation() const { return m_Orientation; }

private:

	GridPosition m_Position{ 3,7 };

	static float s_Height;
	static float s_Width;

	Orientation m_Orientation = Orientation::Horizontal;

	Color m_LeftColor = Color::Magenta;
	Color m_RightColor = Color::Blue;
};

