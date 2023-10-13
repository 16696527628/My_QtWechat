#include <QApplication>
#include <QtSql>
#include "QSqlDatabase"
#include "Login/login.h"
#include "userWidget/PersonalPage.h"
#include "userWidget/main_widget.h"
#include "userWidget/SideBar.h"
#include "userWidget/Message/MessagePage.h"
#include "userWidget/Message/Buddy.h"
#include "userWidget/Message/TalkPage.h"
#include "user_info.h"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("localhost");
    db.setDatabaseName("MyChatDatabase");
    db.setUserName("root");
    db.setPassword("197382465");
    if (db.open()) {
        qDebug() << "Database connected.";
    } else {
        qDebug() << "Database connection failed.";
    }
    login l;
    l.show();
    return QApplication::exec();
}