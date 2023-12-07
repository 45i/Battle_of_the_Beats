#pragma once
#include <SFML/Graphics.hpp>
#include "Game.hpp"
class Start_Menu {
public:
static void run_menu(Game::GameScreens& Current_Screen, sf::RenderWindow& Game_window);
private:
static void render_menu(sf::RenderWindow& Game_window);
};
