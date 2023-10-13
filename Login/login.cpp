//
// Created by 李明渊 on 2023/9/22.
//

#include "login.h"
#include "QtSql"
login::login(QWidget *parent): QWidget(parent){
    this->setFixedSize(320,420);
    this->setStyleSheet("background-color: rgb(255, 255, 255);"
                        "color: rgb(0, 0, 0);");
    stackedWidget = new QStackedWidget(this);
    stackedWidget->setFixedSize(320,380);

    loginPage = new loginPage_main();
    loginPage->setFixedSize(320,380);
    loginPageScan = new loginPage_scan();
    loginPageScan->setFixedSize(320,380);

    stackedWidget->addWidget(loginPage);
    stackedWidget->addWidget(loginPageScan);


    //设置登录按钮下面的东西
    btn_scanLogin = new QPushButton("扫码登录",this);
    btn_scanLogin->setFixedSize(70,30);
    btn_scanLogin->setStyleSheet("background-color:rgba(255,255,255,0)");
    btn_scanLogin->move(3,370);

    btn_SingUp = new QPushButton("账号注册",this);
    btn_SingUp->setFixedSize(70,30);
    btn_SingUp->setStyleSheet("background-color:rgba(255,255,255,0)");
    btn_SingUp->move(this->size().width()-btn_SingUp->size().width(),370);
    connect(btn_scanLogin,&QPushButton::clicked,[=](){
        if(stackedWidget->currentIndex()==0) {
            stackedWidget->setCurrentIndex(1);
            btn_scanLogin->setText("密码登录");
            return ;
        }
        if(stackedWidget->currentIndex()==1) {
            stackedWidget->setCurrentIndex(0);
            btn_scanLogin->setText("扫码登录");
            return ;
        }
    });
    connect(loginPage,&loginPage_main::login_close,this,&QWidget::close);
}