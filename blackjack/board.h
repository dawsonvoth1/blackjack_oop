#ifndef BOARD_H
#define BOARD_H

#include <QColor>
#include <QObject>

// Betting Chip struct
struct Chip {
    QColor color_;
    int value_;
};

// Card Suits
enum class Suit {Heart, Diamond, Spade, Club};

// Playing Card Struct
struct Card {
    int value_;
    Suit suit_;
    int deck_;
    bool dealt_;
};

class Board : public QObject
{
    Q_OBJECT
public:
    explicit Board(QObject *parent = nullptr);

    std::vector<Card> get_dealers_cards() { return dealers_cards_; }
    void clear_dealer_cards() { dealers_cards_.clear(); }
    std::vector<Card> get_cards() { return cards_; }

    int get_count() { return count_; }

    //MARK - TODO
    Card deal_next_card();
    void shuffle_cards();

private:
    std::vector<Card> dealers_cards_;
    int num_decks_;
    std::vector<Card> cards_;
    Card top_card_;
    int count_;
signals:

};

#endif // BOARD_H
