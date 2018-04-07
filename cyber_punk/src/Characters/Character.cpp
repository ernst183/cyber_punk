#include "include/Characters/Character.h"

#include <algorithm>

namespace characters {

  void Character::heal(int amount) {
    if (amount > 0) {
      for (int i = 0; i < status_effects_.size(); ++i)
        amount = status_effects_[i]->change_effect(amount, effects::EffectModification::EffectType::Healing);
      health_ = std::min(health_ + amount, max_health_);
    }
  }

  void Character::damage(int amount) {
    if (amount > 0) {
      for (int i = 0; i < status_effects_.size(); ++i)
        amount = status_effects_[i]->change_effect(amount, effects::EffectModification::EffectType::Damage);
      health_ = std::max(health_ - amount, 0);
    }
  }

  void Character::increase_max_health(int amount) {
    max_health_ += amount;
    for (int i = 0; i < status_effects_.size(); ++i)
      amount = status_effects_[i]->change_effect(amount, effects::EffectModification::EffectType::Healing);
    health_ += amount;
  }

} // namespace characters