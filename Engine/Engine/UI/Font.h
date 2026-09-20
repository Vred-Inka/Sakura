#pragma once
#include <string>

struct TTF_Font;

class Font
{
public:
	Font() = default;
	~Font();

	Font(const Font&) = delete;
	Font& operator= (const Font&) = delete;

	Font(Font&& other) noexcept;
	Font& operator= (Font&& other) noexcept;

	bool Load(const std::string& path, float size);
	void Destroy();

	TTF_Font* GetNativeFont() const;

private:
	TTF_Font* m_Font = nullptr;
};

