#pragma once

#include "../Action.hpp"

#include "../../World/Tile/Object/FoodGiver.hpp"

class CreateBush : public Action
{
    public:
        CreateBush()
        {
            construct("Action/CreateBush");
            price = 25;
        }

        bool can(int pos, World& world)
        {
            Tile* tile = world.tiles.getTile(pos);
            if(tile == nullptr)
                return false;
            if(tile->getObject() != nullptr )
                return false;
            if(dynamic_cast<TileGroundDefault*>(tile->getGround()))
                return true;
            return false;
        }

        bool execute(int pos, World& world)
        {
            Tile* tile = world.tiles.getTile(pos);
            tile->setObject(new FoodGiver("Bush") );
            return true;
        }
        
};