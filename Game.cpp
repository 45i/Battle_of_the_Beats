#include <SFML/Graphics.hpp>

#include "Game.hpp"

#include "Enemy.hpp"

#include "Player.hpp"

#include "Music.hpp"

#include "Menu.hpp"



Game::Game():
  Game_window(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "Battle of The Beats") {
    font.loadFromFile("arcanum.ttf");
  }

void Game::run() {
  Game_window.setFramerateLimit(60);
  ///---------------------///
  Timer_Text.setFont(font);
  Timer_Text.setFillColor(sf::Color(255, 0, 0));
  Timer_Text.setCharacterSize(42);
  ///--------------------///
  if(Current_Screen == GameScreens::Select) {
  Start_Menu::run_menu(Current_Screen, Game_window);
  }
  playerCharacter = std::make_unique < Player > ("thief", sf::Vector2f(20, 475), static_cast < float > (1));
  if(Current_Screen == GameScreens::Gameplay) {
  Render_stage(current_stage, currentEnemy, health);
  while (Game_window.isOpen()) {

    sf::Event event;
    while (Game_window.pollEvent(event)) {
      switch (event.type) {

      case (sf::Event::KeyPressed):
        playerCharacter -> Update_Player(event.key.code, Game_window);
        break;
      case (sf::Event::KeyReleased):
        playerCharacter -> Idle_Position();
        break;
      case (sf::Event::Closed):
        Game_window.close();
      default:
        break;
      }

    }

    if (health -> returnEnemyHealth() <= 0) {
      current_stage += 1;
      Render_stage(current_stage, currentEnemy, health);
    }
    Game_window.clear();
    currentEnemy -> Update_Enemy(Game_window);
    playerCharacter -> draw(Game_window);
    if (playerCharacter -> Player_Sprite.getGlobalBounds().intersects(currentEnemy -> Enemy_Sprite.getGlobalBounds()) && currentEnemy -> currentAction == currentEnemy -> Enemy_Actions::Attacking) {
      playerCharacter -> damage = currentEnemy -> attack;
    }
    health -> Update_Healthbars(Game_window, playerCharacter -> damage, playerCharacter -> character_health);
    Update_Timer();
    Game_window.draw(CurrentBackground);
    Game_window.display();

  }
  }
}

void Game::Render_stage(int current_stage, std::unique_ptr < Enemy > & levelEnemy, std::unique_ptr < Health > & health) {
  Music_Player.Play_audio(current_stage);
  background.loadFromFile("Background" + std::to_string(current_stage) + ".png");
  CurrentBackground.setTexture(background);
  levelEnemy.reset();
  levelEnemy = std::make_unique < Enemy > (enemy_texture, "enemy_thief", sf::Vector2f(725, 475));
  health.reset();
  health = std::make_unique < Health > (Game_window);
  Stage_Time = sf::seconds(60);
  Remaining_Time = Stage_Time;

}

void Game::Update_Timer() {
  Display_Time = Game_Timer.restart();
  if (Remaining_Time > sf::Time::Zero) {
    Remaining_Time -= Display_Time;
  } else {
    Remaining_Time = sf::Time::Zero;
  }
  seconds = static_cast < int > (Remaining_Time.asSeconds());
  time_String = "(" + std::to_string(seconds) + ")";
  Timer_Text.setString(time_String);
  Timer_Text.setOrigin(Timer_Text.getLocalBounds().width/2, Timer_Text.getOrigin().y);
  Timer_Text.setPosition((SCREEN_WIDTH/2), Timer_Text.getPosition().y);
  Game_window.draw(Timer_Text);
}
