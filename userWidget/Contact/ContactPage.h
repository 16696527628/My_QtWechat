//
// Created by 李明渊 on 2023/9/27.
//

#ifndef UNTITLED3_CONTACTPAGE_H
#define UNTITLED3_CONTACTPAGE_H

#include "QWidget"
#include "QListWidget"
#include "QTreeWidget"
#include "../Message/Buddy.h"
#include "../../user_info.h"
class ContactPage :public ::QWidget{
    Q_OBJECT
public:
    explicit ContactPage(QWidget *parent = nullptr);
private:
    int nowUserId;
    QTreeWidget *treeWidget;
    QWidget *widget;
    QLabel *icon;
    QLabel *name;
    QLabel *id;
    void initSql();
    void initPage(QString icon_1,QString id_1,QString name_1);
};


#endif //UNTITLED3_CONTACTPAGE_H
