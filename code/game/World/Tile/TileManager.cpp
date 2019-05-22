#include "TileManager.hpp"
#include <iostream>

TileManager::TileManager()
{

}

TileManager::~TileManager()
{
    for(auto& tile : map)
        delete tile.second;
}

Tile* TileManager::getTile(int pos)
{
    if( map.count(pos) > 0 )
        return map[pos];

    return nullptr;
}

void TileManager::setTile(int pos,Tile* t)
{
    //if( map.count(pos) > 0 )
    //{
    //    Tile* t = map[pos];
    //    delete t;
    //    std::cout << "kasowanko \n";
    //    //map.erase (pos);   
    //}
    if(pos < 1)
        return;
    map[pos] = t;
    if(t == nullptr)
     map.erase (pos);   
    std::cout << "I'm  here" << std::endl; 

}

void TileManager::onUpdate(float t)
{
    for(auto tile : map)
        tile.second->onUpdate(t);
}

void TileManager::onDraw(sf::RenderWindow& window)
{
    for(auto& tile : map)
       tile.second->onDraw(window);
}
