#include "wheel.h"

Wheel::Wheel(std::string factory_name) :
    Part(factory_name) {}

std::string Wheel::GetInfo() const {
    std::string info;
    info.append("[").append(factory_name()).append("] ").append("Wheel");
    return info;
}
