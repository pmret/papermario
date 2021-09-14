#include "common.h"
#include "ld_addrs.h"
#include "partners.h"
#include "map.h"
#include "npc.h"

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

extern f32 D_8010CFC0;
extern s16 D_8010CFC8;
extern s16 D_8010CFCA;
extern s16 D_8010CFCE;
extern s32 D_802C0000;
extern s32 D_8010CFB8;
extern s32 D_8010CFBC;

extern struct struct8015A578* D_8010CD38;

typedef struct struct8010CD38{
    /* 0x00 */ s8 unk_00;
    /* 0x03 */ char unk_01[3];
    /* 0x04 */ Vec3f position;
}struct8010CD38; // size unknown

s32 partner_is_idle(Npc* partner);
s32 world_partner_can_player_pause_default(Npc* partner);
NpcID _create_npc_basic(NpcBlueprint* blueprint);
void _use_partner_ability();

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
s32 D_800F7FCC[] = { (s32) &D_801083D8, 0x80108428, 0x80108400, 0x80108450, 0x80108478, 0x801084A0, 0x801084C8 };

s32 D_800F7FE8 = -1;
s32 D_800F7FEC = 1;
s32 D_800F7FF0 = 2;
s32 D_800F7FF4 = 4;
s32 D_800F7FF8 = 5;
s32 D_800F7FFC = 7;
s32 D_800F8000[] = { 8, 0, 0, 0 };
s32 D_800F8010[] = { _3251D0_ROM_START, _3251D0_ROM_END, (s32) &D_802C05CC, 0x00000000 };
s32 D_800F8020 = 0;
s32 D_800F8024 = 0;
s32 D_800F8028 = 0;
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
        .idle = NPC_ANIM_world_goombario_normal_idle,
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
        .idle = NPC_ANIM_world_kooper_normal_idle,
        .testFirstStrike = 0x802BE818,
        .canUseAbility = partner_is_idle,
        .canPlayerPause = partner_is_idle,
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
        .idle = NPC_ANIM_world_bombette_normal_idle,
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
        .idle = NPC_ANIM_world_parakarry_Palette_00_Anim_1,
        .canPlayerPause = partner_is_idle,
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
        .idle = NPC_ANIM_goompa_Palette_00_Anim_1,
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
        .idle = NPC_ANIM_world_watt_Palette_00_Anim_1,
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
        .idle = NPC_ANIM_world_sushie_Palette_00_Anim_1,
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
        .idle = NPC_ANIM_world_lakilester_Palette_00_Anim_1,
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
        .idle = NPC_ANIM_world_bow_Palette_00_Anim_1,
        .canUseAbility = partner_is_idle,
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
        .idle = NPC_ANIM_goombaria_Palette_00_Anim_1,
        .canUseAbility = partner_is_idle,
        .canPlayerPause = partner_is_idle,
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
        .idle = NPC_ANIM_twink_Palette_00_Anim_1,
        .canUseAbility = partner_is_idle,
        .canPlayerPause = partner_is_idle,
    },
};

f32 D_800F833C = 0;
f32 D_800F8340 = 0;
f32 D_800F8344 = 0;

