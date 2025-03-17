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
        unsigned short ax = 0x00, bx = 0x00, cx = 0x00, dx = 0x00;
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

        // register modifiers
        void modifyRegister(unsigned char reg, unsigned short data);
        unsigned short getRegister(unsigned char reg);

    public:
        CPU(std::string processorName, Hardware::Memory* memory);

        void init();

        unsigned char instructionReadFromMemory();

        void tick();

        void debugPrint();
    };
}