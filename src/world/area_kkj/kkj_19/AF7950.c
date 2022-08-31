#include "kkj_19.h"

static char* N(exit_str_0) = "kkj_10";
static char* N(exit_str_1) = "kkj_00";

extern s32 D_80240E88_AF87D8;
extern s32 D_80240E8C_AF87DC;
extern s32 D_80240E90_AF87E0;

// Needs data migration, matching otherwise
#ifdef NON_MATCHING
ApiStatus func_80240000_AF7950(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 var;

    D_80240E90_AF87E0 = evt_get_variable(script, *args++);
    var = evt_get_variable(NULL, LSWF(18));

    if (var == 1) {
        D_80240E88_AF87D8 = var;
        D_80240E8C_AF87DC = 5;
    } else {
        D_80240E88_AF87D8 = 0;
    }

    return ApiStatus_DONE2;
}
#else
INCLUDE_ASM(s32, "world/area_kkj/kkj_19/AF7950", func_80240000_AF7950);
#endif

void func_80240068_AF79B8(void) {
    if (D_80240E88_AF87D8 != 0) {
        set_window_update(WINDOW_ID_10, (s32)basic_window_update);
        set_window_update(WINDOW_ID_11, (s32)basic_window_update);
    } else {
        set_window_update(WINDOW_ID_10, (s32)basic_hidden_window_update);
        set_window_update(WINDOW_ID_11, (s32)basic_hidden_window_update);
    }

    if (D_80240E8C_AF87DC > 0) {
        D_80240E8C_AF87DC--;
    } else {
        D_80240E88_AF87D8 = 0;
    }
}

INCLUDE_ASM(s32, "world/area_kkj/kkj_19/AF7950", func_802400E4_AF7A34);

INCLUDE_ASM(s32, "world/area_kkj/kkj_19/AF7950", func_80240178_AF7AC8);

INCLUDE_ASM(s32, "world/area_kkj/kkj_19/AF7950", func_802401FC_AF7B4C);
