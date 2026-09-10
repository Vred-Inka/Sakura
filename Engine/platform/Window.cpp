#include "Window.h"
#include <SDL3/SDL.h>

#include <iostream>

bool Window::Create()
{
    m_Window = SDL_CreateWindow("Engine Window", 800, 600, SDL_WINDOW_RESIZABLE);

    if (m_Window == nullptr)
    {
        std::cout << "SDL_CreateWindow failed: " << SDL_GetError() << std::endl;
        SDL_Quit();
        return false;
    }

    return true;
}

void Window::Destroy()
{
    SDL_DestroyWindow(m_Window);
    m_Window = nullptr;
}


SDL_Window* Window::GetNativeWindow() const
{
    return m_Window;
}
