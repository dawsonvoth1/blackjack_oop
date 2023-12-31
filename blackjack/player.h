#ifndef PLAYER_H
#define PLAYER_H

#include <QGraphicsView>
#include <QObject>
#include <QPen>
#include "cardset.h"

class Player : public QObject
{
    Q_OBJECT
public:
    Player(QGraphicsScene *scene, int player_num, QObject *parent = nullptr);

    int get_money() { return money_; }
    void add_money(int amnt) {money_ += amnt; }
    void remove_money(int amnt) {money_ -= amnt; }

    std::vector<CardSet*> get_card_sets() { return card_sets_; }
    void add_card_set(CardSet* c) { card_sets_.push_back(c); }
    void clear_card_sets() { card_sets_.clear(); }

    QString get_name() { return name_; }
    void set_name(QString name) { name_ = name; }

private:
    int player_num_;
    double x_;
    double y_;
    double width_;
    double height_;
    QString name_;
    int money_ = 100;
    std::vector<CardSet*> card_sets_;
    QGraphicsScene *scene_;
};

//class Dealer: public Player{
//    Q_OBJECT
//public:
//    Dealer(QGraphicsScene *scene, QObject *parent = nullptr);

//    std::vector<CardSet*> get_card_sets() { return card_sets_; }
//    void add_card_set(CardSet* c) { card_sets_.push_back(c); }
//    void clear_card_sets() { card_sets_.clear(); }

//     QString get_name() { return name_; }

//    int get_hitline_() { return hitline_; }
//    void set_hitline_(int amnt) { hitline_ = amnt; }

//    // depending on card total < or > than hitline, will either hit or stand
//    void make_move();

//private:
//    int hitline_ = 17;
//    double x_;
//    double y_;
//    double width_;
//    double height_;
//    const QString name_ = "Dealer";
//    std::vector<CardSet*> card_sets_;
//    QGraphicsScene *scene_;
//};

#endif // PLAYER_H
