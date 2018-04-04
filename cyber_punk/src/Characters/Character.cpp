#include "include/Characters/Character.h"

#include <algorithm>

namespace characters {

  void Character::heal(int amount) {
    if (amount > 0) {
      health_ = std::min(health_ + amount, max_health_);
    }
  }

  void Character::damage(int amount) {
    if (amount > 0) {
      health_ = std::max(health_ - amount, 0);
    }
  }

  void Character::increase_max_health(int amount) {
    max_health_ += amount;
    health_ += amount;
  }
  void Character::increase_max_energy(int amount) {
    max_energy_ += amount;
    energy_ += amount;
  }

  void Character::reset_energy() {
    energy_ = max_energy_;
  }

  void Character::resolve_card(const cards::Card& card) {
    damage(card.damage());
    heal(card.healing());
  }


} // namespace characters