#pragma once

#include <SFML/Graphics.hpp>
#include "Tile.hpp"

class TileManager
{
    public: 
        TileManager();
        ~TileManager();

        Tile* getTile(int pos);
        void setTile(int pos, Tile* t);

        void onUpdate(float t);
        void onDraw(sf::RenderWindow& window);

    private:
        std::map<int,Tile*> map;
};