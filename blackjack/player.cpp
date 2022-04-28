#include "player.h"

Player::Player(QGraphicsScene *scene, QObject *parent)
    : QObject{parent}
{
    scene_=scene;
    QColor c1(255,255,255);
    QColor c2(0,0,0);

    QPen p(c1);
    QBrush b(c2, Qt::LinearGradientPattern);

    x_=0;
    y_=350;
    width_=200;
    height_=50;

    QGraphicsRectItem *rec = scene_->addRect(x_, y_, width_, height_,p, b);


}
