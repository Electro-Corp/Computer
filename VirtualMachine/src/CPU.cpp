#include "CPU.hpp"

Hardware::CPU::CPU(std::string name, Hardware::Memory* memory){
    this->processorName = name;
    this->memory = memory;
}

void Hardware::CPU::init(){
    // Read reset vector
    unsigned char inst = (*this->memory)[1114112];
    LOG(INFO, "LOG_TAG") << std::to_string(inst) << "\n";
}