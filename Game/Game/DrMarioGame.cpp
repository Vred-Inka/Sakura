#include "DrMarioGame.h"

#include "states/GameplayState.h"
#include "Engine/assets/AssetsManager.h"
#include "Engine/rendering/Renderer.h"
#include <memory>
#include <map>
#include <string>

std::map<std::string, std::string> s_Textures
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
	
	{"Black", "assets/textures/Empty.png"},
	{"BlackUp", "assets/textures/Empty.png"},
	{"BlackLeft", "assets/textures/Empty.png"},
	{"BlackRight", "assets/textures/Empty.png"},
	{"BlackDown", "assets/textures/Empty.png"}
};

bool DrMarioGame::Initialize(Renderer& renderer, AssetsManager& assets)
{
	m_Assets = &assets;

	for (std::pair<std::string, std::string> p : s_Textures)
	{
		assets.LoadTexture(renderer.GetNativeRenderer(), p.first, p.second);
	}

	m_StateMachine.ChangeState(std::make_unique<GameplayState>(assets));
	return true;
}

void DrMarioGame::Update(float dt)
{
	m_StateMachine.Update(dt);
}

void DrMarioGame::Render(Renderer& renderer)
{
	m_StateMachine.Render(renderer);
}

void DrMarioGame::Shutdown()
{
}
