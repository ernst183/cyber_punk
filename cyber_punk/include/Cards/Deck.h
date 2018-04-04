#ifndef DECK_H
#define DECK_H

#include <vector>
#include <deque>

#include "include/Cards/Card.h"

namespace cards {

class Deck {
public:
  Deck() {}

  Deck(std::deque<Card>&& cards)
    : deck_(std::move(cards))
  {}

  int deck_size() const { return deck_.size(); }
  int discard_size() const { return discard_.size(); }

  std::deque<Card> deck() const { return deck_; }
  std::deque<Card> discard_pile() const { return discard_; }

  Card draw();
  void add_card_to_deck(Card&& card);
  void add_card_to_discard(Card&& card);
  void shuffle_discard();
  void shuffle_deck();

private:
  std::deque<Card> deck_;
  std::deque<Card> discard_;

};

}

#endif // DECK_H