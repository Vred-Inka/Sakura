#pragma once
#include <Engine/rendering/Renderer.h>
#include <Engine/rendering/Texture.h>

class Board;
class Cell;
class Renderer;
class AssetsManager;

class BoardRenderer : public Renderer
{
public:
	explicit BoardRenderer(AssetsManager& assets);

	void Draw(Renderer& renderer, const Board& board);

	void DrawCell(Renderer& renderer, const Cell& cell);
	const Texture& GetTextureForCell(const Cell& cell);

private:
	AssetsManager& m_Assets;
};

