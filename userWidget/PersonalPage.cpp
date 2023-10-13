//
// Created by 李明渊 on 2023/9/27.
//

#include "PersonalPage.h"
#include "SideBar.h"
#include "QApplication"
#include "QtSql"
#include "../user_info.h"

PersonalPage::PersonalPage(QWidget *parent) {
    UserInfo &userInfo = UserInfo::getInstance();
    nowUserId = userInfo.getUserId();
    init();
    connect(exitLogin, &QPushButton::clicked, [&]() {
        QSqlQuery query;
        query.prepare("UPDATE user set isOnline = false where userId = ?");
        query.addBindValue(nowUserId);
        query.exec();
        return QApplication::closeAllWindows();
    });
}

void PersonalPage::init() {
    QSqlQuery query;

    icon = new QLabel(this);
    setname = new QLineEdit(this);
    name = new QLabel(this);
    id = new QLabel(this);
    modPassWord = new QPushButton(this);
    exitLogin = new QPushButton(this);
    icon->move(0, 0);
    name->move(300, 50);
    setname->move(350, 50);
    id->move(300, 100);
    modPassWord->move(350, 350);
    exitLogin->move(350, 380);

    // 查询用户数据
    query.prepare("SELECT * FROM user WHERE userId = ?");
    query.addBindValue(nowUserId); // 查询特定用户

    int userId;
    QString password;
    QString qicon;
    QString nickname;

    query.exec();
    while (query.next()) {
        userId = query.value(0).toInt();
        qicon = query.value(2).toString();
        nickname = query.value(3).toString();
    }

    QPixmap qPixmap(qicon);
    icon->setPixmap(qPixmap.scaled(250, 250, Qt::KeepAspectRatio));//设置大小和显示方式
    name->setText("name:");
    setname->setText(nickname);
    setname->setAlignment(Qt::AlignLeft);
    id->setText("Id:");
    id->setText(id->text() + QString::number(userId));
    id->setAlignment(Qt::AlignCenter);
    modPassWord->setText("修改密码");
    exitLogin->setText("退出登录");
}
