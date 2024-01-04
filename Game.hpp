#pragma once
#include <SFML/Graphics.hpp>

#include "Enemy.hpp"

#include "Player.hpp"

#include "Health.hpp"

#include "Music.hpp"

#include <memory> 

#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600
class Game {
  public: Game();
  void run();
  private: void Render_stage(int current_stage, std::unique_ptr < Enemy > & , std::unique_ptr < Health > & );
  void Update_Timer();

  public:
  enum class GameScreens {
  Select,
  Gameplay,
  GameisOver,
  Stopped
};
  private: sf::RenderWindow Game_window;
  sf::Font font;
    GameScreens Current_Screen = GameScreens::Select;
  /// Enemy Variables ///
  sf::Texture enemy_texture;
  std::unique_ptr < Enemy > currentEnemy;
  /// Player Variables ///
  std::unique_ptr < Player > playerCharacter;
  /// Health Variables ///
  std::unique_ptr < Health > health;
  /// Stage Variables ///
  sf::Texture background;
  sf::Sprite CurrentBackground;
  short int current_stage = 1;
  /// Music Variables ///
  Song Music_Player;
  /// Timer Variables ///
  short int seconds;
  std::string time_String;
  sf::Clock Game_Timer;
  sf::Text Timer_Text;
  sf::Time Display_Time;
  sf::Time Stage_Time;
  sf::Time Remaining_Time;

};
