#include "common_structs.h"
#include "partners.h"
#include "macros.h"

extern s32 D_8010CD20;

// BSS
BSS s32 D_8010CD34;
BSS PlayerPathElement gPlayerMoveHistory[40];
BSS s32 gPlayerMoveHistoryIndex;
BSS s32 D_8010CFBC;
BSS f32 wPartnerTetherDistance;
BSS s32 D_8010CFC4;
BSS s16 D_8010CFC8;
BSS s16 D_8010CFCA;
BSS s16 D_8010CFCC;
BSS s16 D_8010CFCE;
BSS s32 D_8010CFD0;
BSS Evt* wPartnerCurrentScript;
BSS s32 D_8010CFD8;
BSS s32 wPartnerCurrentScriptID;
BSS s32 D_8010CFE0;
BSS s32 D_8010CFE4;
BSS s32 D_8010CFE8;
BSS WorldPartner* wPartner;
BSS s32 D_8010CFF0;
BSS s32 D_8010CFF4;
BSS char D_8010CFF8[0x8];
BSS s32 D_8010D000;
BSS char D_8010D004[0x63C];
BSS s32 D_8010D640;
BSS s32 D_8010D644;
BSS s32 D_8010D648;
BSS s32 D_8010D64C;
BSS s32 D_8010D650;
BSS s8 D_8010D654;
BSS s8 D_8010D655;
BSS s16 D_8010D656;
BSS s16 D_8010D658;
BSS s16 D_8010D65A;
BSS s32 D_8010D65C;
BSS s32 D_8010D660;
BSS s32 D_8010D664;
BSS s32 D_8010D668;
BSS s32 D_8010D66C;
BSS s32 D_8010D670;
BSS s32 D_8010D674;
BSS s32 D_8010D678;
BSS s16 D_8010D67C;
BSS s16 D_8010D67E;
BSS s16 D_8010D680;
BSS s16 D_8010D682;
BSS s16 D_8010D684;
BSS s16 D_8010D686;
BSS s16 D_8010D688;
BSS s16 D_8010D68A;
BSS s16 D_8010D68C;
BSS s8 D_8010D68E;
BSS s8 D_8010D68F;
BSS s8 D_8010D690;
BSS s8 D_8010D691;
BSS s8 D_8010D692;
BSS s8 D_8010D693;
BSS s32 D_8010D694;
BSS s8 D_8010D698;
BSS s8 D_8010D699;
BSS s16 D_8010D69A;
BSS s32 gPopupMenu;
BSS s32 D_8010D6A0;
BSS s32 D_8010D6A4;
BSS char D_8010D6A8[0x8];
BSS char D_8010D6B0[0x1500];
BSS PartnerActionStatus gPartnerActionStatus;
BSS char gSpinHistoryPosY[0x18];
BSS char gSpinHistoryPosX[0x18];
BSS char gSpinHistoryPosZ[0x18];
BSS UiStatus gUIStatus;
BSS PlayerStatus gPlayerStatus;
BSS PlayerSpinState gPlayerSpinState;
BSS s8 D_8010F284[0xC];
BSS PlayerData gPlayerData;
BSS s8 gSpinHistoryPosAngle[0x18];

#include "ld_addrs.h"
#include "npc.h"
#include "hud_element.h"

#include "partner/goombario.h"
#include "sprite/npc/world_goombario.h"

#include "partner/kooper.h"
#include "sprite/npc/world_kooper.h"

#include "partner/bombette.h"
#include "sprite/npc/world_bombette.h"

#include "partner/parakarry.h"
#include "sprite/npc/world_parakarry.h"

#include "partner/goompa.h"
#include "sprite/npc/goompa.h"

#include "partner/watt.h"
#include "sprite/npc/world_watt.h"

#include "partner/sushie.h"
#include "sprite/npc/world_sushie.h"

#include "partner/lakilester.h"
#include "sprite/npc/world_lakilester.h"

#include "partner/bow.h"
#include "sprite/npc/world_bow.h"

#include "partner/goombaria.h"
#include "sprite/npc/goombaria.h"

#include "partner/twink.h"
#include "sprite/npc/twink.h"

extern HudScript HES_Partner0;
extern HudScript HES_Goombario;
extern HudScript HES_Kooper;
extern HudScript HES_Bombette;
extern HudScript HES_Parakarry;
extern HudScript HES_Watt;
extern HudScript HES_Sushie;
extern HudScript HES_Lakilester;
extern HudScript HES_Bow;
extern HudScript HES_PartnerA;
extern HudScript HES_Partner0Disabled;
extern HudScript HES_GoombarioDisabled;
extern HudScript HES_KooperDisabled;
extern HudScript HES_BombetteDisabled;
extern HudScript HES_ParakarryDisabled;
extern HudScript HES_WattDisabled;
extern HudScript HES_SushieDisabled;
extern HudScript HES_LakilesterDisabled;
extern HudScript HES_BowDisabled;
extern HudScript HES_PartnerADisabled;

extern HudScript HES_StatusDigit0;
extern HudScript HES_StatusDigit1;
extern HudScript HES_StatusDigit2;
extern HudScript HES_StatusDigit3;
extern HudScript HES_StatusDigit4;
extern HudScript HES_StatusDigit5;
extern HudScript HES_StatusDigit6;
extern HudScript HES_StatusDigit7;
extern HudScript HES_StatusDigit8;
extern HudScript HES_StatusDigit9;
extern HudScript HES_StatusTimes;
extern HudScript HES_StatusSlash;

extern HudScript HES_StatusStar1;
extern HudScript HES_StatusStar2;
extern HudScript HES_StatusStar3;
extern HudScript HES_StatusStar4;
extern HudScript HES_StatusStar5;
extern HudScript HES_StatusStar6;
extern HudScript HES_StatusStar7;

extern HudScript HES_StatusSPIncrement1;
extern HudScript HES_StatusSPIncrement2;
extern HudScript HES_StatusSPIncrement3;
extern HudScript HES_StatusSPIncrement4;
extern HudScript HES_StatusSPIncrement5;
extern HudScript HES_StatusSPIncrement6;
extern HudScript HES_StatusSPIncrement7;

extern s32 D_802C0000;
extern EvtScript D_802C05CC_32579C;

s32 partner_is_idle(Npc* partner);
s32 world_partner_can_player_pause_default(Npc* partner);
void _use_partner_ability(void);
void partner_flying_follow_player(Npc*);
void partner_move_to_goal(Npc*, s32);

