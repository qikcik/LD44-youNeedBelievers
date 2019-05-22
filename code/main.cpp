
#include <SFML/Graphics.hpp>
#include "core/Window/State.hpp"
#include "game/GameState.hpp"
#include "menuState.hpp"
#include "game/World/Tile/Ground/Default.hpp"

#include "core/Assets/assetManager.hpp"

#define _WindowTitle_ "LD44"

int main()
{
    std::srand(std::time(nullptr));
    AssetManager::get().texture.load("main");
    AssetManager::get().texture.load("player/0");
    AssetManager::get().texture.load("player/1");
    AssetManager::get().texture.load("player/2");
    AssetManager::get().texture.load("player/3");
    AssetManager::get().texture.load("player/4");

    AssetManager::get().texture.load("Human/Boy/0");
    AssetManager::get().texture.load("Human/Boy/1");
    AssetManager::get().texture.load("Human/Boy/2");

    AssetManager::get().texture.load("Human/Girl/0");
    AssetManager::get().texture.load("Human/Girl/1");
    AssetManager::get().texture.load("Human/Girl/2");

    AssetManager::get().texture.load("gui/talk");
    AssetManager::get().texture.load("gui/talk(white)");
    AssetManager::get().texture.load("gui/food");
    AssetManager::get().texture.load("gui/pray");
    AssetManager::get().texture.load("gui/hud");

    AssetManager::get().texture.load("Action/0");
    AssetManager::get().texture.load("Action/1");
    AssetManager::get().texture.load("Action/2");
    AssetManager::get().texture.load("Action/3");
    AssetManager::get().texture.load("Action/CreateBush");
    AssetManager::get().texture.load("Action/CreateTemple");

    AssetManager::get().texture.load("gui/hp");


    AssetManager::get().texture.load("ground/default");


    AssetManager::get().texture.load("object/Bush/ready");
    AssetManager::get().texture.load("object/Bush/growing-0");
    AssetManager::get().texture.load("object/Bush/growing-1");
    AssetManager::get().texture.load("object/Bush/used");
    AssetManager::get().texture.load("object/Temple/efficient");



    MenuState* gs = new MenuState(); 
    //gs->world.onResize(sf::Vector2f(1280,720));
    //gs->hud.onResize(sf::Vector2f(1280,720));

    State* actualState = gs;

    sf::RenderWindow window(sf::VideoMode(1280,720),_WindowTitle_);
    window.setKeyRepeatEnabled(false);
    sf::Clock clock;
    float t = 1.f/60;

    while (window.isOpen())
    {
        // change State
        if(window.hasFocus())
        {
            if(actualState)
            {
                State* temp = actualState->changeState();
                if(temp != nullptr)
                {
                    delete actualState;
                    actualState = temp;
                }
            }

            //handle event
            sf::Event event;
            while (window.pollEvent(event))
            {
                if (event.type == sf::Event::Closed)
                    window.close();

                if(actualState) actualState->handleEvent(event);
            }

            // on update
            if(actualState) actualState->onUpdate(t);

            // on draw
            window.clear(sf::Color(186,213,214));
                if(actualState) actualState->onDraw(window);
            window.display();

            // Delta Time Control
            t = clock.restart().asSeconds();
            window.setTitle( _WindowTitle_"   ("+std::to_string(1.f/t)+" fps)" );
        }
        else
        {
            t = 1.f/60;
            clock.restart();
        }
        
    }
    return 0;
}