// user_info.h

#ifndef USER_INFO_H
#define USER_INFO_H

#include <QString>

class UserInfo
{
public:
    static UserInfo& getInstance();

    int getUserId() const { return userId; }
    int getClickUserId ()const { return clickUserId; }


    void setUserInfo(int id)
    {
        userId = id;
    }

    void setClickId(int id)
    {
        clickUserId = id;
    }



private:
    UserInfo() : userId(-1) {}
    UserInfo(const UserInfo&) = delete;
    UserInfo& operator=(const UserInfo&) = delete;

    int userId;
    int clickUserId;
};

#endif // USER_INFO_H
