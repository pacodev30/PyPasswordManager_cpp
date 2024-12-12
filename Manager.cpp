#include <iostream>
#include <fstream>
#include "Manager.h"
using namespace mpm;

<<<<<<< Updated upstream:Manager.cpp
Manager::Manager() {
    loadFromFile();
}
Manager::~Manager() {
=======
PasswordManager::PasswordManager()
{
    loadFromFile();
}
PasswordManager::~PasswordManager()
{
>>>>>>> Stashed changes:PasswordManager.cpp
    saveToFile();
}

// CREATE
<<<<<<< Updated upstream:Manager.cpp
void Manager::addEntry(const std::string& site, const std::string& username, const std::string& password)
{
    _entries.push_back(Entry(site, username, password));
=======
void PasswordManager::addEntry(const std::string& site, const std::string& username, const std::string& password)
{
    _entries.push_back(PasswordEntry(site, username, password));
>>>>>>> Stashed changes:PasswordManager.cpp
    std::cout << "\n-> Entry added successfully! :) \n";
    saveToFile();
}

// READ
<<<<<<< Updated upstream:Manager.cpp
void Manager::readEntries() const
{
    if (!_entries.empty()) {
=======
void PasswordManager::readEntries() const
{
    if (!_entries.empty())
    {
>>>>>>> Stashed changes:PasswordManager.cpp
        std::cout << "\nStored Password Entries: \n";
        for (const auto& entry : _entries)
        {
            entry.display();
            std::cout << "---------------------------\n";
        }
        return;
    }
    std::cout << "\n-> No entries found! :( \n";
}

// UPDATE
<<<<<<< Updated upstream:Manager.cpp
void Manager::updatePassword(const std::string& site, const std::string& newPassword)
{
    for (auto& entry : _entries) {
        if (entry.getSite() == site) {
=======
void PasswordManager::updatePassword(const std::string& site, const std::string& newPassword)
{
    for (auto& entry : _entries)
    {
        if (entry.getSite() == site)
        {
>>>>>>> Stashed changes:PasswordManager.cpp
            entry.setPassword(newPassword);
            std::cout << "\n->Password updated successfully! :) \n";
            saveToFile();
            return;
        }
    }
    std::cout << "\n-> No entry found for site: " << site << " :( \n";
}

// DELETE
<<<<<<< Updated upstream:Manager.cpp
void Manager::deleteEntry(const std::string& site) {
    auto it = std::remove_if(_entries.begin(), _entries.end(), [&site](const Entry& entry)
=======
void PasswordManager::deleteEntry(const std::string& site)
{
    auto it = std::remove_if(_entries.begin(), _entries.end(), [&site]
                             (const PasswordEntry& entry)
>>>>>>> Stashed changes:PasswordManager.cpp
                             {
                                 return entry.getSite() == site;
                             });

    if (it != _entries.end()) {
        _entries.erase(it, _entries.end());
        std::cout << "\n-> Entry removed successfully! :o \n";
        saveToFile();
    }
    else {
        std::cout << "\n-> No entry found for site : " << site << " :( \n";
    }
}

// LOAD
<<<<<<< Updated upstream:Manager.cpp
void Manager::loadFromFile() {
=======
void PasswordManager::loadFromFile()
{
>>>>>>> Stashed changes:PasswordManager.cpp
    std::ifstream file(filename);
    if (file.is_open()) {
        std::string line;
        while (std::getline(file, line)) {
            if (!line.empty()) {
                _entries.push_back(Entry::deserialize(line));
            }
        }
        file.close();
    }
}

// SAVE
<<<<<<< Updated upstream:Manager.cpp
void Manager::saveToFile() const
{
=======
void PasswordManager::saveToFile() const
{
    std::string line;
>>>>>>> Stashed changes:PasswordManager.cpp
    std::ofstream file(filename);
    if (file.is_open()) {
        for (const auto& e : _entries) {
            file << e.serialize();
        }
        file.close();
    }
}
