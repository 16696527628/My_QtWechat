//
// Created by 李明渊 on 2023/10/10.
//

#ifndef UNTITLED3_MY_LINE_H
#define UNTITLED3_MY_LINE_H

#include "QPlainTextEdit"
#include "QtSql"
#include "../../user_info.h"
class my_Line : public ::QPlainTextEdit{
Q_OBJECT
public:
    my_Line(QWidget *parent = nullptr);
protected:
    void keyPressEvent(QKeyEvent *event) override;
private:
    int nowUserId;
    int clickUserId;
signals:
    void putLineSent();
    void messageSidebarInit();
};


#endif //UNTITLED3_MY_LINE_H
