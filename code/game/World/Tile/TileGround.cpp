#include "TileGround.hpp"

#include "../../../core/Assets/assetManager.hpp"
#include <iostream>

TileGround::TileGround()
{

}

void TileGround::construct(std::string texture)
{
    sprite.setTexture(AssetManager::get().texture.get(texture));
    sprite.setSize(sf::Vector2f(100,325));
    sprite.setOrigin(sf::Vector2f(50,25));
}

TileGround::~TileGround()
{
    
}

void TileGround::onUpdate(float t)
{

}

void TileGround::onDraw(sf::RenderWindow &window)
{
    window.draw(sprite);
}

void TileGround::setPosition(sf::Vector2f pos)
{
    sprite.setPosition(pos);
}