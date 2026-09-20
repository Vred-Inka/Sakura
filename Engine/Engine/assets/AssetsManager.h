#pragma once
#include <string>
#include <unordered_map>

#include "../rendering/Texture.h"
#include "../UI/Font.h"

class Texture;
class Font;

class AssetsManager
{
public:
	bool LoadTexture(SDL_Renderer* renderer, const std::string& id, const std::string& path);
	Texture* GetTexture(const std::string& id);
	
	bool LoadFont(const std::string& id, const std::string& path, float size);
	Font* GetFont(const std::string& id);

private:
	std::unordered_map<std::string, Texture> m_Textures;
	std::unordered_map<std::string, Font> m_Fonts;
};

