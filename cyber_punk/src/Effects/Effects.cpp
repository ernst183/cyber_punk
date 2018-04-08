#include "include/Effects/Effects.h"

namespace effects {
  effect_function make_damage_effect(int damage) {
    return [damage](characters::Character& character, const std::vector<std::shared_ptr<EffectModification>>& input_mods) { 
      int new_damage = damage;
      for (int i = 0; i < input_mods.size(); ++i) 
        new_damage = input_mods[i]->change_effect(new_damage, EffectModification::DealDamage);        
      character.damage(new_damage);
    };
  }

  effect_function make_healing_effect(int healing) {
    return [healing](characters::Character& character, const std::vector<std::shared_ptr<EffectModification>>& input_mods) {
      int new_healing = healing;
      for (int i = 0; i < input_mods.size(); ++i)
        new_healing = input_mods[i]->change_effect(new_healing, EffectModification::Healing);
      
      character.heal(new_healing);
    };
  }

  void damage_50_percent(characters::Character& character, const std::vector<std::shared_ptr<EffectModification>>& input_mods) {
    int new_damage = character.max_health() / 2;
    for (int i = 0; i < input_mods.size(); ++i) 
      new_damage = input_mods[i]->change_effect(new_damage, EffectModification::DealDamage);
    character.damage(new_damage); 
  }

  void heal_50_percent(characters::Character& character, const std::vector<std::shared_ptr<EffectModification>>& input_mods) { 
    int new_healing = character.max_health() / 2;
    for (int i = 0; i < input_mods.size(); ++i)
      new_healing = input_mods[i]->change_effect(new_healing, EffectModification::Healing);
    character.heal(new_healing);
  }

  void draw_a_card(characters::Character& character, const std::vector<std::shared_ptr<EffectModification>>& input_mods) {
    characters::Player* player = static_cast<characters::Player*>(&character);
    int draw_amount = 1;
    for (int i = 0; i < input_mods.size(); ++i)
      draw_amount = input_mods[i]->change_effect(draw_amount, EffectModification::Draw);
    player->draw(draw_amount);
  }
} // effects