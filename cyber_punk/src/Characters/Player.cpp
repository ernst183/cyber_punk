#include "include/Characters/Player.h"

namespace characters {
  void Player::add_card_to_hand(cards::Card&& card) {
    hand_.push_back(card);
  }

  void Player::discard(int card_pos) {
    cards::Card card = hand_[card_pos];
    hand_.erase(hand_.begin() + card_pos);
    deck_.add_card_to_discard(std::move(card));
  }

  void Player::add_card_to_deck(cards::Card&& card) {
    deck_.add_card_to_deck(std::move(card));
  }

  void Player::play_card(int card_pos, Character& character) {
    const cards::Card& card = hand_[card_pos];
    character.resolve_card(card);
    discard(card_pos);
  }

}