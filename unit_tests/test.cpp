#include "pch.h"

TEST(ResolveCard, DamageAndHeal) {
  characters::Character player(100);
  player.resolve_card(cards::Card(50, 20));
  ASSERT_EQ(player.health(), 70);
}

TEST(ResolveCard, Damage) {
  characters::Character player(100);
  player.resolve_card(cards::Card(50, 0));
  ASSERT_EQ(player.health(), 50);
}

TEST(ResolveCard, Heal) {
  characters::Character player(100);
  player.resolve_card(cards::Card(0, 20));
  ASSERT_EQ(player.health(), 100);
}

TEST(DeckSetUp, AddCards) {
  cards::Deck deck;
  deck.add_card_to_deck(cards::Card(10, 10));
  deck.add_card_to_deck(cards::Card(10, 10));
  ASSERT_EQ(deck.size(), 2);
}

TEST(DeckSetUp, DrawCards) {
  cards::Deck deck;
  deck.add_card_to_deck(cards::Card(20, 20));
  deck.add_card_to_deck(cards::Card(10, 10));
  cards::Card card = deck.draw();
  ASSERT_EQ(deck.size(), 1);
  ASSERT_EQ(card.damage(), 10);
  ASSERT_EQ(card.healing(), 10);
}

TEST(DeckSetUp, Shuffle) {
  cards::Deck deck1;
  cards::Deck deck2;
  for (int i = 0; i < 1000; ++i) {
    deck1.add_card_to_deck(cards::Card(i, i));
    deck2.add_card_to_deck(cards::Card(i, i));
  }
  deck1.shuffle_deck();
  ASSERT_EQ(deck1.size(), deck2.size());
  int count = 0;
  for (int i = 0; i < deck1.size(); ++i) {
    if (deck1.deck()[i].damage() == deck2.deck()[i].damage())
      ++count;
  }
  ASSERT_LT(count, 100);
}

TEST(DeckSetUp, Discard) {
  cards::Deck deck;
  deck.add_card_to_deck(cards::Card(20, 20));
  deck.add_card_to_deck(cards::Card(10, 10));
  deck.add_card_to_discard(deck.draw());
  ASSERT_EQ(deck.size(), 1);
  ASSERT_EQ(deck.discard_size(), 1);
  ASSERT_EQ(deck.discard_pile()[0].damage(), 10);
}

TEST(Player, Hand) {
  characters::Player player;
  player.add_card_to_hand(cards::Card(50, 50));
  ASSERT_EQ(player.hand_size(), 1);
}

TEST(Player, HandWithPlayedCard) {
  characters::Player player;
  player.add_card_to_hand(cards::Card(50, 0));
  player.add_card_to_hand(cards::Card(30, 30));
  player.play_card(0, player);
  ASSERT_EQ(player.hand_size(), 1);
  ASSERT_EQ(player.health(), 50);
}