PartnerAnimations gPartnerAnimations[] = {
    {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
    {0x00010000, 0x00010002, 0x00010004, 0x00010005, 0x00010001, 0x00010001, 0x00010003, 0x00010008, 0x00010007},
    {0x00020000, 0x00020004, 0x00020006, 0x00020007, 0x00020000, 0x00020003, 0x00020005, 0x0002000D, 0x0002000C},
    {0x00030000, 0x00030005, 0x00030009, 0x0003000A, 0x00030000, 0x00030003, 0x00030007, 0x0003000E, 0x0003000D},
    {0x00040000, 0x00040002, 0x00040008, 0x00040002, 0x00040002, 0x00040001, 0x00040003, 0x00040006, 0x00040005},
    {0x009D0000, 0x009D0002, 0x009D0004, 0x009D0005, 0x009D0001, 0x009D0001, 0x009D0003, 0x009D0008, 0x009D0001},
    {0x00060000, 0x00060002, 0x00060002, 0x00060002, 0x00060000, 0x00060001, 0x00060003, 0x00060004, 0x00060007},
    {0x00070000, 0x00070002, 0x00070002, 0x00070002, 0x00070000, 0x00070001, 0x00070003, 0x00070004, 0x00070008},
    {0x00080000, 0x00080005, 0x00080005, 0x00080005, 0x00080000, 0x00080001, 0x00080007, 0x00080009, 0x0008000A},
    {0x00050000, 0x00050002, 0x00050002, 0x00050002, 0x00050000, 0x00050001, 0x00050003, 0x00050004, 0x0005000C},
    {0x009E0000, 0x009E0005, 0x009E0012, 0x009E0013, 0x009E0001, 0x009E0001, 0x009E0007, 0x009E000B, 0x009E0001},
    {0x00200000, 0x00200001, 0x00200001, 0x00200001, 0x00200001, 0x00200001, 0x00200001, 0x00200009, 0x00200020},
};

s32 D_800F84F8 = { 0x00000000, 0x00000000, };

s32 use_consumable(s32 arg0) {
    Evt* script;

    D_8010CD20 = arg0;
    arg0 = gPlayerData.invItems[arg0];
    dma_copy(D_800F8010[0], D_800F8010[1], &D_802C0000);
    script = start_script(D_800F8010[2], 1, 0);
    script->varTable[10] = arg0;
    return script->id;
}

void remove_consumable(void) {
    gPlayerData.invItems[D_8010CD20] = 0;
    sort_items();
}

INCLUDE_ASM(s32, "world/partners", func_800EA4B0);

s32 partner_is_idle(Npc* partner) {
    return gPartnerActionStatus.actionState.b[0] == 0;
}

s32 world_partner_can_player_pause_default(Npc* partner) {
    return TRUE;
}

INCLUDE_ASM(s32, "world/partners", func_800EA52C);

s32 partner_is_flying(void) {
    return !wPartner->isFlying;
}

void func_800EA5B8(s32* arg0) {
    *arg0 &= ~0x2007800;
}

void partner_create_npc(void) {
    WorldPartner* partnerEntry = &wPartners[D_8010CFD8];
    Npc** partnerNpcPtr = &wPartnerNpc;
    WorldPartner** partner = &wPartner;
    NpcID npcIndex;
    NpcBlueprint blueprint;
    NpcBlueprint* blueprintPtr;

    *partner = partnerEntry;
    blueprintPtr = &blueprint;
    dma_copy(partnerEntry->dmaStart, partnerEntry->dmaEnd, partnerEntry->dmaDest);

    blueprint.flags = 0x4000100;
    blueprint.initialAnim = (*partner)->idle;
    blueprint.onUpdate = NULL;
    blueprint.onRender = NULL;
    D_8010CFD0 = npcIndex = _create_npc_basic(blueprintPtr);

    *partnerNpcPtr = get_npc_by_index(npcIndex);

    {
        Npc* npc = *partnerNpcPtr;
        npc->npcID = NPC_PARTNER;
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

void partner_free_npc(void) {
    free_npc_by_index(D_8010CFD0);
}

INCLUDE_ASM(s32, "world/partners", _use_partner_ability);

void switch_to_partner(s32 arg0) {
    PlayerStatus* playerStatus = &gPlayerStatus;

    if (D_8010CFD8 != arg0) {
        D_8010CFE0 = 1;
        D_8010CFE4 = arg0;

        if (D_8010CFD8 != 0 && arg0 != 0) {
            D_8010CFE8 = 3;
        } else if (arg0 == 0) {
            D_8010CFE8 = 4;
        } else {
            D_8010CFE8 = 6;
            D_800F833C = playerStatus->position.x;
            D_800F8340 = playerStatus->position.y;
            D_800F8344 = playerStatus->position.z;
        }
    }
}

void partner_init_after_battle(s32 arg0) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    PartnerActionStatus* actionStatus = &gPartnerActionStatus;

    if (D_8010CFD8 != arg0) {
        D_8010CFE0 = 1;
        D_8010CFE4 = arg0;
        actionStatus->actionState.b[0] = 0;
        actionStatus->actionState.b[1] = 0;

        if (D_8010CFD8 != 0 && arg0 != 0) {
            D_8010CFE8 = 2;
        } else if (arg0 == 0) {
            D_8010CFE8 = 4;
        } else {
            D_8010CFE8 = 6;
            D_800F833C = playerStatus->position.x;
            D_800F8340 = playerStatus->position.y;
            D_800F8344 = playerStatus->position.z;
        }
    }
}

void func_800EB2A4(s32 arg0) {
    if (D_8010CFD8 != arg0) {
        D_8010CFE0 = 1;
        D_8010CFE4 = arg0;

        if (D_8010CFD8 != 0 && arg0 != 0) {
            D_8010CFE8 = 3;
        } else if (arg0 == 0) {
            D_8010CFE8 = 5;
        } else {
            D_8010CFE8 = 7;
        }
    }
}

s32 partner_use_ability(void) {
    PartnerActionStatus* actionStatus = &gPartnerActionStatus;

    if (!is_starting_conversation() &&
        wPartner != NULL &&
        (wPartner->canUseAbility == NULL || wPartner->canUseAbility(wPartnerNpc))) {
        if ((gGameStatusPtr->unk_81 != 0) && (actionStatus->currentButtons & 0x4000)) {
            sfx_play_sound(0x21D);
        } else if (D_8010CFD8 != 0) {
            D_8010CFE0 = 1;
            D_8010CFE8 = 8;
            _use_partner_ability();
            return TRUE;
        }
    }
    return FALSE;
}

s32 partner_player_can_pause(void) {
    if (wPartner != NULL && wPartner->canPlayerPause != NULL && !wPartner->canPlayerPause(wPartnerNpc)) {
        return FALSE;
    }
    return TRUE;
}

s32 partner_can_use_ability(void) {
    if (wPartner->canUseAbility != NULL && !wPartner->canUseAbility(wPartnerNpc)) {
        return TRUE;
    }
    return FALSE;
}

void partner_reset_data(void) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    s32 currentPartner = gPlayerData.currentPartner;

    mem_clear(&gPartnerActionStatus, sizeof(gPartnerActionStatus));
    get_generic_entity(create_generic_entity_frontUI(_use_partner_ability, NULL));

    D_8010CFE0 = 1;
    D_8010CFE8 = 9;
    D_8010CFD8 = currentPartner;

    if (gGameStatusPtr->unk_7D != 0) {
        gPartnerActionStatus.actionState.b[0] = 1;
        gGameStatusPtr->unk_7D = 0;
    }

    wPartner = NULL;
    D_800F833C = playerStatus->position.x;
    D_800F8340 = playerStatus->position.y;
    D_800F8344 = playerStatus->position.z;

    if (D_8010CFD8 == 0) {
        D_8010CFE8 = 1;
    } else {
        partner_create_npc();
        wPartnerNpc->scale.x = 1.0f;
        wPartnerNpc->scale.y = 1.0f;
        wPartnerNpc->scale.z = 1.0f;
        _use_partner_ability();
    }
}

void partner_initialize_data(void) {
    PartnerActionStatus* actionStatus = &gPartnerActionStatus;

    D_8010CFD8 = 0;
    D_8010CFE0 = 0;
    D_8010CFE8 = 0;
    D_8010CFC4 = 0;
    actionStatus->actionState.b[3] = 0;
    actionStatus->inputDisabled = 0;
    actionStatus->actionState.b[1] = 0;
    actionStatus->actionState.b[0] = 0;
    actionStatus->unk_358 = 0;
    actionStatus->actionState.b[2] = 0;
    wPartner = NULL;
    D_800F833C = 0;
    D_800F8340 = 0;
    D_800F8344 = 0;
}

s32 partner_test_enemy_collision(s32 arg0) {
    if (D_8010CFD8 != 0 && wPartner->testFirstStrike != NULL) {
        return wPartner->testFirstStrike(wPartnerNpc, arg0);
    }
    return FALSE;
}

Bytecode* partner_get_ride_script(void) {
    WorldPartner* partner = wPartner;

    if (partner == NULL) {
        return NULL;
    }
    return partner->whileRiding;
}

void partner_handle_before_battle(void) {
    if (D_8010CFD8 != 0) {
        s32* scriptID = &D_8010CFDC;

        if (does_script_exist(*scriptID)) {
            kill_script_by_ID(*scriptID);
        }

        if (wPartner->preBattle != NULL) {
            wPartner->preBattle(wPartnerNpc);
        }
    }
}

void partner_handle_after_battle(void) {
    PartnerActionStatus* actionStatus = &gPartnerActionStatus;
    PlayerData* playerData = &gPlayerData;

    if (D_8010CFD8 != 0) {
        if (does_script_exist(D_8010CFDC) != 0) {
            kill_script_by_ID(D_8010CFDC);
        }

        D_8010CFD4 = start_script(wPartner->update, 20, 0x20);
        D_8010CFD4->owner2.npc = wPartnerNpc;
        D_8010CFDC = D_8010CFD4->id;
        D_8010CFD4->groupFlags = 0xA;

        D_8010CFE8 = 1;

        if (playerData->currentPartner != PARTNER_WATT && actionStatus->actionState.b[3] == 6) {
            gPlayerStatusPtr->animFlags &= ~1;
            gPlayerStatusPtr->animFlags &= ~2;
            actionStatus->actionState.b[3] = 0;
        }

        if (wPartner->postBattle != NULL) {
            wPartner->postBattle(wPartnerNpc);
        }
    }
}

void partner_kill_ability_script(void) {
    s32* scriptID = &D_8010CFDC;
    D_8010CFE8 = 10;

    if (does_script_exist(*scriptID)) {
        kill_script_by_ID(*scriptID);
    }
}

void partner_suspend_ability_script(void) {
    if (D_8010CFD8 != NULL) {
        s32* scriptID = &D_8010CFDC;

        if (does_script_exist(*scriptID)) {
            suspend_all_script(*scriptID);
        }
    }
}

void partner_resume_ability_script(void) {
    if (D_8010CFD8 != NULL) {
        s32* scriptID = &D_8010CFDC;

        if (does_script_exist(*scriptID)) {
            resume_all_script(*scriptID);
        }
    }
}

INCLUDE_ASM(void, "world/partners", partner_walking_enable, Npc* partner, s32 val);

void partner_walking_update_player_tracking(Npc* partner) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    s32 tempCondition;
    struct8010CD38* tempStruct;

    if ((playerStatus->flags & 6) != 0) {
        tempCondition = (playerStatus->actionState == ACTION_STATE_LAND || playerStatus->actionState == ACTION_STATE_STEP_DOWN) ^ 1;
    } else {
        tempCondition = 0;
    }
    tempStruct = (D_8010CFB8 << 2) + &D_8010CD38;
    if (((tempStruct->unk_00 == 0) || (tempCondition == 0)) &&
        ((tempStruct->position.x != playerStatus->position.x) || (tempStruct->position.y != playerStatus->position.y)
        || (tempStruct->position.z != playerStatus->position.z))) {
        if (D_8010CFBC != D_8010CFB8 + 1) {
            if (++D_8010CFB8 >= 0x28) {
                D_8010CFB8 = 0;
            }
            tempStruct = (D_8010CFB8 << 2) + &D_8010CD38;
            tempStruct->position.x = playerStatus->position.x;
            tempStruct->position.y = playerStatus->position.y;
            tempStruct->position.z = playerStatus->position.z;
            tempStruct->unk_00 = tempCondition;
        }
    }
}

