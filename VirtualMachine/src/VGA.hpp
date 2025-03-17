#pragma once

#include <Memory.hpp>

namespace Hardware{
    class VGA{
    private:
        int address;
    public:
        VGA(int address);
        VGA();
    };
}