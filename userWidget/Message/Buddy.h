//
// Created by 李明渊 on 2023/10/8.
//

#ifndef UNTITLED3_BUDDY_H
#define UNTITLED3_BUDDY_H

#include "QWidget"
#include "QListWidget"
#include "QLabel"
class Buddy :public QWidget{
    Q_OBJECT
public:
    int getUserId();
    explicit Buddy(int user_1,QString icon_1 = "",QString name_1 = "",QString message_1 = "",QWidget *parent = nullptr);
private:
    QLabel *icon;
    QLabel *name;
    QLabel *message;
    int id;
};


#endif //UNTITLED3_BUDDY_H