void partner_walking_update_motion(Npc* partner) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    PartnerActionStatus* actionStatus = &gPartnerActionStatus;

    if (gGameStatusPtr->unk_81 == 0 || playerStatus->flags & 0x3000 || actionStatus->inputDisabled != 0
        || actionStatus->actionState.b[2] != 0) {
        if (!(playerStatus->animFlags & 0x800)) {
            partner_walking_follow_player(partner);
        }
        if (actionStatus->pressedButtons & 0x6006) {
            actionStatus->actionState.b[2] = 0;
        }
    }

    if (D_8010CFC8 != 50 && fabsf(partner->pos.y - playerStatus->position.y) > 1000.0f) {
        partner->pos.x = playerStatus->position.x;
        partner->pos.y = playerStatus->position.y;
        partner->pos.z = playerStatus->position.z;
        partner->jumpVelocity = 0.0f;
        partner->jumpScale = 0.0f;
        partner->flags = partner->flags & ~0x800;
    }

    partner_do_player_collision(partner);
    D_800F833C = partner->pos.x;
    D_800F8340 = partner->pos.y;
    D_800F8344 = partner->pos.z;
}

INCLUDE_ASM(void, "world/partners", partner_walking_follow_player, Npc* partner);

INCLUDE_ASM(void, "world/partners", partner_flying_enable, Npc* partner, s32 val);

