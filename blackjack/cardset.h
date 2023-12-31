#ifndef CARDSET_H
#define CARDSET_H

#include <QGraphicsView>
#include <QObject>
#include "cardpic.h"
#include "chip.h"
#include <vector>

using namespace std;


class CardSet : public QObject
{
    Q_OBJECT
public:
    CardSet(QGraphicsScene *scene, int player_num, QObject *parent = nullptr);

    std::vector<cardPic*> get_cards_pics_() { return cardPics_; }
    void add_card(Card *c);
    void remove_card(Card *c);

    vector<int> minChips(int bet_amount);
    void set_bet_chips(int bet_amount);
//    void add_chip(int value);

    int get_bet_amount_() { return bet_amount_; }
    int set_bet_amount(int amnt) { bet_amount_ = amnt; }
    void double_bet_amount() { bet_amount_ *= 2; }
    std::tuple<CardSet*, CardSet*> split_cardset();

private:
    int player_num_;
    double x_;
    double y_;
    vector<cardPic*> cardPics_;
    int bet_amount_;
    vector<Chip*> bet_chips_;
    QGraphicsScene *scene_;

};
#endif // CARDSET_H
