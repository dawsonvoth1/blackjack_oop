#include "cardset.h"
#include "board.h"
#include "vector"

CardSet::CardSet(QGraphicsScene *scene, QObject *parent)
    :  QObject{parent}
{
    scene_=scene;
}

/**
 * @brief CardSet::remove_card remove a card from the cardset
 * @param c the card to remove
 */
void CardSet::remove_card(Card *c) {
    for(int i=0; i<cardPics_.size(); i++){
        if(cardPics_[i]->get_card()==c){
            cardPics_.erase(cardPics_.begin()+i);
        }
    }
}

void CardSet::add_card(Card *c){
    cardPic* tmp=new cardPic(c);
    int vec_size=cardPics_.size();
    cardPics_.push_back(tmp);
    qreal x=x_+vec_size*40;
    tmp->setPos(x, y_);
    scene_->addItem(tmp);
}
