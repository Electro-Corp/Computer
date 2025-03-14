#pragma once

#include <vector>
#include <string>

#include <pugixml/pugixml.hpp>
#include <aixlog.hpp>

#include <CPU.hpp>

class Computer{
private:
    std::vector<Hardware::CPU> cpus;
    pugi::xml_document doc;
    pugi::xml_parse_result result;
public:
    Computer(std::string computerInfoPath);
};