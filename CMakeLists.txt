cmake_minimum_required(VERSION 3.5)
project(kb_warrior LANGUAGES CXX)

# Set C++ standard to C++17
set(CMAKE_CXX_STANDARD 17)

# Include directories
include_directories(inc)

# Check for Raylib header
if (NOT EXISTS "${CMAKE_SOURCE_DIR}/inc/raylib.h")
    message(FATAL_ERROR "Error: raylib.h not found in inc directory")
endif()

if (NOT EXISTS "${CMAKE_SOURCE_DIR}/lib/libraylib.a")
    message(FATAL_ERROR "Error: raylib.a not found in lib directory")
endif()

# Add Raylib as an imported library
add_library(raylib STATIC IMPORTED)
set_target_properties(raylib PROPERTIES
                        IMPORTED_LOCATION "${CMAKE_SOURCE_DIR}/lib/libraylib.a"
                        INTERFACE_INCLUDE_DIRECTORIES "${CMAKE_SOURCE_DIR}/inc"
)

# Project executables
file(GLOB SRC_FILES src/*.cpp)
add_executable(${PROJECT_NAME} ${SRC_FILES})

# Library directories
# link_directories(${CMAKE_CURRENT_SOURCE_DIR}/lib)

# Link libraries
target_link_libraries(${PROJECT_NAME} raylib opengl32 gdi32 winmm)

# CMAKE BUILD BASED ON SYSTEM
# CMAKE_HOST_WIN32 # true on windows system, including win64
# CMAKE_HOST_UNIX # true for UNIX or UNIX like (i.e. APPLE or CYGWIN)
