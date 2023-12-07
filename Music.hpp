#pragma once
#include <SFML/Audio.hpp>
class Song {
public:
void Play_audio(int current_stage);
private:
sf::Music Current_Song;
};
