#pragma once
#include <vector>
#include "tile.hpp"
#include "raylib.h"
#include <string>

class Map 
{
    public:
        Map();
        ~Map();
        // Draws map into the screen
        void Draw();
        // Loads map info from text file
        void LoadMap(std::string path);
    private:
        // Contains all tiles in map
        std::vector<Tile> m_tiles;
        // Represents tile map in memory
        std::vector<std::vector<int>> m_grid;
};
