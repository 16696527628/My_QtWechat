//
// Created by 李明渊 on 2023/9/25.
//

#include <QFile>
#include "main_widget.h"
main_widget::main_widget(QWidget *parent): QWidget(parent){
    this->setFixedSize(900,600);
    this->setObjectName("main_Page");
    init();
    my_setStyle();
    connect(sideBar, &SideBar::p1Page, [&]()
    {
        stackedWidget->setCurrentIndex(0);
        emit p1Init();
    });
    connect(sideBar, &SideBar::p2Page, [&]()
    {
        stackedWidget->setCurrentIndex(1);
        emit p2Init();
    });
    connect(sideBar, &SideBar::p3Page, [&]()
    {
        stackedWidget->setCurrentIndex(2);
        emit p3Init();
    });
}

void main_widget::init() {
    //侧边栏
    sideBar = new SideBar(this);
    //右边
    stackedWidget = new QStackedWidget(this);
    //右边的页面
    messagePage  = new MessagePage();
    contactPage = new ContactPage();
    personalPage = new PersonalPage();
    stackedWidget->addWidget(messagePage);
    stackedWidget->addWidget(contactPage);
    stackedWidget->addWidget(personalPage);
    //水平布局
    mainHLayout = new QHBoxLayout(this);

    mainHLayout->addWidget(sideBar);
    mainHLayout->addWidget(stackedWidget);
}

void main_widget::my_setStyle() {
    mainHLayout->setContentsMargins(0,0,0,0);
    mainHLayout->setSpacing(0);
}
