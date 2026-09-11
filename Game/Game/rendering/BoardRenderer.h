#pragma once
#include <Engine/rendering/Renderer.h>

class Board;
class Renderer;

class BoardRenderer : public Renderer
{
public:
	static void Draw(Renderer& renderer, const Board& board);
};

