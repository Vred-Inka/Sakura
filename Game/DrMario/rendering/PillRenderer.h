#pragma once
class Renderer;
struct Pill;

class PillRenderer
{
public:
	static void Draw(Renderer& renderer, const Pill& pill);
	static void DrawPill(Renderer& renderer, Pill& pill);

	
};

