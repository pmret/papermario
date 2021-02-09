#include "common.h"
#include "map.h"
#include "world/partners.h"

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
    WorldPartner* partnerEntry = &D_800F803C[D_8010CFD8];
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
