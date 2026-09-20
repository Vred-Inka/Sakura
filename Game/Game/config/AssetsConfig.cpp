#include "AssetsConfig.h"

namespace AssetsConfig
{
	const TexturePathConfig Textures[] =
	{
		{"Red", "/Game/assets/textures/Red.png"},
		{"RedLeft", "/Game/assets/textures/RedLeft.png"},
		{"RedRight", "/Game/assets/textures/RedRight.png"},
		{"RedUp", "/Game/assets/textures/RedUp.png"},
		{"RedDown", "/Game/assets/textures/RedDown.png"},

		{"Blue", "/Game/assets/textures/Blue.png"},
		{"BlueLeft", "/Game/assets/textures/BlueLeft.png"},
		{"BlueRight", "/Game/assets/textures/BlueRight.png"},
		{"BlueUp", "/Game/assets/textures/BlueUp.png"},
		{"BlueDown", "/Game/assets/textures/BlueDown.png"},

		{"Yellow", "/Game/assets/textures/Yellow.png"},
		{"YellowLeft", "/Game/assets/textures/YellowLeft.png"},
		{"YellowRight", "/Game/assets/textures/YellowRight.png"},
		{"YellowUp", "/Game/assets/textures/YellowUp.png"},
		{"YellowDown", "/Game/assets/textures/YellowDown.png"},

		{"BlueVirus", "/Game/assets/textures/BlueVirus.png"},
		{"RedVirus", "/Game/assets/textures/RedVirus.png"},
		{"YellowVirus", "/Game/assets/textures/YellowVirus.png"},

		{"Bottle", "/Game/assets/textures/background/bottle-1.png"},
		{"Mario", "/Game/assets/textures/background/mario-s1.png"},
		{"Cell", "/Game/assets/textures/background/cell.png"},
		{"Lupa", "/Game/assets/textures/background/lupa.png"},

		{"BlueVirusBig", "/Game/assets/textures/background/big-virus-b1.png"},
		{"RedVirusBig", "/Game/assets/textures/background/big-virus-r1.png"},
		{"YellowVirusBig", "/Game/assets/textures/background/big-virus-y1.png"},

		
	};

	const int TextureCount = sizeof(Textures) / sizeof(TexturePathConfig);
}