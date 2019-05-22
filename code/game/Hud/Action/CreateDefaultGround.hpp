#pragma once

#include "../Action.hpp"

#include "../../World/Tile/Ground/Default.hpp"

class CreateDefaultGround : public Action
{
    public:
        CreateDefaultGround()
        {
            construct("Action/0");
            price = 25;
        }

        bool can(int pos, World& world)
        {
            world.player.hp > 50;
            if(world.tiles.getTile(pos) == nullptr)
                return true;
            return false;
        }

        bool execute(int pos, World& world)
        {
            world.player.hp - 50;
            world.tiles.setTile( world.player.getPosition(), new Tile(world.player.getPosition(), new TileGroundDefault() ) );
            return true;
        }
        
};