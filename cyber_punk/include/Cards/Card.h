#ifndef CARDS_H
#define CARDS_H

#include <functional>
#include <vector>

#include "include/Cards/CardEffect.h"

namespace cards {
 
  class Card {
  public:
    Card(const std::vector<CardEffect>& effects)
      : effects_(effects)
    {}

    const std::vector<CardEffect>& effects() { return effects_; }

    void resolve_effects(characters::Character& character) const;
    void resolve_effects(std::vector<characters::Character>& character) const;

  private:
    std::vector<CardEffect> effects_;
  };

} // cards

#endif // CARDS_H