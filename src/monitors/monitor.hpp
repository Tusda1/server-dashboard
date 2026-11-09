#pragma once

class Monitor {
public:
    virtual void update() = 0;

    virtual ~Monitor() = default;
};