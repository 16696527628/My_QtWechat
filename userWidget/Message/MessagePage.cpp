//
// Created by 李明渊 on 2023/9/27.
#include <QFile>
#include "MessagePage.h"
#include "QtSql"
MessagePage::MessagePage(QWidget *parent) : QWidget(parent) {
    UserInfo &userInfo = UserInfo::getInstance();
    nowUserId = userInfo.getUserId();
    QFile file("/Users/limingyuan/CLionProjects/untitled3/src/SidebarQss.qss");
    file.open(QFile::ReadOnly);
    QByteArray allData = file.readAll();
    this->setStyleSheet(QString(allData));

    this->setAttribute(Qt::WA_StyledBackground, true);//不知道为啥但是必须加,不然不显示样式
    this->setObjectName("messagePageStyle");
    this->setFixedSize(840, 600);

    listWidget = new QListWidget(this);
    listWidget->setFixedSize(200, this->size().height());

    talkPage = new TalkPage(this);
    talkPage->move(200,0);
    line = new my_Line;
    init();
    connect(listWidget,&QListWidget::clicked,[&](){
        int clickId =  listWidget->currentItem()->data(Qt::UserRole).toInt();
        UserInfo& userInfo = UserInfo::getInstance();
        userInfo.setClickId(clickId);
        talkPage->RefreshLine();
    });
}

void MessagePage::init() {
    QSqlQuery query;
    query.prepare("SELECT\n"
                  "    u.userId,\n"
                  "    u.nickName,\n"
                  "    u.Icon AS Avatar,\n"
                  "    cm.Message AS LastMessage\n"
                  "FROM user u\n"
                  "INNER JOIN (\n"
                  "    SELECT\n"
                  "        CASE\n"
                  "            WHEN SenderUserId = ? THEN ReceiverUserId\n"
                  "            ELSE SenderUserId\n"
                  "        END AS CorrespondentUserID,\n"
                  "        MAX(Timestamp) AS LastMessageTime\n"
                  "    FROM chat_messages\n"
                  "    WHERE SenderUserId = ? OR ReceiverUserId = ?\n"
                  "    GROUP BY CorrespondentUserID\n"
                  ") AS latest_messages\n"
                  "ON u.userId = latest_messages.CorrespondentUserID\n"
                  "LEFT JOIN chat_messages cm\n"
                  "ON (\n"
                  "    (cm.SenderUserId = ? AND cm.ReceiverUserId = u.userId)\n"
                  "    OR\n"
                  "    (cm.SenderUserId = u.userId AND cm.ReceiverUserId = ?)\n"
                  ")\n"
                  "AND cm.Timestamp = latest_messages.LastMessageTime;");
    for (int i = 0; i < 5; ++i) {
        query.addBindValue(nowUserId);
    }
    if (query.exec())
    {
        while (query.next())
        {
            int user_1 = query.value(0).toInt();
            QString icon_1 = query.value(2).toString();
            QString name_1 = query.value(1).toString();
            QString message_1 = query.value(3).toString();
            buddy = new Buddy(user_1,icon_1, name_1, message_1);
            QListWidgetItem *newItem = new QListWidgetItem(listWidget);
            newItem->setData(Qt::UserRole,user_1);
            newItem->setSizeHint(QSize(100, 50));
            listWidget->addItem(newItem); // 使用addItem方法添加新的项
            listWidget->setItemWidget(newItem, buddy);
        }
    }
    else
    {
        qDebug() << "Query failed:" << query.lastError().text();
    }
}


