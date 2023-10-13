//
// Created by 李明渊 on 2023/9/28.
//

#ifndef UNTITLED3_SIDEBAR_H
#define UNTITLED3_SIDEBAR_H

#include <QWidget>
#include <QToolButton>
#include <QVBoxLayout>
#include <QSpacerItem>
class SideBar :public ::QWidget{
Q_OBJECT
public:
    explicit SideBar(QWidget *parent = nullptr);
private:
    QToolButton *tbn_MessagePage;
    QToolButton *tbn_ContactPage;
    QToolButton *tbn_PersonalPage;
    QVBoxLayout *qvBoxLayout;
    QSpacerItem *item;
    void init();
    void sideBarStyle();
public: signals:
    void p1Page();
    void p2Page();
    void p3Page();
};


#endif //UNTITLED3_SIDEBAR_H
