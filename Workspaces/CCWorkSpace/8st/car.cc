#include "car.h"
#include "door.h"
#include "wheel.h"
#include "roof.h"
#include <iostream>

Car::Car(Part* door, Part* wheel, Part* roof, std::string color)
    : door_(door), wheel_(wheel), roof_(roof), color_(color) {}


Car::Car(const Car& car)
    : color_(car.color_) {
    door_ = car.door_ ? new Door(car.door_->factory_name()) : nullptr;
    wheel_ = car.wheel_ ? new Wheel(car.wheel_->factory_name()) : nullptr;
    roof_ = car.roof_ ? new Roof(car.roof_->factory_name()) : nullptr;
}

Car& Car::operator=(const Car& car) {
    if (&car == this) {
        return *this;
    }

    delete door_;
    delete wheel_;
    delete roof_;

    color_ = car.color_;
    door_ = car.door_ ? new Door(car.door_->factory_name()) : nullptr;
    wheel_ = car.wheel_ ? new Wheel(car.wheel_->factory_name()) : nullptr;
    roof_ = car.roof_ ? new Roof(car.roof_->factory_name()) : nullptr;

    return *this;
}

Car::~Car() {
    delete door_;
    delete wheel_;
    delete roof_;
}

std::string Car::GetSpec() const {
    std::string spec;

    if (door_) spec += door_->GetInfo();
    if (wheel_) {
        if (!spec.empty()) spec += ", ";
        spec += wheel_->GetInfo();
    }
    if (roof_) {
        if (!spec.empty()) spec += ", ";
        spec += roof_->GetInfo();
    }
    if (!color_.empty()) {
        if (!spec.empty()) spec += ", ";
        spec += color_;
    }

    return spec.empty() ? "" : "Car(" + spec + ")";
}
