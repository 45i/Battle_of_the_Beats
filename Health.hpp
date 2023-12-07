#pragma once
#include <SFML/Graphics.hpp>
#include <string>
class Health {
public:
Health(sf::RenderWindow& Game_window);
void Update_Healthbars(sf::RenderWindow& Game_window, float damage, float& character_health);
float returnEnemyHealth();
private:
sf::Texture healthbars;
sf::Texture healthoutline;
sf::Sprite Enemy_Healthbar;
sf::Sprite Player_Healthbar;
sf::Sprite Enemy_Health_Outline;
sf::Sprite Player_Health_Outline;
const short int Original_Health = 1;
float Player_Health = 1;
float Enemy_Health = 1;
};