// Partner icons
HudScript* wPartnerHudScripts[] = {
    &HES_Partner0, &HES_Goombario, &HES_Kooper, &HES_Bombette,
    &HES_Parakarry, &HES_Partner0, &HES_Watt, &HES_Sushie,
    &HES_Lakilester, &HES_Bow, &HES_PartnerA, &HES_PartnerA,
    &HES_PartnerA, &HES_PartnerA, &HES_PartnerA, &HES_PartnerA,
};
HudScript* wDisabledPartnerHudScripts[] = {
    &HES_Partner0Disabled, &HES_GoombarioDisabled, &HES_KooperDisabled, &HES_BombetteDisabled,
    &HES_ParakarryDisabled, &HES_Partner0Disabled, &HES_WattDisabled, &HES_SushieDisabled,
    &HES_LakilesterDisabled, &HES_BowDisabled, &HES_PartnerADisabled, &HES_PartnerADisabled,
    &HES_PartnerADisabled, &HES_PartnerADisabled, &HES_PartnerADisabled, &HES_PartnerADisabled,
};
HudScript* DigitHudScripts[] = {
    &HES_StatusDigit0, &HES_StatusDigit1, &HES_StatusDigit2, &HES_StatusDigit3, &HES_StatusDigit4,
    &HES_StatusDigit5, &HES_StatusDigit6, &HES_StatusDigit7, &HES_StatusDigit8, &HES_StatusDigit9,
};
HudScript* TimesHudScript = &HES_StatusTimes;
HudScript* SlashHudScript = &HES_StatusSlash;
HudScript* SPIncrementHudScripts[] = { &HES_StatusSPIncrement1, &HES_StatusSPIncrement3, &HES_StatusSPIncrement2,
    &HES_StatusSPIncrement4, &HES_StatusSPIncrement5, &HES_StatusSPIncrement6, &HES_StatusSPIncrement7 };
HudScript* SPStarHudScripts[] = { &HES_StatusStar1, &HES_StatusStar3, &HES_StatusStar2, &HES_StatusStar4,
    &HES_StatusStar5, &HES_StatusStar6, &HES_StatusStar7 };

s32 D_800F7FE8 = -1;
s32 D_800F7FEC = 1;
s32 D_800F7FF0 = 2;
s32 D_800F7FF4 = 4;
s32 D_800F7FF8 = 5;
s32 D_800F7FFC = 7;
s32 D_800F8000[] = { 8, 0, 0, 0 };
UseItemStruct UseItemDmaArgs = {
    _3251D0_ROM_START,
    _3251D0_ROM_END,
    &D_802C05CC_32579C,
    0
};
s32 D_800F8020 = 0;
s32 wPartnerMoveGoalX = 0;
s32 wPartnerMoveGoalZ = 0;
s32 wPartnerMoveTime = 0;
f32 wPartnerMoveSpeed = 0.0f;
f32 D_800F8034 = 0.0f;
s16 D_800F8038 = 0;
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
        .takeOut = &world_goombario_take_out,
        .update = &world_goombario_update,
        .useAbility = &world_goombario_use_ability,
        .putAway = &world_goombario_put_away,
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
        .init = world_kooper_init,
        .takeOut = &world_kooper_take_out,
        .update = &world_kooper_update,
        .useAbility = &world_kooper_use_ability,
        .putAway = &world_kooper_put_away,
        .idle = NPC_ANIM_world_kooper_normal_idle,
        .testFirstStrike = world_kooper_test_first_strike,
        .canUseAbility = partner_is_idle,
        .canPlayerPause = partner_is_idle,
        .preBattle = world_kooper_pre_battle,
        .postBattle = world_kooper_post_battle,
    },
    {
        // Bombette
        .dmaStart = &world_partner_bombette_ROM_START,
        .dmaEnd = &world_partner_bombette_ROM_END,
        .dmaDest = &world_partner_bombette_VRAM,
        .isFlying = FALSE,
        .init = world_bombette_init,
        .takeOut = &world_bombette_take_out,
        .update = &world_bombette_update,
        .useAbility = &world_bombette_use_ability,
        .putAway = &world_bombette_put_away,
        .idle = NPC_ANIM_world_bombette_normal_idle,
        .testFirstStrike = world_bombette_test_first_strike,
        .canUseAbility = world_bombette_can_use_ability,
        .canPlayerPause = world_bombette_can_player_pause,
        .preBattle = world_bombette_pre_battle,
    },
    {
        // Parakarry
        .dmaStart = &world_partner_parakarry_ROM_START,
        .dmaEnd = &world_partner_parakarry_ROM_END,
        .dmaDest = &world_partner_parakarry_VRAM,
        .isFlying = TRUE,
        .init = world_parakarry_init,
        .takeOut = &world_parakarry_take_out,
        .update = &world_parakarry_update,
        .useAbility = &world_parakarry_use_ability,
        .putAway = &world_parakarry_put_away,
        .idle = NPC_ANIM_world_parakarry_Palette_00_Anim_1,
        .canPlayerPause = partner_is_idle,
        .preBattle = world_parakarry_pre_battle,
        .postBattle = world_parakarry_post_battle,
    },
    {
        // Goompa
        .dmaStart = &world_partner_goompa_ROM_START,
        .dmaEnd = &world_partner_goompa_ROM_END,
        .dmaDest = &world_partner_goompa_VRAM,
        .isFlying = FALSE,
        .init = world_goompa_init,
        .takeOut = &world_goompa_take_out,
        .update = &world_goompa_update,
        .useAbility = &world_goompa_use_ability,
        .putAway = &world_goompa_put_away,
        .idle = NPC_ANIM_goompa_Palette_00_Anim_1,
    },
    {
        // Watt
        .dmaStart = &world_partner_watt_ROM_START,
        .dmaEnd = &world_partner_watt_ROM_END,
        .dmaDest = &world_partner_watt_VRAM,
        .isFlying = TRUE,
        .init = world_watt_init,
        .takeOut = &world_watt_take_out,
        .update = &world_watt_update,
        .useAbility = &world_watt_use_ability,
        .putAway = &world_watt_put_away,
        .idle = NPC_ANIM_world_watt_Palette_00_Anim_1,
        .canPlayerPause = world_partner_can_player_pause_default,
        .preBattle = world_watt_pre_battle,
        .postBattle = world_watt_post_battle,
        .whileRiding = &world_watt_while_riding,
    },
    {
        // Sushie
        .dmaStart = &world_partner_sushie_ROM_START,
        .dmaEnd = &world_partner_sushie_ROM_END,
        .dmaDest = &world_partner_sushie_VRAM,
        .isFlying = FALSE,
        .init = world_sushie_init,
        .takeOut = &world_sushie_take_out,
        .update = &world_sushie_update,
        .useAbility = &world_sushie_use_ability,
        .putAway = &world_sushie_put_away,
        .idle = NPC_ANIM_world_sushie_Palette_00_Anim_1,
        .canPlayerPause = world_partner_can_player_pause_default,
        .preBattle = world_sushie_pre_battle,
        .postBattle = world_sushie_post_battle,
        .whileRiding = &world_sushie_while_riding,
    },
    {
        // Lakilester
        .dmaStart = &world_partner_lakilester_ROM_START,
        .dmaEnd = &world_partner_lakilester_ROM_END,
        .dmaDest = &world_partner_lakilester_VRAM,
        .isFlying = TRUE,
        .init = world_lakilester_init,
        .takeOut = &world_lakilester_take_out,
        .update = &world_lakilester_update,
        .useAbility = &world_lakilester_use_ability,
        .putAway = &world_lakilester_put_away,
        .idle = NPC_ANIM_world_lakilester_Palette_00_Anim_1,
        .canPlayerPause = world_partner_can_player_pause_default,
        .preBattle = world_lakilester_pre_battle,
        .postBattle = world_lakilester_post_battle,
        .whileRiding = &world_lakilester_while_riding,
    },
    {
        // Bow
        .dmaStart = &world_partner_bow_ROM_START,
        .dmaEnd = &world_partner_bow_ROM_END,
        .dmaDest = &world_partner_bow_VRAM,
        .isFlying = TRUE,
        .init = world_bow_init,
        .takeOut = &world_bow_take_out,
        .update = &world_bow_update,
        .useAbility = &world_bow_use_ability,
        .putAway = &world_bow_put_away,
        .idle = NPC_ANIM_world_bow_Palette_00_Anim_1,
        .canUseAbility = partner_is_idle,
        .canPlayerPause = world_partner_can_player_pause_default,
        .preBattle = world_bow_pre_battle,
    },
    {
        // Goombaria
        .dmaStart = &world_partner_goombaria_ROM_START,
        .dmaEnd = &world_partner_goombaria_ROM_END,
        .dmaDest = &world_partner_goombaria_VRAM,
        .isFlying = FALSE,
        .init = world_goombaria_init,
        .takeOut = &world_goombaria_take_out,
        .update = &world_goombaria_update,
        .useAbility = &world_goombaria_use_ability,
        .putAway = &world_goombaria_put_away,
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
        .takeOut = &world_twink_take_out,
        .update = &world_twink_update,
        .useAbility = &world_twink_use_ability,
        .putAway = &world_twink_put_away,
        .idle = NPC_ANIM_twink_Palette_00_Anim_1,
        .canUseAbility = partner_is_idle,
        .canPlayerPause = partner_is_idle,
    },
};

