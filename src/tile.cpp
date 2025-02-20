#include "../inc/tile.hpp"

// Constructor
Tile::Tile(Vector2 position)
{
    m_position = position;
}

// Color getter
Color Tile::getColor()
{
    return this->m_color;
}

// Color setter
void Tile::setColor(Color color)
{
    m_color = color;
}

// Draw a tile with given color
void Tile::Draw()
{
    DrawRectangle(m_position.x, m_position.y, 25, 25, m_color);
}