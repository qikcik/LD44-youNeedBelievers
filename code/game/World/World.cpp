#include "World.hpp"

#include "Tile/Ground/Default.hpp"
#include "Tile/Object/FoodGiver.hpp"
#include "Tile/Object/Temple.hpp"
World::World()
: viewCenterTarget(100000,-300)
{
    tiles.setTile( 999, new Tile(999, new TileGroundDefault() ) );
    tiles.setTile( 1000, new Tile(1000, new TileGroundDefault() ) );
    tiles.setTile( 1001, new Tile(1001, new TileGroundDefault() ) );
    tiles.getTile(999)->setObject(new Temple("Temple"));
    tiles.getTile(1001)->setObject(new FoodGiver("Bush"));
    //humans.push_back(Human(0,false));
    humans.push_back(Human(100000,false));
    humans.push_back(Human(100050,true));
    humans.push_back(Human(100080,false));
    //humans.push_back(Human(100050,false));
}

void World::onResize(const sf::Vector2f& vec)
{
    view.reset(sf::FloatRect(0.f, 0.f, vec.x, vec.y));
}
void World::onUpdate(float t)
{
    player.onUpdate(t);
    for(auto& human :humans)
        human.onUpdate(this,t);
    tiles.onUpdate(t);

    humans.erase(std::remove_if(humans.begin(),humans.end(),[](Human &h) {return h.isDead();}),humans.end());
}
void World::onDraw(sf::RenderWindow& window)
{
    //Update Camera Center
    if(viewCenterTarget.x + window.getSize().x/2 - 100 < player.getRealtivePosition().x )
        viewCenterTarget.x = player.getRealtivePosition().x - window.getSize().x/2 + 100;
    if(viewCenterTarget.x - window.getSize().x/2 + 100  > player.getRealtivePosition().x )
        viewCenterTarget.x = player.getRealtivePosition().x + window.getSize().x/2 - 100;
    view.setCenter(viewCenterTarget);
    window.setView(view);

    player.onDraw(window);
    tiles.onDraw(window);
    for(auto& human :humans)
        human.onDraw(window);
}