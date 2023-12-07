#include "Game.hpp"
#include "Player.hpp"

Player::Player(std::string character_name, sf::Vector2f Position, float selected_health) {
Player_name = character_name;
player_texture.loadFromFile(character_name+"Walking6.png");
Player_Sprite.setTexture(player_texture);
player_texture.loadFromFile(character_name+"Idle1.png");
Player_Sprite.setPosition(Position);
character_health = selected_health;
}

void Player::Update_Player(const sf::Keyboard::Key key, sf::RenderWindow& Game_window) {
switch(key) {
case(sf::Keyboard::Left):
if(Player_Sprite.getPosition().x >= 20) {
    current_Actions = Player_Actions::Walking;
    if(currentWalkingFrame<1 || currentWalkingFrame>numOfFrames) {currentWalkingFrame = numOfFrames;}
    player_texture.loadFromFile(Player_name+"Walking"+std::to_string(currentWalkingFrame)+".png");
    --currentWalkingFrame;
     Player_Sprite.move(-character_speed, 0);
     }
    break;
case(sf::Keyboard::Right):
if(Player_Sprite.getPosition().x <= SCREEN_WIDTH-Player_Sprite.getLocalBounds().width) {
    current_Actions = Player_Actions::Walking;
    if(currentWalkingFrame>numOfFrames || currentWalkingFrame<1) currentWalkingFrame = 1;
    player_texture.loadFromFile(Player_name+"Walking"+std::to_string(currentWalkingFrame)+".png");
    ++currentWalkingFrame;
    Player_Sprite.move(character_speed, 0);
    }
    break;
case(sf::Keyboard::Space):
    current_Actions = Player_Actions::Attacking;
    player_texture.loadFromFile(Player_name+"Attacking1.png");

default:
    break;
}
}

void Player::draw(sf::RenderWindow& window) {
damage = 0;
window.draw(Player_Sprite);
if(currentIdleFrame>1) currentIdleFrame = 1;
if(current_Actions==Player_Actions::Idle) player_texture.loadFromFile(Player_name+"Idle"+std::to_string(currentIdleFrame)+".png");
++currentIdleFrame;
}

void Player::Idle_Position() {
current_Actions = Player_Actions::Idle;
}

