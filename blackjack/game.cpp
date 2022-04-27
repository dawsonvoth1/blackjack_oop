#include "game.h"
#include "ui_game.h"//.h"
#include "player.h"
#include "vector"

Game::Game(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Game)
{
    ui->setupUi(this);

    scene_=new QGraphicsScene;
    view_=ui->graphicsView;
    view_->setScene(scene_);
    // make the scene the same size as the view containing it
    view_->setSceneRect(0,0,view_->frameSize().width(),view_->frameSize().height());
    // make an outline
    scene_->addRect(0, 0, view_->frameSize().width(), view_->frameSize().height());
    Card *c=new Card;
    c->dealt_=false;
    c->deck_=1;
    c->suit_=Suit::Club;
    c->value_=2;
    CardSet* cs=new CardSet(scene_);
    cs->add_card(c);
    cs->add_card(c);
//    scene_->addItem(p);


}

Game::~Game()
{
    delete ui;
}

/**
 * @brief Game::remove_player remove a player from the players_ vector
 * @param p the player to remove
 */
void Game::remove_player(Player* p) {
    std::vector<Player*>::iterator position = std::find(players_.begin(), players_.end(), p);
    if (position != players_.end()) {
        players_.erase(position);
    }
}

/**
 * @brief Game::deal deal cards to players
 */
void Game::deal() {

}

/**
 * @brief Game::takeTurn player takes a turn
 * @param p the player
 */
void Game::takeTurn(Player* p) {

}

/**
 * @brief Game::hit the player hits
 * @param p the player
 */

void Game::hit(Player* p) {

}

/**
 * @brief Game::double_bet double a bet into two separate bets
 * @param p the player
 */
void Game::double_bet(Player* p) {

}

/**
 * @brief Game::stay player chooses to stay
 * @param p the player
 */
void Game::stay(Player *p) {

}

/**
 * @brief Game::quit the player chooses to quit
 * @param p the player
 */
void Game::quit(Player *p) {

}

/**
 * @brief Game::addMoney the player chooses to add money
 * @param p the player
 */
void Game::addMoney(Player *p) {
    p->add_money(add_money_amnt);
}

/**
 * @brief Game::exit the player chooses to exit
 */
void Game::exit() {

}
