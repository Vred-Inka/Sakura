#pragma once

class AssetsManager;
class Renderer;

class BackgroundRenderer
{
public:
	explicit BackgroundRenderer(AssetsManager& assets);

	void Draw(Renderer& renderer);

private:
	AssetsManager& m_Assets;
};

