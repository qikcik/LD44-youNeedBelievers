#pragma once

#include "textureManager.hpp"

class AssetManager
{
    /// CLASS
    public:
        TextureManager texture = TextureManager();
        sf::Font font;

    /// SINGLETON
    private:
        AssetManager();
    public:
        ~AssetManager();
        static AssetManager& get() { static AssetManager a; return a;}
};