#include "Pill.h"

float Pill::s_Width{ 32.0f };
float Pill::s_Height{ 32.0f };

void Pill::MoveLeft()
{
	m_Position.m_Column--;
}

void Pill::MoveRight()
{
	m_Position.m_Column++;
}

void Pill::MoveDown()
{
	m_Position.m_Row++;
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
