#include "Entry.h"
#include <iostream>
#include "FileUtils.h"
using namespace mpm;

Entry::Entry(const std::string& site, const std::string& username, const std::string& password)
    : _site(site), _username(username), _password(password) {
}

<<<<<<< Updated upstream:Entry.cpp
std::string Entry::getSite() const {
    return _site;
}
std::string Entry::getUsername() const {
    return _username;
}
std::string Entry::getPassword() const {
    return _password;
}

void Entry::display() const {
=======
std::string PasswordEntry::getSite() const
{
    return _site;
}
std::string PasswordEntry::getUsername() const
{
    return _username;
}
std::string PasswordEntry::getPassword() const
{
    return _password;
}

void PasswordEntry::display() const
{
>>>>>>> Stashed changes:PasswordEntry.cpp
    std::cout   << "Site: " << _site << "\n"
                    << "Username: " << _username << "\n"
                    << "Password: " << _password << "\n";
}

<<<<<<< Updated upstream:Entry.cpp
void Entry::setPassword(const std::string& newPassword) {
    _password = newPassword;
}

std::string Entry::serialize() const {
    return _site + "," + _username + "," + _password + "\n";
}

Entry Entry::deserialize(const std::string& line) {
=======
void PasswordEntry::setPassword(const std::string& newPassword)
{
    _password = newPassword;
}

std::string PasswordEntry::serialize() const
{
    return  _site + "," + _username + "," + _password + "\n";
}

PasswordEntry PasswordEntry::deserialize( std::string& line)
{
>>>>>>> Stashed changes:PasswordEntry.cpp
    size_t step1 = line.find(',');
    size_t step2 = line.find(',', step1 + 1);

    std::string site = line.substr(0, step1);
    std::string username = line.substr(step1 + 1, step2 - step1 - 1);
    std::string password = line.substr(step2 + 1);

    return Entry(site, username, password);
}
