#pragma once

#include <SFML/Graphics.hpp>
#include "../../../core/Window/Actor.hpp"

class TileGround : public Actor
{
    public:
        TileGround();
        ~TileGround();

    public:
        void setPosition(sf::Vector2f pos);
    protected:
        sf::RectangleShape sprite;
        void construct(std::string texture);

    //inheretic Actor
    public:
        void onUpdate(float t);
        void onDraw(sf::RenderWindow& window);
};