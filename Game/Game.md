#### Add includes to project settings
Visual Studio → Project → Properties → C/C++ → Additional Include Directories

Add: external/SDL3/include

Apply to All Configurations and All Platforms

//c++ additional include directories
$(SolutionDir)external/include

//linker/ additional libraries
Visual Studio → Project → Properties → Linker → General → Additional Library Directories
$(SolutionDir)external/lib

//Additional dependencies
SDL3.lib
