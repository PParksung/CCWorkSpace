#ifndef HYUNDAI_PARTS_FACTORY_H
#define HYUNDAI_PARTS_FACTORY_H

#include "car_parts_factory.h"
#include "door.h"
#include "wheel.h"
#include "roof.h"

class HyundaiPartsFactory : public CarPartsFactory {
 public:
    static HyundaiPartsFactory* GetInstance();
    Part* CreateDoor() const override;
    Part* CreateWheel() const override;
    Part* CreateRoof() const override;

 private:
    HyundaiPartsFactory();
    static HyundaiPartsFactory* instance_;
};

#endif
