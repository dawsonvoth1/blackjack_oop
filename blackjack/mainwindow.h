#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

// Board Structs + Enums
// A chip to be putting onto the board
struct Chip {
    QColor color_;
    int value_;
};

// Represents the Suit a card can be
enum class Suit {Heart, Diamond, Spade, Club};

// The Card object
struct Card {
    int value_;
    Suit suit_;
    int deck_;
    bool dealt_;
};


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
