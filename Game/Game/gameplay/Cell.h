#pragma once
#include <Engine/rendering/Color.h>

class Cell
{
public:
	bool IsOccupied() const  { return m_Occupied; }
	const Color& GetColor() const { return color; };

private:
	bool m_Occupied = true;
	Color color;
};

