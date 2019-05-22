#pragma once

#include <SFML/Graphics.hpp>
#include "../../../core/Window/Actor.hpp"
#include "TileObject.hpp"
#include "TileGround.hpp"


class Tile : public Actor
{
    public:
        Tile(int pos, TileGround* g);
        ~Tile();

    public:
        void setObject(TileObject* o);
        void setGround(TileGround* g);
        TileObject* getObject();
        TileGround* getGround();

    public:
        TileObject* object;
        TileGround* ground;



        int getPosition();
    private:
        int position;

    //inheretic ACtor
    public:
        void onUpdate(float t);
        void onDraw(sf::RenderWindow& window);
};