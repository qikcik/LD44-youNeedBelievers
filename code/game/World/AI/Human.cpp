#include "Human.hpp"

#include "../../../core/Assets/assetManager.hpp"
#include <iostream>
#include "../World.hpp"

#include "../Tile/Object/FoodGiver.hpp"
#include "../Tile/Object/Temple.hpp"
#include <cmath>


#include <cstdlib>
#include <ctime>

Human::Human(float pos, bool m)
: state(State::Walking), position(pos), food(65), hp(50), religiosity(5), dead(false), isMen(m)
{

    gender = "Girl";
    if(isMen) gender = "Boy";

    sprite.setTexture(AssetManager::get().texture.get("Human/"+gender+"/0"));
    sprite.setSize(sf::Vector2f(50,75));
    sprite.setOrigin(sf::Vector2f(25,75));

    talk.setTexture(AssetManager::get().texture.get("gui/talk"));
    talk.setSize(sf::Vector2f(60,80));
    talk.setOrigin(sf::Vector2f(30,125));

    icon.setTexture(AssetManager::get().texture.get("gui/food"));
    icon.setSize(sf::Vector2f(50,50));
    icon.setOrigin(sf::Vector2f(25,120));
}

float Human::getPosition()
{
    return position;
}

void Human::onUpdate(World* w,float t)
{

            // perception
        int idPosition = ((int)position +50) /100;
        float offset = position - ((idPosition*100)) ;
        
    Tile* standingTile = w->tiles.getTile(idPosition);
    if(standingTile == nullptr ) dead = true;
    if(!dead)
    {
        if(!isMen && last > 9 && hp < 40 && hp > 20 )
        {
            bool spawn = false;
            for(auto& h : w->humans)
            {
                if(h.isMen && h.hp < 40 && h.hp > 20 && abs(h.getPosition() - position) < 25 )
                {
                    spawn = true;
                    break;
                }
            }
            if(spawn)
            {
                last = 0;
                w->humans.push_back(Human(position,std::rand()%2));
            }
        }


        if(state == State::Hungry)
        {
            stateHungry(t,w, idPosition,offset);
        }
        else if(state == State::Walking)
        { 
            stateWalking(t,w, idPosition,offset);
        }
        else if(state == State::Pray)
        { 
            statePray(t,w, idPosition,offset);
        }
        else
            changeState(State::Walking);
        
        last += 2 * t;
        food -= 5 * t;
        hp -= 2 * t;
        if(food <= 0) dead = true;
        if(hp <= 0) dead = true;
        updatePosition(t);

        if(hp < 40 ) sprite.setTexture(AssetManager::get().texture.get("Human/"+gender+"/1"));
        if(hp < 20 ) sprite.setTexture(AssetManager::get().texture.get("Human/"+gender+"/2"));
    }
}

void Human::stateWalking(float t,World* w,int idPosition, float offset)
{
    // isHungry
    if(isHungry())
    {
        changeState(State::Hungry);
        return;
    }

    Tile* standingTile = w->tiles.getTile(idPosition);
    if( dynamic_cast<Temple*>(standingTile->getObject()) != nullptr && 
        dynamic_cast<Temple*>(standingTile->getObject())->canPray() )
    {
        changeState(State::Pray);
        return;
    }

    // find temple
    #include "macroFindPrev.h"
        if( dynamic_cast<Temple*>(w->tiles.getTile(i)->getObject()) != nullptr && 
            dynamic_cast<Temple*>(w->tiles.getTile(i)->getObject())->canPray() )
        {
            direction = dir;
            changeState(State::Pray);
            return;
        }
    #include "macroFindAfter.h"

    int dir = notFallDawn(w, idPosition, offset, 40);
    if(dir != 0)
    {
         direction = dir;
         return;
    }
}

