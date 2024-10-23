Configuration & Compilation Details:
    1. Currently compile the Raylib library using MinGW64
        a. You can do this by moving to ./depends/raylib/src/
        b. Do $make
        c. Copy the file 'libraylib.a' to the ./lib dir
        d. Copy the file 'raylib.h' to the ./inc dir
    2. Make sure that there's no ./build directory
        a. if there is, then do 'git clean -fdX'
    3. Configure the project with CMake and MinGW64
        a. Make sure MinGW64 is in the env PATH
        b. do 'cmake -S . -B build -G "MinGW Makefiles"
            -S . : SPecifies the source directory (current)
            -B build : Specifies the build directory (build/)
            -G "MinGW Makefiles" : Uses the MinGW Makefiles generator.
        c. do 'cmake --build build -v'
    4. You should now be able to run the executable
        It can be found in the /build/bin/ folder

Cheers!