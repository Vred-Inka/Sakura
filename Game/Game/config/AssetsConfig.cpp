#include "AssetsConfig.h"

namespace AssetsConfig
{
	const TexturePathConfig Textures[] =
	{
		{"Red", "assets/textures/Red.png"},
		{"RedLeft", "assets/textures/RedLeft.png"},
		{"RedRight", "assets/textures/RedRight.png"},
		{"RedUp", "assets/textures/RedUp.png"},
		{"RedDown", "assets/textures/RedDown.png"},

		{"Blue", "assets/textures/Blue.png"},
		{"BlueLeft", "assets/textures/BlueLeft.png"},
		{"BlueRight", "assets/textures/BlueRight.png"},
		{"BlueUp", "assets/textures/BlueUp.png"},
		{"BlueDown", "assets/textures/BlueDown.png"},

		{"Yellow", "assets/textures/Yellow.png"},
		{"YellowLeft", "assets/textures/YellowLeft.png"},
		{"YellowRight", "assets/textures/YellowRight.png"},
		{"YellowUp", "assets/textures/YellowUp.png"},
		{"YellowDown", "assets/textures/YellowDown.png"},

		{"Bottle", "assets/textures/background/bottle-1.png"},
		{"Mario", "assets/textures/background/mario-s1.png"},
		{"Cell", "assets/textures/background/cell.png"},
		{"Lupa", "assets/textures/background/lupa.png"},

		{"BlueVirus", "assets/textures/background/big-virus-b1.png"},
		{"RedVirus", "assets/textures/background/big-virus-r1.png"},
		{"YellowVirus", "assets/textures/background/big-virus-y1.png"},

		
	};

	const int TextureCount = sizeof(Textures) / sizeof(TexturePathConfig);
}