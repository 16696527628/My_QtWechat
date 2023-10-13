//
// Created by 李明渊 on 2023/10/9.
//

#include <QFile>
#include "TalkPage.h"
#include "QPushButton"
TalkPage::TalkPage(QWidget *parent) :QWidget(parent){
    this->setAttribute(Qt::WA_StyledBackground,true);

    QFile file("/Users/limingyuan/CLionProjects/untitled3/src/SidebarQss.qss");
    file.open(QFile::ReadOnly);
    QByteArray allData = file.readAll();
    this->setStyleSheet(QString(allData));

    line = new my_Line(this);
    widget = new QWidget(this);
    putLine = new my_Line(this);

    line->setFixedSize(640,400);
    putLine->setFixedSize(640,200);
    putLine->move(0,430);
    putLine->setWordWrapMode(QTextOption::NoWrap);

    line->setEnabled(false);

    widget->setFixedSize(640,30);
    btn_call = new QPushButton(widget);
    btn_call->setObjectName("");
    btn_call->setIconSize(QSize(30,30));
    btn_call->setIcon(QIcon("/Users/limingyuan/CLionProjects/untitled3/src/blackImage/IMweb_Languagecall.png"));
    widget->move(0,400);
    connect(putLine,&my_Line::putLineSent,this,&TalkPage::RefreshLine);
}

void TalkPage::RefreshLine() {
    line->clear();
    UserInfo &userInfo = UserInfo::getInstance();
    nowUserId = userInfo.getUserId();
    clickUserId = userInfo.getClickUserId();
    QSqlQuery query;
    query.prepare("SELECT subquery.SenderUserId, subquery.Message\n"
                  "FROM (\n"
                  "    SELECT SenderUserId, Message, MessageId\n"
                  "    FROM chat_messages\n"
                  "    WHERE (SenderUserId = ? AND ReceiverUserId = ?) OR\n"
                  "          (SenderUserId = ? AND ReceiverUserId = ?)\n"
                  "    ORDER BY MessageId DESC\n"
//                  "    LIMIT 10\n"
                  ") AS subquery\n"
                  "ORDER BY subquery.MessageId ASC;");
    query.addBindValue(nowUserId);
    query.addBindValue(clickUserId);
    query.addBindValue(clickUserId);
    query.addBindValue(nowUserId);
    query.exec();
    while (query.next()) {
        line->appendPlainText(QString::number(query.value(0).toInt())+":"+query.value(1).toString());
    }
}