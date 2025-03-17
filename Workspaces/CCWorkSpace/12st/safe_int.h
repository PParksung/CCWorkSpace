#ifndef SAFE_INT_H
#define SAFE_INT_H

class SafeInt{
 public:
    explicit SafeInt(int n);
    SafeInt operator+(const SafeInt& x) const;
    SafeInt operator-(const SafeInt& x) const;
    SafeInt operator*(const SafeInt& x) const;
    SafeInt operator/(const SafeInt& x) const;
    SafeInt operator%(const SafeInt& x) const;
    int value() const;
 private:
    int value_;
};

#endif
