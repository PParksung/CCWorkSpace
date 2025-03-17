#ifndef ROOF_H
#define ROOF_H

#include <string>
#include "part.h"

class Roof : public Part {
 public:
    explicit Roof(std::string factory_name);
    std::string GetInfo() const override;
    ~Roof() override {}
};

#endif
