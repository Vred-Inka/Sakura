#pragma once
#include <Engine/rendering/Color.h>

class Cell
{
public:
	bool IsOccupied() const  { return m_Occupied; }
	const Color& GetColor() const { return m_Color; };

	void SetColor(Color color) { m_Color = color; }
	void SetOccupied() { m_Occupied = true; }

private:
	bool m_Occupied = false;
	Color m_Color;
};

