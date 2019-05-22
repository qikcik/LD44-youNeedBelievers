#include "GameState.hpp"
#include "../menuState.hpp"

GameState::GameState()
: world(), hud(world)
{


}

GameState::~GameState()
{

}

void GameState::handleEvent(sf::Event& event)
{
    if (event.type == sf::Event::Resized)
    {
        // update the view to the new size of the window
        world.onResize( sf::Vector2f(event.size.width, event.size.height) );
        hud.onResize( sf::Vector2f(event.size.width, event.size.height) );
        
    }
    hud.handleEvent(event);
}

void GameState::onUpdate(float t)
{
    world.onUpdate(t);
    hud.onUpdate(t);
}

void GameState::onDraw(sf::RenderWindow& window)
{
    world.onDraw(window);
    hud.onDraw(window);
}

State* GameState::changeState()
{
    if(world.player.hp <= 0)
        return new MenuState();
    return nullptr;
}
