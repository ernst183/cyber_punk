#include "include/Cards/Card.h"

namespace cards {
  
  void Card::resolve_effects(
    characters::Character& character, 
    const std::vector<std::shared_ptr<effects::EffectModification>>& input_mods
  ) const {
    for (size_t i = 0; i < effects_.size(); ++i) {
      effects_[i].resolve_effect(character, input_mods);
    }
  }
  
  void Card::resolve_effects(
    std::vector<characters::Character>& characters, 
    const std::vector<std::shared_ptr<effects::EffectModification>>& input_mods
  ) const {
    for (size_t i = 0; i < effects_.size(); ++i) {
      effects_[i].resolve_effect(characters[i], input_mods);
    }
  }

} // cards