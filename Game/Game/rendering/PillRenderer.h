#pragma once
#include <map>
#include "Engine/rendering/Color.h"

class Renderer;
class Pill;


class PillRenderer
{
public:
	static void Draw(Renderer& renderer, const Pill& pill);
	static void DrawPill(Renderer& renderer, Pill& pill);	
};

