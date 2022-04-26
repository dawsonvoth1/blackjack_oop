#include "game.h"
#include "ui_game.h"//.h"
#include "player.h"
#include "vector"

Game::Game(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Game)
{
    ui->setupUi(this);
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
