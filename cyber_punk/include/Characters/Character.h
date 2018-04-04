#ifndef CHARACTER_H
#define CHARACTER_H

#include <iostream>

#include <include/Cards/Card.h>

namespace characters {
  
class Character {
public:
  Character()
    : health_(100)
    , energy_(5)
    , max_health_(100)
    , max_energy_(5)
  {}

  void heal(int amount);
  void damage(int amount);
  void increase_max_health(int amount);
  void increase_max_energy(int amount);
  void reset_energy();

  int health() const { return health_; }
  int energy() const { return energy_; }
  int max_health() const { return max_health_; }
  int max_energy() const { return max_energy_; }

  void resolve_card(const cards::Card& card);

  bool dead() const { return health_ > 0; }

  friend std::ostream& operator<<(std::ostream& os, const Character& character) {
    os << "Health: " << character.health() << '\n' << "Energy: " << character.energy() << "\n\n";
    return os;
  }

private:
  int health_;
  int energy_;

  int max_health_;
  int max_energy_;
};

} // characters
#endif // CHARACTER_H