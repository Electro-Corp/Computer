#pragma once

#include <vector>
#include <string>

#include <pugixml/pugixml.hpp>
#include <aixlog.hpp>

#include <CPU.hpp>
#include <Memory.hpp>

class Computer{
private:
    // Hardware
    std::vector<Hardware::CPU> cpus;
    std::vector<Hardware::MemoryBank> memoryBanks;

    pugi::xml_document doc;
    pugi::xml_parse_result result;
public:
    Computer(std::string computerInfoPath);
};