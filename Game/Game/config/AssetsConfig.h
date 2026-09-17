#pragma once

struct TexturePathConfig
{
	const char* id;
	const char* Path;
};

namespace AssetsConfig
{
	extern const TexturePathConfig Textures[];
	extern const int TextureCount;
}

