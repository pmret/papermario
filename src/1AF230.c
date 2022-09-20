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

extern EvtScript battle_star_focus_usePower;
extern EvtScript battle_star_refresh_usePower;
extern EvtScript battle_star_lullaby_usePower;
extern EvtScript battle_star_star_storm_usePower;
extern EvtScript battle_star_chill_out_usePower;
extern EvtScript battle_star_smooch_usePower;
extern EvtScript battle_star_time_out_usePower;
extern EvtScript battle_star_up_and_away_usePower;
extern EvtScript battle_star_star_beam_usePower;
extern EvtScript battle_star_peach_beam_usePower;
extern EvtScript battle_star_peach_focus_usePower;
extern EvtScript battle_star_peach_dash_usePower;

StarPowerEntry D_8029C7D0[] = {
    { battle_star_focus_ROM_START,       battle_star_focus_ROM_END,       battle_star_focus_VRAM,       battle_star_focus_usePower, },
    { battle_star_refresh_ROM_START,     battle_star_refresh_ROM_END,     battle_star_refresh_VRAM,     battle_star_refresh_usePower, },
    { battle_star_lullaby_ROM_START,     battle_star_lullaby_ROM_END,     battle_star_lullaby_VRAM,     battle_star_lullaby_usePower, },
    { battle_star_star_storm_ROM_START,  battle_star_star_storm_ROM_END,  battle_star_star_storm_VRAM,  battle_star_star_storm_usePower, },
    { battle_star_chill_out_ROM_START,   battle_star_chill_out_ROM_END,   battle_star_chill_out_VRAM,   battle_star_chill_out_usePower, },
    { battle_star_smooch_ROM_START,      battle_star_smooch_ROM_END,      battle_star_smooch_VRAM,      battle_star_smooch_usePower, },
    { battle_star_time_out_ROM_START,    battle_star_time_out_ROM_END,    battle_star_time_out_VRAM,    battle_star_time_out_usePower, },
    { battle_star_up_and_away_ROM_START, battle_star_up_and_away_ROM_END, battle_star_up_and_away_VRAM, battle_star_up_and_away_usePower, },
    { battle_star_star_beam_ROM_START,   battle_star_star_beam_ROM_END,   battle_star_star_beam_VRAM,   battle_star_star_beam_usePower, },
    { battle_star_peach_beam_ROM_START,  battle_star_peach_beam_ROM_END,  battle_star_peach_beam_VRAM,  battle_star_peach_beam_usePower, },
    { battle_star_peach_focus_ROM_START, battle_star_peach_focus_ROM_END, battle_star_peach_focus_VRAM, battle_star_peach_focus_usePower, },
    { battle_star_peach_dash_ROM_START,  battle_star_peach_dash_ROM_END,  battle_star_peach_dash_VRAM,  battle_star_peach_dash_usePower, },
};

s32 D_8029C890[10][5] = {
    { SPRITE_ID(SPR_WorldGoombario, 0x1F), SPRITE_ID(SPR_WorldGoombario, 0x2C), SPRITE_ID(SPR_WorldGoombario, 0x2A), SPRITE_ID(SPR_WorldGoombario, 0x5), }, // Junk? These IDs should be in world_goombario, but don't exist.
    { ANIM_BattleGoombario_Run,    ANIM_BattleGoombario_Sleep, ANIM_BattleGoombario_Sleep, ANIM_BattleGoombario_Run,    ANIM_BattleGoombario_Idle, },
    { ANIM_BattleKooper_Anim06,     ANIM_BattleKooper_Anim1B,    ANIM_BattleKooper_Anim1B,    ANIM_BattleKooper_Anim06,     ANIM_BattleKooper_Anim04, },
    { ANIM_BattleBombette_Anim08,   ANIM_BattleBombette_Anim1D,  ANIM_BattleBombette_Anim1D,  ANIM_BattleBombette_Anim08,   ANIM_BattleBombette_Anim04, },
    { ANIM_BattleParakarry_Anim03,  ANIM_BattleParakarry_Anim18, ANIM_BattleParakarry_Anim18, ANIM_BattleParakarry_Anim03,  ANIM_BattleParakarry_Anim01, },
    {}, // Goompa
    { ANIM_BattleWatt_Anim03,       ANIM_BattleWatt_Anim0A,       ANIM_BattleWatt_Anim0A,       ANIM_BattleWatt_Anim03,       ANIM_BattleParakarry_Anim01, },
    { ANIM_BattleSushie_Anim03,     ANIM_BattleSushie_Anim13,    ANIM_BattleSushie_Anim13,    ANIM_BattleSushie_Anim03,     ANIM_BattleSushie_Anim01, },
    { ANIM_BattleLakilester_Anim03, ANIM_BattleLakilester_Anim09, ANIM_BattleLakilester_Anim09, ANIM_BattleLakilester_Anim03, ANIM_BattleLakilester_Anim01, },
    { ANIM_BattleBow_Anim03,        ANIM_BattleBow_Anim13,       ANIM_BattleBow_Anim13,       ANIM_BattleBow_Anim03,        ANIM_BattleBow_Anim01, },
};

ApiStatus LoadStarPowerScript(Evt* script, s32 isInitialCall) {
    BattleStatus* battleStatus = &gBattleStatus;
    PlayerData* playerData = &gPlayerData;
    s16 selectedItemID;

    playerData->specialBarsFilled -= gMoveTable[battleStatus->selectedMoveID].costFP * 256;
    selectedItemID = battleStatus->selectedItemID;
    dma_copy((&D_8029C7D0[selectedItemID])->dmaStart, (&D_8029C7D0[selectedItemID])->dmaEnd,
             (&D_8029C7D0[selectedItemID])->dmaDest);
    script->varTable[0] = (s32) (&D_8029C7D0[selectedItemID])->init;
    return ApiStatus_DONE2;
}
