
#include "Action.hpp"

#include "../../core/Assets/assetManager.hpp"

void Action::onDraw(sf::RenderWindow& window)
{
    if(id != -1)
    {
        window.draw(back);
        window.draw(sprite);
        window.draw(text);
    }
}

void Action::prepare(int i, std::string t)
{
    id = i;
    sprite.setPosition(sf::Vector2f(250+75*id,50));
    back.setPosition(sf::Vector2f(250+75*id,50));
    text.setPosition(sf::Vector2f(250+75*id,50));
    text.setString(t);
}

int Action::getID()
{
    return id;
}

void Action::construct(std::string texture)
{
    sprite.setTexture(AssetManager::get().texture.get(texture));
    sprite.setSize(sf::Vector2f(50,50));
    sprite.setOrigin(sf::Vector2f(25,25));

    back.setSize(sf::Vector2f(60,60));
    back.setOrigin(sf::Vector2f(30,30));
    back.setTexture(AssetManager::get().texture.get("gui/hud"));

    text.setFont(AssetManager::get().font);
    text.setOrigin(22,-2);
    text.setString("");
    text.setCharacterSize(18);
    text.setFillColor(sf::Color::White);
    text.setOutlineColor(sf::Color::Black);
    text.setOutlineThickness(2);
}


