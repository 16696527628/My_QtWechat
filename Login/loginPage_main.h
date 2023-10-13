//
// Created by 李明渊 on 2023/9/22.
//

#ifndef UNTITLED3_LOGINPAGE_MAIN_H
#define UNTITLED3_LOGINPAGE_MAIN_H
#include "QWidget"
#include "QLabel"
#include "QLineEdit"
#include "QPushButton"
#include "QCheckBox"
#include "QMovie"
#include "QMessageBox"
#include "QStackedWidget"
#include "../userWidget/main_widget.h"
#include "QtSql"
class loginPage_main : public ::QWidget{
    Q_OBJECT
public:
    explicit loginPage_main(QWidget *parent = nullptr);
private:
    QLabel *m_icon;
    QCheckBox *checkBox;
    QLineEdit *userNameEdit;
    QLineEdit *passWordEdit;
    QPushButton *btn_login;
    main_widget *mainWidget;
    bool isUserValid(int UserId, QString password);
    bool isOnline(int UserId);
signals:
    void login_close();
};


#endif //UNTITLED3_LOGINPAGE_MAIN_H
