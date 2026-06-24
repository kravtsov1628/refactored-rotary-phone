#include "task1.h"

int get_mop_holder(int n, int time) {
    if (n <= 1) {
        return 1;
    }

    const int cycle = 2 * n - 2;
    const int pos = time % cycle;

    if (pos < n) {
        return pos + 1;
    }
    return 2 * n - pos - 1;
}
