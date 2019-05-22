#pragma once

#include "../TileObject.hpp"

class Temple : public TileObject
{
    public:
        std::string name;

        Temple(std::string n)
        : name(n)
        {
            construct("object/"+name+"/efficient");

        }

        bool canPray()
        {
            return (ammount < 1);
        }

        int Pray()
        {
            ammount++;
            return 5;
        }

        void onUpdate(float t)
        {
            ammount=0;
        }

        private:
            int ammount = 0;

};