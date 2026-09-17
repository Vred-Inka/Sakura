#include "BackgroundRenderer.h"

#include "Engine/assets/AssetsManager.h"
#include "Engine/rendering/Renderer.h"
#include "../config/GameConfig.h"
#include "ColorWraper.h"

BackgroundRenderer::BackgroundRenderer(AssetsManager& assets)
	:m_Assets(assets)
{
}

void BackgroundRenderer::Draw(Renderer& renderer)
{
	const int step = 32;
	for (int i = 0, x = 0; x < 1024; ++i,x = x + step)
	{
		for (int j = 0, y = 0; y < 768; ++j, y = y + step)
		{
			if ((i + j) % 2 == 0)
			{
				renderer.DrawRect(x, y, step, step, GetColorRGBColor(Color::Red));
			}
		}
	}


	for (int i = 0; i < GameConfig::BackgroundTexturesCount; ++i)
	{
		const TextureConfig& texture = GameConfig::BackgroundTextures[i];

		renderer.DrawTexture(*m_Assets.GetTexture(texture.id), texture.x, texture.y, texture.Width, texture.Height);
	}

}

