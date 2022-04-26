#ifndef BOARD_H
#define BOARD_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class Board; }
QT_END_NAMESPACE

class Board : public QMainWindow
{
    Q_OBJECT

public:
    Board(QWidget *parent = nullptr);
    ~Board();

private:
    Ui::Board *ui;
};
#endif // BOARD_H
