#pragma once

#include <Memory.hpp>

namespace Hardware{
    class VGA{
    private:
        int address;
        std::ofstream displayFile;
        Hardware::Memory* mem;
    public:
        VGA(Hardware::Memory* mem, int address);
        VGA();

        void tick();
    };
}