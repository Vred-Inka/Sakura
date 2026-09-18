#pragma once

struct TextureConfig
{
	const char* id;
	float x{ 0.0f };
	float y{ 0.0f };
	float Width{ 0.0f };
	float Height{ 0.0f };
};

namespace GameConfig
{
	constexpr float WindowWidth = 1024.0f;
	constexpr float WindowHeight = 768.0f;
	constexpr int BoardWidth = 8;
	constexpr int BoardHeight = 16;
	constexpr float CellSize = 32.0f;
	constexpr float BorderX = 384.0f;
	constexpr float BorderY = 210.0f;

	extern const TextureConfig BackgroundTextures[];
	extern const int BackgroundTexturesCount;
}
