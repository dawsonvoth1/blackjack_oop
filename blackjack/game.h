#ifndef GAME_H
#define GAME_H

#include <QColor>
#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class Board; }
QT_END_NAMESPACE

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

class Game : public QMainWindow
{
    Q_OBJECT

public:
    Game(QWidget *parent = nullptr);
    ~Game();

private:
    Ui::Board *ui;
};
#endif // GAME_H
