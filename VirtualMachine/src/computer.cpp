#include <computer.hpp>

/*
*/
Computer::Computer(std::string computerInfoPath){
    LOG(INFO, "LOG_TAG") << "Loading computer from " << computerInfoPath << "\n";
    result = doc.load_file(computerInfoPath.c_str());

    // Load CPUS
    LOG(INFO, "LOG_TAG") << "Loading CPUs... \n";
    pugi::xml_node proccesors = doc.child("Computer").child("Processing");
    for (pugi::xml_node cpuNode = proccesors.child("CPU"); cpuNode; cpuNode = cpuNode.next_sibling("CPU")){
        LOG(INFO, "LOG_TAG") << "Found " << cpuNode.attribute("name").value() << "\n";

        // Load the CPU
        Hardware::CPU cpu = Hardware::CPU(cpuNode.attribute("name").as_string());
        this->cpus.push_back(cpu);
    }
    LOG(INFO, "LOG_TAG") << "Loaded " << this->cpus.size() << " CPU(s).\n";

    // Load memory
    LOG(INFO, "LOG_TAG") << "Loading memory... \n";
    pugi::xml_node memorySlots = doc.child("Computer").child("Memory");
    LOG(INFO, "LOG_TAG") << "Total memory banks: " << memorySlots.attribute("banks").value() << "\n";
    for (pugi::xml_node memBank = memorySlots.child("Bank"); memBank; memBank = memBank.next_sibling("Bank")){
        LOG(INFO, "LOG_TAG") << "Found bank of size " << memBank.attribute("size").value() << ", and empty is " <<  memBank.attribute("empty").value() << "\n";

        // Load the Bank
        Hardware::MemoryBank memoryBank(memBank.attribute("size").as_int());
        this->memoryBanks.push_back(memoryBank);
    }
    LOG(INFO, "LOG_TAG") << "Loaded " << this->memoryBanks.size() << " Memory Bank(s).\n";

}