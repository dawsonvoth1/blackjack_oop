#include "player.h"

Player::Player(QGraphicsScene *scene, int player_num, QObject *parent)
    : QObject{parent}
{
    scene_=scene;
    QColor c1(255,255,255);
    QColor c2(0,0,0);

    QPen p(c1);
    QBrush b(c2, Qt::LinearGradientPattern);
    player_num_=player_num;
    x_=player_num_*250;
    y_=350;
    width_=200;
    height_=50;

    QGraphicsRectItem *rec = scene_->addRect(x_, y_, width_, height_,p, b);

    //create an empty card set
    CardSet* set = new CardSet(scene, player_num_);
    this->add_card_set(set);
}

//Dealer::Dealer(QGraphicsScene *scene,, QObject *parent)
//    : Player(scene)
//{
//    //create an empty card set
//    CardSet* set = new CardSet(scene);
//    this->add_card_set(set);
//}
