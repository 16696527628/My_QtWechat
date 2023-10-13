//
// Created by 李明渊 on 2023/9/28.
//

#include <QFile>
#include "SideBar.h"
#include "main_widget.h"
SideBar::SideBar(QWidget *parent): QWidget(parent) {
    this->setFixedSize(60,600);
    this->setAttribute(Qt::WA_StyledBackground,true);//不知道为啥但是必须加,不然不显示样式
    init();
    sideBarStyle();
    connect(tbn_MessagePage,&QToolButton::clicked,[this]()
    {
        emit p1Page();
    });
    connect(tbn_ContactPage,&QToolButton::clicked,[this]()
    {
        emit p2Page();
    });
    connect(tbn_PersonalPage,&QToolButton::clicked,[this]()
    {
        emit p3Page();
    });
}

void SideBar::init() {
    this->setObjectName("sideBar");

    tbn_MessagePage = new QToolButton();
    tbn_ContactPage = new QToolButton();
    tbn_PersonalPage = new QToolButton();

    tbn_MessagePage->setCheckable(true);
    tbn_ContactPage->setCheckable(true);
    tbn_PersonalPage->setCheckable(true);

    tbn_MessagePage->setAutoExclusive(true);
    tbn_ContactPage->setAutoExclusive(true);
    tbn_PersonalPage->setAutoExclusive(true);


    tbn_MessagePage->setFixedSize(40,40);
    tbn_ContactPage->setFixedSize(40,40);
    tbn_PersonalPage->setFixedSize(40,40);

    qvBoxLayout = new QVBoxLayout();
    qvBoxLayout->addWidget(tbn_MessagePage);
    qvBoxLayout->addWidget(tbn_ContactPage);
    item = new QSpacerItem(70, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);//弹簧的用法
    qvBoxLayout->addItem(item);
    qvBoxLayout->addWidget(tbn_PersonalPage);
    this->setLayout(qvBoxLayout);
}

void SideBar::sideBarStyle() {

    tbn_MessagePage->setChecked(true);

    tbn_MessagePage->setObjectName("sideBarMessageButton");
    tbn_ContactPage->setObjectName("sideBarContactButton");
    tbn_PersonalPage->setObjectName("sidBarePersonalButton");

    qvBoxLayout->setSpacing(5);//控件间的间距

    QFile file("/Users/limingyuan/CLionProjects/untitled3/src/SidebarQss.qss");
    file.open(QFile::ReadOnly);
    QByteArray allData = file.readAll();
    this->setStyleSheet(QString(allData));
}

