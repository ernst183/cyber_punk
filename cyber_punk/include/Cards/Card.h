#ifndef CARDS_H
#define CARDS_H

namespace cards {
 
class Card {
public:
  Card(int damage, int healing)
    : damage_(damage)
    , healing_(healing)
  {}

  virtual int damage() const { return damage_; }
  virtual int healing() const { return healing_; }
  ///virtual Effects effects() = 0; // TODO: Add effects to cards

private:
  int damage_;
  int healing_;
};

} // cards

#endif // CARDS_H