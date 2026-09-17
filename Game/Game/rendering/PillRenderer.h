#pragma once

class AssetsManager;
class Renderer;
class Pill;


class PillRenderer
{
public:
	explicit PillRenderer(AssetsManager& assets);
	void Draw(Renderer& renderer, const Pill& pill);
	void DrawPill(Renderer& renderer, Pill& pill);	

private:
	AssetsManager& m_Assets;
};

