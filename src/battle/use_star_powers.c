#include "common.h"
#include "ld_addrs.h"
#include "battle.h"
#include "sprite/player.h"

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
extern EvtScript battle_move_peach_focus_alt_EVS_UsePower;

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
    BTL_MOVE(peach_focus_alt, EVS_UsePower),
};

s32 PartnerWishAnims[][5] = {
    [PARTNER_NONE] {
        [PARTNER_WISH_ANIM_WALK]    ANIM_Mario1_UsePower,
        [PARTNER_WISH_ANIM_PRAY]    ANIM_Mario1_Pray,
        [PARTNER_WISH_ANIM_UNUSED]  ANIM_Mario1_LookUp,
        [PARTNER_WISH_ANIM_RETURN]  ANIM_Mario1_Run,
        [PARTNER_WISH_ANIM_IDLE]    0,
    },
    [PARTNER_GOOMBARIO] {
        [PARTNER_WISH_ANIM_WALK]    ANIM_BattleGoombario_Run,
        [PARTNER_WISH_ANIM_PRAY]    ANIM_BattleGoombario_CloseEyes,
        [PARTNER_WISH_ANIM_UNUSED]  ANIM_BattleGoombario_CloseEyes,
        [PARTNER_WISH_ANIM_RETURN]  ANIM_BattleGoombario_Run,
        [PARTNER_WISH_ANIM_IDLE]    ANIM_BattleGoombario_Idle,
    },
    [PARTNER_KOOPER] {
        [PARTNER_WISH_ANIM_WALK]    ANIM_BattleKooper_Run,
        [PARTNER_WISH_ANIM_PRAY]    ANIM_BattleKooper_Pray,
        [PARTNER_WISH_ANIM_UNUSED]  ANIM_BattleKooper_Pray,
        [PARTNER_WISH_ANIM_RETURN]  ANIM_BattleKooper_Run,
        [PARTNER_WISH_ANIM_IDLE]    ANIM_BattleKooper_Idle,
    },
   [PARTNER_BOMBETTE] {
        [PARTNER_WISH_ANIM_WALK]    ANIM_BattleBombette_Run,
        [PARTNER_WISH_ANIM_PRAY]    ANIM_BattleBombette_Sleep,
        [PARTNER_WISH_ANIM_UNUSED]  ANIM_BattleBombette_Sleep,
        [PARTNER_WISH_ANIM_RETURN]  ANIM_BattleBombette_Run,
        [PARTNER_WISH_ANIM_IDLE]    ANIM_BattleBombette_Idle,
    },
    [PARTNER_PARAKARRY] {
        [PARTNER_WISH_ANIM_WALK]    ANIM_BattleParakarry_Run,
        [PARTNER_WISH_ANIM_PRAY]    ANIM_BattleParakarry_Pray,
        [PARTNER_WISH_ANIM_UNUSED]  ANIM_BattleParakarry_Pray,
        [PARTNER_WISH_ANIM_RETURN]  ANIM_BattleParakarry_Run,
        [PARTNER_WISH_ANIM_IDLE]    ANIM_BattleParakarry_Idle,
    },
    [PARTNER_GOOMPA] {
        // no data
    },
    [PARTNER_WATT] {
        [PARTNER_WISH_ANIM_WALK]    ANIM_BattleWatt_Run,
        [PARTNER_WISH_ANIM_PRAY]    ANIM_BattleWatt_Sleep,
        [PARTNER_WISH_ANIM_UNUSED]  ANIM_BattleWatt_Sleep,
        [PARTNER_WISH_ANIM_RETURN]  ANIM_BattleWatt_Run,
        [PARTNER_WISH_ANIM_IDLE]    ANIM_BattleParakarry_Idle, // @bug uses wrong sprite!
    },
    [PARTNER_SUSHIE] {
        [PARTNER_WISH_ANIM_WALK]    ANIM_BattleSushie_Run,
        [PARTNER_WISH_ANIM_PRAY]    ANIM_BattleSushie_Pray,
        [PARTNER_WISH_ANIM_UNUSED]  ANIM_BattleSushie_Pray,
        [PARTNER_WISH_ANIM_RETURN]  ANIM_BattleSushie_Run,
        [PARTNER_WISH_ANIM_IDLE]    ANIM_BattleSushie_Idle,
    },
    [PARTNER_LAKILESTER] {
        [PARTNER_WISH_ANIM_WALK]    ANIM_BattleLakilester_Run,
        [PARTNER_WISH_ANIM_PRAY]    ANIM_BattleLakilester_Pray,
        [PARTNER_WISH_ANIM_UNUSED]  ANIM_BattleLakilester_Pray,
        [PARTNER_WISH_ANIM_RETURN]  ANIM_BattleLakilester_Run,
        [PARTNER_WISH_ANIM_IDLE]    ANIM_BattleLakilester_Idle,
    },
    [PARTNER_BOW] {
        [PARTNER_WISH_ANIM_WALK]    ANIM_BattleBow_Run,
        [PARTNER_WISH_ANIM_PRAY]    ANIM_BattleBow_Pray,
        [PARTNER_WISH_ANIM_UNUSED]  ANIM_BattleBow_Pray,
        [PARTNER_WISH_ANIM_RETURN]  ANIM_BattleBow_Run,
        [PARTNER_WISH_ANIM_IDLE]    ANIM_BattleBow_Idle,
    },
};

API_CALLABLE(LoadStarPowerScript) {
    BattleStatus* battleStatus = &gBattleStatus;
    PlayerData* playerData = &gPlayerData;
    s16 starPowerIdx;

    playerData->starPower -= gMoveTable[battleStatus->selectedMoveID].costFP * SP_PER_BAR;
    starPowerIdx = battleStatus->moveArgument;
    dma_copy((&StarPowersTable[starPowerIdx])->romStart,
             (&StarPowersTable[starPowerIdx])->romEnd,
             (&StarPowersTable[starPowerIdx])->vramStart);
    script->varTable[0] = (s32) (&StarPowersTable[starPowerIdx])->mainScript;
    return ApiStatus_DONE2;
}

MATCHING_BSS(0x1390);
