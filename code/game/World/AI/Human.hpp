#pragma once

#include <SFML/Graphics.hpp>
class World;

class Human
{
    public:
        Human(float pos, bool m);

        void onUpdate(World* w,float t);
        void onDraw(sf::RenderWindow& window);

        float getPosition();

        bool isDead();
        bool isMen;
        float hp;


    private:
        enum State 
        {
            Walking,
            Hungry,
            Pray
        } state;


        void stateWalking(float t,World* w,int idPosition, float offset);
        void stateHungry(float t,World* w,int idPosition, float offset);
        void statePray(float t,World* w,int idPosition, float offset);
        void changeState(State n);


        bool isHungry();
        int notFallDawn(World* w,int idPosition, float offset, float saveSpace);

        sf::RectangleShape sprite;
        sf::RectangleShape talk;
        sf::RectangleShape icon;
        bool drawNotify = false;

        float position;
        void updatePosition(float t);

        int direction = 1;

        bool dead;

        std::string gender;

        float religiosity;
        float food;
        float last;


};