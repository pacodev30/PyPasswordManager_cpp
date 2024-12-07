#include <iostream>
#include "Manager.h"

int main()
{
    mpm::Manager manager;
    int choice;

    do {
        std::cout << "\nPassword Manager Menu:\n";
        std::cout << "1. Add Entry\n";
        std::cout << "2. Remove Entry\n";
        std::cout << "3. Update Password\n";
        std::cout << "4. List Entries\n";
        std::cout << "5. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
        case 1: {
            std::string site, username, password;
            std::cout << "Enter site : ";
            std::cin >> site;
            std::cout << "Enter username : ";
            std::cin >> username;
            std::cout << "Enter password : ";
            std::cin >> password;
            manager.addEntry(site, username, password);
            break;
        }
        case 2: {
            std::string site;
            std::cout << "Enter site to remove : ";
            std::cin >> site;
            manager.deleteEntry(site);
            break;
        }
        case 3: {
            std::string site, newPassword;
            std::cout << "Enter site to update password: ";
            std::cin >> site;
            std::cout << "Enter new password : ";
            std::cin >> newPassword;
            manager.updatePassword(site, newPassword);
            break;
        }
        case 4:
            manager.readEntries();
            break;
        case 5:
            std::cout << "Exiting Password Manager. Goodbye! ;) \n";
            break;
        default:
            std::cout << "Invalid choice. Please try again. :( \n";
        }

    } while (choice != 5);

    return 0;

}
