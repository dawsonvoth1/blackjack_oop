#include "cardpic.h"

using namespace std;

cardPic::cardPic(Card *card): card_(card)
{
    string s;
    string v;
    if(card->suit_ == Suit::Club){
        s="c";
    }
    else if(card->suit_ == Suit::Heart){
        s="h";
    }
    else if(card->suit_ == Suit::Diamond){
        s="d";
    }
    else if(card->suit_ == Suit::Spade){
        s="s";
    }
    else{
        //face up card?
    }

    if(card->value_ == 1){
        v="a";
    }
    else if(card->value_ == 2){
        v="2";
    }
    else if(card->value_ == 3){
        v="3";
    }
    else if(card->value_ == 4){
        v="4";
    }
    else if(card->value_ == 5){
        v="5";
    }
    else if(card->value_ == 6){
        v="6";
    }
    else if(card->value_ == 7){
        v="7";
    }
    else if(card->value_ == 8){
        v="8";
    }
    else if(card->value_ == 9){
        v="9";
    }
    else if(card->value_ == 10){
        v="10";
    }
    else if(card->value_ == 11){
        v="j";
    }
    else if(card->value_ == 12){
        v="q";
    }
    else if(card->value_ == 13){
        v="k";
    }
    else {
        //???????
    }

    string file=":/PNGs/cards/Set_B/small/card_b_"+s+v+".png";
    QImage i(QString::fromStdString(file));
    QPixmap p=QPixmap::fromImage(i);
    this->setPixmap(p);
}
