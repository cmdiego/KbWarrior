#pragma once
#include "raylib.h"

class Tile
{
    public:
        Tile(Vector2 position);
        // Draws Tile into screen
        void Draw();
        // Color Setter
        void setColor(Color color);
        // Color Getter
        Color getColor();
    private:
        // Tile x and y position
        Vector2 m_position;
        // Tile color
        Color m_color;
};