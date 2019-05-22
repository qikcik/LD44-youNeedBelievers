#pragma once

#include <SFML/Graphics.hpp>

class Actor
{
    public:
        Actor() {};
        virtual ~Actor() {};

        virtual void onUpdate(float t) {};
        virtual void onDraw(sf::RenderWindow& window) {};
};
