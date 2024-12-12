#pragma once
#include <iostream>
#include <string>
#include <fstream>

namespace utils
{
class FileUtils
{
public:
    static std::string readFromFile(const std::string& fileName)
    {
        std::ifstream file(fileName);
        if(file) {
            std::string line;
            std::string data;
            while(std::getline(file, line))
            {
                if(!line.empty()) {
                    data += line + "\n";
                    std::cout << "-> " << fileName << " is read succesfully" << std::endl;
                    return data;
                }
            }
            file.close();
        }
        std::cerr << "-> Error : " << fileName << " can't be opened or empty !" << std::endl;
        return "";
    }

    static void writeToFile(const std::string& fileName, const std::string& content)
    {
        std::ofstream file(fileName, std::ios::app);
        if (file) {
            file << content << std::endl;
            file.close();
            std::cout << "-> " << fileName << " is writen succesfully" << std::endl;
            return;
        }
        std::cerr << "-> Error : File can't be opened " << fileName << " to write" << std::endl;
    }

    static void clearFile(const std::string& fileName)
    {
        std::ofstream file(fileName, std::ios::trunc);
        if(file) {
            file.close();
            std::cout << "-> " << fileName << " is clear succesfully" << std::endl;
            return;
        }
        std::cerr << "-> Error : File can't be opened " << fileName << " to clear" << std::endl;
    }

    static void caesarEncrypt(std::string& message, int key = 3, int alphabetSize = 26)
    {
        key %= alphabetSize;

        if(key < 0)
            key += alphabetSize;

        for(char& character : message)
        {
            if(std::isalpha(character))
            {
                char base = (character >= 'a') ? 'a' : 'A';
                character = (character - base + key) % alphabetSize + base;
            }
        }
    }

    static void caesarDecrypt(std::string& message, int key = 3, int alphabetSize = 26)
    {
        return caesarEncrypt(message, alphabetSize - key);
    }

};
}
