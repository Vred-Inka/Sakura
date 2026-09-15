#include "Cell.h"
#include <string>

std::string Cell::GetColorName() const
{
    switch (m_Color)
    {
    case Color::Red:
        return "Red";
    case Color::Blue:
        return "Blue";
    case Color::Yellow:
        return "Yellow";
    default:
        return "Black";
    }
}

std::string Cell::GetCellTextureName() const
{
	std::string textureName = GetColorName();
	switch (GetConnection())
	{
	case Connection::Right:
		textureName += "Right";
		break;
	case Connection::Left:
		textureName += "Left";
		break;
	case Connection::Down:
		textureName += "Down";
		break;
	case Connection::Up:
		textureName += "Up";
		break;
	}

	return textureName;
}
