#include "include/Characters/Player.h"

#include <algorithm>

namespace characters {

  void Player::heal(int heal_amount) {
    if (heal_amount > 0) {
      health_ = std::min(health_ + heal_amount, max_health_);
    }
  }

  void Player::damage(int damage_amount) {
    if (damage_amount > 0) {
      health_ = std::max(health_ - damage_amount, 0);
    }
  }


} // namespace characters