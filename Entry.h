#pragma once
#include <string>

namespace mpm
{
class Entry {
public:
    Entry(const std::string& site, const std::string& username, const std::string& password);

    std::string getSite() const;
    std::string getUsername() const;
    std::string getPassword() const;

    void display() const;
    void setPassword(const std::string& newPassword);

    std::string serialize() const;
    static Entry deserialize(const std::string& line);

private:
    std::string _site;
    std::string _username;
    std::string _password;
};
}
