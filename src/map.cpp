#include "../inc/map.hpp"
#include <iostream>
#include <fstream>
#include <sstream>


Map::Map()
{
    // Load map grid from text file
    LoadMap("src\\map_input.txt");
}

Map::~Map()
{

}

void Map::Draw()
{
    // Draw all tiles to screen
    for(auto& tile : m_tiles)
    {
        tile.Draw();
    }
}

void Map::LoadMap(std::string path)
{
    // Open map_input.txt file
    std::ifstream file(path);
    if(!file)
    {
        std::cout << "File failed to open" << std::endl;
        return;
    }

    // Read each line from the file and store it in line string
    std::string line;
    while(std::getline(file, line))
    {
        std::stringstream ss(line);
        std::vector<int> row;
        std::string value;
        // Read each value until next comma and store it in value
        while(std::getline(ss, value, ','))
        {
            row.push_back(std::stoi(value));
        }
        m_grid.push_back(row);
    }

    // Go through all cells in grid and create a new tile for each
    for(int row = 0; row < m_grid.size(); row++)
    {
        for(int column = 0; column < m_grid[0].size(); column++)
        {
            // Calculate position of new tile
            float pos_x = column * 25;
            float pos_y = row * 25;
            // Get tile color from grid cell
            int colorCode = m_grid[row][column];
            // Create new tile
            Tile tile = Tile({pos_x, pos_y});
            // Set tile color depending on grid cell value
            switch(colorCode)
            {
                case 0:
                    tile.setColor(BLUE);
                    break;
                case 1:
                    tile.setColor(YELLOW);
                    break;
                case 2: 
                    tile.setColor(BROWN);
                    break;
                default:
                    tile.setColor(YELLOW);
                    break;
            }
            // Push new tile into tiles vector
            m_tiles.push_back(tile);
        }
    }
}