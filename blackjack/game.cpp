#include "game.h"
#include "ui_board.h"

Game::Game(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Board)
{
    ui->setupUi(this);
}

Game::~Game()
{
    delete ui;
}

