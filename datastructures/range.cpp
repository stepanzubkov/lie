// Integer range datastructure (ex. 0-10, 5-100)
#include "range.h"


Range::Range(int start, int stop) : start(start), stop(stop) {}

Range::Range(int stop) : Range(0, stop) {}

bool Range::contains(int value) {
    return value >= start && value <= stop;
}
