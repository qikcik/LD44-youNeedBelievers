#include "TileObject.hpp"

#include <iostream>

TileObject::TileObject()
{
    
}

void TileObject::construct(std::string texture)
{
    sprite.setTexture(AssetManager::get().texture.get(texture));
    sprite.setSize(sf::Vector2f(100,200));
    sprite.setOrigin(sf::Vector2f(50,200));
}

TileObject::~TileObject()
{
    
}

void TileObject::onUpdate(float t)
{

}

void TileObject::onDraw(sf::RenderWindow &window)
{
    window.draw(sprite);
}

void TileObject::setPosition(sf::Vector2f pos)
{
    std::cout << pos.x << " " << pos.y << std::endl;
    sprite.setPosition(pos);
} 