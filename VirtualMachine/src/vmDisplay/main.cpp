/*
    Reads from a text file and displays it on terminal
*/
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <filesystem>
#include <chrono>
#include <thread>

namespace fs = std::filesystem;

int main(){
    std::string str;
    std::vector<std::string> lines; 
    auto last_mod_time = fs::last_write_time("disp");
   while (true) {
        std::this_thread::sleep_for(std::chrono::seconds(1));

        auto current_mod_time = fs::last_write_time("disp");

        if (current_mod_time != last_mod_time) {
#ifdef _WIN32
            system("cls");
#endif
#ifdef __linux__
            system("clear");
#endif
            std::ifstream file("disp");
            while (std::getline(file, str)){
                std::cout << str << "\n";
            }
            last_mod_time = current_mod_time;  
        }
    }
}