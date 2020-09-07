#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <thread>
#include <mutex>
#include <algorithm>

void format(std::string& word){
    std::transform(word.begin(), word.end(), word.begin(), ::tolower );
    auto newEnd = std::remove_if(word.begin(), word.end(), [](char sym) {
        return !(isalpha(sym));
    });
    word.erase(newEnd, word.end());
}

int main()
    {
    std::vector<std::string> buff;
    std::string line;
    std::ifstream myfile("hello.txt");

        if (myfile.is_open())
        {
            while (std::getline(myfile, line))
            {
                buff.push_back(line);
            }
        } else {
            std::cout << "some error" << std::endl;
        }

        std::thread threads[buff.size()];

        for (int i = 0; i < buff.size(); ++i)
             threads[i] = std::thread{format,std::ref(buff[i])};


        for (int i = 0; i < buff.size(); ++i) {
            threads[i].join();
            std::cout << buff[i] << std::endl;
        }

        myfile.close();
        return 0;
    }

