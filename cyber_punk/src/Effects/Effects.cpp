#include "include/Effects/Effects.h"

namespace effects {
  effect_function make_damage_effect(int damage) {
    return [damage](characters::Character& character) { character.damage(damage); };
  }

  effect_function make_healing_effect(int healing) {
    return [healing](characters::Character& character) { character.heal(healing); };
  }

  void damage_50_percent(characters::Character& character) { character.damage(character.max_health() / 2); }

  void heal_50_percent(characters::Character& character) { character.heal(character.max_health() / 2); }

  void draw_a_card(characters::Character& character) {
    characters::Player* player = static_cast<characters::Player*>(&character);
    player->draw();
  }
} // effects