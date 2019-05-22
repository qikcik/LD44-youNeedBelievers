#pragma once

#include <SFML/Graphics.hpp>
#include <map>
#include <string>

#define TexturePrefix "data/graphics/"
#define TextureSubfix ".png"

class TextureManager
{
    public:
        TextureManager();
        ~TextureManager();

        sf::Texture* load(std::string name);
        sf::Texture* get(std::string name);

        void unload(std::string name);
        void unloadAll();


    private:
        std::map <std::string , sf::Texture*>  textures;

};
