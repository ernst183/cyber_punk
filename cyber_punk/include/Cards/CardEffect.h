#ifndef CARD_EFFECT_H
#define CARD_EFFECT_H

#include <functional>
#include "include/Characters/Character.h"

namespace cards {

  class CardEffect {
  public:
    CardEffect(std::function<void(characters::Character&, const std::vector<std::shared_ptr<effects::EffectModification>>&)> effect)
      : effect_(effect)
    {}

    void resolve_effect(characters::Character& target, const std::vector<std::shared_ptr<effects::EffectModification>>& input_mods = {}) const {
      effect_(target, input_mods);
    }

  private:
    std::function<void(characters::Character&, const std::vector<std::shared_ptr<effects::EffectModification>>&)> effect_;
  };

} // cards

#endif // CARD_EFFECT_H
