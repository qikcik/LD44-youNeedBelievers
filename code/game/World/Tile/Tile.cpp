#include "Tile.hpp"

Tile::Tile(int pos, TileGround* g)
: position(pos), ground(g), object(nullptr)
{
    ground->setPosition(sf::Vector2f(100*position,0));
}

Tile::~Tile()
{
    if(ground) delete ground;
    if(object) delete object;
}

void Tile::onUpdate(float t)
{
    if(object) object->onUpdate(t);
    if(ground) ground->onUpdate(t);
}

void Tile::onDraw(sf::RenderWindow &window)
{
    if(object) object->onDraw(window);
    if(ground) ground->onDraw(window);
}

int Tile::getPosition()
{
    return position;
}

void Tile::setObject(TileObject* o)
{
    if(object) delete object;
    object = o;
    if(object) object->setPosition(sf::Vector2f(100*position,0));
}

void Tile::setGround(TileGround* g)
{
    if(ground) delete ground;
    ground = g;
    if(ground) ground->setPosition(sf::Vector2f(100*position,0));
}

TileObject* Tile::getObject()
{
    if(object) return object;
    else return nullptr;
}  

TileGround* Tile::getGround()
{
    return ground;
}