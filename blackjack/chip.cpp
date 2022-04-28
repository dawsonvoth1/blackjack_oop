#include "chip.h"

using namespace std;

Chip::Chip(int value) : value_(value)
{
    string color;
    if(value_==10){
        color="white";
    }
    else if(value_==20){
        color="yellow";
    }
    else if(value_==50){
        color="red";
    }
    else if(value_==100){
        color="blue";
    }
    else if(value_==200){
        color="grey";
    }
    else if(value_==250){
        color="green";
    }
    else if(value_==500){
        color="biege";
    }
    else if(value_==1000){
        color="black";
    }
    else if(value_==2000){
        color="purple";
    }
    else if(value_==5000){
        color="pink";
    }
    else if(value_==10000){
        color="pink";
    }
    else{
        //?????????
    }

    string file=":/PNGs/chips/small/chip_"+color+"_top.png";
    QImage i(QString::fromStdString(file));
    QPixmap p=QPixmap::fromImage(i);
    this->setPixmap(p);
}
