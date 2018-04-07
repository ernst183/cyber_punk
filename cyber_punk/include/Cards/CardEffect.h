#ifndef CARD_EFFECT_H
#define CARD_EFFECT_H

#include <functional>
#include "include/Characters/Character.h"

namespace cards {

  class CardEffect {
  public:
    CardEffect(std::function<void(characters::Character&)> effect)
      : effect_(effect)
    {}

    void resolve_effect(characters::Character& target) const {
      effect_(target);
    }

  private:
    std::function<void(characters::Character&)> effect_;
  };

} // cards

#endif // CARD_EFFECT_H
