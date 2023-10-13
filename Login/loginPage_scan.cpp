//
// Created by 李明渊 on 2023/9/22.
//

#include "loginPage_scan.h"
loginPage_scan::loginPage_scan(QWidget *parent):QWidget(parent){
    this->setStyleSheet("background-color: rgb(255, 255, 255);");
    scanLab = new QLabel(this);
    scanLab->move(-15,-10);
    scanLab->setFixedSize(350,350);
    QImage image("/Users/limingyuan/CLionProjects/untitled3/src/loginScan.png");
    image.scaled(scanLab->size(), Qt::KeepAspectRatio);
    scanLab->setScaledContents(true);
    scanLab->setPixmap(QPixmap::fromImage(image));
}