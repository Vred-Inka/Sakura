#include "Font.h"

#include <filesystem>

#include <SDL3/SDL3_ttf/SDL_ttf.h>


Font::~Font()
{
	Destroy();
}

Font::Font(Font&& other) noexcept
{
	m_Font = other.m_Font;

	other.m_Font = nullptr;
}

Font& Font::operator=(Font && other) noexcept
{
	if (this == &other)
	{
		return *this;
	}

	Destroy();

	m_Font = other.m_Font;

	other.m_Font = nullptr;

	return *this;
}

bool Font::Load(const std::string& path, float size)
{
	Destroy();

	std::string fullPath = std::filesystem::current_path().string() + path.c_str();
	m_Font = TTF_OpenFont(fullPath.c_str(), size);

	if (m_Font == nullptr)
	{
		SDL_Log("Failed to load font: %s", SDL_GetError());
	}

	return m_Font != nullptr;
}

void Font::Destroy()
{
	if (m_Font != nullptr)
	{
		TTF_CloseFont(m_Font);
		m_Font = nullptr;
	}
}

TTF_Font* Font::GetNativeFont() const
{
	return m_Font;
}
