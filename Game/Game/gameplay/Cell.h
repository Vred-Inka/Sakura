#pragma once
#include <Engine/rendering/Color.h>
#include <string>

enum class CellType
{
	Empty,
	Pill,
	Virus
};

enum class Connection
{
	None,

	Left,
	Right,

	Up,
	Down
};

class Cell
{
public:
	bool IsOccupied() const { return m_Type != CellType::Empty; }
	const Color& GetColor() const { return m_Color; };
	const Connection& GetConnection() const { return m_Connection; };

	std::string GetConnectionName() const;
	double GetCellTextureAngle() const;

	void SetColor(Color color) { m_Color = color; }
	void SetCellType(CellType celltype) { m_Type = celltype; }
	void SetConnection(Connection connection) { m_Connection = connection; }

private:
	CellType m_Type = CellType::Empty;
	Connection m_Connection = Connection::None;
	Color m_Color = Color::Black;
};

