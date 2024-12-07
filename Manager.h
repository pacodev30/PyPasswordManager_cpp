#pragma once
#include <string>
#include <vector>
#include "Entry.h"

namespace mpm
{
class Manager
{
public:
    Manager();
    ~Manager();

    void addEntry(const std::string& site, const std::string& username, const std::string& password);
    void readEntries() const;
    void updatePassword(const std::string& site, const std::string& newPassword);
    void deleteEntry(const std::string& site);

private:
    std::vector<Entry> _entries;
    const std::string filename = "passwords.txt";

    void loadFromFile();
    void saveToFile() const;
};
}
