#pragma once

#include <string>

#include <aixlog.hpp>

#include <Memory.hpp>

namespace Hardware{
    class CPU{
    private:
        std::string processorName;
        Hardware::Memory* memory;

        // General purpose registers
        short ax, bx, cx, dx;
        // Offset registers
        short si, di;
        // Stack pointer
        short sp;
        // Stack frame
        short bp;
        // Segment pointers
        short cs, ds, ss, es;
        // Instruction pointer
        short ip;
        // Flags
        short flags;

    public:
        CPU(std::string processorName, Hardware::Memory* memory);

        void init();
    };
}