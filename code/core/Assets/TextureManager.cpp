#include "textureManager.hpp"
#include <iostream>

TextureManager::TextureManager()
{
 //blank
}

TextureManager::~TextureManager()
{
    unloadAll();
}

sf::Texture* TextureManager::load(std::string name)
{
    sf::Texture *texture = new sf::Texture();

    if(get(name) == nullptr && texture->loadFromFile(TexturePrefix+name+TextureSubfix))
    {
        textures[name] = texture;
        std::cout << "load Texture [" << TexturePrefix+name+TextureSubfix<< "] \n";
        //textures[name]->setSmooth(true);
        return textures[name];
    }
    else
    {
        return textures[name];
    }
}

sf::Texture* TextureManager::get(std::string name)
{
    if(textures.find(name) != textures.end()){
        return textures[name];
    } else {
        return nullptr;
    }
}

void TextureManager::unload(std::string name)
{
    std::map<std::string, sf::Texture*>::iterator it = textures.find(name);
    if(it != textures.end()){
        textures.erase (it);

        std::cout << "unload Texture [" << TexturePrefix+name+TextureSubfix<< "] \n";
    }
}

void TextureManager::unloadAll()
{
    sf::Texture *texture;
    std::map<std::string, sf::Texture*>::iterator iter = textures.begin();
    while(iter != textures.end())
    {
        texture = iter->second;
        delete texture;
        iter++;
    }
}
