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


        int getSize(){
            return bytes;
        } 
    };

    class Memory{
    public:
        std::vector<Hardware::MemoryBank> memoryBanks;

        unsigned char operator[](int i); 
    };
}