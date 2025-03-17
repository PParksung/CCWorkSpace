#ifndef SORT_H
#define SORT_H

#include <iterator>
#include <utility>

template <typename T, typename N>
void Sort(typename T::iterator begin, typename T::iterator end) {
    N compare;
    bool is_swap = true;
    // 5, 2, 4, 6, 1
    // begin() = 5, end() = 1 다음거

    while (is_swap) {
        is_swap = false;
        typename T::iterator i;
        for (i = begin; std::next(i) != end; i++) {
            if (compare(*i, *std::next(i))) {
                 //  i가 i 다음값보다 크면 트루
                std::swap(*i, *std::next(i));
                is_swap = true;
            }
        }
    }
    // 5, 2, 4, 6, 1
    // 2, 4, 5, 1, 6
    // 2, 4, 1, 5, 6
    // 2, 1, 4, 5, 6
    // 1, 2, 4, 5, 6
}

#endif
