#pragma once

struct SDL_Window;

class Window
{
public:
	bool Create();
	void Destroy();

	SDL_Window* GetNativeWindow() const;

private:
	SDL_Window* m_Window = nullptr;
};

