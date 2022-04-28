#ifndef CARDSET_H
#define CARDSET_H

#include <QGraphicsView>
#include <QObject>
#include "board.h"
#include "cardpic.h"
#include "chip.h"
#include <vector>

using namespace std;

class CardSet : public QObject
{
    Q_OBJECT
public:
    CardSet(QGraphicsScene *scene, QObject *parent = nullptr);

    std::vector<cardPic*> get_cards_pics_() { return cardPics_; }
    void add_card(Card *c);
    void remove_card(Card *c);

    vector<int> minChips(int bet_amount);
    void set_bet_cips(int bet_amount);
//    void add_chip(int value);

    int get_bet_amount_() { return bet_amount_; }
    void double_bet_amount() { bet_amount_ *= 2; }
    CardSet *split_cardset();

private:
    double x_;
    double y_;
    vector<cardPic*> cardPics_;
    int bet_amount_;
    vector<Chip*> bet_chips_;
    QGraphicsScene *scene_;

};

#endif // CARDSET_H
