#ifndef PLAYER_H
#define PLAYER_H

namespace characters {
  
class Player {
public:
  Player() 
  : health_(100)
  , energy_(5)
  , max_health_(100)
  , max_energy_(5)
  {}

  void heal(int heal_amount);
  void damage(int damage_amount);

  int health() const { return health_; }
  int energy() const { return energy_; }
  int max_health() const { return max_health_; }
  int max_energy() const { return max_energy_; }

  bool dead() const { return health_ > 0; }

private:
  int health_;
  int energy_;

  int max_health_;
  int max_energy_;
};

} // characters
#endif // PLAYER_H