f32 wSavedPartnerPosX = 0;
f32 wSavedPartnerPosY = 0;
f32 wSavedPartnerPosZ = 0;

PartnerAnimations gPartnerAnimations[] = {
    {{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000}},
    {{0x00010000, 0x00010002, 0x00010004, 0x00010005, 0x00010001, 0x00010001, 0x00010003, 0x00010008, 0x00010007}},
    {{0x00020000, 0x00020004, 0x00020006, 0x00020007, 0x00020000, 0x00020003, 0x00020005, 0x0002000D, 0x0002000C}},
    {{0x00030000, 0x00030005, 0x00030009, 0x0003000A, 0x00030000, 0x00030003, 0x00030007, 0x0003000E, 0x0003000D}},
    {{0x00040000, 0x00040002, 0x00040008, 0x00040002, 0x00040002, 0x00040001, 0x00040003, 0x00040006, 0x00040005}},
    {{0x009D0000, 0x009D0002, 0x009D0004, 0x009D0005, 0x009D0001, 0x009D0001, 0x009D0003, 0x009D0008, 0x009D0001}},
    {{0x00060000, 0x00060002, 0x00060002, 0x00060002, 0x00060000, 0x00060001, 0x00060003, 0x00060004, 0x00060007}},
    {{0x00070000, 0x00070002, 0x00070002, 0x00070002, 0x00070000, 0x00070001, 0x00070003, 0x00070004, 0x00070008}},
    {{0x00080000, 0x00080005, 0x00080005, 0x00080005, 0x00080000, 0x00080001, 0x00080007, 0x00080009, 0x0008000A}},
    {{0x00050000, 0x00050002, 0x00050002, 0x00050002, 0x00050000, 0x00050001, 0x00050003, 0x00050004, 0x0005000C}},
    {{0x009E0000, 0x009E0005, 0x009E0012, 0x009E0013, 0x009E0001, 0x009E0001, 0x009E0007, 0x009E000B, 0x009E0001}},
    {{0x00200000, 0x00200001, 0x00200001, 0x00200001, 0x00200001, 0x00200001, 0x00200001, 0x00200009, 0x00200020}},
};

f32 D_800F84F8 = 0.0f;

s32 use_consumable(s32 invSlot) {
    Evt* script;

    D_8010CD20 = invSlot;
    invSlot = gPlayerData.invItems[invSlot];
    dma_copy(UseItemDmaArgs.dmaStart, UseItemDmaArgs.dmaEnd, _3251D0_VRAM);
    script = start_script(UseItemDmaArgs.script, EVT_PRIORITY_1, 0);
    script->varTable[10] = invSlot;
    return script->id;
}

void remove_consumable(void) {
    gPlayerData.invItems[D_8010CD20] = 0;
    sort_items();
}

s32 func_800EA4B0(s32 collisionID) {
    s32 ret = TRUE;

    if (collisionID >= 0) {
        if (collisionID & COLLISION_WITH_ENTITY_BIT) {
            switch (get_entity_type(collisionID)) {
                case ENTITY_TYPE_BLUE_SWITCH:
                case ENTITY_TYPE_RED_SWITCH:
                case ENTITY_TYPE_HUGE_BLUE_SWITCH:
                case ENTITY_TYPE_GREEN_STOMP_SWITCH:
                case ENTITY_TYPE_SIMPLE_SPRING:
                case ENTITY_TYPE_SCRIPT_SPRING:
                case ENTITY_TYPE_CHEST:
                case ENTITY_TYPE_BELLBELL_PLANT:
                case ENTITY_TYPE_TRUMPET_PLANT:
                case ENTITY_TYPE_MUNCHLESIA:
                case ENTITY_TYPE_CYMBAL_PLANT:
                case ENTITY_TYPE_PINK_FLOWER:
                case ENTITY_TYPE_SPINNING_FLOWER:
                case ENTITY_TYPE_3B:
                case ENTITY_TYPE_TWEESTER:
                    ret = FALSE;
                    break;
                default:
                    ret = TRUE;
                    break;
            }
        }
    }
    return ret;
}

s32 partner_is_idle(Npc* partner) {
    return gPartnerActionStatus.partnerActionState == PARTNER_ACTION_NONE;
}

s32 world_partner_can_player_pause_default(Npc* partner) {
    return TRUE;
}

s32 func_800EA52C(s32 arg0) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    u32 playerActionState = playerStatus->actionState;
    s32 ret = FALSE;

    if (playerStatus->flags & PLAYER_STATUS_FLAGS_800) {
        return FALSE;
    }

    if (playerActionState < ACTION_STATE_JUMP) {
        ret = TRUE;
    }

    if (arg0 == 9) {
        if (playerActionState == ACTION_STATE_RIDE) {
            ret = TRUE;
        }
    } else if (arg0 == 4) {
        if ((playerActionState != ACTION_STATE_RIDE) && (playerActionState != ACTION_STATE_IDLE) && (playerActionState != ACTION_STATE_WALK)) {
            if (playerActionState == ACTION_STATE_RUN) {
                ret = TRUE;
            }
        } else {
            ret = TRUE;
        }
    }

    return ret;
}

