#include <iostream>

#include <Engine/Core/Application.h>

int main(int argc, char* argv[])
{
    //Game
    Application app;//(game)

    if (!app.Initialize())
    {
        return -1;
    }

    app.Run();
    app.Shutdown();

    return 0;
}