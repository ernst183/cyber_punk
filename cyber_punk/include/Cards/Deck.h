#ifndef DECK_H
#define DECK_H

#include <vector>
#include <stack>

#include "include/Cards/Card.h"

namespace cards {

class Deck {
public:
  Deck(std::stack<Card>&& cards)
    : cards_(std::move(cards))
  {}

  int deck_size() const { return cards_.size(); }
  int discard_size() const { return discard_.size(); }

  Card draw() { 
    Card card = cards_.top();
    cards_.pop();
    return card;
  }

  void discard(Card&& card) {
    discard_.push(std::move(card));
  }

private:
  std::stack<Card> cards_;
  std::stack<Card> discard_;
};

}

#endif // DECK_H