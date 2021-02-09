#include "common.h"
#include "ld_addrs.h"
#include "partners.h"
#include "map.h"

#include "partner/goombario.h"
#include "sprite/npc/world_goombario.h"

#include "partner/kooper.h"
#include "sprite/npc/world_kooper.h"

#include "sprite/npc/world_bombette.h"

#include "sprite/npc/world_parakarry.h"

#include "partner/goompa.h"
#include "sprite/npc/goompa.h"

#include "sprite/npc/world_watt.h"

#include "sprite/npc/world_sushie.h"

#include "sprite/npc/world_lakilester.h"

#include "sprite/npc/world_bow.h"

#include "partner/goombaria.h"
#include "sprite/npc/goombaria.h"

#include "partner/twink.h"
#include "sprite/npc/twink.h"

s32 world_partner_can_use_ability_default(Npc* partner);
s32 world_partner_can_player_pause_default(Npc* partner);

// Partner icons
s32 D_800F7F00[] = {
    0x80107CA8, 0x80107CF8, 0x80107D48, 0x80107D98, 0x80107DE8, 0x80107CA8, 0x80107E88, 0x80107ED8, 0x80107F28, 0x80107E38, 0x80107FC8, 0x80107FC8, 0x80107FC8, 0x80107FC8, 0x80107FC8, 0x80107FC8,
};
s32 D_800F7F40[] = {
    0x80107CD0, 0x80107D20, 0x80107D70, 0x80107DC0, 0x80107E10, 0x80107CD0, 0x80107EB0, 0x80107F00, 0x80107F50, 0x80107E60, 0x80107FF0, 0x80107FF0, 0x80107FF0, 0x80107FF0, 0x80107FF0, 0x80107FF0,
};
s32 D_800F7F80[] = {
    0x801080B8, 0x801080E0, 0x80108108, 0x80108130, 0x80108158, 0x80108180, 0x801081A8, 0x801081D0, 0x801081F8, 0x80108220,
};
s32* D_800F7FA8 = &D_80108068;
s32 D_800F7FAC = 0x80108090;
s32 D_800F7FB0[] = { 0x80108298, 0x801082E8, 0x801082C0, 0x80108310, 0x80108338, 0x80108360, 0x80108388 };
s32 D_800F7FCC[] = { (s32)&D_801083D8, 0x80108428, 0x80108400, 0x80108450, 0x80108478, 0x801084A0, 0x801084C8 };

s32 D_800F7FE8 = -1;
s32 D_800F7FEC = 1;
s32 D_800F7FF0 = 2;
s32 D_800F7FF4 = 4;
s32 D_800F7FF8 = 5;
s32 D_800F7FFC = 7;
s32 D_800F8000[] = { 8, 0, 0, 0 };
s32 D_800F8010[] = { 0x003251D0, 0x00325AD0, 0x802C05CC, 0x00000000 };
s32 D_800F8020 = 0;
f32 D_800F8024 = 0.0f;
f32 D_800F8028 = 0.0f;
s32 D_800F802C = 0;
f32 D_800F8030 = 0.0f;
s8 D_800F8034[] = { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 };
s16 D_800F803A = 0;

