#include "common.h"
#include "ld_addrs.h"
#include "sprite/npc/WorldGoombario.h"
#include "sprite/npc/BattleGoombario.h"
#include "sprite/npc/BattleKooper.h"
#include "sprite/npc/BattleBombette.h"
#include "sprite/npc/BattleParakarry.h"
#include "sprite/npc/BattleWatt.h"
#include "sprite/npc/BattleSushie.h"
#include "sprite/npc/BattleLakilester.h"
#include "sprite/npc/BattleBow.h"

typedef struct StarPowerEntry {
    /* 0x04 */ void* dmaStart;
    /* 0x08 */ void* dmaEnd;
    /* 0x0C */ void* dmaDest;
    /* 0x10 */ Bytecode* init;
} StarPowerEntry; // size = 0x14

extern EvtScript battle_star_power_focus_usePower;
extern EvtScript battle_star_power_refresh_usePower;
extern EvtScript battle_star_power_lullaby_usePower;
extern EvtScript battle_star_power_star_storm_usePower;
extern EvtScript battle_star_power_chill_out_usePower;
extern EvtScript battle_star_power_smooch_usePower;
extern EvtScript battle_star_power_time_out_usePower;
extern EvtScript battle_star_power_up_and_away_usePower;
extern EvtScript battle_star_power_star_beam_usePower;
extern EvtScript battle_star_power_peach_beam_usePower;
extern EvtScript battle_star_power_peach_focus_usePower;
extern EvtScript battle_star_power_peach_dash_usePower;

#define STAR_POWER(name) \
{ \
    .dmaStart = battle_star_power_##name##_ROM_START, \
    .dmaEnd   = battle_star_power_##name##_ROM_END, \
    .dmaDest  = battle_star_power_##name##_VRAM, \
    .init     = battle_star_power_##name##_usePower, \
}

StarPowerEntry StarPowersTable[] = {
    STAR_POWER(focus),
    STAR_POWER(refresh),
    STAR_POWER(lullaby),
    STAR_POWER(star_storm),
    STAR_POWER(chill_out),
    STAR_POWER(smooch),
    STAR_POWER(time_out),
    STAR_POWER(up_and_away),
    STAR_POWER(star_beam),
    STAR_POWER(peach_beam),
    STAR_POWER(peach_focus),
    STAR_POWER(peach_dash),
};

s32 D_8029C890[][5] = {
    [PARTNER_NONE] {
        ANIM_Mario_GotItem,
        ANIM_Mario_AnimPray,
        ANIM_Mario_1002A,
        ANIM_Mario_Running,
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
    dma_copy((&StarPowersTable[starPowerIdx])->dmaStart,
             (&StarPowersTable[starPowerIdx])->dmaEnd,
             (&StarPowersTable[starPowerIdx])->dmaDest);
    script->varTable[0] = (s32) (&StarPowersTable[starPowerIdx])->init;
    return ApiStatus_DONE2;
}

MATCHING_BSS(0x1390);
