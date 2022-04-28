#include "cardset.h"

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
    qreal y=y_+150;
    tmp->setPos(x, y);
    scene_->addItem(tmp);
}


vector<int> CardSet::minChips(int bet_amount){
    int chip_values[11]={10000,5000,2000,1000,500,250,200,100,50,20,10};
    vector<int> res;
    for(int i=0; i<11; i++){
        while(chip_values[i] <= bet_amount){
            bet_amount = bet_amount - chip_values[i];
            res.push_back(chip_values[i]);
        }
    }
    return res;
}

void CardSet::set_bet_chips(int bet_amount){
    bet_chips_.clear();
    bet_amount_=bet_amount;
    vector<int> res=minChips(bet_amount);
    for(int i=0; i<res.size(); i++){
        Chip *nc=new Chip(res[i]);
        bet_chips_.push_back(nc);
        qreal x=x_+i*10;
        nc->setPos(x, y_);
        scene_->addItem(nc);
    }
}

/**
 * @brief CardSet::split_cardset splits the cardset into two cardsets
 * @return two card sets with the same bets
 */
 std::tuple<CardSet*, CardSet*> CardSet::split_cardset() {
    Card* c = cardPics_.front()->get_card();
    //remove from current CardSet
    remove_card(c);
    CardSet* set1 = new CardSet(this->scene_);
    set1->set_bet_amount(this->get_bet_amount_());
    set1->add_card(c);
    return std::make_tuple(set1, this);
}








