#pragma once

class CPUMonitor {
private:
    struct CPUTicks {
        unsigned long long idle = 0;
        unsigned long long iowait = 0;
        unsigned long long total = 0;
    };

    CPUTicks cpuTimes;

    double waitPercent = 0.0;
    double usagePercent = 0.0;

    void readCPUTimes();

public:
    CPUMonitor();   // Constructor

    void update();
    double getUsagePercent() const {return usagePercent;}
    double getWaitPercent() const {return waitPercent;}
};