#include "cardpic.h"

cardPic::cardPic(Card *card): card_(card)
{
    QImage i("/Users/dawsonvoth/Desktop/3010/spring 2022/HW5/PNGs/cards/Set_B/small/card_b_sa.png");
    QPixmap p=QPixmap::fromImage(i);
    this->setPixmap(p);
}
