#pragma once
struct SDL_Renderer;

class Window;

class Renderer
{
public:
	bool Create(Window& window);
	void Destroy();

	void BeginFrame();
	void EndFrame();

private:
	SDL_Renderer* m_Renderer = nullptr;
};

