#pragma once

// TODO: Implement class structure

struct MemoryInfo {
    unsigned int totalkB = 0;
    unsigned int availablekB = 0;
};

MemoryInfo readMemory();