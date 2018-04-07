#include "pch.h"

namespace {
  effects::effect_function DAMAGE_50 = effects::make_damage_effect(50);
  effects::effect_function DAMAGE_10 = effects::make_damage_effect(10);
  effects::effect_function HEAL_20 = effects::make_healing_effect(20);
  effects::effect_function DRAW = effects::draw_a_card;

  cards::Card DAMAGE_CARD({ DAMAGE_50 });
  cards::Card SMALL_DAMAGE_CARD({ DAMAGE_10 });
  cards::Card HEAL_CARD({ HEAL_20 });
  cards::Card DAMAGE_HEAL_CARD({ DAMAGE_50, HEAL_20 });
}
////////////////////////////////////
//CARD TESTS
////////////////////////////////////
TEST(ResolveCard, DamageAndHeal) {
  characters::Character player(100);
  DAMAGE_HEAL_CARD.resolve_effects(player);
  ASSERT_EQ(player.health(), 70);
}

TEST(ResolveCard, Damage) {
  characters::Character player(100);
  DAMAGE_CARD.resolve_effects(player);
  ASSERT_EQ(player.health(), 50);
}

TEST(ResolveCard, Heal) {
  characters::Character player(100);
  DAMAGE_HEAL_CARD.resolve_effects(player);
  ASSERT_EQ(player.health(), 70);
}

////////////////////////////////////
//DECK TESTS
////////////////////////////////////
TEST(DeckSetUp, AddCards) {
  cards::Deck deck;
  deck.add_card_to_deck(cards::Card(DAMAGE_CARD));
  deck.add_card_to_deck(cards::Card(HEAL_CARD));
  ASSERT_EQ(deck.size(), 2);
}

TEST(DeckSetUp, DrawCards) {
  cards::Deck deck;
  deck.add_card_to_deck(cards::Card(DAMAGE_CARD));
  deck.add_card_to_deck(cards::Card(HEAL_CARD));
  cards::Card card = deck.draw();
  ASSERT_EQ(deck.size(), 1);
}

TEST(DeckSetUp, Shuffle) {
  cards::Deck deck1;
  cards::Deck deck2;
  for (int i = 0; i < 1000; ++i) {
    effects::effect_function damage_i = effects::make_damage_effect(i);
    deck1.add_card_to_deck(cards::Card({ damage_i }));
    deck2.add_card_to_deck(cards::Card({ damage_i }));
  }
  deck1.shuffle_deck();
  ASSERT_EQ(deck1.size(), deck2.size());
  int count = 0;
  for (int i = 0; i < deck1.size(); ++i) {
    characters::Character test1{ 1000 };
    characters::Character test2{ 1000 };
    deck1.deck()[i].resolve_effects(test1);
    deck2.deck()[i].resolve_effects(test2);
    if (test1.health() == test2.health())
      ++count;
  }
  ASSERT_LT(count, 100);
}

TEST(DeckSetUp, Discard) {
  cards::Deck deck;
  deck.add_card_to_deck(cards::Card(DAMAGE_CARD));
  deck.add_card_to_deck(cards::Card(DAMAGE_HEAL_CARD));
  deck.add_card_to_discard(deck.draw());
  ASSERT_EQ(deck.size(), 1);
  ASSERT_EQ(deck.discard_size(), 1);
  characters::Character test{ 100 };
  deck.discard_pile()[0].resolve_effects(test);
  ASSERT_EQ(test.health(), 70);
}

////////////////////////////////////
//PLAYER TESTS
////////////////////////////////////
TEST(Player, Hand) {
  characters::Player player;
  player.add_card_to_hand(cards::Card(DAMAGE_HEAL_CARD));
  ASSERT_EQ(player.hand_size(), 1);
}

TEST(Player, HandWithPlayedCard) {
  characters::Player player;
  player.add_card_to_hand(cards::Card(DAMAGE_CARD));
  player.add_card_to_hand(cards::Card(DAMAGE_HEAL_CARD));
  player.play_card(0, player);
  ASSERT_EQ(player.hand_size(), 1);
  ASSERT_EQ(player.health(), 50);
}

TEST(Player, HandWithDiscardedCard) {
  characters::Player player;
  player.add_card_to_hand(cards::Card(DAMAGE_CARD));
  player.add_card_to_hand(cards::Card(DAMAGE_HEAL_CARD));
  player.discard(0);
  ASSERT_EQ(player.deck().discard_size(), 1);
  ASSERT_EQ(player.hand_size(), 1);
  ASSERT_EQ(player.deck().discard_size(), 1);
  characters::Character test(100);
  player.play_card(0, test);
  ASSERT_EQ(test.health(), 70);
}

////////////////////////////////////
//CARD EFFECT TESTS
////////////////////////////////////
TEST(Effects, DrawACard) {
  characters::Player player;
  player.add_card_to_deck(cards::Card{ DAMAGE_CARD });
  cards::Card draw_card({ DRAW });
  player.add_card_to_hand(cards::Card({ DRAW }));
  player.play_card(0, player);
  ASSERT_EQ(player.hand_size(), 1);
  player.play_card(0, player);
  ASSERT_EQ(player.health(), 50);
}

TEST(Effects, VulnerabilityExposed) {
  characters::Player player;
  player.add_effect_modifier(std::make_shared<effects::VulnerabilityExposed>(1));
  player.add_card_to_hand(cards::Card{ SMALL_DAMAGE_CARD });
  player.play_card(0, player);
  ASSERT_EQ(player.health(), 80);

}