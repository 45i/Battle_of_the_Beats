#include "Music.hpp"
#include "Game.hpp"

void Song::Play_audio(int current_stage) {
Current_Song.openFromFile("Song_"+std::to_string(current_stage)+".wav");
Current_Song.play();
}




