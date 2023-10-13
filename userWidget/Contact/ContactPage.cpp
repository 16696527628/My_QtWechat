//
// Created by 李明渊 on 2023/9/27.
//

#include <QTreeWidget>
#include <QVBoxLayout>
#include "ContactPage.h"
#include "../Message/Buddy.h"
#include "QtSql"

ContactPage::ContactPage(QWidget *parent): QWidget(parent)  {

    UserInfo &userInfo = UserInfo::getInstance();
    nowUserId = userInfo.getUserId();

    this->setFixedSize(840,600);
    this->setAttribute(Qt::WA_StyledBackground,true);
    this->setObjectName("ConTactPageStyle");
    treeWidget = new QTreeWidget(this);
    treeWidget->setFixedSize(200,this->size().height());
    treeWidget->setColumnCount(1); // 设置一列用于显示分组名称
    treeWidget->setHeaderHidden(true);
    widget = new QWidget(this);
    initSql();
    connect(treeWidget,&QTreeWidget::itemClicked,[&]() {
        if (!treeWidget->currentItem()->data(0, Qt::UserRole + 1).toString().isEmpty()) {
        qDebug() << treeWidget->currentItem()->data(0, Qt::UserRole).toString();
        qDebug() << treeWidget->currentItem()->data(0, Qt::UserRole + 1).toString();
        qDebug() << treeWidget->currentItem()->data(0, Qt::UserRole + 2).toString();
        initPage(treeWidget->currentItem()->data(0, Qt::UserRole).toString(),
                 treeWidget->currentItem()->data(0, Qt::UserRole + 1).toString(),
                 treeWidget->currentItem()->data(0, Qt::UserRole + 2).toString());
        }
    });
}

void ContactPage::initSql() {
    // 添加分组
    QSqlQuery query;
    QSqlQuery query1;
    query.prepare("select GroupID,GroupName from user_groups;");
    QString groupName;
    if (query.exec()) {
        while (query.next()) {
            groupName = query.value(1).toString();
            QTreeWidgetItem *group1 = new QTreeWidgetItem(treeWidget);
            group1->setText(0, groupName);
            group1->setExpanded(true); // 默认展开

            query1.prepare("select * from user where GroupID = ? and userId != ?");
            query1.addBindValue(query.value(0).toInt()); // 查询特定用户
            query1.addBindValue(nowUserId);
            if (query1.exec()) {
                while (query1.next()) {
                    QString icon_1 = query1.value(2).toString();
                    QString name_1 = query1.value(3).toString();
                    QString id_1 = query1.value(0).toString();
                    int i = 0;
                    // 创建自定义的用户项
                    Buddy *buddy = new Buddy(i,icon_1, name_1, id_1);
                    buddy->setFixedHeight(50);
                    // 创建用户项，并将自定义用户项添加到分组下
                    QTreeWidgetItem *friend1 = new QTreeWidgetItem(group1);
                    friend1->setData(0,Qt::UserRole,icon_1);
                    friend1->setData(0,Qt::UserRole+1,id_1);
                    friend1->setData(0,Qt::UserRole+2,name_1);
                    treeWidget->setItemWidget(friend1, 0, buddy);
                }
            }
        }
    } else {
        qDebug() << "User data retrieval failed.";
    }
}

void ContactPage::initPage(QString icon_1,QString id_1,QString name_1) {
    widget->close();
    widget = new QWidget(this);
    widget->move(200,0);
    widget->setFixedSize(this->size().width()-200,this->size().height());
    icon = new QLabel(widget);
    QPixmap qPixmap(icon_1);
    icon->setPixmap(qPixmap.scaled(250, 250, Qt::KeepAspectRatio));//设置大小和显示方式
    name = new QLabel(name_1,widget);
    id = new QLabel(id_1,widget);
    icon->setFixedSize(300,300);
    name->move(0,350);
    id->move(0,400);
    widget->show();
}
