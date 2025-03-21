#pragma once

#include <stdlib.h>
#include <vector>

#include <aixlog.hpp>

namespace Hardware{
    class MemoryBank{
    private:
        int bytes;

        unsigned char* memory;
    public: 
        MemoryBank(int bytes);

        unsigned char operator[](int i);

        void setInBank(int i, unsigned char data);

        int getSize(){
            return bytes;
        } 

        unsigned char* getMemory(){
            return memory;
        }
    };

    class Memory{
    public:
        std::vector<Hardware::MemoryBank> memoryBanks;

        unsigned char operator[](int i); 

        void setMemory(int i, unsigned char data);

        void dumpMemory();

    };
}