#include "checkbitmask.h"

bool checkBitMask(uint32_t val) {

    if (val == 0) {
        return false;
    }

    uint32_t a = 0b1 << 31;

    while (val & a) {
        val = val << 1;
    }

    if (!val) {
        return true;
    }
    else {
        return false;
    }
}

std::string convertIntToBinString(uint32_t val) {

    std::bitset<sizeof(uint32_t) * 8> binary(val);
    return binary.to_string();

}
