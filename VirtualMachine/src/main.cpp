#include <iostream>
#include <aixlog.hpp>

#include <computer.hpp>

int main(){
    AixLog::Log::init<AixLog::SinkCout>(AixLog::Severity::trace);
    LOG(INFO, "LOG_TAG") << "Titanium Virtual Machine starting...\n";

    Computer computer("../SampleHardware/TitaniumSystem1.xml");

    while(1){}
}