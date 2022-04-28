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

    std::vector<Card> get_cards() { return cards_; }
    void clear_cards() { cards_.clear(); }

    int get_count() { return count_; }

    void shuffle_cards();
    Card deal_next_card();


private:
    const int num_decks_ = 3;
    std::vector<Card> cards_;
    Card top_card_;
    int count_;

};

#endif // BOARD_H
