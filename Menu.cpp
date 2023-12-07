#include "Menu.hpp"
#include "Game.hpp"
void Start_Menu::run_menu(Game::GameScreens& CurrentScreen, sf::RenderWindow& Game_window) {
render_menu(Game_window);
while (CurrentScreen == Game::GameScreens::Select) {

    sf::Event event;
    while (Game_window.pollEvent(event)) {
      switch (event.type) {

      case (sf::Event::KeyPressed):

        break;
      case (sf::Event::KeyReleased):

        break;
      case (sf::Event::Closed):
        Game_window.close();
      default:
        break;
      }

    }

    Game_window.display();
    CurrentScreen = Game::GameScreens::Gameplay;
  }
}

void Start_Menu::render_menu(sf::RenderWindow& Game_window) {
Game_window.display();
}
