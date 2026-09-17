#include "Cell.h"
#include <string>
#include "../rendering/ColorWraper.h"

std::string Cell::GetConnectionName() const
{	
	std::string textureName = GetColorName(GetColor());
	switch (GetConnection())
	{
	case Connection::Right:
		return "Right";
		break;
	case Connection::Left:
		return "Left";
		break;
	case Connection::Down:
		return "Down";
		break;
	case Connection::Up:
		return "Up";
		break;
	}

	return "";
}

double Cell::GetCellTextureAngle() const
{
	std::string textureName = GetColorName(GetColor());
	switch (GetConnection())
	{
	case Connection::Right:
		return 180.0;
		break;
	case Connection::Left:
		return 0.0;
		break;
	case Connection::Down:
		return 270.0;
		break;
	case Connection::Up:
		return 90.0;
		break;
	}

	return 0.0;
}