s32 partner_is_flying(void) {
    return !wPartner->isFlying;
}

void func_800EA5B8(s32* partnerNpcFlags) {
    *partnerNpcFlags &= ~(NPC_FLAG_SIMPLIFIED_PHYSICS | NPC_FLAG_4000 | NPC_FLAG_NO_PROJECT_SHADOW | NPC_FLAG_1000 |
                          NPC_FLAG_JUMPING);
}

void partner_create_npc(void) {
    WorldPartner* partnerEntry = &wPartners[D_8010CFD8];
    Npc** partnerNpcPtr = &wPartnerNpc;
    WorldPartner** partner = &wPartner;
    s32 npcIndex;
    NpcBlueprint blueprint;
    NpcBlueprint* blueprintPtr;

    *partner = partnerEntry;
    blueprintPtr = &blueprint;
    dma_copy(partnerEntry->dmaStart, partnerEntry->dmaEnd, partnerEntry->dmaDest);

    blueprint.flags = NPC_FLAG_PARTICLE | NPC_FLAG_100;
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

    TweesterTouchingPartner = NULL;
}

void partner_free_npc(void) {
    free_npc_by_index(D_8010CFD0);
}

void _use_partner_ability(void) {
    static u32 D_8010CD30; // goes into BSS, needs to be static for the function to match

    PlayerData* playerData = &gPlayerData;
    PartnerActionStatus* partnerActionStatus = &gPartnerActionStatus;
    PlayerStatus* playerStatus = &gPlayerStatus;

    if (!partnerActionStatus->inputDisabled) {
        partnerActionStatus->stickX = gGameStatusPtr->stickX[gGameStatusPtr->multiplayerEnabled];
        partnerActionStatus->stickY = gGameStatusPtr->stickY[gGameStatusPtr->multiplayerEnabled];
        partnerActionStatus->currentButtons = gGameStatusPtr->currentButtons[gGameStatusPtr->multiplayerEnabled];
        partnerActionStatus->pressedButtons = gGameStatusPtr->pressedButtons[gGameStatusPtr->multiplayerEnabled];
        partnerActionStatus->heldButtons = gGameStatusPtr->heldButtons[gGameStatusPtr->multiplayerEnabled];
    } else {
        partnerActionStatus->stickX = 0;
        partnerActionStatus->stickY = 0;
        partnerActionStatus->currentButtons = 0;
        partnerActionStatus->pressedButtons = 0;
        partnerActionStatus->heldButtons = 0;
    }

    if (playerStatus->animFlags & PLAYER_STATUS_ANIM_FLAGS_4) {
        playerStatus->animFlags &= ~PLAYER_STATUS_ANIM_FLAGS_4;
        partnerActionStatus->pressedButtons |= BUTTON_B | BUTTON_C_DOWN;
        playerStatus->animFlags |= PLAYER_STATUS_ANIM_FLAGS_40000000;
    }

    if (D_8010CFE8 != 0) {
        D_8010CD30 = D_8010CFE8;
        D_8010CD34 = 0;
        D_8010CFE8 = 0;
    }

    if (D_8010CD30 >= 2) {
        if (D_8010CD30 != 8) {
            D_8010CFC4 = 0;
        }
    }

    switch (D_8010CD30) {
        case 0:
            break;
        case 3:
            D_8010CFC4 = 3;
            switch (D_8010CD34) {
                case 0:
                    disable_player_input();
                    sfx_play_sound(SOUND_D);
                    kill_script_by_ID(wPartnerCurrentScriptID);
                    wPartnerCurrentScript = start_script(wPartner->putAway, EVT_PRIORITY_14, EVT_FLAG_20);
                    wPartnerCurrentScript->owner2.npc = wPartnerNpc;
                    wPartnerCurrentScriptID = wPartnerCurrentScript->id;
                    wPartnerCurrentScript->groupFlags = EVT_GROUP_08 | EVT_GROUP_02;
                    D_8010CD34 += 1;
                    set_time_freeze_mode(TIME_FREEZE_PARTIAL);
                    break;
                case 1:
                    if (does_script_exist(wPartnerCurrentScriptID)) {
                        break;
                    }
                    set_time_freeze_mode(TIME_FREEZE_NORMAL);
                    partner_free_npc();
                    playerData->currentPartner = D_8010CFD8 = D_8010CFE4;
                    partner_create_npc();
                    sfx_play_sound(SOUND_E);
                    wPartner->init(wPartnerNpc);
                    D_8010CD34 += 1;
                case 2:
                    wPartnerCurrentScript = start_script(wPartner->takeOut, EVT_PRIORITY_14, EVT_FLAG_20);
                    wPartnerCurrentScript->owner2.npc = wPartnerNpc;
                    wPartnerCurrentScriptID = wPartnerCurrentScript->id;
                    wPartnerCurrentScript->groupFlags = EVT_GROUP_08 | EVT_GROUP_02;
                    D_8010CD34 += 1;
                    set_time_freeze_mode(TIME_FREEZE_PARTIAL);
                    break;
                case 3:
                    if (does_script_exist(wPartnerCurrentScriptID)) {
                        break;
                    }
                    wPartnerCurrentScript = start_script(wPartner->update, EVT_PRIORITY_14, EVT_FLAG_20);
                    wPartnerCurrentScript->owner2.npc = wPartnerNpc;
                    wPartnerCurrentScriptID = wPartnerCurrentScript->id;
                    wPartnerCurrentScript->groupFlags = EVT_GROUP_08 | EVT_GROUP_02;
                    D_8010CD30 = 1;
                    enable_player_input();
                    set_time_freeze_mode(TIME_FREEZE_NORMAL);
                    break;
            }
            break;
        case 2:
            D_8010CFC4 = 3;
            switch (D_8010CD34) {
                case 0:
                    kill_script_by_ID(wPartnerCurrentScriptID);
                    D_8010CD34 += 1;
                case 1:
                    partner_free_npc();
                    playerData->currentPartner = D_8010CFD8 = D_8010CFE4;
                    partner_create_npc();
                    wPartnerNpc->pos.x = wSavedPartnerPosX;
                    wPartnerNpc->pos.y = wSavedPartnerPosY;
                    wPartnerNpc->pos.z = wSavedPartnerPosZ;
                    wPartnerNpc->jumpVelocity = 0.0f;
                    wPartnerNpc->scale.x = 1.0f;
                    wPartnerNpc->scale.y = 1.0f;
                    wPartnerNpc->scale.z = 1.0f;
                    wPartner->init(wPartnerNpc);
                    D_8010CD34 += 1;
                case 2:
                    D_8010CD34 += 1;
                    break;
                case 3:
                    wPartnerCurrentScript = start_script(wPartner->update, EVT_PRIORITY_14, EVT_FLAG_20);
                    wPartnerCurrentScript->owner2.npc = wPartnerNpc;
                    wPartnerCurrentScriptID = wPartnerCurrentScript->id;
                    wPartnerCurrentScript->groupFlags = EVT_GROUP_08 | EVT_GROUP_02;
                    D_8010CD30 = 1;
                    break;
            }
            break;
        case 4:
            switch (D_8010CD34) {
                case 0:
                    disable_player_input();
                    sfx_play_sound(SOUND_D);
                    kill_script_by_ID(wPartnerCurrentScriptID);
                    wPartnerCurrentScript = start_script(wPartner->putAway, EVT_PRIORITY_14, EVT_FLAG_20);
                    wPartnerCurrentScript->owner2.npc = wPartnerNpc;
                    wPartnerCurrentScriptID = wPartnerCurrentScript->id;
                    wPartnerCurrentScript->groupFlags = EVT_GROUP_08 | EVT_GROUP_02;
                    D_8010CD34 += 1;
                    break;
                case 1:
                    if (does_script_exist(wPartnerCurrentScriptID)) {
                        break;
                    }
                    partner_free_npc();
                    D_8010CD30 = 1;
                    playerData->currentPartner = D_8010CFD8 = D_8010CFE4;
                    enable_player_input();
                    break;
            }
            break;
        case 5:
            if (D_8010CD34 == 0) {
                kill_script_by_ID(wPartnerCurrentScriptID);
                partner_free_npc();
                D_8010CD30 = 1;
                playerData->currentPartner = D_8010CFD8 = D_8010CFE4;
                break;
            }
            break;
        case 6:
            switch (D_8010CD34) {
                case 0:
                    disable_player_input();
                    playerData->currentPartner = D_8010CFD8 = D_8010CFE4;
                    partner_create_npc();
                    wPartner->init(wPartnerNpc);
                    D_8010CD34 += 1;
                case 1:
                    wPartnerCurrentScript = start_script(wPartner->takeOut, EVT_PRIORITY_14, EVT_FLAG_20);
                    wPartnerCurrentScript->owner2.npc = wPartnerNpc;
                    wPartnerCurrentScriptID = wPartnerCurrentScript->id;
                    wPartnerCurrentScript->groupFlags = EVT_GROUP_08 | EVT_GROUP_02;
                    D_8010CD34 += 1;
                    break;
                case 2:
                    if (does_script_exist(wPartnerCurrentScriptID)) {
                        break;
                    }
                    wPartnerCurrentScript = start_script(wPartner->update, EVT_PRIORITY_14, EVT_FLAG_20);
                    wPartnerCurrentScript->owner2.npc = wPartnerNpc;
                    wPartnerCurrentScriptID = wPartnerCurrentScript->id;
                    wPartnerCurrentScript->groupFlags = EVT_GROUP_08 | EVT_GROUP_02;
                    D_8010CD30 = 1;
                    enable_player_input();
                    break;
            }
            break;
        case 7:
            D_8010CFC4 = 2;
            switch (D_8010CD34) {
                case 0:
                    disable_player_input();
                    playerData->currentPartner = D_8010CFD8 = D_8010CFE4;
                    partner_create_npc();
                    wPartnerNpc->pos.x = wSavedPartnerPosX;
                    wPartnerNpc->pos.y = wSavedPartnerPosY;
                    wPartnerNpc->pos.z = wSavedPartnerPosZ;
                    wPartnerNpc->jumpVelocity = 0.0f;
                    wPartnerNpc->scale.x = 1.0f;
                    wPartnerNpc->scale.y = 1.0f;
                    wPartnerNpc->scale.z = 1.0f;
                    wPartner->init(wPartnerNpc);
                    D_8010CD34 += 1;
                    break;
                case 1:
                    wPartnerCurrentScript = start_script(wPartner->update, EVT_PRIORITY_14, EVT_FLAG_20);
                    wPartnerCurrentScript->owner2.npc = wPartnerNpc;
                    wPartnerCurrentScriptID = wPartnerCurrentScript->id;
                    wPartnerCurrentScript->groupFlags = EVT_GROUP_08 | EVT_GROUP_02;
                    D_8010CD30 = 1;
                    wPartnerNpc->currentAnim.w = gPartnerAnimations[D_8010CFD8].anims[4];
                    enable_player_input();
                    break;
            }
            break;
        case 8:
            switch (D_8010CD34) {
                case 0:
                    kill_script_by_ID(wPartnerCurrentScriptID);
                    wPartnerCurrentScript = start_script(wPartner->useAbility, EVT_PRIORITY_14, EVT_FLAG_20);
                    wPartnerCurrentScript->owner2.npc = wPartnerNpc;
                    wPartnerCurrentScriptID = wPartnerCurrentScript->id;
                    wPartnerCurrentScript->groupFlags = EVT_GROUP_08 | EVT_GROUP_02;
                    D_8010CD34 += 1;
                    break;
                case 1:
                    if (does_script_exist(wPartnerCurrentScriptID)) {
                        break;
                    }
                    wPartnerCurrentScript = start_script(wPartner->update, EVT_PRIORITY_14, EVT_FLAG_20);
                    wPartnerCurrentScript->owner2.npc = wPartnerNpc;
                    wPartnerCurrentScriptID = wPartnerCurrentScript->id;
                    wPartnerCurrentScript->groupFlags = EVT_GROUP_08 | EVT_GROUP_02;
                    D_8010CD30 = 1;
                    break;
            }
            break;
        case 9:
            D_8010CFC4 = 1;
            switch (D_8010CD34) {
                case 0:
                    disable_player_input();
                    wPartner->init(wPartnerNpc);
                    D_8010CD34 += 1;
                case 1:
                    D_8010CD34 += 1;
                    break;
                case 2:
                    if (partnerActionStatus->partnerActionState != 1) {
                        wSavedPartnerPosX = playerStatus->position.x;
                        wSavedPartnerPosY = playerStatus->position.y;
                        wSavedPartnerPosZ = playerStatus->position.z;
                        wPartnerCurrentScript = start_script(wPartner->update, EVT_PRIORITY_14, EVT_FLAG_20);
                        wPartnerCurrentScript->owner2.npc = wPartnerNpc;
                        wPartnerCurrentScriptID = wPartnerCurrentScript->id;
                        wPartnerCurrentScript->groupFlags = EVT_GROUP_08 | EVT_GROUP_02;
                    }
                    enable_player_input();
                    D_8010CD30 = 1;
                    break;
            }
            break;
        case 10:
            if (D_8010CD34 == 0) {
                if (does_script_exist(wPartnerCurrentScriptID)) {
                    kill_script_by_ID(wPartnerCurrentScriptID);
                }
                D_8010CD34 += 1;
            }
            break;
        case 1:
            D_8010CD30 = 0;
            D_8010CFE0 = 0;
            if (D_8010CFC4 != 3) {
                D_8010CFC4 = 0;
            }
            break;
    }
}

