#include <iostream>

#include <Engine/core/Application.h>

#include "Game/DrMarioGame.h"

int main(int argc, char* argv[])
{
    DrMarioGame game;
    Application app(game);

    if (!app.Initialize())
    {
        return -1;
    }

    app.Run();
    //app.Shutdown();

    return 0;
}