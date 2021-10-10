#include "sbk_02.h"

static char* N(exit_str_0) = "sbk_01";
static char* N(exit_str_1) = "sbk_03";
static char* N(exit_str_2) = "sbk_12";
static char* N(exit_str_3) = "isk_01";
static char* N(exit_str_4) = "sbk_30";
static char* N(exit_str_5) = "";

//INCLUDE_ASM(s32, "world/area_sbk/sbk_02/92A2B0", func_80240000_92A2B0);
s32 func_80240000_92A2B0(void) {
    s32 phi;

    if (evt_get_variable(NULL, EVT_STORY_PROGRESS) >= -0x3E) {
        phi = 0x00190063;
    } else {
        phi = 0x00190062;
    }
    return phi;
}

#include "world/common/UnkFunc27.inc.c"

#include "world/common/UnkFunc26.inc.c"

// Accesses EVT_MAP_VAR(0) which is an effect handle
INCLUDE_ASM(s32, "world/area_sbk/sbk_02/92A2B0", func_80240338_92A5E8);

INCLUDE_ASM(s32, "world/area_sbk/sbk_02/92A2B0", func_80240364_92A614);
