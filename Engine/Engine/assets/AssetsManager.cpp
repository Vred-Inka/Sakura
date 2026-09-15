#include "AssetsManager.h"

bool AssetsManager::LoadTexture(SDL_Renderer* renderer, const std::string& id, const std::string& path)
{
    Texture texture;

    if (!texture.Load(renderer, "C:/Projects/Sakura_Engine/Game/Game/" + path))
    {
        return false;
    }

    m_Textures.emplace(id, std::move(texture));

    return true;
}

Texture& AssetsManager::GetTexture(const std::string& id)
{
    return m_Textures.at(id);
}
