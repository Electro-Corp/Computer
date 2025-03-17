#pragma once

#include <vector>
#include <string>

#include <pugixml/pugixml.hpp>
#include <aixlog.hpp>

#include <CPU.hpp>
#include <VGA.hpp>
#include <Memory.hpp>

class Computer{
private:
    // Hardware
    std::vector<Hardware::CPU> cpus;
    Hardware::Memory memory;
    Hardware::VGA vga;

    pugi::xml_document doc;
    pugi::xml_parse_result result;
public:
    Computer(std::string computerInfoPath);

    void tick();

    void shutdown();
};