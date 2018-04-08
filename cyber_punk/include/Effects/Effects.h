#ifndef EFFECTS_H
#define EFFECTS_H

#include <functional>
#include <vector>

#include "include/Characters/Player.h"

namespace effects {
  typedef std::function<void(characters::Character&, const std::vector<std::shared_ptr<EffectModification>>&)> effect_function ;

  effect_function make_damage_effect(int damage);
  effect_function make_healing_effect(int healing);

  void damage_50_percent(characters::Character& character, const std::vector<std::shared_ptr<EffectModification>>& input_mods);
  void heal_50_percent(characters::Character& character, const std::vector<std::shared_ptr<EffectModification>>& input_mods);
  void draw_a_card(characters::Character& character, const std::vector<std::shared_ptr<EffectModification>>& input_mods);

}

#endif // EFFECTS_H