static const f32 rodata_padding = 0.0f;

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
            wSavedPartnerPosX = playerStatus->position.x;
            wSavedPartnerPosY = playerStatus->position.y;
            wSavedPartnerPosZ = playerStatus->position.z;
        }
    }
}

void partner_init_after_battle(s32 arg0) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    PartnerActionStatus* actionStatus = &gPartnerActionStatus;

    if (D_8010CFD8 != arg0) {
        D_8010CFE0 = 1;
        D_8010CFE4 = arg0;
        actionStatus->partnerActionState = 0;
        actionStatus->partnerAction_unk_1 = 0;

        if (D_8010CFD8 != 0 && arg0 != 0) {
            D_8010CFE8 = 2;
        } else if (arg0 == 0) {
            D_8010CFE8 = 4;
        } else {
            D_8010CFE8 = 6;
            wSavedPartnerPosX = playerStatus->position.x;
            wSavedPartnerPosY = playerStatus->position.y;
            wSavedPartnerPosZ = playerStatus->position.z;
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
        (wPartner->canUseAbility == NULL || wPartner->canUseAbility(wPartnerNpc)))
    {
        if ((gGameStatusPtr->multiplayerEnabled != 0) && (actionStatus->currentButtons & BUTTON_B)) {
            sfx_play_sound(SOUND_MENU_ERROR);
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

    if (gGameStatusPtr->keepUsingPartnerOnMapChange != 0) {
        gPartnerActionStatus.partnerActionState = 1;
        gGameStatusPtr->keepUsingPartnerOnMapChange = 0;
    }

    wPartner = NULL;
    wSavedPartnerPosX = playerStatus->position.x;
    wSavedPartnerPosY = playerStatus->position.y;
    wSavedPartnerPosZ = playerStatus->position.z;

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
    actionStatus->actingPartner = 0;
    actionStatus->inputDisabled = 0;
    actionStatus->partnerAction_unk_1 = 0;
    actionStatus->partnerActionState = 0;
    actionStatus->unk_358 = 0;
    actionStatus->partnerAction_unk_2 = 0;
    wPartner = NULL;
    wSavedPartnerPosX = 0;
    wSavedPartnerPosY = 0;
    wSavedPartnerPosZ = 0;
}

s32 partner_test_enemy_collision(Npc* enemy) {
    if (D_8010CFD8 != 0 && wPartner->testFirstStrike != NULL) {
        return wPartner->testFirstStrike(wPartnerNpc, enemy);
    }
    return FALSE;
}

EvtScript* partner_get_ride_script(void) {
    WorldPartner* partner = wPartner;

    if (partner == NULL) {
        return NULL;
    }
    return partner->whileRiding;
}

void partner_handle_before_battle(void) {
    if (D_8010CFD8 != 0) {
        s32* scriptID = &wPartnerCurrentScriptID;

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
        if (does_script_exist(wPartnerCurrentScriptID) != 0) {
            kill_script_by_ID(wPartnerCurrentScriptID);
        }

        wPartnerCurrentScript = start_script(wPartner->update, EVT_PRIORITY_14, EVT_FLAG_20);
        wPartnerCurrentScript->owner2.npc = wPartnerNpc;
        wPartnerCurrentScriptID = wPartnerCurrentScript->id;
        wPartnerCurrentScript->groupFlags = EVT_GROUP_08 | EVT_GROUP_02;

        D_8010CFE8 = 1;

        if (playerData->currentPartner != PARTNER_WATT && actionStatus->actingPartner == PARTNER_WATT) {
            gPlayerStatusPtr->animFlags &= ~PLAYER_STATUS_ANIM_FLAGS_HOLDING_WATT;
            gPlayerStatusPtr->animFlags &= ~PLAYER_STATUS_ANIM_FLAGS_2;
            actionStatus->actingPartner = PARTNER_NONE;
        }

        if (wPartner->postBattle != NULL) {
            wPartner->postBattle(wPartnerNpc);
        }
    }
}

void partner_kill_ability_script(void) {
    s32* scriptID = &wPartnerCurrentScriptID;
    D_8010CFE8 = 10;

    if (does_script_exist(*scriptID)) {
        kill_script_by_ID(*scriptID);
    }
}

void partner_suspend_ability_script(void) {
    if (D_8010CFD8 != NULL) {
        s32* scriptID = &wPartnerCurrentScriptID;

        if (does_script_exist(*scriptID)) {
            suspend_all_script(*scriptID);
        }
    }
}

void partner_resume_ability_script(void) {
    if (D_8010CFD8 != NULL) {
        s32* scriptID = &wPartnerCurrentScriptID;

        if (does_script_exist(*scriptID)) {
            resume_all_script(*scriptID);
        }
    }
}

void partner_walking_enable(Npc* partner, s32 val) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    PlayerPathElement* it = gPlayerMoveHistory;
    s32 i;

    partner->pos.x = wSavedPartnerPosX;
    partner->pos.y = wSavedPartnerPosY;
    partner->pos.z = wSavedPartnerPosZ;

    for (i = 0; i < ARRAY_COUNT(gPlayerMoveHistory); i++, it++) {
        it->pos.x = playerStatus->position.x;
        it->pos.y = playerStatus->position.y;
        it->pos.z = playerStatus->position.z;
        it->isJumping = FALSE;
    }

    gPlayerMoveHistoryIndex = 0;
    D_8010CFBC = 0;
    D_8010CFCA = val ? 2 : 0;
    D_8010CFC8 = 0;

    if (D_8010CFC4 == 1 || D_8010CFC4 == 3) {
        D_8010CFC4 = 0;
        D_8010CFCA = 0;
        D_8010CFC8 = 0;
    } else if (D_8010CFC4 == 2) {
        D_8010CFCA = 0;
        D_8010CFC8 = 50;
    }

    D_8010CFCE = 0;
    D_8010CFCC = 0;
    wPartnerMoveTime = 16;
    wPartnerTetherDistance = 40.0f;
    partner->currentAnim.w = gPartnerAnimations[D_8010CFD8].anims[5];
    func_800EA5B8(&partner->flags);
    partner->collisionChannel = 0x10000;
    partner->jumpVelocity = 0.0f;
    partner->flags |= NPC_FLAG_400000 | NPC_FLAG_GRAVITY | NPC_FLAG_100;
    partner->jumpScale = 1.8f;
}

void partner_walking_update_player_tracking(Npc* partner) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    s32 isPlayerJumping;
    PlayerPathElement* currentSnapshot;

    if (playerStatus->flags & (PLAYER_STATUS_FLAGS_FALLING | PLAYER_STATUS_FLAGS_JUMPING)) {
        isPlayerJumping = (playerStatus->actionState == ACTION_STATE_LAND || playerStatus->actionState == ACTION_STATE_STEP_DOWN) ^ 1;
    } else {
        isPlayerJumping = FALSE;
    }
    currentSnapshot = &gPlayerMoveHistory[gPlayerMoveHistoryIndex];
    if ((!currentSnapshot->isJumping || !isPlayerJumping) &&
        ((currentSnapshot->pos.x != playerStatus->position.x) || (currentSnapshot->pos.y != playerStatus->position.y)
        || (currentSnapshot->pos.z != playerStatus->position.z))) {
        if (D_8010CFBC != gPlayerMoveHistoryIndex + 1) {
            if (++gPlayerMoveHistoryIndex >= ARRAY_COUNT(gPlayerMoveHistory)) {
                gPlayerMoveHistoryIndex = 0;
            }
            currentSnapshot = &gPlayerMoveHistory[gPlayerMoveHistoryIndex];
            currentSnapshot->pos.x = playerStatus->position.x;
            currentSnapshot->pos.y = playerStatus->position.y;
            currentSnapshot->pos.z = playerStatus->position.z;
            currentSnapshot->isJumping = isPlayerJumping;
        }
    }
}

