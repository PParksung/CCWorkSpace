// part.h
#ifndef PART_H
#define PART_H

#include <string>

class Part {
 public:
    explicit Part(std::string factory_name);
    virtual ~Part();
    virtual std::string GetInfo() const = 0;
    std::string factory_name() const;
 private:
    std::string factory_name_;
};

#endif
