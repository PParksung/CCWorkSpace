#include <iostream>
#include <set>

class IntCompare {
 public:
    int operator()(const int& x, const int& y) {
        if(x<y) return 1;
        else if(x == y) return 0;
        else return -1;
    }
};

void Print(std::set<int, IntCompare>& s) {
    for (int i : s) {
        std::cout << "ELEM: " << i << std::endl;
    }
}

int main() {
    std::set<int, IntCompare> s;
    s.insert(1);
    s.insert(1);
    s.insert(1);
    s.insert(1);
    s.insert(2);
    s.insert(2);

    Print(s);

    return 0;
}