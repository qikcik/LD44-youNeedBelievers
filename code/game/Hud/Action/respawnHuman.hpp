#pragma once

#include "../Action.hpp"

#include "../../World/Tile/Ground/Default.hpp"

#include <cstdlib>
#include <ctime>

class RespawnHuman : public Action
{
    public:
        RespawnHuman()
        {
            construct("Action/3");
            price = 200;
        }

        bool can(int pos, World& world)
        {
            Tile* tile = world.tiles.getTile(pos);
            if(tile == nullptr)
                return false;
            return true;
        }

        bool execute(int pos, World& world)
        {
            world.humans.push_back(Human(pos*100,std::rand()%2));
            return true;
        }
        
};