#pragma once
#include <string>

struct SDL_Renderer;
struct SDL_Texture;

class Texture
{
public:
	Texture() = default;
	~Texture();

	Texture(const Texture&) = delete;
	Texture& operator= (const Texture&) = delete;

	Texture(Texture&& other) noexcept;
	Texture& operator= (Texture&& other) noexcept;

	bool Load(SDL_Renderer* renderer, const std::string& path);

	void Destroy();

	bool IsValid() const;

	float GetWidth() const { return m_Width; };
	float GetHeight() const { return m_Height; };

	SDL_Texture* GetNativeTexture() const;

private:
	SDL_Texture* m_Texture{ nullptr };
	float m_Width{ 0.0f };
	float m_Height{ 0.0f };
};