#ifndef CONSTANTS_HPP
#define CONSTANTS_HPP

#include <string>
#include <ostream>

struct User
{
    std::string username;
    std::string password;

    bool isSameUser(const User& other) const
    {
        return username == other.username;
    }

    bool operator==(const User& other) const
    {
        return isSameUser(other) && password == other.password;
    }

    friend std::ostream& operator<<(std::ostream& os, const User& user)
    {
        return os << user.username << ", " << user.password;
    }
};

#endif
