//
// Created by 李明渊 on 2023/10/9.
//

#ifndef UNTITLED3_TALKPAGE_H
#define UNTITLED3_TALKPAGE_H

#include <QPushButton>
#include "QWidget"
#include <QKeyEvent>
#include <QPlainTextEdit>
#include "my_Line.h"
class TalkPage :public ::QWidget{
Q_OBJECT
public:
    explicit TalkPage(QWidget *parent = nullptr);
private:
    QWidget *widget;
    my_Line *line;
    my_Line *putLine;
    QPushButton *btn_call;
    QPushButton *btn_video;
    QPushButton *btn_file;
    QPushButton *btn_expression;
    int nowUserId;
    int clickUserId;
public slots:
    void RefreshLine();
};


#endif //UNTITLED3_TALKPAGE_H