WorldPartner wPartners[12] = {
    {}, // None
    {
        // Goombario
        .dmaStart = &world_partner_goombario_ROM_START,
        .dmaEnd = &world_partner_goombario_ROM_END,
        .dmaDest = &world_partner_goombario_VRAM,
        .isFlying = FALSE,
        .init = world_goombario_init,
        .takeOut = world_goombario_take_out,
        .update = world_goombario_update,
        .useAbility = world_goombario_use_ability,
        .putAway = world_goombario_put_away,
        .idle = NPC_ANIM(world_goombario, normal, idle),
        .canUseAbility = world_goombario_can_pause,
        .canPlayerPause = world_goombario_can_pause,
        .preBattle = world_goombario_pre_battle,
    },
    {
        // Kooper
        .dmaStart = &world_partner_kooper_ROM_START,
        .dmaEnd = &world_partner_kooper_ROM_END,
        .dmaDest = &world_partner_kooper_VRAM,
        .isFlying = FALSE,
        .init = 0x802BD200,
        .takeOut = 0x802BEB44,
        .update = 0x802BEB64,
        .useAbility = 0x802BEB80,
        .putAway = 0x802BEB9C,
        .idle = NPC_ANIM(world_kooper, normal, idle),
        .testFirstStrike = 0x802BE818,
        .canUseAbility = world_partner_can_use_ability_default,
        .canPlayerPause = world_partner_can_use_ability_default,
        .preBattle = 0x802BEA24,
        .postBattle = 0x802BEB10,
    },
    {
        // Bombette
        .dmaStart = &world_partner_bombette_ROM_START,
        .dmaEnd = &world_partner_bombette_ROM_END,
        .dmaDest = &world_partner_bombette_VRAM,
        .isFlying = FALSE,
        .init = 0x802BD2D8,
        .takeOut = 0x802BE880,
        .update = 0x802BE8A0,
        .useAbility = 0x802BE8BC,
        .putAway = 0x802BE8D8,
        .idle = NPC_ANIM(world_bombette, normal, idle),
        .testFirstStrike = 0x802BE520,
        .canUseAbility = 0x802BD720,
        .canPlayerPause = 0x802BD748,
        .preBattle = 0x802BE6E8,
    },
    {
        // Parakarry
        .dmaStart = &world_partner_parakarry_ROM_START,
        .dmaEnd = &world_partner_parakarry_ROM_END,
        .dmaDest = &world_partner_parakarry_VRAM,
        .isFlying = TRUE,
        .init = 0x802BD100,
        .takeOut = 0x802BEA90,
        .update = 0x802BEAB0,
        .useAbility = 0x802BEACC,
        .putAway = 0x802BEAE8,
        .idle = NPC_ANIM(world_parakarry, Palette_00, Anim_1),
        .canPlayerPause = world_partner_can_use_ability_default,
        .preBattle = 0x802BE90C,
        .postBattle = 0x802BE9D0,
    },
    {
        // Goompa
        .dmaStart = &world_partner_goompa_ROM_START,
        .dmaEnd = &world_partner_goompa_ROM_END,
        .dmaDest = &world_partner_goompa_VRAM,
        .isFlying = FALSE,
        .init = world_goompa_init,
        .takeOut = world_goompa_take_out,
        .update = world_goompa_update,
        .useAbility = world_goompa_use_ability,
        .putAway = world_goompa_put_away,
        .idle = NPC_ANIM(goompa, Palette_00, Anim_1),
    },
    {
        // Watt
        .dmaStart = &world_partner_watt_ROM_START,
        .dmaEnd = &world_partner_watt_ROM_END,
        .dmaDest = &world_partner_watt_VRAM,
        .isFlying = TRUE,
        .init = 0x802BD23C,
        .takeOut = 0x802BE258,
        .update = 0x802BE27C,
        .useAbility = 0x802BE298,
        .putAway = 0x802BE2B4,
        .idle = NPC_ANIM(world_watt, Palette_00, Anim_1),
        .canPlayerPause = world_partner_can_player_pause_default,
        .preBattle = 0x802BDD9C,
        .postBattle = 0x802BDE10,
        .whileRiding = 0x802BE2D0,
    },
    {
        // Sushie
        .dmaStart = &world_partner_sushie_ROM_START,
        .dmaEnd = &world_partner_sushie_ROM_END,
        .dmaDest = &world_partner_sushie_VRAM,
        .isFlying = FALSE,
        .init = 0x802BF520,
        .takeOut = 0x802BFDDC,
        .update = 0x802BFDFC,
        .useAbility = 0x802BFDC0,
        .putAway = 0x802BFE18,
        .idle = NPC_ANIM(world_sushie, Palette_00, Anim_1),
        .canPlayerPause = world_partner_can_player_pause_default,
        .preBattle = 0x802BF9B8,
        .postBattle = 0x802BFA58,
        .whileRiding = 0x802BFE34,
    },
    {
        // Lakilester
        .dmaStart = &world_partner_lakilester_ROM_START,
        .dmaEnd = &world_partner_lakilester_ROM_END,
        .dmaDest = &world_partner_lakilester_VRAM,
        .isFlying = TRUE,
        .init = 0x802BD21C,
        .takeOut = 0x802BFE60,
        .update = 0x802BFE80,
        .useAbility = 0x802BFE9C,
        .putAway = 0x802BFEB8,
        .idle = NPC_ANIM(world_lakilester, Palette_00, Anim_1),
        .canPlayerPause = world_partner_can_player_pause_default,
        .preBattle = 0x802BFA00,
        .postBattle = 0x802BFAA8,
        .whileRiding = 0x802BFED4,
    },
    {
        // Bow
        .dmaStart = &world_partner_bow_ROM_START,
        .dmaEnd = &world_partner_bow_ROM_END,
        .dmaDest = &world_partner_bow_VRAM,
        .isFlying = TRUE,
        .init = 0x802BD100,
        .takeOut = 0x802BDFE0,
        .update = 0x802BE000,
        .useAbility = 0x802BE01C,
        .putAway = 0x802BE038,
        .idle = NPC_ANIM(world_bow, Palette_00, Anim_1),
        .canUseAbility = world_partner_can_use_ability_default,
        .canPlayerPause = world_partner_can_player_pause_default,
        .preBattle = 0x802BDF64,
    },
    {
        // Goombaria
        .dmaStart = &world_partner_goombaria_ROM_START,
        .dmaEnd = &world_partner_goombaria_ROM_END,
        .dmaDest = &world_partner_goombaria_VRAM,
        .isFlying = FALSE,
        .init = world_goombaria_init,
        .takeOut = world_goombaria_take_out,
        .update = world_goombaria_update,
        .useAbility = world_goombaria_use_ability,
        .putAway = world_goombaria_put_away,
        .idle = NPC_ANIM(goombaria, Palette_00, Anim_1),
        .canUseAbility = world_partner_can_use_ability_default,
        .canPlayerPause = world_partner_can_use_ability_default,
    },
    {
        // Twink
        .dmaStart = &world_partner_twink_ROM_START,
        .dmaEnd = &world_partner_twink_ROM_END,
        .dmaDest = &world_partner_twink_VRAM,
        .isFlying = TRUE,
        .init = world_twink_init,
        .takeOut = world_twink_take_out,
        .update = world_twink_update,
        .useAbility = world_twink_use_ability,
        .putAway = world_twink_put_away,
        .idle = NPC_ANIM(twink, Palette_00, Anim_1),
        .canUseAbility = world_partner_can_use_ability_default,
        .canPlayerPause = world_partner_can_use_ability_default,
    },
};


