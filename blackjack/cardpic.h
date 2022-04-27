#ifndef CARDPIC_H
#define CARDPIC_H

#include <QObject>
#include <QGraphicsItem>
#include <QGraphicsPixmapItem>
#include <QPixmap>
#include <QImage>

#include <board.h>
//// Card Suits
//enum class Suit {Heart, Diamond, Spade, Club};

//// Playing Card Struct
//struct Card {
//    int value_;
//    Suit suit_;
//    int deck_;
//    bool dealt_;
//};

class cardPic : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    cardPic(Card *card);

private:
    Card *card_;
};

#endif // CARDPIC_H
