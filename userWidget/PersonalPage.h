//
// Created by 李明渊 on 2023/9/27.
//

#ifndef UNTITLED3_PERSONALPAGE_H
#define UNTITLED3_PERSONALPAGE_H

#include "QWidget"
#include "QPushButton"
#include "QLabel"
#include "QVBoxLayout"
#include "QLineEdit"
class PersonalPage :public ::QWidget{
Q_OBJECT
public:
    explicit PersonalPage(QWidget *parent = nullptr);
private:
    QVBoxLayout *qvBoxLayout;
    QPushButton *modPassWord;
    QPushButton *exitLogin;
    QLabel *icon;
    QLabel *name;
    QLineEdit *setname;
    QLabel *id;
    void init();
    int nowUserId;
};


#endif //UNTITLED3_PERSONALPAGE_H
