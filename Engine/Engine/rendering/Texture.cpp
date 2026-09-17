#include "Texture.h"

#include <SDL3/SDL.h>
#include <SDL3/SDL3_image/SDL_image.h>

Texture::Texture(Texture&& other) noexcept
{
    m_Texture = other.m_Texture;
    m_Width = other.m_Width;
    m_Height = other.m_Height;

    other.m_Texture = nullptr;
    other.m_Width = 0;
    other.m_Height = 0;
}

Texture::~Texture()
{
    Destroy();
}

Texture& Texture::operator=(Texture&& other) noexcept
{
    if (this == &other)
    {
        return *this;
    }

    Destroy();

    m_Texture = other.m_Texture;
    m_Width = other.m_Width;
    m_Height = other.m_Height;

    other.m_Texture = nullptr;
    other.m_Width = 0;
    other.m_Height = 0;  

    return *this;
}

bool Texture::Load(SDL_Renderer* renderer, const std::string& path)
{
    Destroy();
    m_Texture = IMG_LoadTexture(renderer, path.c_str());

    if (!m_Texture)
    {
        return false;
    }

    float width = 0.0f;
    float height = 0.0f;

    SDL_GetTextureSize(m_Texture, &width, &height);

    m_Width = width;
    m_Height = height;

    return true;
}

void Texture::Destroy()
{
    if (!m_Texture)
    {
        return;
    }
}

bool Texture::IsValid() const
{
    return true;
}

SDL_Texture* Texture::GetNativeTexture() const
{
    return m_Texture;
}


