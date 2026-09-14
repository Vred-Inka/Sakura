#pragma once
#include <Engine/rendering/Color.h>
#include "GridPosition.h"

enum class Orientation
{
	Horizontal,
	Vertical
};

class Pill
{
public:
	void MoveLeft();
	void MoveRight();
	void MoveDown();

	void Rotate();

	const GridPosition& GetPosition() const { return m_Position; }
	int GetX() const { return m_Position.m_Column; }
	int GetY() const { return m_Position.m_Row; }

	void SetPosition(int column, int row) { m_Position.m_Column = column; 
											m_Position.m_Row = row; }
	
	float GetWidth() const{ return s_Width; }
	float GetHeight() const{ return s_Height; }

	const Color& GetLeftColor() const { return m_LeftColor; }
	const Color& GetRightColor() const { return m_RightColor; }

	void SetLeftColor(Color color) { m_LeftColor = color; }
	void SetRightColor(Color color) { m_RightColor = color; }

	Orientation GetOrientation() const { return m_Orientation; }

private:

	GridPosition m_Position{ 0,4 };

	static float s_Height;
	static float s_Width;

	Orientation m_Orientation = Orientation::Horizontal;

	Color m_LeftColor = Color::Red;
	Color m_RightColor = Color::Blue;
};

