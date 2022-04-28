#ifndef PLAYER_H
#define PLAYER_H

#include <QGraphicsView>
#include <QObject>
#include <QPen>
#include "board.h"
#include "cardset.h"

class Player : public QObject
{
    Q_OBJECT
public:
    Player(QGraphicsScene *scene, QObject *parent = nullptr);

    int get_money() { return money_; }
    void add_money(int amnt) {money_ += amnt; }
    void remove_money(int amnt) {money_ -= amnt; }

    std::vector<CardSet*> get_card_sets() { return card_sets_; }
    void add_card_set(CardSet* c) { card_sets_.push_back(c); }
    void clear_card_sets() { card_sets_.clear(); }

private:
    double x_;
    double y_;
    double width_;
    double height_;
    QString name_;
    int money_;
    std::vector<CardSet*> card_sets_;
    QGraphicsScene *scene_;

signals:

};

#endif // PLAYER_H
