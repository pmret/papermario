#include "kkj_19.h"

typedef struct {
    /* 0x00 */ s32 itemID;
    /* 0x04 */ s32 flagIndex;
    /* 0x08 */ s32 overrideDescMsg;
} UnkKkj19; // size = 0x0C

extern UnkKkj19 D_80240E10_AF8760[];
extern s32 D_80240E88_AF87D8;
extern s32 D_80240E8C_AF87DC;
extern s32 D_80240E90_AF87E0;
extern EvtScript D_80240E94_AF87E4;
extern MenuWindowBP D_80240EF0_AF8840[2];

static char* N(exit_str_0) = "kkj_10";
static char* N(exit_str_1) = "kkj_00";

NOP_FIX // TODO remove after D_80240E8C_AF87DC is migrated

ApiStatus func_80240000_AF7950(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 var;

    D_80240E90_AF87E0 = evt_get_variable(script, *args++);
    var = evt_get_variable(NULL, AreaFlag(18));

    if (var == 1) {
        D_80240E88_AF87D8 = var;
        D_80240E8C_AF87DC = 5;
    } else {
        D_80240E88_AF87D8 = 0;
    }

    return ApiStatus_DONE2;
}

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

void func_802400E4_AF7A34(s32 arg0, s32 x, s32 y) {
    ItemData* item = &gItemTable[D_80240E10_AF8760[D_80240E90_AF87E0].itemID];
    s32 width = (get_msg_width(item->nameMsg, 0) >> 1) - 60;

    draw_msg(item->nameMsg, x - width, y + 6, 255, 0, 0);
}

void func_80240178_AF7AC8(s32 arg0, s32 x, s32 y) {
    UnkKkj19* temp_a3 = &D_80240E10_AF8760[D_80240E90_AF87E0];
    ItemData* item = &gItemTable[temp_a3->itemID];

    if (temp_a3->overrideDescMsg != 0) {
        draw_msg(temp_a3->overrideDescMsg, x + 8, y, 255, 10, 0);
    } else {
        draw_msg(item->shortDescMsg, x + 8, y, 255, 10, 0);
    }
}

ApiStatus func_802401FC_AF7B4C(Evt* script, s32 isInitialCall) {
    s32 i;

    D_80240E88_AF87D8 = 0;
    D_80240E8C_AF87DC = 0;
    D_80240E90_AF87E0 = 0;

    get_worker(create_worker_frontUI(func_80240068_AF79B8, NULL));
    setup_pause_menu_tab(D_80240EF0_AF8840, ARRAY_COUNT(D_80240EF0_AF8840));

    for (i = 0; i < 10; i++) {
        bind_trigger_1(&D_80240E94_AF87E4, TRIGGER_FLOOR_TOUCH, D_80240E10_AF8760[i].flagIndex, i, 0, 3);
    }

    return ApiStatus_DONE2;
}
