#include "mgm_02.h"

#define SCOREKEEPER_ENEMY_IDX 0
#define SMASH_DATA_VAR_IDX 5

#define PLAY_COST 10

INCLUDE_ASM(s32, "world/area_mgm/mgm_02/E15D80", func_80240000_E15D80);

INCLUDE_ASM(s32, "world/area_mgm/mgm_02/E15D80", func_80240430_E161B0);

INCLUDE_ASM(s32, "world/area_mgm/mgm_02/E15D80", func_80240468_E161E8);

INCLUDE_ASM(s32, "world/area_mgm/mgm_02/E15D80", func_80240544_E162C4);

INCLUDE_ASM(s32, "world/area_mgm/mgm_02/E15D80", func_80240580_E16300);

INCLUDE_ASM(s32, "world/area_mgm/mgm_02/E15D80", func_802405A4_E16324);

INCLUDE_ASM(s32, "world/area_mgm/mgm_02/E15D80", func_802405D0_E16350);

INCLUDE_ASM(s32, "world/area_mgm/mgm_02/E15D80", func_80240644_E163C4);

INCLUDE_ASM(s32, "world/area_mgm/mgm_02/E15D80", func_80240790_E16510);

INCLUDE_ASM(s32, "world/area_mgm/mgm_02/E15D80", func_80240BB0_E16930);

static char* N(exit_str_0) = "mgm_00";

INCLUDE_ASM(s32, "world/area_mgm/mgm_02/E15D80", func_80241DCC_E17B4C);

INCLUDE_ASM(s32, "world/area_mgm/mgm_02/E15D80", func_80241F38_E17CB8);

INCLUDE_ASM(s32, "world/area_mgm/mgm_02/E15D80", func_80241FE4_E17D64);

INCLUDE_ASM(s32, "world/area_mgm/mgm_02/E15D80", func_80242274_E17FF4);

INCLUDE_ASM(s32, "world/area_mgm/mgm_02/E15D80", func_802422D0_E18050);

/* N(GetCoinCount) */
ApiStatus func_80242314_E18094(Evt* script, s32 isInitialCall) {
    evt_set_variable(script, LW(0xA), gPlayerData.coins);
    return ApiStatus_DONE2;
}

/* N(TakeCoinCost) */
ApiStatus func_80242340_E180C0(Evt* script, s32 isInitialCall) {
    PlayerData* playerData = &gPlayerData;

    if (isInitialCall) {
        playerData->smashGamePlays++;
        script->functionTemp[0] = 0;
    }
    add_coins(-1);
    sfx_play_sound(SOUND_211);

    return (++script->functionTemp[0] == PLAY_COST) ? ApiStatus_DONE2 : ApiStatus_BLOCK;
}

ApiStatus func_802423A4_E18124(Evt* script, s32 isInitialCall) {
    hide_coin_counter_immediately();
    return ApiStatus_DONE2;
}
