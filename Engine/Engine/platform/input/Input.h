#pragma once
#include "KeyCodes.h"

union SDL_Event;

class Input
{
public:
	static bool IsKeyDown(Key key);

	static void OnKeyDown(Key key);
	static void OnKeyUp(Key key);

	static void ProcessEvent(const SDL_Event& event);
	static void Update();

private:
	static bool s_CurrentFrameKeys[7];
	static bool s_PreviousFrameKeys[7];
};

