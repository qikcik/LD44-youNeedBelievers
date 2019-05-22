#include "HudMain.hpp"
#include "Action/CreateDefaultGround.hpp"
#include "Action/DeleteDefaultGround.hpp"

#include "Action/CreateBush.hpp"
#include "Action/CreateTemple.hpp"

#include "Action/RespawnHuman.hpp"

#include <iostream>


HudMain::HudMain(World& w)
: world(w)
{
    actions.reserve(10);
    actions.push_back( new RespawnHuman() );

    actions.push_back( new CreateTemple() );
    actions.push_back( new CreateBush() );

    actions.push_back( new CreateDefaultGround() );
    actions.push_back( new DeleteDefaultGround() );




    back.setSize(sf::Vector2f(150,60));
    back.setOrigin(sf::Vector2f(30,30));
    back.setPosition(sf::Vector2f(60,50));
    back.setTexture(AssetManager::get().texture.get("gui/hp"));

    text.setFont(AssetManager::get().font);
    text.setOrigin(0,0);
    text.setPosition(sf::Vector2f(92,28));
    text.setString("999+");
    text.setCharacterSize(35);
    text.setFillColor(sf::Color::White);
    text.setOutlineColor(sf::Color::Black);
    text.setOutlineThickness(2);

}

HudMain::~HudMain()
{
    for(auto& action :actions)
        delete action;
    actions.clear();
}

void HudMain::onResize(const sf::Vector2f& vec)
{
    view.reset(sf::FloatRect(0.f, 0.f, vec.x, vec.y));
}

void HudMain::handleEvent(const sf::Event& event)
{
    if(event.type == sf::Event::KeyPressed)
    {
        if(event.key.code == sf::Keyboard::Key::Q)
            keyClicked = 0;
        if(event.key.code == sf::Keyboard::Key::W)
            keyClicked = 1;
        if(event.key.code == sf::Keyboard::Key::E)
            keyClicked = 2;
        if(event.key.code == sf::Keyboard::Key::R)
            keyClicked = 3;
        if(event.key.code == sf::Keyboard::Key::T)
            keyClicked = 4;
        if(event.key.code == sf::Keyboard::Key::Y)
            keyClicked = 5;
        if(event.key.code == sf::Keyboard::Key::A)
            keyClicked = 6;
        if(event.key.code == sf::Keyboard::Key::S)
            keyClicked = 7;
        if(event.key.code == sf::Keyboard::Key::D)
            keyClicked = 8;
        if(event.key.code == sf::Keyboard::Key::F)
            keyClicked = 9;
        if(event.key.code == sf::Keyboard::Key::G)
            keyClicked = 10;
        if(event.key.code == sf::Keyboard::Key::H)
            keyClicked = 11;
    }
}

void HudMain::onUpdate(float t)
{
    if(!world.player.isMoving())
    {
        int i=0;
        for(auto& action :actions)
        {
            if( action->can(world.player.getPosition(), world) && world.player.hp > action->price)
            {
                std::string s = "Q";
                if( i == 1) s = 'W';
                else if( i == 2) s = 'E';
                else if( i == 3) s = 'R';
                else if( i == 4) s = 'T';
                else if( i == 5) s = 'Y';
                else if( i == 6) s = 'A';
                else if( i == 7) s = 'S';
                else if( i == 8) s = 'D';
                else if( i == 9) s = 'F';
                else if( i == 10) s = 'G';
                else if( i == 11) s = 'H';
                action->prepare(i,s);
                i++;
            }
            else
            {
                action->prepare(-1,"Error");
            }
            
        }

        if(keyClicked != -1)
        {
            for(auto& action :actions)
            {
                if( action->getID() == keyClicked)
                {
                    if(action->can(world.player.getPosition(), world) && world.player.hp > action->price )
                    {
                        world.player.hp -= action->price;
                        action->execute(world.player.getPosition(), world);
                        keyClicked = -1;

                        break;
                    }
                }
            }
        }
        
        


    }
    keyClicked = -1;

    int temp = (int)(world.player.hp);
    if(temp > 999) text.setString("999+");
    else
    {
    std::string tx = std::to_string(temp);
    if(temp < 10)
        tx="   "+tx;
    else if(temp < 100)
        tx="  "+tx;
    else if(temp < 1000)
        tx=" "+tx;

    text.setString(tx);
    }
}

void HudMain::onDraw(sf::RenderWindow& window)
{
    window.setView(view);
    for(auto& action :actions)
        action->onDraw(window);

    window.draw(back);
    window.draw(text);
}