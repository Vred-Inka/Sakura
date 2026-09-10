#pragma once
#include "../platform/Window.h"
#include "../rendering/Renderer.h"
#include "../framework/StateMachine.h"
#include "../framework/IGame.h"


class Application
{
public:
	explicit Application(IGame& game);
	bool Initialize();
	void Run();
	void Shutdown();

	void ProcessEvents();

private:
	bool m_Running = false;

	Window m_Window;
	Renderer m_Renderer;

	IGame& m_Game;
	StateMachine m_StateMachine;
};

