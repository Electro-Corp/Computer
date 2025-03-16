#include <Memory.hpp>

Hardware::MemoryBank::MemoryBank(int size){
    this->bytes = size * 1000;

    this->memory = new unsigned char[bytes];

    // Initilize memory
    for(int i = 0; i < size * 1000; i++){
        memory[i] = 0;
    }
}

unsigned char Hardware::MemoryBank::operator[](int i){
    return memory[i];
} 

void Hardware::MemoryBank::setInBank(int i, unsigned char data){
    this->memory[i] = data;
}


unsigned char Hardware::Memory::operator[](int i){
    // Quick little optimization
    if(i < memoryBanks[0].getSize()){
        return memoryBanks[0][i];
    }
    int totalBytesTraversed = 0;
    for(int g = 0; g < memoryBanks.size(); g++){
        totalBytesTraversed += memoryBanks[g].getSize();
        if(i < totalBytesTraversed){
            return memoryBanks[g][totalBytesTraversed - i];
        }
    }
    LOG(ERROR, "LOG_ERROR") << "CPU tried to address memory that doesn't physically exist!\n";
    return 0;
}

void Hardware::Memory::setMemory(int i, unsigned char data){
    if(i < memoryBanks[0].getSize()){
        memoryBanks[0].setInBank(i, data);
        return;
    }
    int totalBytesTraversed = 0;
    for(int g = 0; g < memoryBanks.size(); g++){
        totalBytesTraversed += memoryBanks[g].getSize();
        if(i < totalBytesTraversed){
            memoryBanks[g].setInBank(totalBytesTraversed - i, data);
            return;
        }
    }
    LOG(ERROR, "LOG_ERROR") << "CPU tried to address memory that doesn't physically exist!\n";
    return;
}