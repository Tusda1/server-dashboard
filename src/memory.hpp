#pragma once

#include "monitor.hpp"

class MemoryMonitor : Monitor{
private:
    struct MemoryInfo {
        unsigned int totalkB = 0;
        unsigned int availablekB = 0;
    };

    MemoryInfo memoryStats;

    double memoryUsagePercent = 0;

    void readMemory();

public:
    void update() override;
    double getMemoryPercent();
};