#include "GameConfig.h"

namespace GameConfig
{
	const TextureConfig BackgroundTextures[] =
	{
		{"Bottle", 352.0f, 50.0f, 320.0f, 704.0f},
		{"Cell", 722, 170, 224, 224 },
		{"Mario", 750, 220, 168, 168 },
		{"Lupa", 0, 300, 320, 352 },
		{"BlueVirusBig", 195, 350, 96, 104 },
		{"RedVirusBig", 65, 400, 96, 104 },
		{"YellowVirusBig", 175, 480, 96, 104 },
	};

	const int BackgroundTexturesCount = sizeof(BackgroundTextures) / sizeof(TextureConfig);
}