void Human::stateHungry(float t,World* w,int idPosition, float offset)
{
    // Can Harvest
    Tile* standingTile = w->tiles.getTile(idPosition);
    if(standingTile != nullptr )
    {
        FoodGiver* foodGiver = dynamic_cast<FoodGiver*>(standingTile->getObject());
        if(foodGiver && foodGiver->canHarvest())
        {
            if(abs(offset) < 25)
            {
                food += foodGiver->Harvest();
                if(!isHungry())
                {
                    changeState(Walking);
                    return;
                }
            }
            else
            {
                direction = 1;
                if(offset > 0) direction = -1;
                return;
            }
        }
    }
    // find food
    #include "macroFindPrev.h"
        if( dynamic_cast<FoodGiver*>(w->tiles.getTile(i)->getObject()) != nullptr && 
            dynamic_cast<FoodGiver*>(w->tiles.getTile(i)->getObject())->canHarvest() )
        {
            direction = dir;
            return;
        }
    #include "macroFindAfter.h"

    // dont fall dawn
    int dir = notFallDawn(w, idPosition, offset, 40);
    if(dir != 0)
    {
         direction = dir;
         return;
    }
}

void Human::statePray(float t,World* w,int idPosition, float offset)
{
    if(isHungry())
    {
        changeState(State::Hungry);
        return;
    }
    // Can Harvest
    Tile* standingTile = w->tiles.getTile(idPosition);
    if(standingTile != nullptr )
    {
        Temple* temple = dynamic_cast<Temple*>(standingTile->getObject());
        if(temple && temple->canPray())
        {
            if(abs(offset) < 25)
            {
                //food += foodGiver->Harvest();
                //if(!isHungry())
                //{
                //    changeState(Walking);
                w->player.hp += temple->Pray() *t;
                drawNotify = true;
                //direction = 0;
                return;
                //}
            }
            else
            {
                direction = 1;
                if(offset > 0) direction = -1;
                return;
            }
        }
    }
    // find temple
    #include "macroFindPrev.h"
        if( dynamic_cast<Temple*>(w->tiles.getTile(i)->getObject()) != nullptr && 
            dynamic_cast<Temple*>(w->tiles.getTile(i)->getObject())->canPray() )
        {
            direction = dir;
            return;
        }
    #include "macroFindAfter.h"

    // dont fall dawn
    int dir = notFallDawn(w, idPosition, offset, 40);
    if(dir != 0)
    {
         direction = dir;
         return;
    }
}

bool Human::isHungry()
{
    //std::cout << "Food=" << food << std::endl;
    return food <= 30;
}

int Human::notFallDawn(World* w,int idPosition, float offset, float saveSpace)
{
    if( w->tiles.getTile(idPosition+1) == nullptr && offset > saveSpace )
    {
        return -1;
    }
    if( w->tiles.getTile(idPosition-1) == nullptr && offset < saveSpace*-1 )
    {
        return 1;
    }
    return 0;
}

void Human::onDraw(sf::RenderWindow& window)
{
    window.draw(sprite);
    if(drawNotify)
    {
        window.draw(talk);
        window.draw(icon);
    }
}

bool Human::isDead()
{
    return dead;
}


void Human::changeState(State n)
{
    std::cout << "State=" << n << std::endl;
    state = n;
    if(state == State::Walking)
    {
        drawNotify = false;
    }
    if(state == State::Hungry)
    {
        drawNotify = true;
        talk.setTexture(AssetManager::get().texture.get("gui/talk"));
        icon.setTexture(AssetManager::get().texture.get("gui/food"));
    }
    if(state == State::Pray)
    {
        drawNotify = false;
        talk.setTexture(AssetManager::get().texture.get("gui/talk(white)"));
        icon.setTexture(AssetManager::get().texture.get("gui/pray"));
    }
}

void Human::updatePosition(float t)
{
    position +=  t * (50+(50+hp*2)) * direction;

    sprite.setPosition(sf::Vector2f(position,0));
    talk.setPosition(sf::Vector2f(position,0));
    icon.setPosition(sf::Vector2f(position,0));

}