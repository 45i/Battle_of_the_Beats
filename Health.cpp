#include "Health.hpp"
#include <iostream>
Health::Health(sf::RenderWindow &Game_window) {
healthbars.loadFromFile("health_bar.png");
healthoutline.loadFromFile("empty_bar.png");
Enemy_Healthbar.setTexture(healthbars);
Player_Healthbar.setTexture(healthbars);
Enemy_Health_Outline.setTexture(healthoutline);
Player_Health_Outline.setTexture(healthoutline);
Enemy_Health_Outline.setOrigin(Enemy_Health_Outline.getLocalBounds().width, Enemy_Health_Outline.getOrigin().y);
Enemy_Healthbar.setOrigin(Enemy_Health_Outline.getOrigin());
Enemy_Health_Outline.setPosition(800-(Enemy_Health_Outline.getGlobalBounds().width+20), 25);
Player_Health_Outline.setPosition(0+(Player_Health_Outline.getGlobalBounds().width+20), 25);
Enemy_Healthbar.setPosition(800-(Enemy_Healthbar.getGlobalBounds().width+20), 25);
Player_Healthbar.setPosition(0+(Player_Healthbar.getGlobalBounds().width+20), 25);
Game_window.draw(Enemy_Health_Outline);
Game_window.draw(Player_Health_Outline);
}

void Health::Update_Healthbars(sf::RenderWindow& Game_window, float damage, float& character_health) {
Player_Health = Player_Health-(damage/character_health);
Player_Healthbar.setScale(Original_Health*Player_Health, Player_Healthbar.getScale().y);
if(Player_Healthbar.getScale().x < 0) Player_Healthbar.setScale(0, Player_Healthbar.getScale().y);
Game_window.draw(Enemy_Healthbar);
Game_window.draw(Player_Healthbar);
Game_window.draw(Enemy_Health_Outline);
Game_window.draw(Player_Health_Outline);
}

float Health::returnEnemyHealth() {
return Enemy_Health;
}

