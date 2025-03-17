#include "door.h"

Door::Door(std::string factory_name) :
    Part(factory_name) {}

std::string Door::GetInfo() const {
    std::string info;
    info.append("[").append(factory_name()).append("] ").append("Door");
    return info;
}
