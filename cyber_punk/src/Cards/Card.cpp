#include "include/Cards/Card.h"

namespace cards {
  
  void Card::resolve_effects(characters::Character& character) const {
    for (size_t i = 0; i < effects_.size(); ++i) {
      effects_[i].resolve_effect(character);
    }
  }
  
  void Card::resolve_effects(std::vector<characters::Character>& characters) const {
    for (size_t i = 0; i < effects_.size(); ++i) {
      effects_[i].resolve_effect(characters[i]);
    }
  }

} // cards