void partner_flying_update_player_tracking(Npc* partner) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    struct8010CD38* tempStruct;
    f32 tempY;
    s32 zero = 0; // TODO fix this as || zero == 0 is always going to be true as is

    tempY = playerStatus->position.y;
    if ((playerStatus->actionState == 23) || (playerStatus->actionState == 21)) {
        tempY = playerStatus->lastGoodPosition.y + partner->collisionHeight + 5;
    }
    tempStruct = (D_8010CFB8 << 2) + &D_8010CD38;
    if ((!tempStruct->unk_00 || zero == 0) && (tempStruct->position.x != playerStatus->position.x || tempStruct->position.y != tempY
                                            || tempStruct->position.z != playerStatus->position.z)) {
        if (D_8010CFBC != D_8010CFB8 + 1) {
            if (++D_8010CFB8 >= 0x28) {
                D_8010CFB8 = 0;
            }
            tempStruct = (D_8010CFB8 << 2) + &D_8010CD38;
            tempStruct->position.x = playerStatus->position.x;
            tempStruct->position.y = tempY;
            tempStruct->position.z = playerStatus->position.z;
            tempStruct->unk_00 = zero;
        }
    }
}

INCLUDE_ASM(void, "world/partners", partner_flying_update_motion, Npc* partner);

