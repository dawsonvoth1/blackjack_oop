#ifndef CHIP_H
#define CHIP_H

#include <QObject>
#include <QGraphicsItem>
#include <QGraphicsPixmapItem>
#include <QPixmap>
#include <QImage>
#include <QString>
#include <QDir>

class Chip : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Chip(int value);
    Chip* get_chip(){return chip_;};

private:
    int value_;
    Chip* chip_;
};

#endif // CHIP_H
