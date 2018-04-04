#include <string>
#include <iostream>

#include "include/Characters/Player.h"

int main(int argc, char* argv[]) {
  // Create Player
  characters::Player player;
  player.draw();
  player.draw();
  player.play_card(0, player);
  std::cout << player;
  player.play_card(0, player);
  std::cout << player;
  std::cin.get();
}