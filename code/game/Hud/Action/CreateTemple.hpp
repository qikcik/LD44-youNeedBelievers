#pragma once

#include "../Action.hpp"

#include "../../World/Tile/Object/Temple.hpp"

class CreateTemple : public Action
{
    public:
        CreateTemple()
        {
            construct("Action/CreateTemple");
            price = 100;
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
            tile->setObject(new Temple("Temple") );
            return true;
        }
        
};