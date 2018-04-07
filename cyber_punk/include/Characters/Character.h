#ifndef CHARACTER_H
#define CHARACTER_H

#include <iostream>
#include <vector>
#include <memory>

#include "include/Effects/EffectModification.h"

namespace characters {
  
class Character {
public:
  Character(int health)
    : health_(health)
    , max_health_(health)
  {}

  // Heal character for amount
  void heal(int amount);

  // Damage character for amount
  void damage(int amount);

  // Increase character's max health by amount
  void increase_max_health(int amount);

  // Get character's current health
  int health() const { return health_; }

  // Get character's maximum health
  int max_health() const { return max_health_; }

  // Add effect modifier to character
  void add_effect_modifier(std::shared_ptr<effects::EffectModification> mod) { status_effects_.push_back(mod); }

  // Check if character is dead
  bool dead() const { return health_ == 0; }

  friend std::ostream& operator<<(std::ostream& os, const Character& character) {
    os << "Health: " << character.health() << "\n\n";
    return os;
  }

private:
  int health_;
  int max_health_;
  std::vector<std::shared_ptr<effects::EffectModification>> status_effects_;
};

} // characters
#endif // CHARACTER_H