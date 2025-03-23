#pragma once

#include <Memory.hpp>

namespace Hardware{
    class VGA{
    private:
        int address;
        std::ofstream displayFile;
        Hardware::Memory* mem;
        unsigned char prevFb[2000];
    public:
        VGA(Hardware::Memory* mem, int address);
        VGA();

        void tick();
    };
}