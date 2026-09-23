#include "Input.h"

#include <algorithm>

#include <SDL3/SDL.h>

bool Input::s_CurrentFrameKeys[] = {};
bool Input::s_PreviousFrameKeys[] = {};

namespace
{
	Key ConvertSDLKey(SDL_Keycode key)
	{
		switch (key)
		{
		case SDLK_LEFT:
			return Key::Left;

		case SDLK_RIGHT:
			return Key::Right;

		case SDLK_UP:
			return Key::Up;

		case SDLK_DOWN:
			return Key::Down;

		case SDLK_SPACE:
			return Key::Space;

		case SDLK_ESCAPE:
			return Key::Escape;

		case SDLK_P:
			return Key::Pause;

		default:
			return Key::Unknown;
		}
	}
}

bool Input::IsKeyDown(Key key)
{
	const auto index = static_cast<int>(key);

	return s_CurrentFrameKeys[index]	&& !s_PreviousFrameKeys[index];
}

void Input::OnKeyDown(Key key)
{
	s_CurrentFrameKeys[static_cast<int>(key)] = true;
}

void Input::OnKeyUp(Key key)
{
	s_CurrentFrameKeys[static_cast<int>(key)] = false;
}

void Input::ProcessEvent(const SDL_Event& event)
{
	switch (event.type)
	{
	case SDL_EVENT_KEY_DOWN:
		Input::OnKeyDown(ConvertSDLKey(event.key.key));
		break;

	case SDL_EVENT_KEY_UP:
		Input::OnKeyUp(ConvertSDLKey(event.key.key));
		break;
	default:
		break;
	}
}

void Input::Update()
{
	std::copy(
		std::begin(s_CurrentFrameKeys),
		std::end(s_CurrentFrameKeys),
		std::begin(s_PreviousFrameKeys));
}
