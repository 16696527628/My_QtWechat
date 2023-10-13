//
// Created by 李明渊 on 2023/9/22.
//
#include "QStyledItemDelegate"
#include "loginPage_main.h"
#include "../user_info.h"
loginPage_main::loginPage_main(QWidget *parent): QWidget(parent){

    this->setFixedSize(320,420);
    this->setStyleSheet("background-color: rgb(255, 255, 255);");
    //设置gif动画
    m_icon = new QLabel(this);
    m_icon->resize(100,100);
    m_icon->move(100,10);
    QMovie *movie = new QMovie("/Users/limingyuan/CLionProjects/untitled3/src/loginIcon.gif");
    movie->setScaledSize(QSize(100,100));
    m_icon->setMovie(movie);
    movie->start();


    //设置账号密码框
    userNameEdit = new QLineEdit(this);
    passWordEdit = new QLineEdit(this);
    userNameEdit->move(30,140);
    passWordEdit->move(30,195);
    userNameEdit->resize(260,45);
    passWordEdit->resize(260,45);
    QFont lineFont;
    lineFont.setPointSize(16);
    userNameEdit->setFont(lineFont);
    passWordEdit->setFont(lineFont);
    userNameEdit->setStyleSheet("border-style:solid;\n"
                                "border-width:2px;\n"
                                "background-color:rgba(255,255,255,0);\n"
                                "border-top-color: rgba(255, 255, 255, 0);\n"
                                "border-right-color: rgba(255, 255, 255, 0);\n"
                                "border-left-color: rgba(255, 255, 255, 0);\n"
                                "border-bottom-color: rgb(129, 129, 129);");
    passWordEdit->setStyleSheet("border-style:solid;\n"
                                "border-width:2px;\n"
                                "background-color:rgba(255,255,255,0);\n"
                                "border-top-color: rgba(255, 255, 255, 0);\n"
                                "border-right-color: rgba(255, 255, 255, 0);\n"
                                "border-left-color: rgba(255, 255, 255, 0);\n"
                                "border-bottom-color: rgb(129, 129, 129);");

    userNameEdit->setPlaceholderText("请输入账号");//背景文字
    passWordEdit->setPlaceholderText("请输入密码");//背景文字
    passWordEdit->setEchoMode(QLineEdit::Password);//在输入每个字符期间都进行隐藏
//    passWordEdit->setEchoMode(QLineEdit::PasswordEchoOnEdit);//输入时显示字符，失去焦点时隐藏


//    comboBox->setFixedSize(260,100);
    //设置复选框和同意协议
    checkBox = new QCheckBox(this);
    checkBox->setStyleSheet("background-color:rgba(255,255,255,0);");
    checkBox->move(35,255);
    QLabel *lb = new QLabel(this);
    lb->setMinimumWidth(230);
    lb->setWordWrap(true);
    lb->setOpenExternalLinks(true);
    lb->setText(u8"已阅读并同意<style> a {text-decoration: none} </style><a href = https://rule.tencent.com/rule/46a15f24-e42c-4cb6-a308-2347139b1201>服务协议</a>和<a href = https://rule.tencent.com/rule/3fd52bde-6555-453b-9ab8-c5f1f3d22c62>隐私保护指引</a>");
    lb->setStyleSheet("background-color:rgba(255,255,255,0);");
    lb->move(60,256);

    //设置登录按钮
    //67 151 247
    btn_login = new QPushButton("登录",this);
    btn_login->resize(260,45);
    btn_login->move(30,305);
    btn_login->setStyleSheet("background-color:rgb(67,151,247);");

    //登录
    connect(btn_login,&QPushButton::clicked,[=](){
        if(checkBox->isChecked()){
            int userId = userNameEdit->text().toInt();
            QString passWord = passWordEdit->text();
            if(isUserValid(userId,passWord))
            {
                isOnline(userId);
                this->close();
                emit login_close();
                mainWidget = new main_widget();
                mainWidget->show();
            }
        }else{
            QMessageBox::information(nullptr,"请阅读并同意协议","请阅读并同意协议");
        }
    });
//    测试
    userNameEdit->setText("123456");
    passWordEdit->setText("hashed_password1");
    checkBox->setChecked(true);
}

bool loginPage_main::isUserValid(int UserId, QString password) {
    QSqlQuery query;
    query.prepare("SELECT passWord FROM user WHERE userID = :UserId");
    query.bindValue(":UserId", UserId);

    if (query.exec()) {
        if (query.next()) {
            QString storedPassword = query.value(0).toString();
            // 比较提供的密码和存储的密码是否匹配
            if(storedPassword == password) {
                // 登录成功后调用
                UserInfo& userInfo = UserInfo::getInstance();
                userInfo.setUserInfo(UserId);
                return storedPassword == password;
            }
            qDebug()<<"密码错误";
        }
        qDebug()<<"用户不存在";
    } else {
        qDebug() << "Query failed:" << query.lastError().text();
    }
    return false; // 查询失败或没有匹配的记录
}

bool loginPage_main::isOnline(int UserId) {
    QSqlQuery query;
    query.prepare("UPDATE user set isOnline = true where userID = :UserId;");
    query.bindValue(":UserId", UserId);

    if (!query.exec()) {
        qDebug() << "Query failed:" << query.lastError().text();
    }
    return false;
}


