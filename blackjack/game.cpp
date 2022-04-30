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

     //disable buttons before choosing players
     ui->hitpushButton->setEnabled(false);
     ui->doublepushButton->setEnabled(false);
     ui->staypushButton->setEnabled(false);
     ui->betpushButton->setEnabled(false);
     ui->redopushButton->setEnabled(false);
     ui->insureTurnpushButton->setEnabled(false);
     // add players + dealer
     ui->notificationlabel->setText("Add more players to the game or Deal");

    //start with one player
    add_player();
    set_current_player_(players_.at(0));

    //Add Dealer
    Player* dealer = new Dealer(scene_);
    players_.push_back(dealer);

     //set up game
     //set turn to be first player
     set_current_player_(players_.at(0));

     // execute game

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
    ui->addPlayerpushButton->setEnabled(false);
    //give two cards to each player
    for (int i = 0; i < players_.size(); i++) {
        std::vector<CardSet *> user_sets = players_.at(i)->get_card_sets();
        for (int j = 0; j < user_sets.size(); j++) {
            Card one = board_->deal_next_card();
            Card two = board_->deal_next_card();

            user_sets.at(j)->add_card(&one);
            user_sets.at(j)->add_card(&two);
        }
    }
    ui->dealpushButton->setEnabled(false);
}

/**
 * @brief Game::takeTurn player takes a turn
 */
void Game::takeTurn() {
    // make a player take a turn

}

/**
 * @brief Game::bet bets a certain amount
 */
void Game::bet() {
    int betamnt = ui->inputBetlineEdit->text().toInt();
    if (betamnt <= current_player_->get_money()) {
        for (int i = 0; i < current_player_->get_card_sets().size(); i++) {
            current_player_->get_card_sets().at(i)->set_bet_amount(betamnt);
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

    ui->doublepushButton->setEnabled(false);
}

/**
 * @brief Game::stay player chooses to stay
 */
void Game::stay() {
//do nothing?
}

/**
 * @brief Game::add_player add player to the players vector
 */
void Game::add_player() {
    Player* p = new Player(scene_);
    p->set_name("Player " + QString::number(players_.size() + 1));
    players_.push_back(p);
}
/**
 * @brief Game::quit the player chooses to quit
 */
void Game::quit() {
// quit game?
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

}

/**
 * @brief Game::insure_turn insure the current turn
 */
void Game::insure_turn() {

}

/**
 * @brief Game::exit the player chooses to exit
 */
void Game::exit() {
    close();
}
