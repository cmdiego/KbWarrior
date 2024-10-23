cmake_minimum_required(VERSION 3.2)
project(Kb_warrior LANGUAGES CXX)

set (Kb_warrior_VERSION_MAJOR_ 1)
set (Kb_warrior_VERSION_MINOR 0)

# Set C++ standard to C++11
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Include directories
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/inc)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/depends/raylib)

# Source files
file(GLOB SOURCES "src/*.cpp")

# Add executable target
add_executable(${PROJECT_NAME} ${SOURCES})

# Library directories
link_directories(${CMAKE_CURRENT_SOURCE_DIR}/lib)

# Link libraries
target_link_libraries(${PROJECT_NAME} raylib opengl32 gdi32 winmm)

# Set the output directory for the executable
set_target_properties(${PROJECT_NAME} PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/build
)

# CMAKE BUILD BASED ON SYSTEM
# CMAKE_HOST_WIN32 # true on windows system, including win64
# CMAKE_HOST_UNIX # true for UNIX or UNIX like (i.e. APPLE or CYGWIN)
