#include <string>
#include <iostream>

#include "include/Characters/Player.h"

int main(int argc, char* argv[]) {
  // Create Player
  characters::Player player;
  
  // Create Cards
  cards::Card damage_card{ 60, 0 };
  cards::Card healing_card{ 0, 20 };

  // Damage, heal, and damage player, then test for death
  std::cout << player;
  player.resolve_card(damage_card);
  std::cout << player;
  std::cout << player.dead() << '\n';
  player.resolve_card(healing_card);
  std::cout << player;
  std::cout << player.dead() << '\n';
  player.resolve_card(damage_card);
  std::cout << player;
  std::cout << player.dead() << '\n';
  std::cin.get();  
}