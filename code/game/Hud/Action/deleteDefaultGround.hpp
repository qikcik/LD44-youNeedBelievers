#pragma once

#include "../Action.hpp"

#include "../../World/Tile/Ground/Default.hpp"

class DeleteDefaultGround : public Action
{
    public:
        DeleteDefaultGround()
        {
            construct("Action/1");
            price = 20;
        }

        bool can(int pos, World& world)
        {
            if(world.tiles.getTile(pos) == nullptr)
                return false;
            return true;
        }

        bool execute(int pos, World& world)
        {
            world.tiles.setTile(world.player.getPosition(), nullptr );
            std::cout << "dlete" << std::endl; 
            return true;
        }
        
};