#include <string>
#include <iostream>

#include "include/Characters/Player.h"

int main(int argc, char* argv[]) {
  characters::Player player;
  while (!player.dead()) {
    characters::Character monster(100);
    while (!monster.dead()) {
      player.add_card_to_hand(cards::Card(0, 20));
      player.add_card_to_hand(cards::Card(50, 0));
      player.play_card(0, monster);
      std::cout << monster;
      player.play_card(0, monster);
      std::cout << monster;
      std::cin.get();
    }
    std::cout << "Killed monster!\n";
  }

}