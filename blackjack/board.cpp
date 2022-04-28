#include "board.h"
#include <random>

Board::Board(QObject *parent)
    : QObject{parent}
{
    //shuffle cards
    shuffle_cards();
}

/**
 * @brief Board::shuffle_cards init a deck and shuffle them
 */
void Board::shuffle_cards() {
    for (int deckval = 0; deckval < num_decks_; deckval++) {
        //iterate through all cards
        for (int i = 1; i <= 13; i++) {
            //init Heart card
            Card heart;
            heart.value_ = i;
            heart.suit_ = Suit::Heart;
            heart.deck_ = deckval;
            heart.dealt_ = false;

            //init Diamond card
            Card diamond;
            diamond.value_ = i;
            diamond.suit_ = Suit::Diamond;
            diamond.deck_ = deckval;
            diamond.dealt_ = false;

            //init Spade card
            Card spade;
            spade.value_ = i;
            spade.suit_ = Suit::Spade;
            spade.deck_ = deckval;
            spade.dealt_ = false;

            //init Club card
            Card club;
            club.value_ = i;
            club.suit_ = Suit::Club;
            club.deck_ = deckval;
            club.dealt_ = false;

            cards_.push_back(heart);
            cards_.push_back(diamond);
            cards_.push_back(spade);
            cards_.push_back(club);
        }
    }

    // begin shuffle of cards_ vector
    auto rng = std::default_random_engine {};
    std::shuffle(std::begin(cards_), std::end(cards_), rng);
}

/**
 * @brief Board::deal_next_card calls on the deck to deal the next card
 * @return the first card of the top
 */
Card Board::deal_next_card() {
    Card c = cards_.back();
    cards_.pop_back();
    return c;
}
