enum {
    VINE_0      = 0,
    VINE_1      = 1,
    VINE_2      = 2,
    VINE_3      = 3,
    NUM_VINES   = 4
};

enum {
    VINE_0_BASE  = 0x80200000,
    VINE_1_BASE  = 0x80204000,
    VINE_2_BASE  = 0x80207000,
    VINE_3_BASE  = 0x8020A000,
}; // TODO shiftability -- hard-coded addresses in gBackgroundImage

#include "world/common/lava_piranha/skele1.c"
#include "world/common/lava_piranha/skele2.c"
#include "world/common/lava_piranha/skele3.c"
