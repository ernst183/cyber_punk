#include "include/Cards/Deck.h"

#include <algorithm>

namespace cards {

  Card Deck::draw() {
    Card card = deck_.front();
    deck_.pop_front();
    return card;
  }

  void Deck::add_card_to_deck(Card&& card) {
    deck_.push_back(card);
  }

  void Deck::add_card_to_discard(Card&& card) {
    discard_.push_back(card);
  }

  void Deck::shuffle_discard() {
    while (!discard_.empty()) {
      deck_.push_back(discard_.front());
      discard_.pop_front();
    }
    shuffle_deck();
  }

  void Deck::shuffle_deck() {
    std::random_shuffle(deck_.begin(), deck_.end());
  }

} // cards