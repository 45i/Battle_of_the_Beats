#pragma once
#include <SFML/Graphics.hpp>
#include <string>
#include <vector>
#include <map>
class Player {
public:
Player(std::string character_name, sf::Vector2f Position, float selected_health);
void Update_Player(const sf::Keyboard::Key key, sf::RenderWindow&);
void draw(sf::RenderWindow&);
void Idle_Position();
private:
sf::Texture player_texture;
std::string Player_name;
/// Frames Variables ///
const int numOfFrames = 8;
short int currentIdleFrame = 1;
short int currentWalkingFrame = 1;
short int currentCrouchingFrame = 1;
enum class Player_Actions {
Idle, Walking, Attacking, Crouching
};
Player_Actions current_Actions = Player_Actions::Idle;
/// Stats Variables ///
public:
sf::Sprite Player_Sprite;
float damage = 0;
float character_health = 1;
float character_speed = 3.0;
};