INCLUDE_ASM(s32, "world/partners", partner_flying_follow_player);

s32 partner_init_put_away(Npc* arg0) {
    arg0->unk_80 = 0x10000;
    D_8010CFC8 = 0;
    arg0->flags |= 0x100;
    return D_8010CFC8;
}

s32 partner_put_away(Npc* partner) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    f32 tempMoveToY;
    f32 tempMoveToZ;
    f32 tempPosZ;
    f32 tempMoveToX;
    f32 tempPosX;
    f32 tempPosY;
    f32 tempDuration;
    f32 divisor;

    switch (D_8010CFC8){
        case 0:
            tempMoveToX = partner->pos.x;
            tempMoveToY = partner->pos.y;
            tempMoveToZ = partner->pos.z;
            partner->flags &= ~0x200;
            partner->flags &= ~8;
            tempPosX = playerStatus->position.x;
            partner->moveToPos.x = tempPosX;
            tempPosY = playerStatus->position.y + (playerStatus->colliderHeight / 2);
            partner->moveToPos.y = playerStatus->position.y + (playerStatus->colliderHeight / 2);
            tempPosZ = playerStatus->position.z;
            D_800F833C = tempMoveToX;
            D_800F8340 = tempMoveToY;
            D_800F8344 = tempMoveToZ;
            partner->moveSpeed = 4.0f;
            partner->jumpScale = 1.6f;
            partner->moveToPos.z = tempPosZ;
            partner->planarFlyDist = dist2D(tempMoveToX, tempMoveToZ, tempPosX, tempPosZ);
            partner->yaw = atan2(tempMoveToX, tempMoveToZ, tempPosX, tempPosZ);
            partner->duration = 0xF;
            divisor = 15.0f;
            partner->moveSpeed = partner->planarFlyDist / divisor;
            tempMoveToY = tempPosY - tempMoveToY;
            partner->jumpVelocity = (tempMoveToY + partner->jumpScale * partner->duration * partner->duration * 0.5f) / partner->duration;
            partner->currentAnim.w = gPartnerAnimations[D_8010CFD8].anims[2];
            enable_npc_blur(partner);
            D_8010CFC8 = 1;
            break;
        case 1:
            partner->jumpVelocity -= partner->jumpScale;
            partner->pos.y += partner->jumpVelocity;
            if (partner->jumpVelocity <= 0.0f) {
                partner->currentAnim.w = gPartnerAnimations[D_8010CFD8].anims[3];
            }
            npc_move_heading(partner, partner->moveSpeed, partner->yaw);
            tempDuration = partner->duration;
            if (partner->duration > 10.0f) {
                tempDuration = 10.0f;
            }
            partner->scale.x = tempDuration / 10.0f;
            partner->scale.y = partner->scale.x;
            partner->scale.z = partner->scale.x;
            partner->duration--;
            if (partner->duration >> 0x10 != 0) {
                D_8010CFC8 = 2;
            }
            break;
        case 2:
            partner->currentAnim.w = gPartnerAnimations[D_8010CFD8].anims[4];
            partner->jumpVelocity = 0.0f;
            partner->pos.y = partner->moveToPos.y;
            disable_npc_blur(partner);
            return 1;
    }
    return 0;
}

s32 partner_init_get_out(Npc* arg0) {
    arg0->unk_80 = 0x10000;
    D_8010CFC8 = 0;
    arg0->flags |= 0x100;
    return D_8010CFC8;
}

