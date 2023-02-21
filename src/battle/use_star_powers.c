#include "common.h"
#include "ld_addrs.h"
#include "battle.h"

#include "sprite/npc/WorldGoombario.h"
#include "sprite/npc/BattleGoombario.h"
#include "sprite/npc/BattleKooper.h"
#include "sprite/npc/BattleBombette.h"
#include "sprite/npc/BattleParakarry.h"
#include "sprite/npc/BattleWatt.h"
#include "sprite/npc/BattleSushie.h"
#include "sprite/npc/BattleLakilester.h"
#include "sprite/npc/BattleBow.h"

extern EvtScript battle_move_focus_EVS_UsePower;
extern EvtScript battle_move_refresh_EVS_UsePower;
extern EvtScript battle_move_lullaby_EVS_UsePower;
extern EvtScript battle_move_star_storm_EVS_UsePower;
extern EvtScript battle_move_chill_out_EVS_UsePower;
extern EvtScript battle_move_smooch_EVS_UsePower;
extern EvtScript battle_move_time_out_EVS_UsePower;
extern EvtScript battle_move_up_and_away_EVS_UsePower;
extern EvtScript battle_move_star_beam_EVS_UsePower;
extern EvtScript battle_move_peach_beam_EVS_UsePower;
extern EvtScript battle_move_peach_focus_EVS_UsePower;
extern EvtScript battle_move_twink_dash_EVS_UsePower;

BattleMoveEntry StarPowersTable[] = {
    BTL_MOVE(focus,           EVS_UsePower),
    BTL_MOVE(refresh,         EVS_UsePower),
    BTL_MOVE(lullaby,         EVS_UsePower),
    BTL_MOVE(star_storm,      EVS_UsePower),
    BTL_MOVE(chill_out,       EVS_UsePower),
    BTL_MOVE(smooch,          EVS_UsePower),
    BTL_MOVE(time_out,        EVS_UsePower),
    BTL_MOVE(up_and_away,     EVS_UsePower),
    BTL_MOVE(star_beam,       EVS_UsePower),
    BTL_MOVE(peach_beam,      EVS_UsePower),
    BTL_MOVE(peach_focus,     EVS_UsePower),
    BTL_MOVE(twink_dash,      EVS_UsePower),
};

s32 D_8029C890[][5] = {
    [PARTNER_NONE] {
        ANIM_Mario1_UsePower,
        ANIM_Mario1_Pray,
        ANIM_Mario1_LookUp,
        ANIM_Mario1_Run,
        0,
    },
    [PARTNER_GOOMBARIO] {
        ANIM_BattleGoombario_Run,
        ANIM_BattleGoombario_CloseEyes,
        ANIM_BattleGoombario_CloseEyes,
        ANIM_BattleGoombario_Run,
        ANIM_BattleGoombario_Idle,
    },
    [PARTNER_KOOPER] {
        ANIM_BattleKooper_Run,
        ANIM_BattleKooper_Pray,
        ANIM_BattleKooper_Pray,
        ANIM_BattleKooper_Run,
        ANIM_BattleKooper_Idle,
    },
   [PARTNER_BOMBETTE] {
        ANIM_BattleBombette_Run,
        ANIM_BattleBombette_Sleep,
        ANIM_BattleBombette_Sleep,
        ANIM_BattleBombette_Run,
        ANIM_BattleBombette_Idle,
    },
    [PARTNER_PARAKARRY] {
        ANIM_BattleParakarry_Run,
        ANIM_BattleParakarry_Pray,
        ANIM_BattleParakarry_Pray,
        ANIM_BattleParakarry_Run,
        ANIM_BattleParakarry_Idle,
    },
    [PARTNER_GOOMPA] {
        // no data
    },
    [PARTNER_WATT] {
        ANIM_BattleWatt_Run,
        ANIM_BattleWatt_Sleep,
        ANIM_BattleWatt_Sleep,
        ANIM_BattleWatt_Run,
        ANIM_BattleParakarry_Idle, // @bug uses wrong sprite!
    },
    [PARTNER_SUSHIE] {
        ANIM_BattleSushie_Run,
        ANIM_BattleSushie_Pray,
        ANIM_BattleSushie_Pray,
        ANIM_BattleSushie_Run,
        ANIM_BattleSushie_Idle,
    },
    [PARTNER_LAKILESTER] {
        ANIM_BattleLakilester_Run,
        ANIM_BattleLakilester_Pray,
        ANIM_BattleLakilester_Pray,
        ANIM_BattleLakilester_Run,
        ANIM_BattleLakilester_Idle,
    },
    [PARTNER_BOW] {
        ANIM_BattleBow_Run,
        ANIM_BattleBow_Pray,
        ANIM_BattleBow_Pray,
        ANIM_BattleBow_Run,
        ANIM_BattleBow_Idle,
    },
};

ApiStatus LoadStarPowerScript(Evt* script, s32 isInitialCall) {
    BattleStatus* battleStatus = &gBattleStatus;
    PlayerData* playerData = &gPlayerData;
    s16 starPowerIdx;

    playerData->specialBarsFilled -= gMoveTable[battleStatus->selectedMoveID].costFP * 256;
    starPowerIdx = battleStatus->moveArgument;
    dma_copy((&StarPowersTable[starPowerIdx])->romStart,
             (&StarPowersTable[starPowerIdx])->romEnd,
             (&StarPowersTable[starPowerIdx])->vramStart);
    script->varTable[0] = (s32) (&StarPowersTable[starPowerIdx])->mainScript;
    return ApiStatus_DONE2;
}

MATCHING_BSS(0x1390);
