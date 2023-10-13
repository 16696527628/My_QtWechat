// user_info.cpp

#include "user_info.h"

UserInfo& UserInfo::getInstance()
{
    static UserInfo instance;
    return instance;
}