INCLUDE_ASM(s32, "world/partners", partner_get_out);

void func_800EF300(void) {
    D_8010CFC8 = 40;
}

void func_800EF314(void) {
    D_8010CFC8 = 50;
}

void enable_partner_ai(void) {
    D_8010CFC8 = 0;
    partner_clear_player_tracking(wPartnerNpc);

    if (!wPartner->isFlying) {
        partner_walking_enable(wPartnerNpc, FALSE);
    } else {
        partner_flying_enable(wPartnerNpc, FALSE);
    }
}

void partner_set_tether_distance(f32 arg0) {
    D_8010CFC0 = arg0;
}

void repartner_set_tether_distance(void) {
    D_8010CFC0 = 40.0f;
}

void partner_set_goal_pos(s32 arg0, s32 arg1) {
    D_800F8024 = arg0;
    D_800F8028 = arg1;
}

void func_800EF3D4(s16 arg0) {
    D_8010CFCA = arg0;
}

void func_800EF3E4(void) {
    D_8010CFC8 = 15;
    D_8010CFCA = 0;
    D_800F802C = 10;
    D_8010CFCE = 0;
}

void func_800EF414(s32 arg0, s32 arg1) {
    partner_set_goal_pos(arg0, arg1);
    D_8010CFC8 = 20;
}

void func_800EF43C(void) {
    D_8010CFC8 = 0;
    D_8010CFCA = 0;
    D_8010CFCE = 0;
}

INCLUDE_ASM(void, "world/partners", partner_clear_player_tracking, Npc* partner);

s32 func_800EF4E0(void) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    Camera* cameras = &gCameras;
    s32 ret;

    if (playerStatus->unk_90 == 0.0f) {
        if (!(playerStatus->spriteFacingAngle >= 90.0f) || !(playerStatus->spriteFacingAngle < 270.0f)) {
            ret = 1;
            playerStatus->targetYaw = clamp_angle(cameras[0].currentYaw - 90.0f);
        } else {
            playerStatus->targetYaw = clamp_angle(cameras[0].currentYaw + 90.0f);
            ret = 0;
        }
    } else if (get_clamped_angle_diff(cameras[0].currentYaw, playerStatus->targetYaw) < 0.0f) {
        ret = 1;
        playerStatus->targetYaw = clamp_angle(cameras[0].currentYaw - 90.0f);
    } else {
        ret = 0;
        playerStatus->targetYaw = clamp_angle(cameras[0].currentYaw + 90.0f);
    }

    playerStatus->currentYaw = playerStatus->targetYaw;
    return ret;
}

void partner_enable_input(void) {
    PartnerActionStatus* actionStatus = &gPartnerActionStatus;

    actionStatus->inputDisabled--;
    if (actionStatus->inputDisabled < 0) {
        actionStatus->inputDisabled = 0;
    }
}

void partner_disable_input(void) {
    PartnerActionStatus* actionStatus = &gPartnerActionStatus;

    actionStatus->inputDisabled++;
}

void partner_do_player_collision(Npc* partner) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    f32 sp28;
    f32 sp2C;
    f32 sp30;
    f32 sp34;
    f32 sp38;
    f32 sp3C;
    f32 sp40;

    transform_point(gCameras->perspectiveMatrix, playerStatus->position.x, playerStatus->position.y, playerStatus->position.z, 1.0f, &sp28, &sp2C, &sp30, &sp34);
    transform_point(gCameras->perspectiveMatrix, partner->pos.x, partner->pos.y, partner->pos.z, 1.0f, &sp38, &sp3C, &sp40, &sp34);
    sp28 = fabsf(sp28 - sp38);
    sp2C = fabsf(sp2C - sp3C);
    sp30 = fabsf(sp30 - sp40);
    if (sp28 <= (partner->collisionRadius + playerStatus->colliderDiameter) * 0.9f && sp2C <= partner->collisionHeight + playerStatus->colliderHeight && sp30 <= 4.0) {
        npc_move_heading(partner, 1.0f, atan2(playerStatus->position.x, playerStatus->position.z, partner->pos.x, partner->pos.z));
        add_vec2D_polar(&partner->pos.x, &partner->pos.z, 2.0f, gCameras[gCurrentCameraID].currentYaw);
    }
}

INCLUDE_ASM(s32, "world/partners", partner_move_to_goal);
