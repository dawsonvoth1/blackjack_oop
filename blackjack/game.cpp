#include "game.h"
#include "ui_game.h"//.h"
#include <iostream>
#include <QMessageBox>

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
    //Create Board Instance
    board_ = new Board();

    //connect buttons
     connect(ui->hitpushButton, &QAbstractButton::clicked, this, &Game::hit);
     connect(ui->doublepushButton, &QAbstractButton::clicked, this, &Game::double_bet);
     connect(ui->staypushButton, &QAbstractButton::clicked, this, &Game::stay);
     connect(ui->betpushButton, &QAbstractButton::clicked, this, &Game::bet);
     connect(ui->quitpushButton, &QAbstractButton::clicked, this, &Game::quit);
     connect(ui->redopushButton, &QAbstractButton::clicked, this, &Game::redo_turn);
     connect(ui->addMoneypushButton, &QAbstractButton::clicked, this, &Game::addMoney);
     connect(ui->insureTurnpushButton, &QAbstractButton::clicked, this, &Game::insure_turn);
     connect(ui->dealpushButton, &QAbstractButton::clicked, this, &Game::deal);
     connect(ui->exitpushButton, &QAbstractButton::clicked, this, &Game::exit);
     connect(ui->addPlayerpushButton, &QAbstractButton::clicked, this, &Game::add_player);

}

Game::~Game()
{
    delete ui;
}

/**
 * @brief Game::remove_player remove a player from the players_ vector
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
    //give two cards to each player
    for (int i = 0; i < players_.size(); i++) {
        std::vector<CardSet *> user_sets = players_[i]->get_card_sets();
        for (int j = 0; j < user_sets.size(); j++) {
            Card one = board_->deal_next_card();
            Card two = board_->deal_next_card();

            user_sets.at(j)->add_card(&one);
            user_sets.at(j)->add_card(&two);
        }
    }
}

/**
 * @brief Game::bet bets a certain amount
 */
void Game::bet() {
    int betamnt = ui->inputBetlineEdit->text().toInt();
    if (betamnt <= current_player_->get_money()) {
        for (int i = 0; i < current_player_->get_card_sets().size(); i++) {
            current_player_->get_card_sets()[i]->set_bet_amount(betamnt);
            current_player_->get_card_sets()[i]->set_bet_chips(betamnt);
            current_player_->remove_money(betamnt);
        }
    } else {
        //not enough money to bet
        QMessageBox::information(
            this,
            tr("Please Check Your Balance"),
            tr("You do not have enough money to bet that.") );
    }
}

/**
 * @brief Game::hit the player hits
 */

void Game::hit() {
    if (current_player_->get_card_sets().size() > 1) {
        for (int i = 0; i < current_player_->get_card_sets().size(); i++) {
            Card newCard = board_->deal_next_card();
            current_player_->get_card_sets().at(i)->add_card(&newCard);
        }
    } else {
        Card newCard = board_->deal_next_card();
        current_player_->get_card_sets().at(0)->add_card(&newCard);
    }
}

/**
 * @brief Game::double_bet double a bet into two separate bets
 */
void Game::double_bet() {
    CardSet* temp = current_player_->get_card_sets().at(0);
    current_player_->clear_card_sets();
    auto split_sets = temp->split_cardset();
    current_player_->add_card_set(std::get<0>(split_sets));
    current_player_->add_card_set(std::get<1>(split_sets));
}

/**
 * @brief Game::stay player chooses to stay
 */
void Game::stay() {

}

/**
 * @brief Game::add_player add player to the players vector
 */
void Game::add_player() {
    Player* p = new Player(scene_, players_.size());
    p->set_name("Player " + QString::number(players_.size()));
    players_.push_back(p);
    current_player_=p;
}
/**
 * @brief Game::quit the player chooses to quit
 */
void Game::quit() {
// quit game?
    remove_player(current_player_);
}

/**
 * @brief Game::addMoney the player chooses to add money
 */
void Game::addMoney() {
    get_current_player_()->add_money(add_money_amnt);
}

/**
 * @brief Game::redo_turn redo the current turn (POWER UP)
 */
void Game::redo_turn() {
    //clear current player's card sets
    for (int i = 0; i < current_player_->get_card_sets().size(); i++) {
        for (int j = 0; j < current_player_->get_card_sets().at(i)->get_cards_pics_().size(); i++) {
            current_player_->get_card_sets().at(i)->remove_card(current_player_->get_card_sets().at(i)->get_cards_pics_().at(j)->get_card());
        }
    }
    ui->redopushButton->setEnabled(false);
}

/**
 * @brief Game::insure_turn insure the current turn
 */
void Game::insure_turn() {
    //insure turn by simply adding money back into their account
    for (int i = 0; i < current_player_->get_card_sets().size(); i++) {
        current_player_->add_money(current_player_->get_card_sets().at(i)->get_bet_amount_());
    }
    ui->insureTurnpushButton->setEnabled(false);
}

/**
 * @brief Game::exit the player chooses to exit
 */
void Game::exit() {
    close();
}
