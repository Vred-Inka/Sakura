#pragma once
#include <string>
#include <unordered_map>

#include "../rendering/Texture.h"

class Texture;

class AssetsManager
{
public:
	bool LoadTexture(SDL_Renderer* renderer, const std::string& id, const std::string& path);

	Texture& GetTexture(const std::string& id);

private:
	std::unordered_map<std::string, Texture> m_Textures;
};

