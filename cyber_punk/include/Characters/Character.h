#ifndef CHARACTER_H
#define CHARACTER_H

#include <iostream>

namespace characters {
  
class Character {
public:
  Character(int health)
    : health_(health)
    , max_health_(health)
  {}

  void heal(int amount);
  void damage(int amount);
  void increase_max_health(int amount);

  int health() const { return health_; }
  int max_health() const { return max_health_; }

  bool dead() const { return health_ == 0; }

  friend std::ostream& operator<<(std::ostream& os, const Character& character) {
    os << "Health: " << character.health() << '\n' << "Energy: " << "\n\n";
    return os;
  }

private:
  int health_;

  int max_health_;
};

} // characters
#endif // CHARACTER_H