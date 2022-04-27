#ifndef CARDSET_H
#define CARDSET_H

#include <QGraphicsView>
#include <QObject>
#include "board.h"
#include "cardpic.h"
#include "game.h"

using namespace std;

class CardSet : public QObject
{
    Q_OBJECT
public:
    CardSet(QGraphicsScene *scene, QObject *parent = nullptr);

    std::vector<cardPic*> get_cards_pics_() { return cardPics_; }
    void add_card(Card *c);
    void remove_card(Card *c);

    int get_bet_amount_() { return bet_amount_; }
    void double_bet_amount() { bet_amount_ *= 2; }
    CardSet *split_cardset();

private:
    double x_;
    double y_;
    vector<cardPic*> cardPics_;
    int bet_amount_;
    QGraphicsScene *scene_;

};

#endif // CARDSET_H
