#pragma once

#include <SFML/Graphics.hpp>
#include "../core/Window/State.hpp"

#include "Hud/HudMain.hpp"
#include "World/World.hpp"


class GameState : public State
{
    public:
        GameState();
        ~GameState();

    public:
        HudMain hud;
        World world;


     // Inheretic from State
    public:
        void handleEvent(sf::Event& event);
        void onUpdate(float t);
        void onDraw(sf::RenderWindow& window);
        State* changeState(); // if None, return nullptr
};