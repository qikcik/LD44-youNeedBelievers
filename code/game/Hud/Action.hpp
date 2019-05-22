#pragma once 

#include <SFML/Graphics.hpp>
#include "../World/World.hpp"

class Action
{
    public:
        void onDraw(sf::RenderWindow& window);

        void prepare(int i,std::string t);
        int getID();

        virtual bool can(int pos, World& world) =0;
        virtual bool execute(int pos, World& world) =0;

        int price;

    protected:
        void construct(std::string texture);
        int id = -1;
        sf::RectangleShape sprite;
        sf::RectangleShape back;
        sf::Text text;
    
};