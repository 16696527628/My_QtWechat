//
// Created by 李明渊 on 2023/10/8.
//

#include "Buddy.h"
#include "QLabel"
#include "QPushButton"
Buddy::Buddy(int user_1,QString icon_1,QString name_1,QString message_1,QWidget *parent) :QWidget (parent){
    this->setObjectName("buddy");
    icon = new QLabel(this);
    QPixmap qPixmap(icon_1);
    icon->setPixmap(qPixmap.scaled(40, 40, Qt::KeepAspectRatio));
    name = new QLabel(name_1,this);
    name->move(50,0);
    QLabel *mess = new QLabel(message_1,this);
    mess->move(50,20);
}

int Buddy::getUserId() {
    return id;
}
