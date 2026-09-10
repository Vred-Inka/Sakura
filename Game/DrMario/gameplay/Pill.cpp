#include "Pill.h"

float Pill::s_Width{ 32.0f };
float Pill::s_Height{ 32.0f };

void Pill::Move(float dx, float dy)
{
	m_X += dx * s_Width;
	m_Y += dy * s_Height;
}

void Pill::Rotate()
{
	if (m_Orientation == Orientation::Horizontal)
	{
		m_Orientation = Orientation::Vertical;
	}
	else
	{
		m_Orientation = Orientation::Horizontal;
		std::swap(m_LeftColor, m_RightColor);
	}
}
