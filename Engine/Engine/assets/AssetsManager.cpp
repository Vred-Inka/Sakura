#include "AssetsManager.h"

#include "../UI/Font.h"

bool AssetsManager::LoadTexture(SDL_Renderer* renderer, const std::string& id, const std::string& path)
{
    Texture texture;

    if (!texture.Load(renderer, path))
    {
        return false;
    }

    m_Textures.emplace(id, std::move(texture));

    return true;
}

Texture* AssetsManager::GetTexture(const std::string& id)
{
    std::unordered_map<std::string, Texture>::iterator texture = m_Textures.find(id);
    if (texture != m_Textures.end())
    {
        return &texture->second;
    }

    return nullptr;
}

bool AssetsManager::LoadFont(const std::string& id, const std::string& path, float size)
{
    Font font;

    if (!font.Load(path, size))
    {
        return false;
    }

    m_Fonts.emplace(id, std::move(font));

    return true;
}

Font* AssetsManager::GetFont(const std::string& id)
{
    std::unordered_map<std::string, Font>::iterator font = m_Fonts.find(id);
    if (font != m_Fonts.end())
    {
        return &font->second;
    }

    return nullptr;
}
