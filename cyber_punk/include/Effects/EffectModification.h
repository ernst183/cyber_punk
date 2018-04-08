#ifndef EFFECT_MODIFICATIONS_H
#define EFFECT_MODIFICATIONS_H

namespace effects {

class EffectModification {
public:
  enum StatusEffect : uint16_t {
    VulnerabilityExposed = 0,
    Lag                  = 1,
    Strong               = 2
  };

  enum EffectType : uint16_t {
    Damage = 0,
    Defense = 1,
    Healing = 2,
    Draw = 3
  };

  EffectModification(StatusEffect effect)
    : status_effect_(effect)
  {}

  StatusEffect status_effect() const { return status_effect_; }

  virtual int change_effect(int effect_amount, EffectType type) const = 0;

private:
  StatusEffect status_effect_;
};


// Double all damage done
class VulnerabilityExposed : public EffectModification {
public:
  VulnerabilityExposed(int turns)
    : EffectModification(StatusEffect::VulnerabilityExposed)
    , turns_(turns)
  {}

  int change_effect(int effect_amount, EffectType type) const { 
    if (type == EffectType::Damage) {
      return effect_amount * 2;
    }
    else {
      return effect_amount;
    }
  }

private:
  int turns_;
};

class Strong : public EffectModification {
public:
  Strong(int amount)
    :EffectModification(StatusEffect::Strong)
    , amount_(amount)
  {}

  int change_effect(int effect_amount, EffectType type) const {
    if (type == EffectType::Damage) {

    }
  }

private:
  int amount_;
};
} // effects

#endif // EFFECT_MODIFCATIONS_H

