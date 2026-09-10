#include "PillRenderer.h"

#include <Engine/rendering/Renderer.h>
#include "../gameplay/Pill.h"

void PillRenderer::Draw(Renderer& renderer, const Pill& pill)
{
	if (pill.GetOrientation() == Orientation::Horizontal)
	{
		renderer.DrawRect(pill.GetX(), pill.GetY(), pill.GetWidth(), pill.GetHeight(), pill.GetLeftColor());
		renderer.DrawRect(pill.GetX() + pill.GetWidth(), pill.GetY(), pill.GetWidth(), pill.GetHeight(), pill.GetRightColor());
	} 
	else
	{
		renderer.DrawRect(pill.GetX(), pill.GetY(), pill.GetWidth(), pill.GetHeight(), pill.GetLeftColor());
		renderer.DrawRect(pill.GetX(), pill.GetY() + pill.GetHeight(), pill.GetWidth(), pill.GetHeight(), pill.GetRightColor());
	}
}

