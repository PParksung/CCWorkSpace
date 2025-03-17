#include "roof.h"

Roof::Roof(std::string factory_name) :
    Part(factory_name) {}

std::string Roof::GetInfo() const {
    std::string info;
    info.append("[").append(factory_name()).append("] ").append("Roof");
    return info;
}
