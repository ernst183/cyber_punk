#ifndef PLAYER_H
#define PLAYER_H

#include "include/Characters/Character.h"
#include "include/Cards/Deck.h"

namespace characters {
  
class Player : public Character {
public:
  Player() {
    add_card_to_deck(cards::Card(60, 0));
    add_card_to_deck(cards::Card(0, 20));
  }

  int hand_size() const { return hand_.size(); }
  std::vector<cards::Card> hand() const { return hand_; }
  void add_card_to_hand(cards::Card&& card);
  void add_card_to_deck(cards::Card&& card);

  void draw() { hand_.push_back(deck_.draw()); }
  void discard(int card_pos);
  void play_card(int card_pos, Character& character);

private:
  std::vector<cards::Card> hand_;
  cards::Deck deck_;
};

} // characters
#endif // PLAYER_H