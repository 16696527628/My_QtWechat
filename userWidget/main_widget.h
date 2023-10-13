//
// Created by 李明渊 on 2023/9/25.
//

#ifndef UNTITLED3_MAIN_WIDGET_H
#define UNTITLED3_MAIN_WIDGET_H

#include <QWidget>
#include <QStackedWidget>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QSpacerItem>
#include <QButtonGroup>
#include "SideBar.h"
#include "Message/MessagePage.h"
#include "Contact/ContactPage.h"
#include "PersonalPage.h"
class main_widget :public ::QWidget{
    Q_OBJECT
public:
    explicit main_widget(QWidget *parent = nullptr);
private:
    void init();
    void my_setStyle();
    SideBar *sideBar;
    MessagePage *messagePage;
    ContactPage *contactPage;
    PersonalPage *personalPage;
    QHBoxLayout *mainHLayout;
    QStackedWidget *stackedWidget;
public: signals:
    void p1Init();
    void p2Init();
    void p3Init();
};


#endif //UNTITLED3_MAIN_WIDGET_H
