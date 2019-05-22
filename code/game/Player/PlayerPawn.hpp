#pragma once

#include <SFML/Graphics.hpp>
#include "../../core/Window/Actor.hpp"


class PlayerPawn : public Actor
{
    public:
        PlayerPawn();
        ~PlayerPawn();

    public: 
        sf::Vector2f getRealtivePosition();

        bool isMoving();
        bool moveTo(int pos);
        int getPosition();

        double hp;

    private:
        float speed;
        int position;
        int targetPosition;

    private:
        sf::RectangleShape sprite;

    //inheretic ACtor
    public:
        void onUpdate(float t);
        void onDraw(sf::RenderWindow& window);
};