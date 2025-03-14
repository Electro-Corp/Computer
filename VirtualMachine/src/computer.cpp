#include <computer.hpp>

/*
*/
Computer::Computer(std::string computerInfoPath){
    LOG(INFO, "LOG_TAG") << "Loading computer from " << computerInfoPath << "\n";
    result = doc.load_file(computerInfoPath.c_str());

    // Load CPUS
    LOG(INFO, "LOG_TAG") << "Loading CPUs... \n";
    pugi::xml_node proccesors = doc.child("Computer").child("Processing");
    for (pugi::xml_node cpuNode = proccesors.child("CPU"); cpuNode; cpuNode = proccesors.next_sibling("CPU")){
        std::cout << "CPU " << cpuNode.attribute("name").value();

        // Load the CPU
        Hardware::CPU cpu = Hardware::CPU();
        this->cpus.push_back(cpu);
    }
}