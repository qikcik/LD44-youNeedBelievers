#pragma once

#include <SFML/Graphics.hpp>
#include "core/Window/State.hpp"

#include "game/GameState.hpp"
#include "core/Assets/assetManager.hpp"


class MenuState : public State
{
    public:
        MenuState()
        {
            sprite.setTexture(*AssetManager::get().texture.get("main"));
        }


    public:


        sf::Sprite sprite;


     // Inheretic from State
    public:
        void handleEvent(sf::Event& event)
        {

        }
        void onUpdate(float t)
        {

        }
        void onDraw(sf::RenderWindow& window)
        {
            window.draw(sprite);
        }
        State* changeState()
        {
           if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
           {
               GameState* state = new GameState();
               state->world.onResize(sf::Vector2f(1280,720));
               state->hud.onResize(sf::Vector2f(1280,720));
               return state;
           }
            return nullptr;
        }
};