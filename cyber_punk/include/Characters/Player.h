#ifndef PLAYER_H
#define PLAYER_H

#include "include/Cards/Deck.h"
#include "include/Characters/Character.h"

namespace characters {
  
class Player : public Character {
public:
  Player()
    : Character(100)
    , energy_(5)
    , max_energy_(5)
  {}

  // Get current energy
  int energy() const { return energy_; }

  // Get max energy
  int max_energy() const { return max_energy_; }

  // Get size of hand
  int hand_size() const { return hand_.size(); }
  
  // Get reference to player hand
  std::vector<cards::Card>& hand() { return hand_; }
  
  // Get reference to player deck
  cards::Deck& deck() { return deck_; }
  
  // Add any card to player hand
  void add_card_to_hand(cards::Card&& card);
  
  // Add any card to player deck
  void add_card_to_deck(cards::Card&& card);

  // Draw a card from the player deck and put it in the player hand
  void draw(int cards) { 
    for (int i = 0; i < status_effects_.size(); ++i)
      cards = status_effects_[i]->change_effect(cards, effects::EffectModification::Draw);
    for(int i = 0; i < cards; ++i) 
      hand_.push_back(deck_.draw()); 
  }

  // Discard the card at card_pos position in player hand
  void discard(int card_pos);

  // Play card at card_pos position in player hand on Character character or Player player
  void play_card(int card_pos, Character& character);

  // Here for debug purposes
  friend std::ostream& operator<<(std::ostream& os, const Player& player) {
    os << "Health: " << player.health() << ", " << "Energy: " << player.energy() << "\n\n";
    return os;
  }


private:
  int energy_;
  int max_energy_;

  std::vector<cards::Card> hand_;
  cards::Deck deck_;
};

} // characters
#endif // PLAYER_H