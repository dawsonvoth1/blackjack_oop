#ifndef PLAYER_H
#define PLAYER_H

#include <QObject>
#include "board.h"

class Player : public QObject
{
    Q_OBJECT
public:
    explicit Player(QObject *parent = nullptr);

    int get_money() { return money_; }
    void add_money(int amnt) {money_ += amnt; }
    void remove_money(int amnt) {money_ -= amnt; }

    std::vector<Card> get_cards() { return cards_; }
    void add_card(Card c) { cards_.push_back(c); }
    void clear_cards() { cards_.clear(); }

private:
    QString name_;
    int money_;
    std::vector<Card> cards_;

signals:

};

#endif // PLAYER_H
