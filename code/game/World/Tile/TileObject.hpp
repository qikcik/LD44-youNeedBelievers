#pragma once

#include <SFML/Graphics.hpp>
#include "../../../core/Window/Actor.hpp"
#include "../../../core/Assets/assetManager.hpp"


class TileObject : public Actor
{
    public:
        TileObject();
        ~TileObject();

    public:
        void setPosition(sf::Vector2f);
    protected:
        void construct(std::string texture);
        sf::RectangleShape sprite;

    //inheretic Actor
    public:
        virtual void onUpdate(float t);
        void onDraw(sf::RenderWindow& window);
};