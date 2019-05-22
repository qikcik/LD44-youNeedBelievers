#pragma once

#include "../TileGround.hpp"

class TileGroundDefault : public TileGround
{
    public:
        TileGroundDefault()
        {
            construct("ground/default");
        }

};