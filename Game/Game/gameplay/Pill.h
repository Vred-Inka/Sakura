#pragma once
#include <Engine/rendering/Color.h>

enum class Orientation
{
	Horizontal,
	Vertical
};


struct Pill
{
public:
	void Move(float dx, float dy);

	void Rotate();

	float GetX() const { return m_X; }
	float GetY() const { return m_Y; }
	
	float GetWidth() const{ return s_Width; }
	float GetHeight() const{ return s_Height; }

	const Color& GetLeftColor() const { return m_LeftColor; }
	const Color& GetRightColor() const { return m_RightColor; }

	Orientation GetOrientation() const { return m_Orientation; }

private:

	float m_X = 300.f;
	float m_Y = 200.f;

	static float s_Height;
	static float s_Width;

	Orientation m_Orientation = Orientation::Horizontal;

	Color m_LeftColor = Color::Magenta;
	Color m_RightColor = Color::Blue;
};

