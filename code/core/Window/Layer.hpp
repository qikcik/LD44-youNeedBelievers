#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>

class Layer
{
    public:
        Layer() {};
        virtual ~Layer() {};

        virtual void onResize(const sf::Vector2f& vec) {};
        virtual void onUpdate(float t) {};
        virtual void onDraw(sf::RenderWindow& window) {};
    private:
        sf::View view;
};