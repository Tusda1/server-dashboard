#include <fstream>
#include <string>
#include <sstream>

#include "cpu.hpp"

CPUMonitor::CPUMonitor() {
    readCPUTimes();    // Read cpu times at the start to have a baseline ready for the first update call
}

void CPUMonitor::readCPUTimes() {
    CPUTicks cpuinfo;

    std::ifstream fs("/proc/stat");
    std::string label;
    unsigned long long user, nice, system, idle, iowait, irq, softirq, steal, guest, guest_nice;

    fs >> label;
    fs >> user >> nice >> system >> idle >> iowait >> irq >> softirq >> steal >> guest >> guest_nice;

    cpuinfo.idle = idle;
    cpuinfo.iowait = iowait;
    cpuinfo.total = user + nice + system + idle + iowait + irq + softirq + steal + guest + guest_nice;

    cpuTimes = cpuinfo;
}

void CPUMonitor::update() {
    unsigned long long prevWait = cpuTimes.iowait;
    unsigned long long prevIdle = cpuTimes.idle;
    unsigned long long prevTotal = cpuTimes.total;

    readCPUTimes();

    double deltaWait = cpuTimes.iowait - prevWait;
    double deltaIdle = cpuTimes.idle - prevIdle;
    double deltaTotal = cpuTimes.total - prevTotal;

    if (deltaTotal <= 0.0) return;

    waitPercent = (deltaWait/deltaTotal) * 100;
    usagePercent = ((deltaTotal - deltaWait - deltaIdle)/deltaTotal) * 100;
}

// TODO: Maybe also read static cpu info like amount of cores and threads so it can be displayed?