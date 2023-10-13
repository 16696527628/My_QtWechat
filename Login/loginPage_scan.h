//
// Created by 李明渊 on 2023/9/22.
//

#ifndef UNTITLED3_LOGINPAGE_SCAN_H
#define UNTITLED3_LOGINPAGE_SCAN_H

#include "QWidget"
#include "QLabel"
class loginPage_scan :public ::QWidget{
    Q_OBJECT
public:
    explicit loginPage_scan(QWidget *parent = nullptr);
private:
    QLabel *scanLab;
};


#endif //UNTITLED3_LOGINPAGE_SCAN_H
