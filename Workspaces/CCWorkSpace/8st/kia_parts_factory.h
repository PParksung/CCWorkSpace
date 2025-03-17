#ifndef KIA_PARTS_FACTORY_H
#define KIA_PARTS_FACTORY_H

#include "car_parts_factory.h"
#include "door.h"
#include "wheel.h"
#include "roof.h"

class KiaPartsFactory : public CarPartsFactory {
 public:
    static KiaPartsFactory* GetInstance();
    Part* CreateDoor() const override;
    Part* CreateWheel() const override;
    Part* CreateRoof() const override;

 private:
    KiaPartsFactory();
    static KiaPartsFactory* instance_;
};

#endif
