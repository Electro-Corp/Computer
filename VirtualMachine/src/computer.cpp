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
        Hardware::CPU cpu = Hardware::CPU(cpuNode.attribute("name").as_string(), &(this->memory));
        this->cpus.push_back(cpu);
    }
    LOG(INFO, "LOG_TAG") << "Loaded " << this->cpus.size() << " CPU(s).\n";

    // Load memory
    LOG(INFO, "LOG_TAG") << "Loading memory... \n";
    pugi::xml_node memorySlots = doc.child("Computer").child("Memory");
    LOG(INFO, "LOG_TAG") << "Total memory banks: " << memorySlots.attribute("banks").value() << "\n";
    for (pugi::xml_node memBank = memorySlots.child("Bank"); memBank; memBank = memBank.next_sibling("Bank")){
        LOG(INFO, "LOG_TAG") << "Found bank of size " << memBank.attribute("size").value() << "KB, and empty is " <<  memBank.attribute("empty").value() << "\n";

        // Load the Bank
        Hardware::MemoryBank memoryBank(memBank.attribute("size").as_int());
        this->memory.memoryBanks.push_back(memoryBank);
    }
    LOG(INFO, "LOG_TAG") << "Loaded " << this->memory.memoryBanks.size() << " Memory Bank(s).\n";
    LOG(INFO, "LOG_TAG") << "Init BIOS ROM at 0xFFFF0..\n";
    std::string biosFile = doc.child("Computer").child("BIOS").attribute("location").as_string();
    LOG(INFO, "LOG_TAG") << "Using BIOS file at " << biosFile << "\n";
    // Open it
    std::ifstream bios(biosFile, std::ios::binary);
    if(!bios.is_open()){
        LOG(ERROR, "LOG_ERROR") << "Failed to open BIOS!\n";
        exit(-1);
    }
    std::vector<unsigned char> biosBuffer(std::istreambuf_iterator<char>(bios), {});
    for(int i = 0; i < biosBuffer.size(); i++){
        (&this->memory)->setMemory(0xFFFF0 + i, biosBuffer[i]);
    }
    
    //(&this->memory)->setMemory(0xFFFF0, 5);

    
    LOG(INFO, "LOG_TAG") << "0xB8000 will be set as the Text Mode video memory space.\n";


    // Starting computer
    LOG(INFO, "LOG_TAG") << "Starting " << doc.child("Computer").attribute("name").value() << "...\n";
    cpus[0].init();

}