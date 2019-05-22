#pragma once

#include <SFML/Graphics.hpp>
#include "../../core/Window/Layer.hpp"


#include "Tile/TileManager.hpp"
#include "../Player/PlayerPawn.hpp"
#include "AI/Human.hpp"

class World : public Layer
{

    public:
        World();


    public: 
        TileManager tiles;
        PlayerPawn player;

        std::vector<Human> humans;

    // inhertic from layer
    public:
        void onResize(const sf::Vector2f& vec); //require before use
        void onUpdate(float t);
        void onDraw(sf::RenderWindow& window);

    private:
        sf::View view;
        sf::Vector2f viewCenterTarget;
};