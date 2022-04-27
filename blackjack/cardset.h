#ifndef CARDSET_H
#define CARDSET_H

#include <QObject>
#include "board.h"

class CardSet : public QObject
{
    Q_OBJECT
public:
    explicit CardSet(QObject *parent = nullptr);

    std::vector<Card> get_cards_() { return cards_; }
    void add_card(Card c) { cards_.push_back(c); }
    void remove_card(Card c);

    int get_bet_amount_() { return bet_amount_; }
    void double_bet_amount() { bet_amount_ *= 2; }

private slots:
    std::vector<CardSet> get_split_cardset();

private:
    std::vector<Card> cards_;
    int bet_amount_;

};

#endif // CARDSET_H
