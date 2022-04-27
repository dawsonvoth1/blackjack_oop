#ifndef GAME_H
#define GAME_H

#include <QGraphicsView>
#include <QMainWindow>
#include "player.h"
#include "board.h"
#include "cardpic.h"
#include "cardset.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Game; }
QT_END_NAMESPACE

class Game : public QMainWindow
{
    Q_OBJECT

public:
    Game(QWidget *parent = nullptr);
    ~Game();

    std::vector<Player*> get_players() { return players_; }
    void add_player(Player* p) { players_.push_back(p); }
    // MARK - TODO
    void remove_player(Player* p);
    QGraphicsScene *get_scene(){return scene_;};

private slots:
    void deal();

    void takeTurn(Player* p);
    void hit(Player* p);
    void double_bet(Player* p);
    void stay(Player *p);
    void quit(Player *p);
    void addMoney(Player *p);

    void exit();

private:
    const int add_money_amnt = 10;
    std::vector<Player*> players_;
    Board *board_;
    Ui::Game *ui;
    QGraphicsView* view_;
    QGraphicsScene * scene_;
};
#endif // GAME_H
