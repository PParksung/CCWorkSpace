#include "car_builder.h"
#include "part.h"
#include "car.h"
#include <cassert>
#include <string>

CarBuilder::CarBuilder(const CarPartsFactory* carPartsFactory)
    : factory_(carPartsFactory), door_(nullptr),
    wheel_(nullptr), roof_(nullptr), color_("") {}

CarBuilder& CarBuilder::CreateDoor() {
    if (door_ != nullptr) {
        assert(false && "Attempting to create a door when one already exists.");
    } else {
        Part* tempDoor = factory_->CreateDoor();
        if (tempDoor != nullptr) {
            door_ = tempDoor;
        } else {
            door_ = nullptr;
        }
    }
    return *this;
}

CarBuilder& CarBuilder::CreateWheel() {
    if (wheel_ != nullptr) {
        assert(false &&
        "Attempting to create a wheel when one already exists.");
    } else {
        Part* tempWheel = factory_->CreateWheel();
        if (tempWheel != nullptr) {
            wheel_ = tempWheel;
        } else {
            wheel_ = nullptr;
        }
    }
    return *this;
}

CarBuilder& CarBuilder::CreateRoof() {
    if (roof_ != nullptr) {
        assert(false && "Attempting to create a roof when one already exists.");
    } else {
        Part* tempRoof = factory_->CreateRoof();
        if (tempRoof != nullptr) {
            roof_ = tempRoof;
        } else {
            roof_ = nullptr;
        }
    }
    return *this;
}

CarBuilder& CarBuilder::SetColor(std::string newColor) {
    if (!newColor.empty()) {
        color_ = newColor;
    } else {
        color_ = "defaultColor";
    }
    return *this;
}

Car* CarBuilder::Build() {
    Car* constructedCar = new Car(door_, wheel_, roof_, color_);
    door_ = nullptr;
    wheel_ = nullptr;
    roof_ = nullptr;
    color_ = "";
    return constructedCar;
}
