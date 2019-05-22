#pragma once

#include <SFML/Graphics.hpp>

class State;

class State
{
    public:
        State() {}
        virtual  ~State() {};

        virtual void handleEvent(sf::Event& event) = 0;
        virtual void onUpdate(float t) = 0;
        virtual void onDraw(sf::RenderWindow& window) = 0;

        virtual State* changeState() = 0; // None, return nullptr
};