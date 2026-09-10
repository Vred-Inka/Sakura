#include <iostream>

#include <Engine/Engine.h>

int main(int argc, char* argv[])
{
    Engine engine;
    if (!engine.Init()) {
        std::cout << "Failed to initialize engine." << std::endl;
        return 1;
    }

    engine.Run();
    engine.Shutdown();

    return 0;
}