void partner_walking_update_motion(Npc* partner) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    PartnerActionStatus* actionStatus = &gPartnerActionStatus;

    if (gGameStatusPtr->multiplayerEnabled == 0 || playerStatus->flags & (PLAYER_STATUS_FLAGS_INPUT_DISABLED | PLAYER_STATUS_FLAGS_1000)
        || actionStatus->inputDisabled != 0 || actionStatus->partnerAction_unk_2 != 0) {
        if (!(playerStatus->animFlags & PLAYER_STATUS_ANIM_FLAGS_800)) {
            partner_walking_follow_player(partner);
        }
        if (actionStatus->pressedButtons & (BUTTON_Z | BUTTON_B | BUTTON_C_LEFT | BUTTON_C_DOWN)) {
            actionStatus->partnerAction_unk_2 = 0;
        }
    }

    if (D_8010CFC8 != 50 && fabsf(partner->pos.y - playerStatus->position.y) > 1000.0f) {
        partner->pos.x = playerStatus->position.x;
        partner->pos.y = playerStatus->position.y;
        partner->pos.z = playerStatus->position.z;
        partner->jumpVelocity = 0.0f;
        partner->jumpScale = 0.0f;
        partner->flags = partner->flags & ~PLAYER_STATUS_ANIM_FLAGS_800;
    }

    partner_do_player_collision(partner);
    wSavedPartnerPosX = partner->pos.x;
    wSavedPartnerPosY = partner->pos.y;
    wSavedPartnerPosZ = partner->pos.z;
}

