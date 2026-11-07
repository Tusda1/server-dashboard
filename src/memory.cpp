#include <fstream>
#include <string>
#include <sstream>

#include "memory.hpp"

MemoryInfo readMemory() {
    MemoryInfo memInfo;

    std::ifstream fs("/proc/meminfo");
    std::string currentLine;
    int found = 0;
    
    while(found < 2 && std::getline(fs, currentLine)) {
        std::istringstream ss(currentLine);
        std::string key;
        unsigned int value;
        ss >> key >> value;

        if (key == "MemTotal:") {
            memInfo.totalkB = value;
            found++;
        }
        else if (key == "MemAvailable:") {
            memInfo.availablekB = value;
            found ++;
        }
    }
    return memInfo;
}