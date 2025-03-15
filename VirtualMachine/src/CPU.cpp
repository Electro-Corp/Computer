#include "CPU.hpp"

Hardware::CPU::CPU(std::string name, Hardware::Memory* memory){
    this->processorName = name;
    this->memory = memory;
}

void Hardware::CPU::init(){
    // Read reset vector
    this->cs = 0xFFFF;
    this->ip = 0;
    
    LOG(INFO, "LOG_TAG") << std::to_string(instructionReadFromMemory()) << "\n";
}

unsigned char Hardware::CPU::instructionReadFromMemory(){
    unsigned char inst = (*this->memory)[(this->cs * 16) + this->ip];
    return inst;
}