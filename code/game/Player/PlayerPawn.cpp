#include "PlayerPawn.hpp"

#include "../../core/Assets/assetManager.hpp"
#include <iostream>

PlayerPawn::PlayerPawn()
: position(1000-4), targetPosition(1000-2), speed(5), hp(300)
{
    sprite.setSize(sf::Vector2f(100,100));
    sprite.setOrigin(sf::Vector2f(50,50));
    sprite.setPosition(sf::Vector2f(100*position,-300));

    //sprite.setTexture(AssetManager::get().texture.get("player/standing"));
}

PlayerPawn::~PlayerPawn()
{

}

void PlayerPawn::onUpdate(float t)
{
    if(!isMoving())
    {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
            moveTo(getPosition() -1);
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
            moveTo(getPosition() +1);
    }

    int direction = 1;
    if(targetPosition < position)
        direction = -1;

    sprite.move(speed * t * 100 * direction,0);
    
    float goal = targetPosition * 100;
    if( ( direction == -1 && sprite.getPosition().x < goal ) ||
        ( direction == 1 && sprite.getPosition().x > goal ) )
    {
        sprite.setPosition(goal,-300);
        position = targetPosition;
    }

    if(hp > 500) sprite.setTexture(AssetManager::get().texture.get("player/4"));
    else if(hp > 290) sprite.setTexture(AssetManager::get().texture.get("player/3"));
    else if(hp > 100) sprite.setTexture(AssetManager::get().texture.get("player/2"));
    else if(hp > 50) sprite.setTexture(AssetManager::get().texture.get("player/1"));
    else sprite.setTexture(AssetManager::get().texture.get("player/0"));

    hp -= 1*t;
}

void PlayerPawn::onDraw(sf::RenderWindow& window)
{
    window.draw(sprite);
}

 sf::Vector2f PlayerPawn::getRealtivePosition()
 {
     return sprite.getPosition();
 }


bool PlayerPawn::isMoving()
{
    return position != targetPosition;
}

bool PlayerPawn::moveTo(int pos)
{
    targetPosition = pos;
    return true;
}

int PlayerPawn::getPosition()
{
    return position;
}