INCLUDE_ASM(void, "world/partners", partner_walking_follow_player, Npc* partner);

void partner_flying_enable(Npc* partner, s32 val) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    PlayerPathElement* it = gPlayerMoveHistory;
    s32 i;

    partner->pos.x = wSavedPartnerPosX;
    partner->pos.y = wSavedPartnerPosY;
    partner->pos.z = wSavedPartnerPosZ;

    for (i = 0; i < ARRAY_COUNT(gPlayerMoveHistory); i++, it++) {
        it->pos.x = wSavedPartnerPosX;
        it->pos.y = wSavedPartnerPosY;
        it->pos.z = wSavedPartnerPosZ;
        it->isJumping = FALSE;
    }

    gPlayerMoveHistoryIndex = 0;
    D_8010CFBC = 0;

    if (!val) {
        D_8010CFC8 = 0;
        D_8010CFCA = 0;
    } else if (D_8010CFC4 == 0) {
        D_8010CFC8 = 15;
        D_8010CFCA = 2;
    } else if (D_8010CFC4 == 1 || D_8010CFC4 == 3) {
        D_8010CFC4 = 0;
        D_8010CFC8 = 0;
        D_8010CFCA = 0;
    } else if (D_8010CFC4 == 2) {
        D_8010CFC8 = 50;
        D_8010CFCA = 0;
    }

    D_8010CFCE = 0;
    D_8010CFCC = 0;
    wPartnerMoveTime = 16;
    wPartnerTetherDistance = 40.0f;
    partner->currentAnim.w = gPartnerAnimations[D_8010CFD8].anims[5];
    func_800EA5B8(&partner->flags);
    partner->collisionChannel = 0x10000;
    partner->flags |= NPC_FLAG_100;
    partner->flags &= ~NPC_FLAG_GRAVITY;
}

void partner_flying_update_player_tracking(Npc* partner) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    PlayerPathElement* currentSnapshot;
    f32 effectiveY;
    s32 zero = 0; // TODO fix this as || zero == 0 is always going to be true as is

    effectiveY = playerStatus->position.y;
    if ((playerStatus->actionState == ACTION_STATE_HIT_LAVA) || (playerStatus->actionState == ACTION_STATE_HIT_FIRE)) {
        effectiveY = playerStatus->lastGoodPosition.y + partner->collisionHeight + 5;
    }
    currentSnapshot = &gPlayerMoveHistory[gPlayerMoveHistoryIndex];
    if ((!currentSnapshot->isJumping || zero == 0) && (currentSnapshot->pos.x != playerStatus->position.x || currentSnapshot->pos.y != effectiveY
        || currentSnapshot->pos.z != playerStatus->position.z)) {
        if (D_8010CFBC != gPlayerMoveHistoryIndex + 1) {
            if (++gPlayerMoveHistoryIndex >= ARRAY_COUNT(gPlayerMoveHistory)) {
                gPlayerMoveHistoryIndex = 0;
            }
            currentSnapshot = &gPlayerMoveHistory[gPlayerMoveHistoryIndex];
            currentSnapshot->pos.x = playerStatus->position.x;
            currentSnapshot->pos.y = effectiveY;
            currentSnapshot->pos.z = playerStatus->position.z;
            currentSnapshot->isJumping = zero;
        }
    }
}

