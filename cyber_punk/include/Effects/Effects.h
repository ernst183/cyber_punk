#ifndef EFFECTS_H
#define EFFECTS_H

#include <functional>
#include <vector>

#include "include/Characters/Player.h"

namespace effects {
  typedef std::function<void(characters::Character&)> effect_function ;

  effect_function make_damage_effect(int damage);
  effect_function make_healing_effect(int healing);

  void damage_50_percent(characters::Character& character); 
  void heal_50_percent(characters::Character& character);
  void draw_a_card(characters::Character& character);

}

#endif // EFFECTS_H