NpcId create_basic_npc(NpcBlueprint* blueprint);

INCLUDE_ASM(s32, "code_838b0_len_5900", use_consumable);

void remove_consumable(void) {
    gPlayerData.invItems[D_8010CD20] = 0;
    sort_items();
}

INCLUDE_ASM(s32, "code_838b0_len_5900", func_800EA4B0);

s32 world_partner_can_use_ability_default(Npc* partner) {
    return D_8010EBB0[0] == 0;
}

s32 world_partner_can_player_pause_default(Npc* partner) {
    return TRUE;
}

INCLUDE_ASM(s32, "code_838b0_len_5900", func_800EA52C);

INCLUDE_ASM(s32, "code_838b0_len_5900", is_current_partner_flying, void);

INCLUDE_ASM(s32, "code_838b0_len_5900", func_800EA5B8);

void load_partner_npc(void) {
    WorldPartner* partnerEntry = &wPartners[D_8010CFD8];
    Npc** partnerNpcPtr = &D_8010C930;
    WorldPartner** partner = &D_8010CFEC;
    NpcId npcIndex;
    NpcBlueprint blueprint;
    NpcBlueprint* blueprintPtr;

    *partner = partnerEntry;
    blueprintPtr = &blueprint;
    dma_copy(partnerEntry->dmaStart, partnerEntry->dmaEnd, partnerEntry->dmaDest);

    blueprint.flags = 0x4000100;
    blueprint.initialAnim = (*partner)->idle;
    blueprint.onUpdate = NULL;
    blueprint.onRender = NULL;
    D_8010CFD0 = npcIndex = create_basic_npc(blueprintPtr);

    *partnerNpcPtr = get_npc_by_index(npcIndex);

    {
        Npc* npc = *partnerNpcPtr;
        npc->npcID = NpcId_PARTNER;
        npc->collisionRadius = 10;
        npc->collisionHeight = 10;
    }

    {
        Npc* npc = *partnerNpcPtr;
        npc->pos.x = 0.0f;
        npc->pos.y = -1000.0f;
        npc->pos.z = 0.0f;
        npc->scale.x = 0.0f;
        npc->scale.y = 0.0f;
        npc->scale.z = 0.0f;
    }

    D_8010C954 = 0;
}

