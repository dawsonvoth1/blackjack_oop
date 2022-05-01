#ifndef GAME_H
#define GAME_H

#include <QGraphicsView>
#include <QMainWindow>
#include "player.h"
#include "board.h"
//#include "cardpic.h"
//#include "cardset.h"


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
    void remove_player(Player* p);

    Player* get_current_player_() { return current_player_; }
    void set_current_player_(Player* p) { current_player_ = p; }

    QGraphicsScene *get_scene(){ return scene_; };

    void rotate_current_player();


private slots:
    void deal();

    void bet();
    void hit();
    void double_bet();
    void stay();
    void quit();
    void addMoney();
    void add_player();

    void redo_turn();
    void insure_turn();

    void exit();

private:
    Player* current_player_;
    const int add_money_amnt = 10;
    std::vector<Player*> players_;
    Board *board_;
    Ui::Game *ui;
    QGraphicsView* view_;
    QGraphicsScene * scene_;
};
#endif // GAME_H
