#pragma once

#include "../TileObject.hpp"

class FoodGiver : public TileObject
{
    public:
        std::string name;

        bool canHarvest()
        {
            return isReady;
        }

        int Harvest()
        {
            isReady = false;
            growTime = 2;
            //sprite.setTexture(AssetManager::get().texture.get("object/"+name+"/growing-0"));
            used ++;
            return FoodAmmount;
        }


        FoodGiver(std::string n)
        : name(n)
        {
            construct("object/"+name+"/growing-1");

        }

        void onUpdate(float t)
        {
            if(used != 10)
            {
                growTime += t;
                if(growTime > 7)
                {
                    isReady = true;
                    sprite.setTexture(AssetManager::get().texture.get("object/"+name+"/ready"));
                } 
                else if(growTime > 2)
                {
                    sprite.setTexture(AssetManager::get().texture.get("object/"+name+"/growing-0"));
                } 
            }
            else sprite.setTexture(AssetManager::get().texture.get("object/"+name+"/used"));
        }

        private:
            bool isReady = false;
            float growTime = 0;
            int FoodAmmount = 25;
            int used = 0;

};