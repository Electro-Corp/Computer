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

void Hardware::CPU::tick(){
    // Read from memory the thing
    switch(instructionReadFromMemory()){
        // Lets cover all the MOV stuff first
        // Register to register
        case 0xA0:
        {
            this->ip++;
            unsigned char reg1 = instructionReadFromMemory();
            this->ip++;
            unsigned char reg2 = instructionReadFromMemory();
            modifyRegister(reg1, getRegister(reg2));
            this->ip++;
            break;
        }
        // Value into register
        case 0xA1:
        {
            this->ip++;
            unsigned char reg1 = instructionReadFromMemory();
            this->ip++;
            unsigned char data = instructionReadFromMemory();
            modifyRegister(reg1, data);
            this->ip++;
            break;
        }
        // Register into Pointer
        case 0xA2:
        {
            this->ip++;
            // This guy 4 bytes
            // First part
            unsigned char high = instructionReadFromMemory();
            this->ip++;
            unsigned char low = instructionReadFromMemory();
            unsigned short final = (low << 8) | high;
            this->ip++;
            unsigned char reg2 = instructionReadFromMemory();
            // Write it into memory
            this->memory->setMemory(final, getRegister(reg2));
            this->ip++;
            break;
        }
        // Value into Pointer
        case 0xA3:
        {
            this->ip++;
            // Grab pointer location
            unsigned char location = instructionReadFromMemory();
            this->ip++;
            // Grab value
            unsigned char value = instructionReadFromMemory();
            // Write
            this->memory->setMemory(location, value);
            this->ip++;
            break;
        }
        default:
            LOG(INFO, "LOG_TAG") << std::to_string(instructionReadFromMemory()) << "is a command that the CPU doesn't know how to handle yet!" << "\n";
            break;
    }
    
}


// Register helpers
void Hardware::CPU::modifyRegister(unsigned char reg, unsigned short data){
    switch(reg){
        case 0xAA:
            this->ax = data;
            break;
        case 0xAB:
            this->bx = data;
            break;
        case 0xAC:
            this->cx = data;
            break;
        case 0xAD:
            this->dx = data;
            break;
    }
}
unsigned short Hardware::CPU::getRegister(unsigned char reg){
    switch(reg){
        case 0xAA:
            return this->ax;
            break;
        case 0xAB:
            return this->bx;
            break;
        case 0xAC:
            return this->cx;
            break;
        case 0xAD:
            return this->dx;
            break;
    }
}


void Hardware::CPU::debugPrint(){
    printf("====\nCS:%x IP:%x\n", this->cs, this->ip);
    printf("AX:%x BX:%x CX:%x DX:%x\n", ax, bx, cx, dx);
}