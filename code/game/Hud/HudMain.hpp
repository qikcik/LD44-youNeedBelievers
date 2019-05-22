#pragma once

#include <SFML/Graphics.hpp>
#include "../../core/Window/Layer.hpp"
#include "Action.hpp"
#include "../World/World.hpp"

class HudMain : public Layer
{
    public:
        HudMain(World& w);
        ~HudMain();

        void handleEvent(const sf::Event& event);

    // inhertic from layer
    public:
        void onResize(const sf::Vector2f& vec); //require before use
        void onUpdate(float t);
        void onDraw(sf::RenderWindow& window);

    private:
        sf::View view;
        int keyClicked = -1;

        sf::RectangleShape back;
        sf::Text text;

        World& world;

        std::vector<Action*> actions;
        int targetPos = -9999;
};