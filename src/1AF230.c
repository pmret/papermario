#include "common.h"
#include "ld_addrs.h"
#include "sprite/npc/battle_goombario.h"
#include "sprite/npc/battle_kooper.h"
#include "sprite/npc/battle_bombette.h"
#include "sprite/npc/battle_parakarry.h"
#include "sprite/npc/battle_watt.h"
#include "sprite/npc/battle_sushie.h"
#include "sprite/npc/battle_lakilester.h"
#include "sprite/npc/battle_bow.h"

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
    { 0x1001F,                                      0x1002C,                                      0x1002A,                                      0x10005,                                      0, }, // Junk? These IDs should be in world_goombario, but don't exist.
    { NPC_ANIM_battle_goombario_default_run,        NPC_ANIM_battle_goombario_default_sleep,      NPC_ANIM_battle_goombario_default_sleep,      NPC_ANIM_battle_goombario_default_run,        NPC_ANIM_battle_goombario_default_idle, },
    { NPC_ANIM_battle_kooper_Palette_00_Anim_6,     NPC_ANIM_battle_kooper_Palette_00_Anim_1B,    NPC_ANIM_battle_kooper_Palette_00_Anim_1B,    NPC_ANIM_battle_kooper_Palette_00_Anim_6,     NPC_ANIM_battle_kooper_Palette_00_Anim_4, },
    { NPC_ANIM_battle_bombette_Palette_00_Anim_8,   NPC_ANIM_battle_bombette_Palette_00_Anim_1D,  NPC_ANIM_battle_bombette_Palette_00_Anim_1D,  NPC_ANIM_battle_bombette_Palette_00_Anim_8,   NPC_ANIM_battle_bombette_Palette_00_Anim_4, },
    { NPC_ANIM_battle_parakarry_Palette_00_Anim_3,  NPC_ANIM_battle_parakarry_Palette_00_Anim_18, NPC_ANIM_battle_parakarry_Palette_00_Anim_18, NPC_ANIM_battle_parakarry_Palette_00_Anim_3,  NPC_ANIM_battle_parakarry_Palette_00_Anim_1, },
    {}, // Goompa
    { NPC_ANIM_battle_watt_Palette_00_Anim_3,       NPC_ANIM_battle_watt_Palette_00_Anim_A,       NPC_ANIM_battle_watt_Palette_00_Anim_A,       NPC_ANIM_battle_watt_Palette_00_Anim_3,       NPC_ANIM_battle_parakarry_Palette_00_Anim_1, },
    { NPC_ANIM_battle_sushie_Palette_00_Anim_3,     NPC_ANIM_battle_sushie_Palette_00_Anim_13,    NPC_ANIM_battle_sushie_Palette_00_Anim_13,    NPC_ANIM_battle_sushie_Palette_00_Anim_3,     NPC_ANIM_battle_sushie_Palette_00_Anim_1, },
    { NPC_ANIM_battle_lakilester_Palette_00_Anim_3, NPC_ANIM_battle_lakilester_Palette_00_Anim_9, NPC_ANIM_battle_lakilester_Palette_00_Anim_9, NPC_ANIM_battle_lakilester_Palette_00_Anim_3, NPC_ANIM_battle_lakilester_Palette_00_Anim_1, },
    { NPC_ANIM_battle_bow_Palette_00_Anim_3,        NPC_ANIM_battle_bow_Palette_00_Anim_13,       NPC_ANIM_battle_bow_Palette_00_Anim_13,       NPC_ANIM_battle_bow_Palette_00_Anim_3,        NPC_ANIM_battle_bow_Palette_00_Anim_1, },
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
