/*
    Reads from a text file and displays it on terminal
*/
#include <iostream>
#include <vector>
#include <string>
#include <fstream>


int main(){
    
    std::string str; 
    while(1){
        std::ifstream file("disp");
        while (std::getline(file, str)){
            std::cout << str << "\n";
        }
        getchar();
        system("clear");
        system("cls");
    }
}