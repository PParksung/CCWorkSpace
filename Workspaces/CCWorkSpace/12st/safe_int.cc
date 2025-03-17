#include "safe_int.h"
#include "divide_by_zero_exception.h"
#include <stdexcept>
#include <limits>
#include <string>  // For std::string

SafeInt::SafeInt(int n) : value_(n) {}

SafeInt SafeInt::operator+(const SafeInt& x) const {
    int result = value_ + x.value_;
    if ((value_ > 0 && x.value_ > 0 && result < 0) ||
        result > std::numeric_limits<int>::max()) {
        throw std::overflow_error("Integer overflow occurs in "
        + std::to_string(value_) + " + " +
        std::to_string(x.value_));
    }
    return SafeInt(result);
}

SafeInt SafeInt::operator-(const SafeInt& x) const {
    int result = value_ - x.value_;
    if ((value_ < 0 && x.value_ > 0 && result > 0) ||
        result < std::numeric_limits<int>::min()) {
        throw std::overflow_error("Integer overflow occurs in "
        + std::to_string(value_) + " - " +
        std::to_string(x.value_));
    }
    return SafeInt(result);
}

SafeInt SafeInt::operator*(const SafeInt& x) const {
    int result = value_ * x.value_;
    if ((value_ > 0 && x.value_ > 0 && result < 0) ||
        (value_ < 0 && x.value_ < 0 && result < 0) ||
        (value_ > 0 && x.value_ < 0 && result > 0) ||
        (value_ < 0 && x.value_ > 0 && result > 0)) {
        throw std::overflow_error
        ("Integer overflow occurs in " +
        std::to_string(value_) + " * " +
        std::to_string(x.value_));
    }
    return SafeInt(result);
}

SafeInt SafeInt::operator/(const SafeInt& x) const {
    if (x.value_ == 0) {
        throw DivideByZeroException
        (("Divide-by-zero exception occurs in "
        + std::to_string(value_) + " / " +
        std::to_string(x.value_)).c_str());
    }
    return SafeInt(value_ / x.value_);
}

SafeInt SafeInt::operator%(const SafeInt& x) const {
    if (x.value_ == 0) {
        throw DivideByZeroException
        (("Divide-by-zero exception occurs in " +
        std::to_string(value_) + " % " +
        std::to_string(x.value_)).c_str());
    }
    return SafeInt(value_ % x.value_);
}

int SafeInt::value() const {
    return value_;
}
