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
