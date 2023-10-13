//
// Created by 李明渊 on 2023/9/22.
//

#ifndef UNTITLED3_LOGIN_H
#define UNTITLED3_LOGIN_H

#include "QWidget"
#include "QStackedWidget"
#include "loginPage_main.h"
#include "loginPage_scan.h"
class login : public ::QWidget{
public:
    explicit login(QWidget *parent = nullptr);
private:
    QStackedWidget *stackedWidget;
    loginPage_main *loginPage;
    loginPage_scan *loginPageScan;
    QPushButton *btn_scanLogin;
    QPushButton *btn_SingUp;
};


#endif //UNTITLED3_LOGIN_H
