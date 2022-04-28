#ifndef BOARD_H
#define BOARD_H

#include <QColor>
#include <QObject>
#include "cardset.h"

class Board : public QObject
{
    Q_OBJECT
public:
    explicit Board(QObject *parent = nullptr);

    std::vector<Card> get_dealers_cards() { return dealers_cards_; }
    void clear_dealer_cards() { dealers_cards_.clear(); }
    std::vector<Card> get_cards() { return cards_; }

    int get_count() { return count_; }

    void shuffle_cards();
    //MARK - TODO
    Card deal_next_card();

private:
    std::vector<Card> dealers_cards_;
    const int num_decks_ = 3;
    std::vector<Card> cards_;
    Card top_card_;
    int count_;
signals:

};

#endif // BOARD_H
