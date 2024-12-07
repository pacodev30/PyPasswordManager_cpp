#include <iostream>
#include <fstream>
#include "Manager.h"
using namespace mpm;

Manager::Manager() {
    loadFromFile();
}
Manager::~Manager() {
    saveToFile();
}

// CREATE
void Manager::addEntry(const std::string& site, const std::string& username, const std::string& password) {
    _entries.push_back(Entry(site, username, password));
    std::cout << "\n-> Entry added successfully! :) \n";
    saveToFile();
}

// READ
void Manager::readEntries() const {
    if (!_entries.empty()) {
        std::cout << "\nStored Password Entries: \n";
        for (const auto& entry : _entries) {
            entry.display();
            std::cout << "---------------------------\n";
        }
        return;
    }
    std::cout << "\n-> No entries found! :( \n";
}

// UPDATE
void Manager::updatePassword(const std::string& site, const std::string& newPassword) {
    for (auto& entry : _entries) {
        if (entry.getSite() == site) {
            entry.setPassword(newPassword);
            std::cout << "\n->Password updated successfully! :) \n";
            saveToFile();
            return;
        }
    }
    std::cout << "\n-> No entry found for site: " << site << " :( \n";
}

// DELETE
void Manager::deleteEntry(const std::string& site) {
    auto it = std::remove_if(_entries.begin(), _entries.end(), [&site](const Entry& entry)
                             {
                                 return entry.getSite() == site;
                             });

    if (it != _entries.end()) {
        _entries.erase(it, _entries.end());
        std::cout << "\n-> Entry removed successfully! :o \n";
        saveToFile();
    }
    else {
        std::cout << "\n-> No entry found for site: " << site << " :( \n";
    }
}

// LOAD
void Manager::loadFromFile() {
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
void Manager::saveToFile() const {
    std::ofstream file(filename);
    if (file.is_open()) {
        for (const auto& entry : _entries) {
            file << entry.serialize();
        }
        file.close();
    }
}
