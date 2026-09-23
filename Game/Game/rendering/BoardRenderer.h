#pragma once
#include <Engine/rendering/Renderer.h>
#include <Engine/rendering/Texture.h>

class Board;
class Cell;
class Renderer;
class AssetsManager;
struct MatchResult;

class BoardRenderer : public Renderer
{
public:
	explicit BoardRenderer(AssetsManager& assets);

	void Draw(Renderer& renderer, const Board& board, const MatchResult* matchResult, float amimationTime);

	void DrawCell(Renderer& renderer, const Cell& cell);
	const Texture* GetTextureForCell(const Cell& cell);

private:
	AssetsManager& m_Assets;
};

