#include <VGA.hpp>

Hardware::VGA::VGA(){

}

Hardware::VGA::VGA(Hardware::Memory* mem, int add){
    this->mem = mem;
    this->address = add;
    displayFile = std::ofstream("disp");
}

void Hardware::VGA::tick(){
    displayFile = std::ofstream("disp", std::ios::trunc);
    displayFile = std::ofstream("disp");
    // We gon write to a file
    for(int y = 0; y < 20; y++){
        std::string line;
        for(int x = 0; x < 80; x++){
            char c = (char)(*this->mem)[2 * x + 160 * y];
            if(!c) c = ' ';
            line.append(std::string{c});
        }
        line.append("\n");
        displayFile << line;
    }
}