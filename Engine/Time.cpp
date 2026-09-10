#include "Time.h"

#include <SDL3/SDL.h>

float Time::s_DeltaTime = 0.0f;

float Time::Update()
{
	static Uint64 lastCounter = SDL_GetPerformanceCounter();

	uint64_t currentCounter = SDL_GetPerformanceCounter();

	s_DeltaTime = static_cast<float>(currentCounter - lastCounter) / SDL_GetPerformanceFrequency();

	lastCounter = currentCounter;
}

float Time::GetDeltaTime()
{
	return s_DeltaTime;
}