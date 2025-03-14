#pragma once

#include <stdlib.h>

namespace Hardware{
    class MemoryBank{
    private:
        int bytes;

        unsigned char* memory;
    public: 
        MemoryBank(int bytes);

        unsigned char operator[](int i); 
    };
}