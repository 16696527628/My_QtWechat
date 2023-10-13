//
// Created by 李明渊 on 2023/9/27.
//

#ifndef UNTITLED3_MESSAGEPAGE_H
#define UNTITLED3_MESSAGEPAGE_H
#include "QPushButton"
#include "QWidget"
#include "Buddy.h"
#include "TalkPage.h"
#include "../../user_info.h"
class MessagePage  :public ::QWidget{
    Q_OBJECT
public:
    explicit MessagePage(QWidget *parent = nullptr);
private:
    QListWidget *listWidget;
    Buddy *buddy;
    TalkPage *talkPage;
    my_Line *line;
    int nowUserId;
    void init();
};


#endif //UNTITLED3_MESSAGEPAGE_H
