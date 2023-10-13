//
// Created by 李明渊 on 2023/10/10.
//

#include "my_Line.h"
my_Line::my_Line(QWidget *parent)
        : QPlainTextEdit(parent)
{
    // 构造函数可以进行其他初始化操作
}
void my_Line::keyPressEvent(QKeyEvent *event)
{
    UserInfo &userInfo = UserInfo::getInstance();
    nowUserId = userInfo.getUserId();
    clickUserId = userInfo.getClickUserId();
    // 在这里处理键盘事件
    if (event->key() == Qt::Key_Enter || event->key() == Qt::Key_Return)
    {
        // 当用户按下 Enter 键时执行你的操作
        QString message = toPlainText(); // 获取文本
        QSqlQuery query;
        query.prepare("insert into chat_messages (senderuserid, receiveruserid, message, timestamp)\n"
                      "values (?,?,?,now());");
        query.addBindValue(nowUserId);
        query.addBindValue(clickUserId);
        query.addBindValue(message);
        if(!query.exec()) {
            qDebug() << "信息发送失败！！！请选择和谁发送信息";
            this->clear();
            return;
        }
        this->clear();
        emit putLineSent();
        emit messageSidebarInit();
        event->accept();
    }
    else
    {
        // 允许其他键继续处理
        QPlainTextEdit::keyPressEvent(event);
    }
}