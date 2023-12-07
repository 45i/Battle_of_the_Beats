#include "Game.hpp"
#include "Enemy.hpp"
Enemy::Enemy(sf::Texture &enemy_texture, std::string enemy_name, sf::Vector2f Position) {
enemy_texture.loadFromFile(enemy_name+"Idle1.png");
Enemy_Sprite.setTexture(enemy_texture);
Enemy_Sprite.setPosition(Position);
}

void Enemy::Update_Enemy(sf::RenderWindow& Game_window) {
    deltaTime = Enemy_Clock.restart();
    moveTimer += deltaTime;
    attackTimer += deltaTime;
    holdTimer += deltaTime;

    if(moveTimer > moveDelay) {
        moveTimer = sf::Time::Zero;
        if(Enemy_Sprite.getPosition().x > Enemy_Sprite.getGlobalBounds().width && Enemy_Sprite.getPosition().x < SCREEN_WIDTH-Enemy_Sprite.getGlobalBounds().width) {
        currentAction = Enemy_Actions::Walking;
        Enemy_Sprite.move(-1, 0);
        }
    }

    Game_window.draw(Enemy_Sprite);
}
