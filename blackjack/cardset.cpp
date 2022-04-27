#include "cardset.h"
#include "board.h"
#include "vector"

CardSet::CardSet(QObject *parent)
    : QObject{parent}
{}

/**
 * @brief CardSet::remove_card remove a card from the cardset
 * @param c the card to remove
 */
void CardSet::remove_card(Card c) {
    std::vector<Card>::iterator position = std::find(cards_.begin(), cards_.end(), c);
    if (position != cards_.end()) {
        cards_.erase(position);
    }
}