INCLUDE_ASM(s32, "code_838b0_len_5900", func_800EA6A8);

INCLUDE_ASM(s32, "code_838b0_len_5900", _use_partner_ability);

INCLUDE_ASM(s32, "code_838b0_len_5900", func_800EB168, s32 arg0);

INCLUDE_ASM(s32, "code_838b0_len_5900", func_800EB200);

INCLUDE_ASM(s32, "code_838b0_len_5900", func_800EB2A4);

INCLUDE_ASM(s32, "code_838b0_len_5900", partner_use_ability);

INCLUDE_ASM(s32, "code_838b0_len_5900", partner_player_can_pause);

INCLUDE_ASM(s32, "code_838b0_len_5900", partner_can_use_ability);

INCLUDE_ASM(s32, "code_838b0_len_5900", partner_reset_data);

INCLUDE_ASM(s32, "code_838b0_len_5900", partner_initialize_data);

INCLUDE_ASM(s32, "code_838b0_len_5900", partner_test_enemy_collision);

INCLUDE_ASM(s32, "code_838b0_len_5900", partner_get_ride_script);

INCLUDE_ASM(s32, "code_838b0_len_5900", partner_handle_before_battle);

INCLUDE_ASM(s32, "code_838b0_len_5900", partner_handle_after_battle);

INCLUDE_ASM(s32, "code_838b0_len_5900", partner_kill_ability_script);

INCLUDE_ASM(s32, "code_838b0_len_5900", partner_suspend_ability_script);

INCLUDE_ASM(s32, "code_838b0_len_5900", partner_resume_ability_script);

INCLUDE_ASM(void, "code_838b0_len_5900", enable_partner_walking, Npc* partner, s32 val);

INCLUDE_ASM(void, "code_838b0_len_5900", func_800EBA3C, Npc* partner);

INCLUDE_ASM(void, "code_838b0_len_5900", func_800EBB40, Npc* partner);

INCLUDE_ASM(s32, "code_838b0_len_5900", func_800EBC74);

INCLUDE_ASM(void, "code_838b0_len_5900", enable_partner_flying, Npc* partner, s32 val);

INCLUDE_ASM(void, "code_838b0_len_5900", update_player_move_history, Npc* partner);

INCLUDE_ASM(void, "code_838b0_len_5900", func_800ED5D0, Npc* partner);

INCLUDE_ASM(s32, "code_838b0_len_5900", func_800ED9F8);

INCLUDE_ASM(s32, "code_838b0_len_5900", func_800EE994);

INCLUDE_ASM(s32, "code_838b0_len_5900", func_800EE9B8);

INCLUDE_ASM(s32, "code_838b0_len_5900", func_800EECC4);

INCLUDE_ASM(s32, "code_838b0_len_5900", func_800EECE8);

INCLUDE_ASM(s32, "code_838b0_len_5900", func_800EF300);

INCLUDE_ASM(s32, "code_838b0_len_5900", func_800EF314);

INCLUDE_ASM(void, "code_838b0_len_5900", enable_partner_ai, void);

INCLUDE_ASM(s32, "code_838b0_len_5900", set_parter_tether_distance, f32 arg0);

INCLUDE_ASM(s32, "code_838b0_len_5900", reset_parter_tether_distance);

INCLUDE_ASM(s32, "code_838b0_len_5900", func_800EF3C0);

INCLUDE_ASM(s32, "code_838b0_len_5900", func_800EF3D4);

INCLUDE_ASM(s32, "code_838b0_len_5900", func_800EF3E4);

INCLUDE_ASM(s32, "code_838b0_len_5900", func_800EF414);

INCLUDE_ASM(s32, "code_838b0_len_5900", func_800EF43C);

INCLUDE_ASM(void, "code_838b0_len_5900", clear_partner_move_history, Npc* partner);

INCLUDE_ASM(s32, "code_838b0_len_5900", func_800EF4E0);

INCLUDE_ASM(s32, "code_838b0_len_5900", func_800EF600);

INCLUDE_ASM(s32, "code_838b0_len_5900", func_800EF628);

INCLUDE_ASM(s32, "code_838b0_len_5900", func_800EF640);

INCLUDE_ASM(s32, "code_838b0_len_5900", func_800EF82C);
