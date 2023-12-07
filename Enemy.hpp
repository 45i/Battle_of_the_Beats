#pragma once
#include <SFML/Graphics.hpp>
#include <string>
#include <vector>
class Enemy {
public:
Enemy(sf::Texture& enemy_texture, std::string enemy_name, sf::Vector2f Position);
void Update_Enemy(sf::RenderWindow&);
public:
sf::Sprite Enemy_Sprite;
enum class Enemy_Actions {
    Idle, Walking, Attacking
};
Enemy_Actions currentAction = Enemy_Actions::Idle;
float attack = 0.01;
sf::Text Enemy_Name;
private:
sf::Clock Enemy_Clock;
/// Clock Variables ////
const sf::Time attackDelay = sf::seconds(1);
const sf::Time moveDelay = sf::seconds(.05);
const sf::Time holdTime = sf::seconds(0.5);
sf::Time deltaTime;
sf::Time attackTimer;
sf::Time moveTimer;
sf::Time holdTimer;
};