void partner_flying_update_motion(Npc* partner) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    PartnerActionStatus* partnerActionStatus = &gPartnerActionStatus;
    f32 x, y, z, hitDepth;
    f32 var_f0;
    f32 var_f2;

    if (gGameStatusPtr->multiplayerEnabled == 0 ||
        (playerStatus->flags & (PLAYER_STATUS_FLAGS_INPUT_DISABLED | PLAYER_STATUS_FLAGS_1000)) ||
        partnerActionStatus->inputDisabled ||
        partnerActionStatus->partnerAction_unk_2 != 0)
    {
        if (!(playerStatus->animFlags & PLAYER_STATUS_ANIM_FLAGS_800) || D_800F8020 == 0) {
            partner_flying_follow_player(partner);
        }
        if (partnerActionStatus->pressedButtons & (BUTTON_B | BUTTON_Z | BUTTON_C_DOWN | BUTTON_C_LEFT)) {
            partnerActionStatus->partnerAction_unk_2 = 0;
        }
    }
    if (D_8010CFC8 != 50 && fabsf(partner->pos.y - playerStatus->position.y) > 1000.0f) {
        partner->pos.x = playerStatus->position.x;
        partner->pos.y = playerStatus->position.y;
        partner->pos.z = playerStatus->position.z;
        partner->jumpVelocity = 0.0f;
        partner->jumpScale = 0.0f;
        partner->flags &= ~NPC_FLAG_JUMPING;
    }

    D_800F8020 = 0;
    x = partner->pos.x;
    y = partner->pos.y + (partner->collisionHeight * 0.5f);
    z = partner->pos.z;

    hitDepth = partner->collisionHeight * 0.5f;
    if (npc_raycast_up(0, &x, &y, &z, &hitDepth) != 0) {
        D_800F8020 = 1;
        wSavedPartnerPosX = partner->pos.x;
        wSavedPartnerPosY = partner->pos.y;
        wSavedPartnerPosZ = partner->pos.z;
    } else {
        partner_do_player_collision(partner);
        if (D_8010CFC8 != 0x32) {
            x = partner->pos.x;
            y = partner->pos.y;
            z = partner->pos.z;
            hitDepth = 1000.0f;
            if (npc_raycast_down_around(0x10000, &x, &y, &z, &hitDepth, partner->yaw, partner->collisionRadius) == 0) {
                y = playerStatus->position.y;
            }

            if (partner->pos.y <= y + partner->collisionHeight + 2.0f) {
                if (playerStatus->currentSpeed != 0.0f) {
                    D_800F84F8 = ((y + (partner->collisionHeight / 2) + 2.0f) - partner->pos.y) * 0.125f;
                } else {
                    if (y < playerStatus->position.y) {
                        var_f0 = playerStatus->position.y + 10.0f - partner->pos.y;
                    } else {
                        var_f0 = y + 10.0f - partner->pos.y;
                    }
                    var_f2 = 0.25f;
                    D_800F84F8 = var_f0 * var_f2;
                }
            } else {
                if (playerStatus->position.y + playerStatus->colliderHeight < y) {
                    D_800F84F8 = (y + partner->collisionHeight - partner->pos.y) * 0.125f;
                    if (partner->pos.y + D_800F84F8 <= y + partner->collisionHeight) {
                        D_800F84F8 = (y + partner->collisionHeight - partner->pos.y) * 0.25f;
                    }
                } else {
                    var_f0 = (playerStatus->position.y + playerStatus->colliderHeight + 5.0f) - partner->pos.y;
                    var_f2 = 0.0625f;
                    D_800F84F8 = var_f0 * var_f2;
                }
            }
            partner->pos.y += D_800F84F8;
        }
        wSavedPartnerPosX = partner->pos.x;
        wSavedPartnerPosY = partner->pos.y;
        wSavedPartnerPosZ = partner->pos.z;
    }
}

INCLUDE_ASM(s32, "world/partners", partner_flying_follow_player);

s32 partner_init_put_away(Npc* partner) {
    partner->collisionChannel = 0x10000;
    D_8010CFC8 = 0;
    partner->flags |= 0x100;
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
            wSavedPartnerPosX = tempMoveToX;
            wSavedPartnerPosY = tempMoveToY;
            wSavedPartnerPosZ = tempMoveToZ;
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
            return TRUE;
    }
    return FALSE;
}

s32 partner_init_get_out(Npc* npc) {
    npc->collisionChannel = 0x10000;
    D_8010CFC8 = 0;
    npc->flags |= NPC_FLAG_100;
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

void partner_set_tether_distance(f32 dist) {
    wPartnerTetherDistance = dist;
}

void repartner_set_tether_distance(void) {
    wPartnerTetherDistance = 40.0f;
}

void partner_set_goal_pos(s32 x, s32 z) {
    wPartnerMoveGoalX = x;
    wPartnerMoveGoalZ = z;
}

void func_800EF3D4(s32 arg0) {
    D_8010CFCA = arg0;
}

void func_800EF3E4(void) {
    D_8010CFC8 = 15;
    D_8010CFCA = 0;
    wPartnerMoveTime = 10;
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

void partner_clear_player_tracking(Npc* partner) {
    PlayerPathElement* it = gPlayerMoveHistory;
    s32 i;

    wSavedPartnerPosX = partner->pos.x;
    wSavedPartnerPosY = partner->pos.y;
    wSavedPartnerPosZ = partner->pos.z;

    for (i = 0; i < ARRAY_COUNT(gPlayerMoveHistory); i++, it++) {
        it->pos.x = wSavedPartnerPosX;
        it->pos.y = wSavedPartnerPosY;
        it->pos.z = wSavedPartnerPosZ;
        it->isJumping = FALSE;
    }
}

s32 func_800EF4E0(void) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    Camera* cameras = gCameras;
    s32 ret;

    if (playerStatus->unk_90[CAM_DEFAULT] == 0.0f) {
        if (!(playerStatus->spriteFacingAngle >= 90.0f) || !(playerStatus->spriteFacingAngle < 270.0f)) {
            ret = 1;
            playerStatus->targetYaw = clamp_angle(cameras[CAM_DEFAULT].currentYaw - 90.0f);
        } else {
            playerStatus->targetYaw = clamp_angle(cameras[CAM_DEFAULT].currentYaw + 90.0f);
            ret = 0;
        }
    } else if (get_clamped_angle_diff(cameras[CAM_DEFAULT].currentYaw, playerStatus->targetYaw) < 0.0f) {
        ret = 1;
        playerStatus->targetYaw = clamp_angle(cameras[CAM_DEFAULT].currentYaw - 90.0f);
    } else {
        ret = 0;
        playerStatus->targetYaw = clamp_angle(cameras[CAM_DEFAULT].currentYaw + 90.0f);
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
    f32 playerScreenX;
    f32 playerScreenY;
    f32 playerScreenZ;
    f32 partnerScreenX;
    f32 partnerScreenY;
    f32 partnerScreenZ;
    f32 W;

    transform_point(gCameras[CAM_DEFAULT].perspectiveMatrix, playerStatus->position.x, playerStatus->position.y, playerStatus->position.z, 1.0f, &playerScreenX, &playerScreenY, &playerScreenZ, &W);
    transform_point(gCameras[CAM_DEFAULT].perspectiveMatrix, partner->pos.x, partner->pos.y, partner->pos.z, 1.0f, &partnerScreenX, &partnerScreenY, &partnerScreenZ, &W);
    playerScreenX = fabsf(playerScreenX - partnerScreenX);
    playerScreenY = fabsf(playerScreenY - partnerScreenY);
    playerScreenZ = fabsf(playerScreenZ - partnerScreenZ);
    if (playerScreenX <= (partner->collisionRadius + playerStatus->colliderDiameter) * 0.9f && playerScreenY <= partner->collisionHeight + playerStatus->colliderHeight && playerScreenZ <= 4.0) {
        npc_move_heading(partner, 1.0f, atan2(playerStatus->position.x, playerStatus->position.z, partner->pos.x, partner->pos.z));
        add_vec2D_polar(&partner->pos.x, &partner->pos.z, 2.0f, gCameras[gCurrentCameraID].currentYaw);
    }
}

INCLUDE_ASM(s32, "world/partners", partner_move_to_goal);
