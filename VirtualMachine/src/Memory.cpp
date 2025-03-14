#include <Memory.hpp>

Hardware::MemoryBank::MemoryBank(int size){
    this->bytes = size;

    this->memory = new unsigned char[size * 1000];

    // Initilize memory
    for(int i = 0; i < size * 1000; i++){
        memory[i] = 0;
    }
}

unsigned char Hardware::MemoryBank::operator[](int i){
    return memory[i];
} 