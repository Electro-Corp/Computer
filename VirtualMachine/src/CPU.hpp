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
        unsigned short ax, bx, cx, dx;
        // Offset registers
        unsigned short si, di;
        // Stack pointer
        unsigned short sp;
        // Stack frame
        unsigned short bp;
        // Segment pointers
        unsigned short cs, ds, ss, es;
        // Instruction pointer
        unsigned short ip;
        // Flags
        unsigned short flags;

    public:
        CPU(std::string processorName, Hardware::Memory* memory);

        void init();

        unsigned char instructionReadFromMemory();
    };
}