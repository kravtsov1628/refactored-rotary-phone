#include "task5.h"

bool can_reach_from_one(unsigned int fx, unsigned int fy) {
    if (fx == 0 && fy == 0) {
        return false;
    }

    if (fx > 0 && fy > 0) {
        return true;
    }

    if (fx == 0) {
        return (fy & (fy - 1)) == 0;
    }
    return (fx & (fx - 1)) == 0;
}
