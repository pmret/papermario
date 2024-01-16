#include "common_structs.h"
#include "partners.h"
#include "macros.h"

#include "ld_addrs.h"
#include "npc.h"
#include "hud_element.h"

#include "partner/goombario.h"
#include "sprite/npc/WorldGoombario.h"

#include "partner/kooper.h"
#include "sprite/npc/WorldKooper.h"

#include "partner/bombette.h"
#include "sprite/npc/WorldBombette.h"

#include "partner/parakarry.h"
#include "sprite/npc/WorldParakarry.h"

#include "partner/goompa.h"
#include "sprite/npc/Goompa.h"

#include "partner/watt.h"
#include "sprite/npc/WorldWatt.h"

#include "partner/sushie.h"
#include "sprite/npc/WorldSushie.h"

#include "partner/lakilester.h"
#include "sprite/npc/WorldLakilester.h"

#include "partner/bow.h"
#include "sprite/npc/WorldBow.h"

#include "partner/goombaria.h"
#include "sprite/npc/Goombaria.h"

#include "partner/twink.h"
#include "sprite/npc/Twink.h"

extern s32 D_8010CD20;

SHIFT_BSS PartnerStatus gPartnerStatus;
SHIFT_BSS Npc* wPartnerNpc;

BSS s32 PartnerCommandState;
BSS PlayerPathElement gPlayerMoveHistory[40];
BSS s32 gPlayerMoveHistoryIndex;
BSS s32 D_8010CFBC;
SHIFT_BSS f32 wPartnerTetherDistance;
SHIFT_BSS s32 D_8010CFC4;
SHIFT_BSS s16 wPartnerFollowState;
SHIFT_BSS s16 D_8010CFCA;
SHIFT_BSS s16 D_8010CFCC;
SHIFT_BSS s16 D_8010CFCE;
SHIFT_BSS s32 wPartnerNpcIndex;
SHIFT_BSS Evt* wPartnerCurrentScript;
SHIFT_BSS s32 wCurrentPartnerId;
SHIFT_BSS s32 wPartnerCurrentScriptID;
SHIFT_BSS s32 D_8010CFE0;
SHIFT_BSS s32 NextPartnerID;
SHIFT_BSS s32 NextPartnerCommand;
SHIFT_BSS WorldPartner* wPartner;

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

extern EvtScript EVS_World_UseItem;

#if VERSION_JP // TODO remove once segments are split
extern Addr world_use_item_ROM_START;
extern Addr world_use_item_ROM_END;
extern Addr world_use_item_VRAM;
extern Addr world_partner_goombario_ROM_START;
extern Addr world_partner_goombario_ROM_END;
extern Addr world_partner_goombario_VRAM;
extern Addr world_partner_kooper_ROM_START;
extern Addr world_partner_kooper_ROM_END;
extern Addr world_partner_kooper_VRAM;
extern Addr world_partner_bombette_ROM_START;
extern Addr world_partner_bombette_ROM_END;
extern Addr world_partner_bombette_VRAM;
extern Addr world_partner_parakarry_ROM_START;
extern Addr world_partner_parakarry_ROM_END;
extern Addr world_partner_parakarry_VRAM;
extern Addr world_partner_goompa_ROM_START;
extern Addr world_partner_goompa_ROM_END;
extern Addr world_partner_goompa_VRAM;
extern Addr world_partner_watt_ROM_START;
extern Addr world_partner_watt_ROM_END;
extern Addr world_partner_watt_VRAM;
extern Addr world_partner_sushie_ROM_START;
extern Addr world_partner_sushie_ROM_END;
extern Addr world_partner_sushie_VRAM;
extern Addr world_partner_lakilester_ROM_START;
extern Addr world_partner_lakilester_ROM_END;
extern Addr world_partner_lakilester_VRAM;
extern Addr world_partner_bow_ROM_START;
extern Addr world_partner_bow_ROM_END;
extern Addr world_partner_bow_VRAM;
extern Addr world_partner_goombaria_ROM_START;
extern Addr world_partner_goombaria_ROM_END;
extern Addr world_partner_goombaria_VRAM;
extern Addr world_partner_twink_ROM_START;
extern Addr world_partner_twink_ROM_END;
extern Addr world_partner_twink_VRAM;
#endif

s32 partner_is_idle(Npc* partner);
s32 world_partner_can_open_menus_default(Npc* partner);
void _use_partner_ability(void);
void partner_flying_follow_player(Npc*);
void partner_move_to_goal(Npc*, s32);

typedef struct UseItemStruct {
    /* 0x00 */ u8* dmaStart;
    /* 0x04 */ u8* dmaEnd;
    /* 0x08 */ EvtScript* main;
    /* 0x0C */ s32 unk_0C;
} UseItemStruct;

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
HudScript* SPIncrementHudScripts[] = {
    &HES_StatusSPIncrement1, &HES_StatusSPIncrement3, &HES_StatusSPIncrement2,
    &HES_StatusSPIncrement4, &HES_StatusSPIncrement5, &HES_StatusSPIncrement6, &HES_StatusSPIncrement7
};
HudScript* SPStarHudScripts[] = { &HES_StatusStar1, &HES_StatusStar3, &HES_StatusStar2, &HES_StatusStar4,
    &HES_StatusStar5, &HES_StatusStar6, &HES_StatusStar7
};

s32 StatusBarSPIncrementOffsets[] = { -1, 1, 2, 4, 5, 7, 8, 0, 0, 0 };
UseItemStruct UseItemDmaArgs = {
    world_use_item_ROM_START,
    world_use_item_ROM_END,
    &EVS_World_UseItem,
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

WorldPartner wPartners[] = {
    [PARTNER_NONE] {
        // blank
    },
    [PARTNER_GOOMBARIO] {
        .dmaStart = &world_partner_goombario_ROM_START,
        .dmaEnd = &world_partner_goombario_ROM_END,
        .dmaDest = &world_partner_goombario_VRAM,
        .isFlying = FALSE,
        .init = world_goombario_init,
        .takeOut = &EVS_WorldGoombario_TakeOut,
        .update = &EVS_WorldGoombario_Update,
        .useAbility = &EVS_WorldGoombario_UseAbility,
        .putAway = &EVS_WorldGoombario_PutAway,
        .idle = ANIM_WorldGoombario_Idle,
        .canUseAbility = world_goombario_can_open_menus,
        .canPlayerOpenMenus = world_goombario_can_open_menus,
        .preBattle = world_goombario_pre_battle,
    },
    [PARTNER_KOOPER] {
        .dmaStart = &world_partner_kooper_ROM_START,
        .dmaEnd = &world_partner_kooper_ROM_END,
        .dmaDest = &world_partner_kooper_VRAM,
        .isFlying = FALSE,
        .init = world_kooper_init,
        .takeOut = &EVS_WorldKooper_TakeOut,
        .update = &EVS_WorldKooper_Update,
        .useAbility = &EVS_WorldKooper_UseAbility,
        .putAway = &EVS_WorldKooper_PutAway,
        .idle = ANIM_WorldKooper_Idle,
        .testFirstStrike = world_kooper_test_first_strike,
        .canUseAbility = partner_is_idle,
        .canPlayerOpenMenus = partner_is_idle,
        .preBattle = world_kooper_pre_battle,
        .postBattle = world_kooper_post_battle,
    },
    [PARTNER_BOMBETTE] {
        .dmaStart = &world_partner_bombette_ROM_START,
        .dmaEnd = &world_partner_bombette_ROM_END,
        .dmaDest = &world_partner_bombette_VRAM,
        .isFlying = FALSE,
        .init = world_bombette_init,
        .takeOut = &EVS_WorldBombette_TakeOut,
        .update = &EVS_WorldBombette_Update,
        .useAbility = &EVS_WorldBombette_UseAbility,
        .putAway = &EVS_WorldBombette_PutAway,
        .idle = ANIM_WorldBombette_Idle,
        .testFirstStrike = world_bombette_test_first_strike,
        .canUseAbility = world_bombette_can_use_ability,
        .canPlayerOpenMenus = world_bombette_can_open_menus,
        .preBattle = world_bombette_pre_battle,
    },
    [PARTNER_PARAKARRY] {
        .dmaStart = &world_partner_parakarry_ROM_START,
        .dmaEnd = &world_partner_parakarry_ROM_END,
        .dmaDest = &world_partner_parakarry_VRAM,
        .isFlying = TRUE,
        .init = world_parakarry_init,
        .takeOut = &EVS_WorldParakarry_TakeOut,
        .update = &EVS_WorldParakarry_Update,
        .useAbility = &EVS_WorldParakarry_UseAbility,
        .putAway = &EVS_WorldParakarry_PutAway,
        .idle = ANIM_WorldParakarry_Idle,
        .canPlayerOpenMenus = partner_is_idle,
        .preBattle = world_parakarry_pre_battle,
        .postBattle = world_parakarry_post_battle,
    },
    [PARTNER_GOOMPA] {
        .dmaStart = &world_partner_goompa_ROM_START,
        .dmaEnd = &world_partner_goompa_ROM_END,
        .dmaDest = &world_partner_goompa_VRAM,
        .isFlying = FALSE,
        .init = world_goompa_init,
        .takeOut = &EVS_WorldGoompa_TakeOut,
        .update = &EVS_WorldGoompa_Update,
        .useAbility = &EVS_WorldGoompa_UseAbility,
        .putAway = &EVS_WorldGoompa_PutAway,
        .idle = ANIM_Goompa_Idle,
    },
    [PARTNER_WATT] {
        .dmaStart = &world_partner_watt_ROM_START,
        .dmaEnd = &world_partner_watt_ROM_END,
        .dmaDest = &world_partner_watt_VRAM,
        .isFlying = TRUE,
        .init = world_watt_init,
        .takeOut = &EVS_WorldWatt_TakeOut,
        .update = &EVS_WorldWatt_Update,
        .useAbility = &EVS_WorldWatt_UseAbility,
        .putAway = &EVS_WorldWatt_PutAway,
        .idle = ANIM_WorldWatt_Idle,
        .canPlayerOpenMenus = world_partner_can_open_menus_default,
        .preBattle = world_watt_pre_battle,
        .postBattle = world_watt_post_battle,
        .onEnterMap = &EVS_WorldWatt_EnterMap,
    },
    [PARTNER_SUSHIE] {
        .dmaStart = &world_partner_sushie_ROM_START,
        .dmaEnd = &world_partner_sushie_ROM_END,
        .dmaDest = &world_partner_sushie_VRAM,
        .isFlying = FALSE,
        .init = world_sushie_init,
        .takeOut = &EVS_WorldSushie_TakeOut,
        .update = &EVS_WorldSushie_Update,
        .useAbility = &EVS_WorldSushie_UseAbility,
        .putAway = &EVS_WorldSushie_PutAway,
        .idle = ANIM_WorldSushie_Idle,
        .canPlayerOpenMenus = world_partner_can_open_menus_default,
        .preBattle = world_sushie_pre_battle,
        .postBattle = world_sushie_post_battle,
        .onEnterMap = &EVS_WorldSushie_EnterMap,
    },
    [PARTNER_LAKILESTER] {
        .dmaStart = &world_partner_lakilester_ROM_START,
        .dmaEnd = &world_partner_lakilester_ROM_END,
        .dmaDest = &world_partner_lakilester_VRAM,
        .isFlying = TRUE,
        .init = world_lakilester_init,
        .takeOut = &EVS_WorldLakilester_TakeOut,
        .update = &EVS_WorldLakilester_Update,
        .useAbility = &EVS_WorldLakilester_UseAbility,
        .putAway = &EVS_WorldLakilester_PutAway,
        .idle = ANIM_WorldLakilester_Idle,
        .canPlayerOpenMenus = world_partner_can_open_menus_default,
        .preBattle = world_lakilester_pre_battle,
        .postBattle = world_lakilester_post_battle,
        .onEnterMap = &EVS_WorldLakilester_EnterMap,
    },
    [PARTNER_BOW] {
        .dmaStart = &world_partner_bow_ROM_START,
        .dmaEnd = &world_partner_bow_ROM_END,
        .dmaDest = &world_partner_bow_VRAM,
        .isFlying = TRUE,
        .init = world_bow_init,
        .takeOut = &EVS_WorldBow_TakeOut,
        .update = &EVS_WorldBow_Update,
        .useAbility = &EVS_WorldBow_UseAbility,
        .putAway = &EVS_WorldBow_PutAway,
        .idle = ANIM_WorldBow_Idle,
        .canUseAbility = partner_is_idle,
        .canPlayerOpenMenus = world_partner_can_open_menus_default,
        .preBattle = world_bow_pre_battle,
    },
    [PARTNER_GOOMBARIA] {
        .dmaStart = &world_partner_goombaria_ROM_START,
        .dmaEnd = &world_partner_goombaria_ROM_END,
        .dmaDest = &world_partner_goombaria_VRAM,
        .isFlying = FALSE,
        .init = world_goombaria_init,
        .takeOut = &EVS_WorldGoombaria_TakeOut,
        .update = &EVS_WorldGoombaria_Update,
        .useAbility = &EVS_WorldGoombaria_UseAbility,
        .putAway = &EVS_WorldGoombaria_PutAway,
        .idle = ANIM_Goombaria_Idle,
        .canUseAbility = partner_is_idle,
        .canPlayerOpenMenus = partner_is_idle,
    },
    [PARTNER_TWINK] {
        .dmaStart = &world_partner_twink_ROM_START,
        .dmaEnd = &world_partner_twink_ROM_END,
        .dmaDest = &world_partner_twink_VRAM,
        .isFlying = TRUE,
        .init = world_twink_init,
        .takeOut = &EVS_WorldTwink_TakeOut,
        .update = &EVS_WorldTwink_Update,
        .useAbility = &EVS_WorldTwink_UseAbility,
        .putAway = &EVS_WorldTwink_PutAway,
        .idle = ANIM_Twink_Idle,
        .canUseAbility = partner_is_idle,
        .canPlayerOpenMenus = partner_is_idle,
    },
};

f32 wSavedPartnerPosX = 0;
f32 wSavedPartnerPosY = 0;
f32 wSavedPartnerPosZ = 0;

PartnerAnimations gPartnerAnimations[] = {
    [PARTNER_NONE] {
        // blank
    },
    [PARTNER_GOOMBARIO] {{
        ANIM_WorldGoombario_Still,
        ANIM_WorldGoombario_Walk,
        ANIM_WorldGoombario_Jump,
        ANIM_WorldGoombario_Fall,
        ANIM_WorldGoombario_Idle,
        ANIM_WorldGoombario_Idle,
        ANIM_WorldGoombario_Run,
        ANIM_WorldGoombario_Talk,
        ANIM_WorldGoombario_Hurt
    }},
    [PARTNER_KOOPER] {{
        ANIM_WorldKooper_Still,
        ANIM_WorldKooper_Walk,
        ANIM_WorldKooper_Jump,
        ANIM_WorldKooper_Fall,
        ANIM_WorldKooper_Still,
        ANIM_WorldKooper_Idle,
        ANIM_WorldKooper_Run,
        ANIM_WorldKooper_Talk,
        ANIM_WorldKooper_Hurt
    }},
    [PARTNER_BOMBETTE] {{
        ANIM_WorldBombette_Still,
        ANIM_WorldBombette_Walk,
        ANIM_WorldBombette_Jump,
        ANIM_WorldBombette_Fall,
        ANIM_WorldBombette_Still,
        ANIM_WorldBombette_Idle,
        ANIM_WorldBombette_Run,
        ANIM_WorldBombette_Talk,
        ANIM_WorldBombette_Hurt
    }},
    [PARTNER_PARAKARRY] {{
        ANIM_WorldParakarry_Still,
        ANIM_WorldParakarry_Walk,
        ANIM_WorldParakarry_FlyFast,
        ANIM_WorldParakarry_Walk,
        ANIM_WorldParakarry_Walk,
        ANIM_WorldParakarry_Idle,
        ANIM_WorldParakarry_Run,
        ANIM_WorldParakarry_Talk,
        ANIM_WorldParakarry_Hurt
    }},
    [PARTNER_GOOMPA] {{
        ANIM_Goompa_Still,
        ANIM_Goompa_Walk,
        ANIM_Goompa_Jump,
        ANIM_Goompa_Fall,
        ANIM_Goompa_Idle,
        ANIM_Goompa_Idle,
        ANIM_Goompa_Run,
        ANIM_Goompa_Talk,
        ANIM_Goompa_Idle
    }},
    [PARTNER_WATT] {{
        ANIM_WorldWatt_Still,
        ANIM_WorldWatt_Walk,
        ANIM_WorldWatt_Walk,
        ANIM_WorldWatt_Walk,
        ANIM_WorldWatt_Still,
        ANIM_WorldWatt_Idle,
        ANIM_WorldWatt_Run,
        ANIM_WorldWatt_Talk,
        ANIM_WorldWatt_Hurt
    }},
    [PARTNER_SUSHIE] {{
        ANIM_WorldSushie_Still,
        ANIM_WorldSushie_Walk,
        ANIM_WorldSushie_Walk,
        ANIM_WorldSushie_Walk,
        ANIM_WorldSushie_Still,
        ANIM_WorldSushie_Idle,
        ANIM_WorldSushie_Run,
        ANIM_WorldSushie_Talk,
        ANIM_WorldSushie_Hurt
    }},
    [PARTNER_LAKILESTER] {{
        ANIM_WorldLakilester_Still,
        ANIM_WorldLakilester_Walk,
        ANIM_WorldLakilester_Walk,
        ANIM_WorldLakilester_Walk,
        ANIM_WorldLakilester_Still,
        ANIM_WorldLakilester_Idle,
        ANIM_WorldLakilester_Run,
        ANIM_WorldLakilester_Talk,
        ANIM_WorldLakilester_TiredTalk
    }},
    [PARTNER_BOW] {{
        ANIM_WorldBow_Still,
        ANIM_WorldBow_Walk,
        ANIM_WorldBow_Walk,
        ANIM_WorldBow_Walk,
        ANIM_WorldBow_Still,
        ANIM_WorldBow_Idle,
        ANIM_WorldBow_Run,
        ANIM_WorldBow_Talk,
        ANIM_WorldBow_Flail
    }},
    [PARTNER_GOOMBARIA] {{
        ANIM_Goombaria_Still,
        ANIM_Goombaria_Walk,
        ANIM_Goombaria_Jump,
        ANIM_Goombaria_Fall,
        ANIM_Goombaria_Idle,
        ANIM_Goombaria_Idle,
        ANIM_Goombaria_Run,
        ANIM_Goombaria_Talk,
        ANIM_Goombaria_Idle
    }},
    [PARTNER_TWINK] {{
        ANIM_Twink_Still,
        ANIM_Twink_Idle,
        ANIM_Twink_Idle,
        ANIM_Twink_Idle,
        ANIM_Twink_Idle,
        ANIM_Twink_Idle,
        ANIM_Twink_Idle,
        ANIM_Twink_Talk,
        ANIM_Twink_Hurt
    }},
};

f32 D_800F84F8 = 0.0f;

s32 use_consumable(s32 invSlot) {
    Evt* script;

    D_8010CD20 = invSlot;
    invSlot = gPlayerData.invItems[invSlot];
    dma_copy(UseItemDmaArgs.dmaStart, UseItemDmaArgs.dmaEnd, world_use_item_VRAM);
    script = start_script(UseItemDmaArgs.main, EVT_PRIORITY_1, 0);
    script->varTable[10] = invSlot;
    return script->id;
}

void remove_consumable(void) {
    gPlayerData.invItems[D_8010CD20] = ITEM_NONE;
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
    return gPartnerStatus.partnerActionState == PARTNER_ACTION_NONE;
}

s32 world_partner_can_open_menus_default(Npc* partner) {
    return TRUE;
}

s32 func_800EA52C(s32 partnerID) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    u32 playerActionState = playerStatus->actionState;
    s32 ret = FALSE;

    if (playerStatus->flags & PS_FLAG_HIT_FIRE) {
        return FALSE;
    }

    // any partner
    if (playerActionState == ACTION_STATE_IDLE
     || playerActionState == ACTION_STATE_WALK
     || playerActionState == ACTION_STATE_RUN
    ) {
        ret = TRUE;
    }

    // check specific partners
    if (partnerID == PARTNER_BOW) {
        if (playerActionState == ACTION_STATE_RIDE) {
            ret = TRUE;
        }
    } else if (partnerID == PARTNER_PARAKARRY) {
        if (playerActionState == ACTION_STATE_RIDE
         || playerActionState == ACTION_STATE_IDLE
         || playerActionState == ACTION_STATE_WALK
         || playerActionState == ACTION_STATE_RUN
        ) {
            ret = TRUE;
        }
    }

    return ret;
}

s32 partner_is_flying(void) {
    return !wPartner->isFlying;
}

void func_800EA5B8(Npc* partner) {
    partner->flags &= ~(NPC_FLAG_COLLIDING_WITH_NPC | NPC_FLAG_COLLDING_FORWARD_WITH_WORLD | NPC_FLAG_COLLDING_WITH_WORLD | NPC_FLAG_GROUNDED |
                          NPC_FLAG_JUMPING);
}

void create_partner_npc(void) {
    WorldPartner* partnerEntry = &wPartners[wCurrentPartnerId];
    Npc** partnerNpcPtr = &wPartnerNpc;
    WorldPartner** partner = &wPartner;
    s32 npcIndex;
    NpcBlueprint blueprint;
    NpcBlueprint* blueprintPtr;

    *partner = partnerEntry;
    blueprintPtr = &blueprint;
    dma_copy(partnerEntry->dmaStart, partnerEntry->dmaEnd, partnerEntry->dmaDest);

    blueprint.flags = NPC_FLAG_PARTNER | NPC_FLAG_IGNORE_PLAYER_COLLISION;
    blueprint.initialAnim = (*partner)->idle;
    blueprint.onUpdate = NULL;
    blueprint.onRender = NULL;
    wPartnerNpcIndex = npcIndex = create_basic_npc(blueprintPtr);

    *partnerNpcPtr = get_npc_by_index(npcIndex);

    {
        Npc* npc = *partnerNpcPtr;
        npc->npcID = NPC_PARTNER;
        npc->collisionDiameter = 10;
        npc->collisionHeight = 10;
    }

    {
        Npc* npc = *partnerNpcPtr;
        npc->pos.x = NPC_DISPOSE_POS_X;
        npc->pos.y = NPC_DISPOSE_POS_Y;
        npc->pos.z = NPC_DISPOSE_POS_Z;
        npc->scale.x = 0.0f;
        npc->scale.y = 0.0f;
        npc->scale.z = 0.0f;
    }

    TweesterTouchingPartner = NULL;
}

void partner_free_npc(void) {
    free_npc_by_index(wPartnerNpcIndex);
}

void _use_partner_ability(void) {
    static u32 PartnerCommand; // goes into BSS, needs to be static for the function to match

    PlayerData* playerData = &gPlayerData;
    PartnerStatus* partnerStatus = &gPartnerStatus;
    PlayerStatus* playerStatus = &gPlayerStatus;

    if (partnerStatus->inputDisabledCount == 0) {
        partnerStatus->stickX = gGameStatusPtr->stickX[gGameStatusPtr->multiplayerEnabled];
        partnerStatus->stickY = gGameStatusPtr->stickY[gGameStatusPtr->multiplayerEnabled];
        partnerStatus->curButtons = gGameStatusPtr->curButtons[gGameStatusPtr->multiplayerEnabled];
        partnerStatus->pressedButtons = gGameStatusPtr->pressedButtons[gGameStatusPtr->multiplayerEnabled];
        partnerStatus->heldButtons = gGameStatusPtr->heldButtons[gGameStatusPtr->multiplayerEnabled];
    } else {
        partnerStatus->stickX = 0;
        partnerStatus->stickY = 0;
        partnerStatus->curButtons = 0;
        partnerStatus->pressedButtons = 0;
        partnerStatus->heldButtons = 0;
    }

    if (playerStatus->animFlags & PA_FLAG_INTERRUPT_USE_PARTNER) {
        playerStatus->animFlags &= ~PA_FLAG_INTERRUPT_USE_PARTNER;
        partnerStatus->pressedButtons |= BUTTON_B | BUTTON_C_DOWN;
        playerStatus->animFlags |= PA_FLAG_FORCED_PARTNER_ABILITY_END;
    }

    if (NextPartnerCommand != PARTNER_CMD_NONE) {
        PartnerCommand = NextPartnerCommand;
        PartnerCommandState = 0;
        NextPartnerCommand = PARTNER_CMD_NONE;
    }

    if (PartnerCommand >= PARTNER_CMD_INSTA_SWITCH) {
#if VERSION_JP
        D_8010CFC4 = 0;
#else
        if (PartnerCommand != PARTNER_CMD_USE_ABILITY) {
            D_8010CFC4 = 0;
        }
#endif
    }

    switch (PartnerCommand) {
        case PARTNER_CMD_NONE:
            break;
        case PARTNER_CMD_SWITCH:
            D_8010CFC4 = 3;
            switch (PartnerCommandState) {
                case 0: // put away current partner
                    disable_player_input();
                    sfx_play_sound(SOUND_PARTNER_PUT_AWAY);
                    kill_script_by_ID(wPartnerCurrentScriptID);
                    wPartnerCurrentScript = start_script(wPartner->putAway, EVT_PRIORITY_14, EVT_FLAG_RUN_IMMEDIATELY);
                    wPartnerCurrentScript->owner2.npc = wPartnerNpc;
                    wPartnerCurrentScriptID = wPartnerCurrentScript->id;
                    wPartnerCurrentScript->groupFlags = EVT_GROUP_08 | EVT_GROUP_02;
                    PartnerCommandState += 1;
                    set_time_freeze_mode(TIME_FREEZE_PARTIAL);
                    break;
                case 1: // free old partner and create new one
                    if (does_script_exist(wPartnerCurrentScriptID)) {
                        break;
                    }
                    set_time_freeze_mode(TIME_FREEZE_NORMAL);
                    partner_free_npc();
                    playerData->curPartner = wCurrentPartnerId = NextPartnerID;
                    create_partner_npc();
                    sfx_play_sound(SOUND_PARTNER_GET_OUT);
                    wPartner->init(wPartnerNpc);
                    PartnerCommandState += 1;
                    // fallthrough
                case 2: // take out new partner
                    wPartnerCurrentScript = start_script(wPartner->takeOut, EVT_PRIORITY_14, EVT_FLAG_RUN_IMMEDIATELY);
                    wPartnerCurrentScript->owner2.npc = wPartnerNpc;
                    wPartnerCurrentScriptID = wPartnerCurrentScript->id;
                    wPartnerCurrentScript->groupFlags = EVT_GROUP_08 | EVT_GROUP_02;
                    PartnerCommandState += 1;
                    set_time_freeze_mode(TIME_FREEZE_PARTIAL);
                    break;
                case 3: // resume normal partner behaviour
                    if (does_script_exist(wPartnerCurrentScriptID)) {
                        break;
                    }
                    wPartnerCurrentScript = start_script(wPartner->update, EVT_PRIORITY_14, EVT_FLAG_RUN_IMMEDIATELY);
                    wPartnerCurrentScript->owner2.npc = wPartnerNpc;
                    wPartnerCurrentScriptID = wPartnerCurrentScript->id;
                    wPartnerCurrentScript->groupFlags = EVT_GROUP_08 | EVT_GROUP_02;
                    PartnerCommand = PARTNER_CMD_INIT;
                    enable_player_input();
                    set_time_freeze_mode(TIME_FREEZE_NORMAL);
                    break;
            }
            break;
        case PARTNER_CMD_INSTA_SWITCH:
            D_8010CFC4 = 3;
            switch (PartnerCommandState) {
                case 0:
                    kill_script_by_ID(wPartnerCurrentScriptID);
                    PartnerCommandState += 1;
                case 1:
                    partner_free_npc();
                    playerData->curPartner = wCurrentPartnerId = NextPartnerID;
                    create_partner_npc();
                    wPartnerNpc->pos.x = wSavedPartnerPosX;
                    wPartnerNpc->pos.y = wSavedPartnerPosY;
                    wPartnerNpc->pos.z = wSavedPartnerPosZ;
                    wPartnerNpc->jumpVel = 0.0f;
                    wPartnerNpc->scale.x = 1.0f;
                    wPartnerNpc->scale.y = 1.0f;
                    wPartnerNpc->scale.z = 1.0f;
                    wPartner->init(wPartnerNpc);
                    PartnerCommandState += 1;
                    // fallthrough
                case 2:
                    PartnerCommandState += 1;
                    break;
                case 3:
                    wPartnerCurrentScript = start_script(wPartner->update, EVT_PRIORITY_14, EVT_FLAG_RUN_IMMEDIATELY);
                    wPartnerCurrentScript->owner2.npc = wPartnerNpc;
                    wPartnerCurrentScriptID = wPartnerCurrentScript->id;
                    wPartnerCurrentScript->groupFlags = EVT_GROUP_08 | EVT_GROUP_02;
                    PartnerCommand = PARTNER_CMD_INIT;
                    break;
            }
            break;
        case PARTNER_CMD_PUT_AWAY:
            switch (PartnerCommandState) {
                case 0: // put away current partner
                    disable_player_input();
                    sfx_play_sound(SOUND_PARTNER_PUT_AWAY);
                    kill_script_by_ID(wPartnerCurrentScriptID);
                    wPartnerCurrentScript = start_script(wPartner->putAway, EVT_PRIORITY_14, EVT_FLAG_RUN_IMMEDIATELY);
                    wPartnerCurrentScript->owner2.npc = wPartnerNpc;
                    wPartnerCurrentScriptID = wPartnerCurrentScript->id;
                    wPartnerCurrentScript->groupFlags = EVT_GROUP_08 | EVT_GROUP_02;
                    PartnerCommandState += 1;
                    break;
                case 1: // free old partner and resume game
                    if (does_script_exist(wPartnerCurrentScriptID)) {
                        break;
                    }
                    partner_free_npc();
                    PartnerCommand = PARTNER_CMD_INIT;
                    playerData->curPartner = wCurrentPartnerId = NextPartnerID;
                    enable_player_input();
                    break;
            }
            break;
        case PARTNER_CMD_INSTA_PUT_AWAY:
            if (PartnerCommandState == 0) {
                kill_script_by_ID(wPartnerCurrentScriptID);
                partner_free_npc();
                PartnerCommand = PARTNER_CMD_INIT;
                playerData->curPartner = wCurrentPartnerId = NextPartnerID;
                break;
            }
            break;
        case PARTNER_CMD_TAKE_OUT:
            switch (PartnerCommandState) {
                case 0: // create the new partner
                    disable_player_input();
                    playerData->curPartner = wCurrentPartnerId = NextPartnerID;
                    create_partner_npc();
                    wPartner->init(wPartnerNpc);
                    PartnerCommandState += 1;
                    // fallthrough
                case 1: // take out new partner
                    wPartnerCurrentScript = start_script(wPartner->takeOut, EVT_PRIORITY_14, EVT_FLAG_RUN_IMMEDIATELY);
                    wPartnerCurrentScript->owner2.npc = wPartnerNpc;
                    wPartnerCurrentScriptID = wPartnerCurrentScript->id;
                    wPartnerCurrentScript->groupFlags = EVT_GROUP_08 | EVT_GROUP_02;
                    PartnerCommandState += 1;
                    break;
                case 2: // resume standard partner behaviour
                    if (does_script_exist(wPartnerCurrentScriptID)) {
                        break;
                    }
                    wPartnerCurrentScript = start_script(wPartner->update, EVT_PRIORITY_14, EVT_FLAG_RUN_IMMEDIATELY);
                    wPartnerCurrentScript->owner2.npc = wPartnerNpc;
                    wPartnerCurrentScriptID = wPartnerCurrentScript->id;
                    wPartnerCurrentScript->groupFlags = EVT_GROUP_08 | EVT_GROUP_02;
                    PartnerCommand = PARTNER_CMD_INIT;
                    enable_player_input();
                    break;
            }
            break;
        case PARTNER_CMD_INSTA_TAKE_OUT:
            D_8010CFC4 = 2;
            switch (PartnerCommandState) {
                case 0:
                    disable_player_input();
                    playerData->curPartner = wCurrentPartnerId = NextPartnerID;
                    create_partner_npc();
                    wPartnerNpc->pos.x = wSavedPartnerPosX;
                    wPartnerNpc->pos.y = wSavedPartnerPosY;
                    wPartnerNpc->pos.z = wSavedPartnerPosZ;
                    wPartnerNpc->jumpVel = 0.0f;
                    wPartnerNpc->scale.x = 1.0f;
                    wPartnerNpc->scale.y = 1.0f;
                    wPartnerNpc->scale.z = 1.0f;
                    wPartner->init(wPartnerNpc);
                    PartnerCommandState += 1;
                    break;
                case 1:
                    wPartnerCurrentScript = start_script(wPartner->update, EVT_PRIORITY_14, EVT_FLAG_RUN_IMMEDIATELY);
                    wPartnerCurrentScript->owner2.npc = wPartnerNpc;
                    wPartnerCurrentScriptID = wPartnerCurrentScript->id;
                    wPartnerCurrentScript->groupFlags = EVT_GROUP_08 | EVT_GROUP_02;
                    PartnerCommand = PARTNER_CMD_INIT;
                    wPartnerNpc->curAnim = gPartnerAnimations[wCurrentPartnerId].fly;
                    enable_player_input();
                    break;
            }
            break;
        case PARTNER_CMD_USE_ABILITY:
            switch (PartnerCommandState) {
                case 0:
                    kill_script_by_ID(wPartnerCurrentScriptID);
                    wPartnerCurrentScript = start_script(wPartner->useAbility, EVT_PRIORITY_14, EVT_FLAG_RUN_IMMEDIATELY);
                    wPartnerCurrentScript->owner2.npc = wPartnerNpc;
                    wPartnerCurrentScriptID = wPartnerCurrentScript->id;
                    wPartnerCurrentScript->groupFlags = EVT_GROUP_08 | EVT_GROUP_02;
                    PartnerCommandState += 1;
                    break;
                case 1:
                    if (does_script_exist(wPartnerCurrentScriptID)) {
                        break;
                    }
                    wPartnerCurrentScript = start_script(wPartner->update, EVT_PRIORITY_14, EVT_FLAG_RUN_IMMEDIATELY);
                    wPartnerCurrentScript->owner2.npc = wPartnerNpc;
                    wPartnerCurrentScriptID = wPartnerCurrentScript->id;
                    wPartnerCurrentScript->groupFlags = EVT_GROUP_08 | EVT_GROUP_02;
                    PartnerCommand = PARTNER_CMD_INIT;
                    break;
            }
            break;
        case PARTNER_CMD_RESET:
            D_8010CFC4 = 1;
            switch (PartnerCommandState) {
                case 0:
                    disable_player_input();
                    wPartner->init(wPartnerNpc);
                    PartnerCommandState += 1;
                    // fallthrough
                case 1:
                    PartnerCommandState += 1;
                    break;
                case 2:
                    if (partnerStatus->partnerActionState != 1) {
                        wSavedPartnerPosX = playerStatus->pos.x;
                        wSavedPartnerPosY = playerStatus->pos.y;
                        wSavedPartnerPosZ = playerStatus->pos.z;
                        wPartnerCurrentScript = start_script(wPartner->update, EVT_PRIORITY_14, EVT_FLAG_RUN_IMMEDIATELY);
                        wPartnerCurrentScript->owner2.npc = wPartnerNpc;
                        wPartnerCurrentScriptID = wPartnerCurrentScript->id;
                        wPartnerCurrentScript->groupFlags = EVT_GROUP_08 | EVT_GROUP_02;
                    }
                    enable_player_input();
                    PartnerCommand = PARTNER_CMD_INIT;
                    break;
            }
            break;
        case PARTNER_CMD_ABORT:
            if (PartnerCommandState == 0) {
                if (does_script_exist(wPartnerCurrentScriptID)) {
                    kill_script_by_ID(wPartnerCurrentScriptID);
                }
                PartnerCommandState += 1;
            }
            break;
        case PARTNER_CMD_INIT:
            PartnerCommand = PARTNER_CMD_NONE;
            D_8010CFE0 = 0;
            if (D_8010CFC4 != 3) {
                D_8010CFC4 = 0;
            }
            break;
    }
}

void switch_to_partner(s32 partnerID) {
    PlayerStatus* playerStatus = &gPlayerStatus;

    if (wCurrentPartnerId != partnerID) {
        D_8010CFE0 = 1;
        NextPartnerID = partnerID;

        if (wCurrentPartnerId != PARTNER_NONE && partnerID != PARTNER_NONE) {
            NextPartnerCommand = PARTNER_CMD_SWITCH;
        } else if (partnerID == PARTNER_NONE) {
            NextPartnerCommand = PARTNER_CMD_PUT_AWAY;
        } else {
            NextPartnerCommand = PARTNER_CMD_TAKE_OUT;
            wSavedPartnerPosX = playerStatus->pos.x;
            wSavedPartnerPosY = playerStatus->pos.y;
            wSavedPartnerPosZ = playerStatus->pos.z;
        }
    }
}

void partner_init_after_battle(s32 partnerID) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    PartnerStatus* partnerStatus = &gPartnerStatus;

    if (wCurrentPartnerId != partnerID) {
        D_8010CFE0 = 1;
        NextPartnerID = partnerID;
        partnerStatus->partnerActionState = 0;
        partnerStatus->shouldResumeAbility = FALSE;

        if (wCurrentPartnerId != PARTNER_NONE && partnerID != PARTNER_NONE) {
            NextPartnerCommand = PARTNER_CMD_INSTA_SWITCH;
        } else if (partnerID == PARTNER_NONE) {
            NextPartnerCommand = PARTNER_CMD_PUT_AWAY;
        } else {
            NextPartnerCommand = PARTNER_CMD_TAKE_OUT;
            wSavedPartnerPosX = playerStatus->pos.x;
            wSavedPartnerPosY = playerStatus->pos.y;
            wSavedPartnerPosZ = playerStatus->pos.z;
        }
    }
}

void func_800EB2A4(s32 partnerID) {
    if (wCurrentPartnerId != partnerID) {
        D_8010CFE0 = 1;
        NextPartnerID = partnerID;

        if (wCurrentPartnerId != PARTNER_NONE && partnerID != PARTNER_NONE) {
            NextPartnerCommand = PARTNER_CMD_SWITCH;
        } else if (partnerID == PARTNER_NONE) {
            NextPartnerCommand = PARTNER_CMD_INSTA_PUT_AWAY;
        } else {
            NextPartnerCommand = PARTNER_CMD_INSTA_TAKE_OUT;
        }
    }
}

s32 partner_use_ability(void) {
    PartnerStatus* partnerStatus = &gPartnerStatus;

    if (!is_starting_conversation()
        && wPartner != NULL
        && (wPartner->canUseAbility == NULL || wPartner->canUseAbility(wPartnerNpc)))
    {
        if (gGameStatusPtr->multiplayerEnabled && (partnerStatus->curButtons & BUTTON_B)) {
            sfx_play_sound(SOUND_MENU_ERROR);
        } else if (wCurrentPartnerId != PARTNER_NONE) {
            D_8010CFE0 = 1;
            NextPartnerCommand = PARTNER_CMD_USE_ABILITY;
            _use_partner_ability();
            return TRUE;
        }
    }
    return FALSE;
}

s32 partner_can_open_world_menus(void) {
    if (wPartner != NULL
        && wPartner->canPlayerOpenMenus != NULL
        && !wPartner->canPlayerOpenMenus(wPartnerNpc)
    ) {
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
    s32 currentPartner = gPlayerData.curPartner;

    mem_clear(&gPartnerStatus, sizeof(gPartnerStatus));
    get_worker(create_worker_frontUI(_use_partner_ability, NULL));

    D_8010CFE0 = 1;
    NextPartnerCommand = PARTNER_CMD_RESET;
    wCurrentPartnerId = currentPartner;

    if (gGameStatusPtr->keepUsingPartnerOnMapChange) {
        gPartnerStatus.partnerActionState = PARTNER_ACTION_USE;
        gGameStatusPtr->keepUsingPartnerOnMapChange = FALSE;
    }

    wPartner = NULL;
    wSavedPartnerPosX = playerStatus->pos.x;
    wSavedPartnerPosY = playerStatus->pos.y;
    wSavedPartnerPosZ = playerStatus->pos.z;

    if (wCurrentPartnerId == PARTNER_NONE) {
        NextPartnerCommand = PARTNER_CMD_INIT;
    } else {
        create_partner_npc();
        wPartnerNpc->scale.x = 1.0f;
        wPartnerNpc->scale.y = 1.0f;
        wPartnerNpc->scale.z = 1.0f;
        _use_partner_ability();
    }
}

void partner_initialize_data(void) {
    PartnerStatus* partnerStatus = &gPartnerStatus;

    wCurrentPartnerId = 0;
    D_8010CFE0 = 0;
    NextPartnerCommand = PARTNER_CMD_NONE;
    D_8010CFC4 = 0;
    partnerStatus->actingPartner = 0;
    partnerStatus->inputDisabledCount = 0;
    partnerStatus->shouldResumeAbility = FALSE;
    partnerStatus->partnerActionState = 0;
    partnerStatus->unk_358 = 0;
    partnerStatus->partnerAction_unk_2 = FALSE;
    wPartner = NULL;
    wSavedPartnerPosX = 0;
    wSavedPartnerPosY = 0;
    wSavedPartnerPosZ = 0;
}

s32 partner_test_enemy_collision(Npc* enemy) {
    if (wCurrentPartnerId != PARTNER_NONE && wPartner->testFirstStrike != NULL) {
        return wPartner->testFirstStrike(wPartnerNpc, enemy);
    }
    return FALSE;
}

EvtScript* partner_get_enter_map_script(void) {
    WorldPartner* partner = wPartner;

    if (partner == NULL) {
        return NULL;
    }
    return partner->onEnterMap;
}

void partner_handle_before_battle(void) {
    if (wCurrentPartnerId != PARTNER_NONE) {
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
    PartnerStatus* partnerStatus = &gPartnerStatus;
    PlayerData* playerData = &gPlayerData;

    if (wCurrentPartnerId != PARTNER_NONE) {
        if (does_script_exist(wPartnerCurrentScriptID) != 0) {
            kill_script_by_ID(wPartnerCurrentScriptID);
        }

        wPartnerCurrentScript = start_script(wPartner->update, EVT_PRIORITY_14, EVT_FLAG_RUN_IMMEDIATELY);
        wPartnerCurrentScript->owner2.npc = wPartnerNpc;
        wPartnerCurrentScriptID = wPartnerCurrentScript->id;
        wPartnerCurrentScript->groupFlags = EVT_GROUP_08 | EVT_GROUP_02;

        NextPartnerCommand = PARTNER_CMD_INIT;

        if (playerData->curPartner != PARTNER_WATT && partnerStatus->actingPartner == PARTNER_WATT) {
            gPlayerStatusPtr->animFlags &= ~PA_FLAG_USING_WATT;
            gPlayerStatusPtr->animFlags &= ~PA_FLAG_WATT_IN_HANDS;
            partnerStatus->actingPartner = PARTNER_NONE;
        }

        if (wPartner->postBattle != NULL) {
            wPartner->postBattle(wPartnerNpc);
        }
    }
}

void partner_kill_ability_script(void) {
    NextPartnerCommand = PARTNER_CMD_ABORT;

    if (does_script_exist(wPartnerCurrentScriptID)) {
        kill_script_by_ID(wPartnerCurrentScriptID);
    }
}

void partner_suspend_ability_script(void) {
    if (wCurrentPartnerId != NULL) {
        if (does_script_exist(wPartnerCurrentScriptID)) {
            suspend_all_script(wPartnerCurrentScriptID);
        }
    }
}

void partner_resume_ability_script(void) {
    if (wCurrentPartnerId != NULL) {
        if (does_script_exist(wPartnerCurrentScriptID)) {
            resume_all_script(wPartnerCurrentScriptID);
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
        it->pos.x = playerStatus->pos.x;
        it->pos.y = playerStatus->pos.y;
        it->pos.z = playerStatus->pos.z;
        it->isJumping = FALSE;
    }

    gPlayerMoveHistoryIndex = 0;
    D_8010CFBC = 0;
    D_8010CFCA = val ? 2 : 0;
    wPartnerFollowState = 0;

    if (D_8010CFC4 == 1 || D_8010CFC4 == 3) {
        D_8010CFC4 = 0;
        D_8010CFCA = 0;
        wPartnerFollowState = 0;
    } else if (D_8010CFC4 == 2) {
        D_8010CFCA = 0;
        wPartnerFollowState = 50;
    }

    D_8010CFCE = 0;
    D_8010CFCC = 0;
    wPartnerMoveTime = 16;
    wPartnerTetherDistance = 40.0f;
    partner->curAnim = gPartnerAnimations[wCurrentPartnerId].idle;
    func_800EA5B8(partner);
    partner->collisionChannel = COLLIDER_FLAG_IGNORE_PLAYER;
    partner->jumpVel = 0.0f;
    partner->flags |= NPC_FLAG_TOUCHES_GROUND | NPC_FLAG_GRAVITY | NPC_FLAG_IGNORE_PLAYER_COLLISION;
    partner->jumpScale = 1.8f;
}

void partner_walking_update_player_tracking(Npc* partner) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    s32 isPlayerJumping;
    PlayerPathElement* currentSnapshot;

    if (playerStatus->flags & (PS_FLAG_FALLING | PS_FLAG_JUMPING)) {
        isPlayerJumping = (playerStatus->actionState == ACTION_STATE_LAND || playerStatus->actionState == ACTION_STATE_STEP_DOWN) ^ 1;
    } else {
        isPlayerJumping = FALSE;
    }
    currentSnapshot = &gPlayerMoveHistory[gPlayerMoveHistoryIndex];
    if ((!currentSnapshot->isJumping || !isPlayerJumping) &&
        ((currentSnapshot->pos.x != playerStatus->pos.x) || (currentSnapshot->pos.y != playerStatus->pos.y)
        || (currentSnapshot->pos.z != playerStatus->pos.z))) {
        if (D_8010CFBC != gPlayerMoveHistoryIndex + 1) {
            if (++gPlayerMoveHistoryIndex >= ARRAY_COUNT(gPlayerMoveHistory)) {
                gPlayerMoveHistoryIndex = 0;
            }
            currentSnapshot = &gPlayerMoveHistory[gPlayerMoveHistoryIndex];
            currentSnapshot->pos.x = playerStatus->pos.x;
            currentSnapshot->pos.y = playerStatus->pos.y;
            currentSnapshot->pos.z = playerStatus->pos.z;
            currentSnapshot->isJumping = isPlayerJumping;
        }
    }
}

void partner_walking_update_motion(Npc* partner) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    PartnerStatus* partnerStatus = &gPartnerStatus;

    if (!gGameStatusPtr->multiplayerEnabled || playerStatus->flags & (PS_FLAG_INPUT_DISABLED | PS_FLAG_NO_STATIC_COLLISION)
        || partnerStatus->inputDisabledCount != 0 || partnerStatus->partnerAction_unk_2) {
        if (!(playerStatus->animFlags & PA_FLAG_OPENED_HIDDEN_PANEL)) {
            partner_walking_follow_player(partner);
        }
        if (partnerStatus->pressedButtons & (BUTTON_Z | BUTTON_B | BUTTON_C_LEFT | BUTTON_C_DOWN)) {
            partnerStatus->partnerAction_unk_2 = FALSE;
        }
    }

    if (wPartnerFollowState != 50 && fabsf(partner->pos.y - playerStatus->pos.y) > 1000.0f) {
        partner->pos.x = playerStatus->pos.x;
        partner->pos.y = playerStatus->pos.y;
        partner->pos.z = playerStatus->pos.z;
        partner->jumpVel = 0.0f;
        partner->jumpScale = 0.0f;
        partner->flags = partner->flags & ~PA_FLAG_OPENED_HIDDEN_PANEL;
    }

    partner_do_player_collision(partner);
    wSavedPartnerPosX = partner->pos.x;
    wSavedPartnerPosY = partner->pos.y;
    wSavedPartnerPosZ = partner->pos.z;
}

void partner_walking_follow_player(Npc* partner) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    Camera* cameras = &gCameras[CAM_DEFAULT];
    s32 surfaceType;
    f32 moveHistoryX, moveHistoryY, moveHistoryZ;
    f32 x, y, z;
    f32 distance;
    f32 yaw;
    f32 temp_a3;
    f32 angle;
    s32 var_a1;
    PlayerPathElement* currentSnapshot;

    switch (wPartnerFollowState) {
        case 0:
            currentSnapshot = &gPlayerMoveHistory[D_8010CFBC];
            moveHistoryX = currentSnapshot->pos.x;
            moveHistoryZ = currentSnapshot->pos.z;
            x = partner->pos.x;
            y = partner->pos.y;
            z = partner->pos.z;
            partner->moveSpeed = 3.0f;

            distance = dist2D(partner->pos.x, partner->pos.z, playerStatus->pos.x, playerStatus->pos.z);
            if (distance >= 50.0) {
                partner->moveSpeed = !(playerStatus->animFlags & PA_FLAG_SPINNING) ? 5.0f : 7.0f;
            }
            if (wPartnerTetherDistance < 20.0) {
                partner->moveSpeed = 4.0f;
            }
            partner->curAnim = gPartnerAnimations[wCurrentPartnerId].run;
            if (!(partner->flags & NPC_FLAG_GROUNDED)) {
                partner->curAnim = gPartnerAnimations[wCurrentPartnerId].fall;
            }
            while (TRUE) {
                distance = dist2D(x, z, moveHistoryX, moveHistoryZ);
                yaw = atan2(x, z, moveHistoryX, moveHistoryZ);
                if (partner->moveSpeed < distance) {
                    distance = dist2D(x, z, playerStatus->pos.x, playerStatus->pos.z);
                    if (distance >= 50.0) {
                        break;
                    }
                    if (wPartnerTetherDistance < distance) {
                        partner->moveSpeed = distance - wPartnerTetherDistance;
                        if (partner->moveSpeed > 3.0) {
                            partner->moveSpeed = 3.0f;
                            if (wPartnerTetherDistance < 20.0f) {
                                partner->moveSpeed = 4.0f;
                            }
                        } else {
                            partner->moveSpeed += 1.0;
                        }
                        break;
                    } else {
                        partner->moveSpeed = 0.0f;
                        partner->yaw = atan2(partner->pos.x, partner->pos.z, playerStatus->pos.x, playerStatus->pos.z);
                    }
                }
                if (D_8010CFBC == gPlayerMoveHistoryIndex) {
                    yaw = partner->yaw;
                    partner->moveSpeed = 0.0f;
                    partner->jumpScale = 0.0f;
                    wPartnerFollowState = 5;
                    partner->curAnim = gPartnerAnimations[wCurrentPartnerId].idle;
                    break;
                } else {
                    D_8010CFBC++;
                    if (D_8010CFBC >= 40) {
                        D_8010CFBC = 0;
                    }
                    currentSnapshot = &gPlayerMoveHistory[D_8010CFBC];
                    moveHistoryX = currentSnapshot->pos.x;
                    moveHistoryZ = currentSnapshot->pos.z;

                    if (fabsf(get_clamped_angle_diff(partner->yaw, atan2(partner->pos.x, partner->pos.z, moveHistoryX, moveHistoryZ))) > 90.0f) {
                        wPartnerFollowState = 5;
                        break;
                    }

                    if ((partner->flags & NPC_FLAG_GROUNDED) && currentSnapshot->isJumping) {
                        wPartnerFollowState = 1;
                        break;
                    }
                }
            }

            if (!(partner->flags & NPC_FLAG_GROUNDED)) {
                partner->moveSpeed *= 0.5f;
            }
            partner->yaw = yaw;
            npc_move_heading(partner, partner->moveSpeed, partner->yaw);
            spawn_surface_effects(partner, (partner->moveSpeed < 4.0) ? SURFACE_INTERACT_WALK : SURFACE_INTERACT_RUN);
            surfaceType = get_collider_flags(partner->curFloor);
            if (surfaceType == SURFACE_TYPE_SPIKES
                || surfaceType == SURFACE_TYPE_LAVA
                || ((partner->flags & NPC_FLAG_GROUNDED) && (partner->flags & NPC_FLAG_COLLDING_FORWARD_WITH_WORLD))
            ) {
                if (!func_800EA4B0(partner->curWall)) {
                    D_8010CFBC++;
                    if (D_8010CFBC >= 40) {
                        D_8010CFBC = 0;
                    }
                    currentSnapshot = &gPlayerMoveHistory[D_8010CFBC];
                    moveHistoryX = currentSnapshot->pos.x;
                    moveHistoryZ = currentSnapshot->pos.z;
                    if (fabsf(get_clamped_angle_diff(partner->yaw, atan2(partner->pos.x, partner->pos.z, moveHistoryX, moveHistoryZ))) > 90.0f) {
                        wPartnerFollowState = 5;
                        return;
                    }
                } else {
                    wPartnerFollowState = 1;
                    return;
                }
            }
            break;
        case 1:
            surfaceType = get_collider_flags(partner->curFloor);
            if (D_8010CFBC == gPlayerMoveHistoryIndex) {
                if (surfaceType == SURFACE_TYPE_SPIKES || surfaceType == SURFACE_TYPE_LAVA) {
                    moveHistoryX = partner->pos.x;
                    moveHistoryY = playerStatus->pos.y;
                    moveHistoryZ = partner->pos.z;
                    add_vec2D_polar(&moveHistoryX, &moveHistoryZ, 6.0f, atan2(partner->pos.x, partner->pos.z, playerStatus->pos.x, playerStatus->pos.z));
                } else {
                    break;
                }
            } else {
                D_8010CFBC++;
                if (D_8010CFBC >= 40) {
                    D_8010CFBC = 0;
                }
                currentSnapshot = &gPlayerMoveHistory[D_8010CFBC];
                moveHistoryX = currentSnapshot->pos.x;
                moveHistoryY = currentSnapshot->pos.y;
                moveHistoryZ = currentSnapshot->pos.z;
            }
            partner->moveToPos.x = moveHistoryX;
            partner->moveToPos.y = moveHistoryY;
            partner->moveToPos.z = moveHistoryZ;
            partner->duration = 0;
            partner->jumpScale = 3.0f;
            partner->moveSpeed = 6.0f;
            partner->planarFlyDist = dist2D(partner->pos.x, partner->pos.z, partner->moveToPos.x, partner->moveToPos.z);
            partner->yaw = atan2(partner->pos.x, partner->pos.z, partner->moveToPos.x, partner->moveToPos.z);
            if (partner->planarFlyDist > 50.0) {
                partner->planarFlyDist = 50.0f;
            }
            distance = partner->planarFlyDist;
            y = partner->moveToPos.y - partner->pos.y;
            if (distance < wPartnerTetherDistance && !(surfaceType == SURFACE_TYPE_SPIKES || surfaceType == SURFACE_TYPE_LAVA)) {
                partner->jumpVel = 0.0f;
                partner->yaw = atan2(partner->pos.x, partner->pos.z, playerStatus->pos.x, playerStatus->pos.z);
                wPartnerFollowState = 0;
                return;
            }
            partner->duration = distance / partner->moveSpeed;
            if (partner->duration < 10) {
                partner->duration = 10;
            }
            partner->moveSpeed = partner->planarFlyDist / partner->duration;
            partner->jumpVel = (y + partner->jumpScale * partner->duration * partner->duration * 0.5f) / partner->duration;
            if (partner->jumpVel > 20.0) {
                partner->jumpVel = 20.0f;
            }
            if (partner->jumpVel < 0.0) {
                partner->jumpVel = 0.0f;
            }
            if (!(surfaceType == SURFACE_TYPE_SPIKES || surfaceType == SURFACE_TYPE_LAVA)) {
                partner->curAnim = gPartnerAnimations[wCurrentPartnerId].jump;
            } else {
                partner->curAnim = gPartnerAnimations[wCurrentPartnerId].hurt;
            }

            partner->moveToPos.x = partner->pos.x;
            partner->moveToPos.y = partner->pos.y;
            partner->moveToPos.z = partner->pos.z;
            partner->flags |= NPC_FLAG_JUMPING;
            wPartnerFollowState = 2;
            // fallthrough
        case 2:
            partner->jumpVel -= partner->jumpScale;
            partner->pos.y += partner->jumpVel;
            if (partner->jumpVel <= 0.0f) {
                partner->curAnim = gPartnerAnimations[wCurrentPartnerId].fall;
            }
            if (partner->pos.y < -2000.0f) {
                partner->curAnim = gPartnerAnimations[wCurrentPartnerId].fly;
                partner->flags &= ~NPC_FLAG_JUMPING;
                partner->jumpVel = 0.0f;
                partner->yaw = atan2(partner->pos.x, partner->pos.z, playerStatus->pos.x, playerStatus->pos.z);
                partner->pos.x = playerStatus->pos.x;
                partner->pos.y = playerStatus->pos.y;
                partner->pos.z = playerStatus->pos.z;
                wPartnerFollowState = 5;
                return;
            }
            if (partner->jumpVel <= 0.0f) {
                distance = fabsf(partner->jumpVel) + 11.0f;
                x = partner->pos.x;
                y = partner->pos.y + distance;
                z = partner->pos.z;
                if (npc_raycast_down_around(partner->collisionChannel, &x, &y, &z, &distance, partner->yaw, partner->collisionDiameter) != 0) {
                    if (distance <= fabsf(partner->jumpVel) + 22.0f) {
                        partner->curAnim = gPartnerAnimations[wCurrentPartnerId].fly;
                        partner->flags &= ~NPC_FLAG_JUMPING;
                        partner->jumpVel = 0.0f;
                        partner->pos.y = y;
                        partner->yaw = atan2(x, z, playerStatus->pos.x, playerStatus->pos.z);
                        spawn_surface_effects(partner, SURFACE_INTERACT_LAND);
                        wPartnerFollowState = 0;
                        distance = dist2D(partner->pos.x, partner->pos.z, partner->moveToPos.x, partner->moveToPos.z);
                        if (distance < 5.0) {
                            partner->pos.x = playerStatus->pos.x;
                            partner->pos.y = playerStatus->pos.y;
                            partner->pos.z = playerStatus->pos.z;
                            add_vec2D_polar(&partner->pos.x, &partner->pos.z, 5.0f, clamp_angle((cameras[CAM_DEFAULT].curYaw + 90.0f) - playerStatus->spriteFacingAngle));
                            wPartnerFollowState = 5;
                        }
                        break;
                    }
                }
            }
            npc_move_heading(partner, partner->moveSpeed, partner->yaw);
            break;
        case 5:
            currentSnapshot = &gPlayerMoveHistory[D_8010CFBC];
            moveHistoryX = currentSnapshot->pos.x;
            moveHistoryZ = currentSnapshot->pos.z;
            x = partner->pos.x;
            y = partner->pos.y;
            z = partner->pos.z;
            distance = dist2D(partner->pos.x, partner->pos.z, playerStatus->pos.x, playerStatus->pos.z);
            if (distance <= wPartnerTetherDistance) {
                if (D_8010CFCA == 0) {
                    partner->moveSpeed = 0.0f;
                    partner->jumpScale = 0.0f;
                    partner->curAnim = gPartnerAnimations[wCurrentPartnerId].idle;
                    if (playerStatus->actionState == ACTION_STATE_TALK) {
                        D_8010CFCA = 0;
                    }
                    surfaceType = get_collider_flags(partner->curFloor);
                    if (surfaceType == SURFACE_TYPE_SPIKES || surfaceType == SURFACE_TYPE_LAVA) {
                        wPartnerFollowState = 0;
                        return;
                    }
                } else {
                    temp_a3 = clamp_angle(cameras[CAM_DEFAULT].curYaw + (playerStatus->spriteFacingAngle < 180.0f ? 90.0f : -90.0f));
                    partner->moveToPos.x = playerStatus->pos.x;
                    partner->moveToPos.y = playerStatus->pos.y;
                    partner->moveToPos.z = playerStatus->pos.z;
                    add_vec2D_polar(&partner->moveToPos.x, &partner->moveToPos.z, wPartnerTetherDistance - 10.0f, temp_a3);
                    yaw = atan2(partner->pos.x, partner->pos.z, partner->moveToPos.x, partner->moveToPos.z);
                    distance = dist2D(partner->pos.x, partner->pos.z, partner->moveToPos.x, partner->moveToPos.z);
                    partner->moveSpeed = 2.0f;
                    if (distance > 2.0f) {
                        partner->yaw = yaw;
                        partner->curAnim = gPartnerAnimations[wCurrentPartnerId].run;
                        if (!(partner->flags & NPC_FLAG_COLLDING_FORWARD_WITH_WORLD)) {
                            D_800F803A = 0;
                        } else {
                            D_800F803A++;
                            if (D_800F803A > 10) {
                                yaw = playerStatus->targetYaw;
                                partner->moveSpeed = 0.0f;
                                partner->jumpScale = 0.0f;
                                partner->renderYaw = yaw;
                                partner->curAnim = gPartnerAnimations[wCurrentPartnerId].idle;
                                if (D_8010CFCA == 2 || playerStatus->actionState == ACTION_STATE_TALK) {
                                    D_8010CFCA = 0;
                                }
                            }
                        }
                    } else {
                        yaw = atan2(partner->pos.x, partner->pos.z, playerStatus->pos.x, playerStatus->pos.z);
                        partner->yaw = yaw;
                        partner->moveSpeed = 0.0f;
                        partner->jumpScale = 0.0f;
                        partner->curAnim = gPartnerAnimations[wCurrentPartnerId].idle;
                        if (D_8010CFCA == 2 || playerStatus->actionState == ACTION_STATE_TALK) {
                            D_8010CFCA = 0;
                        }
                    }
                    partner->yaw = yaw;
                    npc_move_heading(partner, partner->moveSpeed, yaw);
                    spawn_surface_effects(partner, (partner->moveSpeed < 4.0) ? SURFACE_INTERACT_WALK : SURFACE_INTERACT_RUN);
                    distance = 1000.0f;
                    x = partner->pos.x;
                    z = partner->pos.z;
                    y = partner->pos.y + partner->collisionHeight;
                    if (npc_raycast_down_around(partner->collisionChannel, &x, &y, &z, &distance, partner->yaw, partner->collisionDiameter) != 0) {
                        s32 surfaceType = get_collider_flags(NpcHitQueryColliderID);
                        if (surfaceType == SURFACE_TYPE_SPIKES || surfaceType == SURFACE_TYPE_LAVA) {
                            partner->yaw = clamp_angle(yaw + 180.0f);
                            npc_move_heading(partner, partner->moveSpeed, partner->yaw);
                            partner->moveSpeed = 0.0f;
                            partner->jumpScale = 0.0f;
                            partner->curAnim = gPartnerAnimations[wCurrentPartnerId].idle;
                            if (D_8010CFCA == 2) {
                                D_8010CFCA = 0;
                            } else if (playerStatus->actionState == ACTION_STATE_TALK) {
                                D_8010CFCA = 0;
                            }
                        } else if (!func_800EA4B0(NpcHitQueryColliderID)) {
                            D_8010CFCA = 2;
                        }
                    }
                    break;
                }
            }
            distance = dist2D(partner->pos.x, partner->pos.z, playerStatus->pos.x, playerStatus->pos.z);
            if (distance <= wPartnerTetherDistance) {
                if (!func_800EA4B0(NpcHitQueryColliderID)) {
                    D_8010CFCA = 2;
                }
            } else {
                while (TRUE) {
                    if (currentSnapshot->isJumping) {
                        break;
                    }
                    yaw = atan2(partner->pos.x, partner->pos.z, moveHistoryX, moveHistoryZ);
                    if (fabsf(get_clamped_angle_diff(yaw, atan2(partner->pos.x, partner->pos.z, playerStatus->pos.x, playerStatus->pos.z))) < 90.0f) {
                        break;
                    }
                    if (D_8010CFBC == gPlayerMoveHistoryIndex) {
                        break;
                    }
                    D_8010CFBC++;
                    if (D_8010CFBC >= 40) {
                        D_8010CFBC = 0;
                    }
                    currentSnapshot = &gPlayerMoveHistory[D_8010CFBC];
                    moveHistoryX = currentSnapshot->pos.x;
                    moveHistoryZ = currentSnapshot->pos.z;
                }
                if (!currentSnapshot->isJumping) {
                    wPartnerFollowState = 0;
                    return;
                }
                while (TRUE) {
                    if (!currentSnapshot->isJumping) {
                        break;
                    }
                    yaw = atan2(partner->pos.x, partner->pos.z, moveHistoryX, moveHistoryZ);
                    if (fabsf(get_clamped_angle_diff(yaw, atan2(partner->pos.x, partner->pos.z, playerStatus->pos.x, playerStatus->pos.z))) < 90.0f) {
                        break;
                    }
                    if (D_8010CFBC == gPlayerMoveHistoryIndex) {
                        break;
                    }
                    D_8010CFBC++;
                    if (D_8010CFBC >= 40) {
                        D_8010CFBC = 0;
                    }
                    currentSnapshot = &gPlayerMoveHistory[D_8010CFBC];
                    moveHistoryX = currentSnapshot->pos.x;
                    moveHistoryZ = currentSnapshot->pos.z;
                }
                wPartnerFollowState = 1;
                return;
            }
            break;
        case 15:
            switch (D_8010CFCE) {
                case 0:
                    angle = clamp_angle(func_800E5348() + 180.0f);
                    partner->moveToPos.x = playerStatus->pos.x;
                    partner->moveToPos.y = playerStatus->pos.y;
                    partner->moveToPos.z = playerStatus->pos.z;
                    add_vec2D_polar(&partner->moveToPos.x, &partner->moveToPos.z, playerStatus->colliderDiameter, angle);
                    distance = dist2D(partner->pos.x, partner->pos.z, partner->moveToPos.x, partner->moveToPos.z);
                    wPartnerMoveSpeed = distance / wPartnerMoveTime;
                    partner->moveSpeed = wPartnerMoveSpeed;
                    partner->curAnim = gPartnerAnimations[wCurrentPartnerId].anims[wPartnerMoveSpeed >= 4.0 ? PARTNER_ANIM_INDEX_RUN : PARTNER_ANIM_INDEX_WALK];
                    yaw = atan2(partner->pos.x, partner->pos.z, partner->moveToPos.x, partner->moveToPos.z);
                    partner->yaw = D_800F8034 = yaw;
                    D_8010CFCE++;
                    // fallthrough
                case 1:
                    if (wPartnerMoveTime != 0) {
                        wPartnerMoveTime--;
                        if (partner->jumpScale != 0.0f) {
                            partner->jumpVel -= partner->jumpScale;
                            partner->pos.y += partner->jumpVel;
                            if (partner->jumpVel <= 0.0f) {
                                partner->curAnim = gPartnerAnimations[wCurrentPartnerId].fall;
                            }
                            if (partner->jumpVel <= 0.0f) {
                                distance = fabsf(partner->jumpVel) + 11.0f;
                                x = partner->pos.x;
                                y = partner->pos.y + distance;
                                z = partner->pos.z;
                                if ((npc_raycast_down_around(partner->collisionChannel, &x, &y, &z, &distance, partner->yaw, partner->collisionDiameter) != 0) && (distance <= (fabsf(partner->jumpVel) + 22.0f))) {
                                    partner->curAnim = gPartnerAnimations[wCurrentPartnerId].anims[partner->moveSpeed >= 4.0 ? PARTNER_ANIM_INDEX_RUN : PARTNER_ANIM_INDEX_WALK];
                                    partner->jumpScale = 0.0f;
                                    partner->jumpVel = 0.0f;
                                    partner->pos.y = y;
                                    partner->flags &= ~NPC_FLAG_JUMPING;
                                }
                            }
                        }
                        partner->moveSpeed = wPartnerMoveSpeed;
                        partner->yaw = D_800F8034;
                        npc_move_heading(partner, partner->moveSpeed, partner->yaw);
                        spawn_surface_effects(partner, (partner->moveSpeed < 4.0) ? SURFACE_INTERACT_WALK : SURFACE_INTERACT_RUN);
                    } else {
                        partner_clear_player_tracking(partner);
                        partner->moveSpeed = 0.0f;
                        partner->jumpScale = 0.0f;
                        partner->curAnim = gPartnerAnimations[wCurrentPartnerId].idle;
                        partner->yaw = clamp_angle((cameras[CAM_DEFAULT].curYaw + 270.0f) - playerStatus->spriteFacingAngle);
                        wPartnerMoveTime = 30;
                        D_8010CFCE++;
                    }
                    return;
                case 2:
                    if (wPartnerMoveTime != 0) {
                        wPartnerMoveTime--;
                        return;
                    }
                    wPartnerFollowState = 0;
                    D_8010CFCA = 0;
                    D_8010CFCE = 0;
            }
            break;
        case 20:
            partner_move_to_goal(partner, FALSE);
            break;
        case 40:
            if (partner->flags & NPC_FLAG_GROUNDED) {
                if (func_800EA4B0(partner->curFloor)) {
                    wPartnerFollowState = 50;
                    partner->curAnim = gPartnerAnimations[wCurrentPartnerId].idle;
                } else {
                    wPartnerFollowState = 1;
                }
                break;
            }
            partner->jumpScale = 3.0f;
            partner->jumpVel -= partner->jumpScale;
            partner->pos.y += partner->jumpVel;
            if (partner->jumpVel <= 0.0f) {
                partner->curAnim = gPartnerAnimations[wCurrentPartnerId].fall;
            }
            if (partner->pos.y < -2000.0f) {
                partner->curAnim = gPartnerAnimations[wCurrentPartnerId].idle;
                partner->flags &= ~NPC_FLAG_JUMPING;
                partner->jumpVel = 0.0f;
                partner->yaw = atan2(partner->pos.x, partner->pos.z, playerStatus->pos.x, playerStatus->pos.z);
                partner->pos.x = playerStatus->pos.x;
                partner->pos.y = playerStatus->pos.y;
                partner->pos.z = playerStatus->pos.z;
                wPartnerFollowState = 50;
                return;
            }
            distance = fabsf(partner->jumpVel) + 11.0f;
            x = partner->pos.x;
            y = partner->pos.y + distance;
            z = partner->pos.z;
            if (npc_raycast_down_around(partner->collisionChannel, &x, &y, &z, &distance, partner->yaw, partner->collisionDiameter) != 0) {
                partner->curAnim = gPartnerAnimations[wCurrentPartnerId].idle;
                partner->flags &= ~NPC_FLAG_JUMPING;
                partner->jumpVel = 0.0f;
                partner->pos.y = y;
                partner->yaw = atan2(x, z, playerStatus->pos.x, playerStatus->pos.z);
                spawn_surface_effects(partner, SURFACE_INTERACT_LAND);
                wPartnerFollowState = 50;
            }
            break;
        case 50:
            break;
    }
}

static const f32 padding = 0.0f;

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
        wPartnerFollowState = 0;
        D_8010CFCA = 0;
    } else if (D_8010CFC4 == 0) {
        wPartnerFollowState = 15;
        D_8010CFCA = 2;
    } else if (D_8010CFC4 == 1 || D_8010CFC4 == 3) {
        D_8010CFC4 = 0;
        wPartnerFollowState = 0;
        D_8010CFCA = 0;
    } else if (D_8010CFC4 == 2) {
        wPartnerFollowState = 50;
        D_8010CFCA = 0;
    }

    D_8010CFCE = 0;
    D_8010CFCC = 0;
    wPartnerMoveTime = 16;
    wPartnerTetherDistance = 40.0f;
    partner->curAnim = gPartnerAnimations[wCurrentPartnerId].idle;
    func_800EA5B8(partner);
    partner->collisionChannel = COLLIDER_FLAG_IGNORE_PLAYER;
    partner->flags |= NPC_FLAG_IGNORE_PLAYER_COLLISION;
    partner->flags &= ~NPC_FLAG_GRAVITY;
}

void partner_flying_update_player_tracking(Npc* partner) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    PlayerPathElement* currentSnapshot;
    f32 effectiveY;
    s32 isPlayerJumping = FALSE;

    effectiveY = playerStatus->pos.y;
    if ((playerStatus->actionState == ACTION_STATE_HIT_LAVA) || (playerStatus->actionState == ACTION_STATE_HIT_FIRE)) {
        effectiveY = playerStatus->lastGoodPos.y + partner->collisionHeight + 5;
    }
    currentSnapshot = &gPlayerMoveHistory[gPlayerMoveHistoryIndex];
    if ((!currentSnapshot->isJumping || !isPlayerJumping) && (currentSnapshot->pos.x != playerStatus->pos.x || currentSnapshot->pos.y != effectiveY
        || currentSnapshot->pos.z != playerStatus->pos.z)) {
        if (D_8010CFBC != gPlayerMoveHistoryIndex + 1) {
            if (++gPlayerMoveHistoryIndex >= ARRAY_COUNT(gPlayerMoveHistory)) {
                gPlayerMoveHistoryIndex = 0;
            }
            currentSnapshot = &gPlayerMoveHistory[gPlayerMoveHistoryIndex];
            currentSnapshot->pos.x = playerStatus->pos.x;
            currentSnapshot->pos.y = effectiveY;
            currentSnapshot->pos.z = playerStatus->pos.z;
            currentSnapshot->isJumping = isPlayerJumping;
        }
    }
}

void partner_flying_update_motion(Npc* partner) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    PartnerStatus* partnerStatus = &gPartnerStatus;
    f32 x, y, z, hitDepth;
    f32 var_f0;
    f32 var_f2;

    if (!gGameStatusPtr->multiplayerEnabled ||
        (playerStatus->flags & (PS_FLAG_INPUT_DISABLED | PS_FLAG_NO_STATIC_COLLISION)) ||
        partnerStatus->inputDisabledCount ||
        partnerStatus->partnerAction_unk_2)
    {
        if (!(playerStatus->animFlags & PA_FLAG_OPENED_HIDDEN_PANEL) || D_800F8020 == 0) {
            partner_flying_follow_player(partner);
        }
        if (partnerStatus->pressedButtons & (BUTTON_B | BUTTON_Z | BUTTON_C_DOWN | BUTTON_C_LEFT)) {
            partnerStatus->partnerAction_unk_2 = FALSE;
        }
    }
    if (wPartnerFollowState != 50 && fabsf(partner->pos.y - playerStatus->pos.y) > 1000.0f) {
        partner->pos.x = playerStatus->pos.x;
        partner->pos.y = playerStatus->pos.y;
        partner->pos.z = playerStatus->pos.z;
        partner->jumpVel = 0.0f;
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
        if (wPartnerFollowState != 50) {
            x = partner->pos.x;
            y = partner->pos.y;
            z = partner->pos.z;
            hitDepth = 1000.0f;
            if (npc_raycast_down_around(COLLIDER_FLAG_IGNORE_PLAYER, &x, &y, &z, &hitDepth, partner->yaw, partner->collisionDiameter) == 0) {
                y = playerStatus->pos.y;
            }

            if (partner->pos.y <= y + partner->collisionHeight + 2.0f) {
                if (playerStatus->curSpeed != 0.0f) {
                    D_800F84F8 = ((y + (partner->collisionHeight / 2) + 2.0f) - partner->pos.y) * 0.125f;
                } else {
                    if (y < playerStatus->pos.y) {
                        var_f0 = playerStatus->pos.y + 10.0f - partner->pos.y;
                    } else {
                        var_f0 = y + 10.0f - partner->pos.y;
                    }
                    var_f2 = 0.25f;
                    D_800F84F8 = var_f0 * var_f2;
                }
            } else {
                if (playerStatus->pos.y + playerStatus->colliderHeight < y) {
                    D_800F84F8 = (y + partner->collisionHeight - partner->pos.y) * 0.125f;
                    if (partner->pos.y + D_800F84F8 <= y + partner->collisionHeight) {
                        D_800F84F8 = (y + partner->collisionHeight - partner->pos.y) * 0.25f;
                    }
                } else {
                    var_f0 = (playerStatus->pos.y + playerStatus->colliderHeight + 5.0f) - partner->pos.y;
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

void partner_flying_follow_player(Npc* partner) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    Camera* camera = &gCameras[CAM_DEFAULT];
    f32 x, y, z;
    f32 distance;
    f32 yaw;
    f32 temp_a3;
    f32 temp_f0_15;
    f32 var_f12;
    f32 moveHistoryX, moveHistoryY, moveHistoryZ;
    PlayerPathElement* currentSnapshot;

    switch (wPartnerFollowState) {
        case 0:
            var_f12 = 0.0f;
            x = partner->pos.x;
            y = partner->pos.y;
            z = partner->pos.z;
            wSavedPartnerPosX = x;
            wSavedPartnerPosY = y;
            wSavedPartnerPosZ = z;
            currentSnapshot = &gPlayerMoveHistory[D_8010CFBC];
            moveHistoryX = currentSnapshot->pos.x;
            moveHistoryY = currentSnapshot->pos.y;
            moveHistoryZ = currentSnapshot->pos.z;
            if (wPartnerTetherDistance < 20.0f) {
                var_f12 = (20.0f - wPartnerTetherDistance) * 0.5f;
            }
            partner->pos.y = y + (moveHistoryY + 20.0f + var_f12 - y) * 0.125f;
            partner->moveSpeed = 3.0f;
            y = partner->pos.y;
            distance = dist2D(partner->pos.x, partner->pos.z, playerStatus->pos.x, playerStatus->pos.z);
            if (distance >= 50.0) {
                if (partner->pos.y >= playerStatus->pos.y) {
                    partner->moveSpeed = distance * 0.25f;
                } else {
                    partner->moveSpeed = 8.0f;
                }
            }
            if (wPartnerTetherDistance < 20.0f) {
                partner->moveSpeed = 4.0f;
            }

            while (TRUE) {
                yaw = atan2(x, z, moveHistoryX, moveHistoryZ);
                distance = dist2D(x, z, moveHistoryX, moveHistoryZ);
                if (partner->moveSpeed < distance) {
                    if (partner->pos.y >= playerStatus->pos.y) {
                        if (partner->moveSpeed >= distance * 0.25f) {
                            partner->moveSpeed = distance * 0.25f;
                        } else {
                            partner->moveSpeed += distance * 0.0625f;
                        }
                    } else {
                        if (partner->moveSpeed > 6.0) {
                            partner->moveSpeed = 6.0f;
                        } else {
                            partner->moveSpeed += 1.0;
                        }
                    }
                    break;
                }
                if (D_8010CFBC == gPlayerMoveHistoryIndex) {
                    yaw = partner->yaw;
                    partner->moveSpeed = 0.0f;
                    partner->jumpScale = 0.0f;
                    partner->curAnim = gPartnerAnimations[wCurrentPartnerId].idle;
                    break;
                }
                distance = dist2D(partner->pos.x, partner->pos.z, playerStatus->pos.x, playerStatus->pos.z);
                if (distance <= wPartnerTetherDistance) {
                    wPartnerFollowState = 5;
                    yaw = partner->yaw;
                    partner->moveSpeed = 0.0f;
                    partner->jumpScale = 0.0f;
                    partner->curAnim = gPartnerAnimations[wCurrentPartnerId].idle;
                    break;
                }
                D_8010CFBC++;
                if (D_8010CFBC >= 40) {
                    D_8010CFBC = 0;
                }
                currentSnapshot = &gPlayerMoveHistory[D_8010CFBC];
                moveHistoryX = currentSnapshot->pos.x;
                moveHistoryZ = currentSnapshot->pos.z;
            }
            partner->yaw = yaw;
            npc_move_heading(partner, partner->moveSpeed, yaw);
            if (partner->flags & 0x4000) {
                wPartnerFollowState = 1;
                return;
            }
            break;
        case 1:
        case 3:
            if (D_8010CFBC != gPlayerMoveHistoryIndex) {
                D_8010CFBC++;
                if (D_8010CFBC >= 40) {
                    D_8010CFBC = 0;
                }
                currentSnapshot = &gPlayerMoveHistory[D_8010CFBC];
                moveHistoryX = currentSnapshot->pos.x;
                moveHistoryY = currentSnapshot->pos.y;
                moveHistoryZ = currentSnapshot->pos.z;
                partner->moveToPos.x = moveHistoryX;
                partner->moveToPos.y = moveHistoryY;
                partner->moveToPos.z = moveHistoryZ;
                partner->duration = 0;
                partner->jumpScale = 1.3f;
                if (wPartnerFollowState == 1) {
                    partner->moveSpeed = 6.0f;
                }
                partner->planarFlyDist = dist2D(partner->pos.x, partner->pos.z, partner->moveToPos.x, partner->moveToPos.z);
                partner->yaw = atan2(partner->pos.x, partner->pos.z, partner->moveToPos.x, partner->moveToPos.z);
                if (partner->planarFlyDist > 50.0) {
                    partner->planarFlyDist = 50.0f;
                }
                distance = partner->planarFlyDist;
                y = partner->moveToPos.y - partner->pos.y;
                if (partner->planarFlyDist < y) {
                    distance = y;
                }
                if (wPartnerFollowState == 1) {
                    if (distance < wPartnerTetherDistance) {
                        partner->jumpVel = 0.0f;
                        partner->yaw = atan2(partner->pos.x, partner->pos.z, playerStatus->pos.x, playerStatus->pos.z);
                        wPartnerFollowState = 5;
                        return;
                    }
                    partner->duration = distance / partner->moveSpeed;
                    if (partner->duration < 10) {
                        partner->duration = 10;
                    }
                    partner->moveSpeed = partner->planarFlyDist / partner->duration;
                } else {
                    partner->duration = 10;
                }

                partner->jumpVel = (y + (partner->jumpScale * partner->duration * partner->duration * 0.5f)) / partner->duration;
                if (partner->jumpVel > 20.0) {
                    partner->jumpVel = 20.0f;
                }
                wPartnerFollowState = 2;
                partner->curAnim = gPartnerAnimations[wCurrentPartnerId].jump;
                partner->moveToPos.x = partner->pos.x;
                partner->moveToPos.y = partner->pos.y;
                partner->moveToPos.z = partner->pos.z;
            }
            break;
        case 2:
            partner->jumpVel -= partner->jumpScale;
            partner->pos.y += partner->jumpVel;
            if (partner->jumpVel <= 0.0f) {
                partner->curAnim = gPartnerAnimations[wCurrentPartnerId].fall;
            }
            npc_move_heading(partner, partner->moveSpeed, partner->yaw);
            if (partner->jumpVel <= 0.0f) {
                if (partner->pos.y < partner->moveToPos.y) {
                    partner->curAnim = gPartnerAnimations[wCurrentPartnerId].fly;
                    partner->jumpVel = 0.0f;
                    partner->pos.y = partner->moveToPos.y;
                    partner->yaw = atan2(partner->pos.x, partner->pos.z, playerStatus->pos.x, playerStatus->pos.z);
                    wPartnerFollowState = 0;
                    distance = dist2D(partner->pos.x, partner->pos.z, partner->moveToPos.x, partner->moveToPos.z);
                    if (distance < wPartnerTetherDistance) {
                        wPartnerFollowState = 15;
                    }
                }
            }
            break;
        case 5:
            x = partner->pos.x;
            y = partner->pos.y;
            z = partner->pos.z;
            currentSnapshot = &gPlayerMoveHistory[D_8010CFBC];
            moveHistoryX = currentSnapshot->pos.x;
            moveHistoryZ = currentSnapshot->pos.z;
            distance = dist2D(partner->pos.x, partner->pos.z, playerStatus->pos.x, playerStatus->pos.z);
            if (distance <= wPartnerTetherDistance) {
                if (D_8010CFCA == 0) {
                    partner->pos.y = y + (((playerStatus->pos.y + (playerStatus->colliderHeight - partner->collisionHeight / 2)) - partner->pos.y) * 0.03125);
                    y = partner->pos.y;
                    partner->moveSpeed = 0.0f;
                    partner->jumpScale = 0.0f;
                    partner->curAnim = gPartnerAnimations[wCurrentPartnerId].idle;
                    if (playerStatus->actionState == ACTION_STATE_TALK) {
                        D_8010CFCA = 0;
                    }
                } else {
                    temp_a3 = clamp_angle(camera->curYaw + (playerStatus->spriteFacingAngle < 180.0f ? 90.0f : -90.0f));
                    partner->moveToPos.x = playerStatus->pos.x;
                    partner->moveToPos.y = playerStatus->pos.y;
                    partner->moveToPos.z = playerStatus->pos.z;
                    add_vec2D_polar(&partner->moveToPos.x, &partner->moveToPos.z, wPartnerTetherDistance - 10.0f, temp_a3);
                    yaw = atan2(partner->pos.x, partner->pos.z, partner->moveToPos.x, partner->moveToPos.z);
                    distance = dist2D(partner->pos.x, partner->pos.z, partner->moveToPos.x, partner->moveToPos.z);
                    partner->moveSpeed = 2.0f;
                    if (distance > 2.0f) {
                        partner->yaw = yaw;
                        partner->curAnim = gPartnerAnimations[wCurrentPartnerId].run;
                        if (!(partner->flags & NPC_FLAG_COLLDING_FORWARD_WITH_WORLD)) {
                            D_800F803A = 0;
                        } else {
                            D_800F803A++;
                            if (D_800F803A > 10) {
                                yaw = playerStatus->targetYaw;
                                partner->moveSpeed = 0.0f;
                                partner->jumpScale = 0.0f;
                                partner->renderYaw = yaw;
                                partner->curAnim = gPartnerAnimations[wCurrentPartnerId].idle;
                                if (D_8010CFCA == 2 || playerStatus->actionState == ACTION_STATE_TALK) {
                                    D_8010CFCA = 0;
                                }
                            }
                        }
                    } else {
                        yaw = atan2(partner->pos.x, partner->pos.z, playerStatus->pos.x, playerStatus->pos.z);
                        partner->yaw = yaw;
                        partner->moveSpeed = 0.0f;
                        partner->jumpScale = 0.0f;
                        partner->curAnim = gPartnerAnimations[wCurrentPartnerId].idle;
                        if (D_8010CFCA == 2 || playerStatus->actionState == ACTION_STATE_TALK) {
                            D_8010CFCA = 0;
                        }
                    }
                    partner->yaw = yaw;
                    npc_move_heading(partner, partner->moveSpeed, yaw);
                    return;
                }
            }

            distance = dist2D(partner->pos.x, partner->pos.z, playerStatus->pos.x, playerStatus->pos.z);
            if (!(distance <= wPartnerTetherDistance)) {
                while (TRUE) {
                    if (!currentSnapshot->isJumping) {
                        yaw = atan2(partner->pos.x, partner->pos.z, moveHistoryX, moveHistoryZ);
                        if (!(fabsf(get_clamped_angle_diff(yaw, atan2(partner->pos.x, partner->pos.z, playerStatus->pos.x, playerStatus->pos.z))) < 90.0f)) {
                            if (D_8010CFBC != gPlayerMoveHistoryIndex) {
                                D_8010CFBC++;
                                if (D_8010CFBC >= 40) {
                                    D_8010CFBC = 0;
                                }
                                currentSnapshot = &gPlayerMoveHistory[D_8010CFBC];
                                moveHistoryX = currentSnapshot->pos.x;
                                moveHistoryZ = currentSnapshot->pos.z;
                                continue;
                            }
                        }
                    }
                    break;
                }
                wPartnerFollowState = 0;
            }
            break;
        case 15:
            if (!(playerStatus->animFlags & PA_FLAG_CHANGING_MAP)) {
                switch (D_8010CFCE) {
                    case 0:
                        temp_f0_15 = clamp_angle(func_800E5348() + 180.0f);
                        partner->moveToPos.x = playerStatus->pos.x;
                        partner->moveToPos.y = playerStatus->pos.y;
                        partner->moveToPos.z = playerStatus->pos.z;
                        add_vec2D_polar(&partner->moveToPos.x, &partner->moveToPos.z, playerStatus->colliderDiameter, temp_f0_15);
                        distance = dist2D(partner->pos.x, partner->pos.z, partner->moveToPos.x, partner->moveToPos.z);
                        partner->moveSpeed = wPartnerMoveSpeed = distance / wPartnerMoveTime;
                        partner->curAnim = gPartnerAnimations[wCurrentPartnerId].anims[(partner->moveSpeed < 4.0) ? PARTNER_ANIM_INDEX_WALK : PARTNER_ANIM_INDEX_RUN];
                        yaw = atan2(partner->pos.x, partner->pos.z, partner->moveToPos.x, partner->moveToPos.z);
                        partner->yaw = D_800F8034 = yaw;
                        D_8010CFCE++;
                        // fallthrough
                    case 1:
                        if (wPartnerMoveTime != 0) {
                            x = partner->pos.x;
                            y = partner->pos.y + partner->collisionHeight;
                            z = partner->pos.z;
                            distance = partner->collisionHeight + 1;
                            wPartnerMoveTime--;
                            if (npc_raycast_down_around(COLLIDER_FLAG_IGNORE_PLAYER, &x, &y, &z, &distance, partner->yaw, partner->collisionDiameter) == 0) {
                                if (partner->collisionHeight + 5 < fabs((partner->pos.y - playerStatus->pos.y))) {
                                    partner->pos.y += (playerStatus->pos.y - partner->pos.y) / 10.0f;
                                }
                            } else {
                                partner->pos.y += (((playerStatus->pos.y + playerStatus->colliderHeight) - partner->pos.y) * 0.125f);
                            }
                            partner->moveSpeed = wPartnerMoveSpeed;
                            partner->yaw = D_800F8034;
                            x = partner->pos.x;
                            y = partner->pos.y;
                            z = partner->pos.z;
                            if (npc_test_move_taller_with_slipping(0, &x, &y, &z, partner->moveSpeed, partner->yaw, partner->collisionHeight, partner->collisionDiameter)) {
                                partner->pos.x += (x - partner->pos.x) / 5.0f;
                                partner->pos.z += (z - partner->pos.z) / 5.0f;
                            } else {
                                npc_move_heading(partner, partner->moveSpeed, partner->yaw);
                            }
                            return;
                        }
                        partner_clear_player_tracking(partner);
                        partner->moveSpeed = 0.0f;
                        partner->jumpScale = 0.0f;
                        partner->curAnim = gPartnerAnimations[wCurrentPartnerId].idle;
                        wPartnerFollowState = 0;
                        D_8010CFCA = 0;
                        D_8010CFCE = 0;
                        partner->yaw = clamp_angle((camera->curYaw + 270.0f) - playerStatus->spriteFacingAngle);
                }
            }
            break;
        case 20:
            partner_move_to_goal(partner, TRUE);
            break;
        case 40:
            partner->curAnim = gPartnerAnimations[wCurrentPartnerId].idle;
            break;
        case 50:
            break;
    }
}

s32 partner_init_put_away(Npc* partner) {
    partner->collisionChannel = COLLIDER_FLAG_IGNORE_PLAYER;
    wPartnerFollowState = 0;
    partner->flags |= NPC_FLAG_IGNORE_PLAYER_COLLISION;
    return wPartnerFollowState;
}

s32 partner_put_away(Npc* partner) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    f32 tempMoveToX;
    f32 tempMoveToY;
    f32 tempMoveToZ;
    f32 tempPosX;
    f32 tempPosZ;
    f32 tempPosY;
    f32 tempDuration;

    switch (wPartnerFollowState){
        case 0:
            tempMoveToX = partner->pos.x;
            tempMoveToY = partner->pos.y;
            tempMoveToZ = partner->pos.z;
            partner->flags &= ~NPC_FLAG_GRAVITY;
            partner->flags &= ~NPC_FLAG_FLYING;
            tempPosX = playerStatus->pos.x;
            partner->moveToPos.x = tempPosX;
            tempPosY = playerStatus->pos.y + (playerStatus->colliderHeight / 2);
            partner->moveToPos.y = playerStatus->pos.y + (playerStatus->colliderHeight / 2);
            tempPosZ = playerStatus->pos.z;
            wSavedPartnerPosX = tempMoveToX;
            wSavedPartnerPosY = tempMoveToY;
            wSavedPartnerPosZ = tempMoveToZ;
            partner->moveSpeed = 4.0f;
            partner->jumpScale = 1.6f;
            partner->moveToPos.z = tempPosZ;
            partner->planarFlyDist = dist2D(tempMoveToX, tempMoveToZ, tempPosX, tempPosZ);
            partner->yaw = atan2(tempMoveToX, tempMoveToZ, tempPosX, tempPosZ);
            partner->duration = 15;
            partner->moveSpeed = partner->planarFlyDist / partner->duration;
            tempMoveToY = tempPosY - tempMoveToY;
            partner->jumpVel = (tempMoveToY + partner->jumpScale * partner->duration * partner->duration * 0.5f) / partner->duration;
            partner->curAnim = gPartnerAnimations[wCurrentPartnerId].jump;
            enable_npc_blur(partner);
            wPartnerFollowState = 1;
            break;
        case 1:
            partner->jumpVel -= partner->jumpScale;
            partner->pos.y += partner->jumpVel;
            if (partner->jumpVel <= 0.0f) {
                partner->curAnim = gPartnerAnimations[wCurrentPartnerId].fall;
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
            if (partner->duration < 0) {
                wPartnerFollowState = 2;
            }
            break;
        case 2:
            partner->curAnim = gPartnerAnimations[wCurrentPartnerId].fly;
            partner->jumpVel = 0.0f;
            partner->pos.y = partner->moveToPos.y;
            disable_npc_blur(partner);
            return TRUE;
    }
    return FALSE;
}

s32 partner_init_get_out(Npc* npc) {
    npc->collisionChannel = COLLIDER_FLAG_IGNORE_PLAYER;
    wPartnerFollowState = 0;
    npc->flags |= NPC_FLAG_IGNORE_PLAYER_COLLISION;
    return wPartnerFollowState;
}

s32 partner_get_out(Npc* partner) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    Camera* camera = &gCameras[gCurrentCameraID];
    f32 x, y, z, hitDepth;
    f32 var_f0;

    f32 moveToX, moveToY, moveToZ;

    switch (wPartnerFollowState) {
        case 0:
            if (clamp_angle(playerStatus->spriteFacingAngle) < 180.0f) {
                partner->yaw = clamp_angle(camera->curYaw + 90.0f);
            } else {
                partner->yaw = clamp_angle(camera->curYaw - 90.0f);
            }
            partner->moveToPos.x = playerStatus->pos.x;
            partner->moveToPos.y = playerStatus->pos.y;
            if (wPartner->isFlying) {
                partner->moveToPos.y = playerStatus->pos.y;
            }
            partner->moveToPos.z = playerStatus->pos.z;
            add_vec2D_polar(&partner->moveToPos.x, &partner->moveToPos.z, playerStatus->colliderDiameter, partner->yaw);
            moveToX = partner->moveToPos.x;
            moveToY = partner->moveToPos.y;
            moveToZ = partner->moveToPos.z;
            if (!wPartner->isFlying) {
                x = moveToX;
                y = moveToY + partner->collisionHeight;
                z = moveToZ;
                add_vec2D_polar(&x, &z, 2.0f, gCameras[gCurrentCameraID].curYaw);
                hitDepth = 1000.0f;
                if (npc_raycast_down_around(COLLIDER_FLAG_IGNORE_PLAYER, &x, &y, &z, &hitDepth, partner->yaw, partner->collisionDiameter)) {
                    /// @bug? collider flags not properly masked with COLLIDER_FLAG_SURFACE_TYPE
                    s32 surfaceType = get_collider_flags(NpcHitQueryColliderID);

                    if ((surfaceType == SURFACE_TYPE_SPIKES || surfaceType == SURFACE_TYPE_LAVA) || (hitDepth > 100.0f)) {
                        moveToX = playerStatus->pos.x;
                        moveToY = playerStatus->pos.y;
                        moveToZ = playerStatus->pos.z;
                        add_vec2D_polar(&x, &z, 2.0f, gCameras[gCurrentCameraID].curYaw);
                    }
                } else {
                    moveToX = playerStatus->pos.x;
                    moveToY = playerStatus->pos.y;
                    moveToZ = playerStatus->pos.z;
                    add_vec2D_polar(&x, &z, 2.0f, gCameras[gCurrentCameraID].curYaw);
                }
            }

            x = partner->pos.x = playerStatus->pos.x;
            y = partner->pos.y = playerStatus->pos.y + (playerStatus->colliderHeight / 2);
            z = partner->pos.z = playerStatus->pos.z;

            partner->moveSpeed = 4.0f;
            partner->jumpScale = 1.2f;
            partner->planarFlyDist = dist2D(x, z, moveToX, moveToZ);
            partner->yaw = atan2(x, z, moveToX, moveToZ);
            partner->duration = partner->planarFlyDist / partner->moveSpeed;
            if (partner->duration < 10) {
                partner->duration = 10;
                partner->moveSpeed = partner->planarFlyDist / partner->duration;
            }
            partner->jumpVel = (moveToY - y + (partner->jumpScale * partner->duration * partner->duration * 0.5f)) /
                                    partner->duration;
            wPartnerFollowState = 1;
            y = moveToY - y;
            partner->curAnim = gPartnerAnimations[wCurrentPartnerId].jump;
            break;
        case 1:
            if (partner->jumpVel < 0.0f && npc_try_snap_to_ground(partner, fabsf(partner->jumpVel))) {
                wPartnerFollowState = 2;
                break;
            }
            partner->jumpVel -= partner->jumpScale;
            partner->pos.y += partner->jumpVel;
            if (partner->jumpVel <= 0.0f) {
                partner->curAnim = gPartnerAnimations[wCurrentPartnerId].fall;
            }
            npc_move_heading(partner, partner->moveSpeed, partner->yaw);
            npc_do_world_collision(partner);
            var_f0 = partner->duration;
            if (var_f0 > 10.0f) {
                var_f0 = 10.0f;
            }

            partner->scale.x = (10.0f - var_f0) / 10.0f;
            partner->scale.y = partner->scale.x;
            partner->scale.z = partner->scale.x;

            partner->duration--;
            if (partner->duration < 0) {
                wPartnerFollowState = 2;
            }
            break;
        case 2:
            partner->pos.y = partner->moveToPos.y;
            partner->jumpVel = 0.0f;
            partner->scale.x = 1.0f;
            partner->scale.y = 1.0f;
            partner->scale.z = 1.0f;
            partner->moveToPos.x = partner->pos.x;
            partner->moveToPos.y = partner->pos.y;
            partner->moveToPos.z = partner->pos.z;
            partner->pos.x = partner->pos.x;
            partner->pos.y = playerStatus->pos.y;
            if (wPartner->isFlying) {
                partner->pos.y = playerStatus->pos.y;
            }
            partner->pos.z = partner->pos.z;
            partner_clear_player_tracking(partner);
            partner->pos.x = partner->moveToPos.x;
            partner->pos.y = partner->moveToPos.y;
            partner->pos.z = partner->moveToPos.z;
            if (partner->flags & NPC_FLAG_GROUNDED) {
                if (!wPartner->isFlying) {
                    spawn_surface_effects(partner, SURFACE_INTERACT_LAND);
                }
            }
            return TRUE;
    }
    return FALSE;
}

void func_800EF300(void) {
    wPartnerFollowState = 40;
}

void func_800EF314(void) {
    wPartnerFollowState = 50;
}

void enable_partner_ai(void) {
    wPartnerFollowState = 0;
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

void partner_reset_tether_distance(void) {
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
    wPartnerFollowState = 15;
    D_8010CFCA = 0;
    wPartnerMoveTime = 10;
    D_8010CFCE = 0;
}

void func_800EF414(s32 posX, s32 posZ) {
    partner_set_goal_pos(posX, posZ);
    wPartnerFollowState = 20;
}

void func_800EF43C(void) {
    wPartnerFollowState = 0;
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

// forces the player to complete a direction flip if they are currently performing one
// the resulting camera-relative direction is returned as a boolean 'isFacingLeft'
s32 partner_force_player_flip_done(void) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    Camera* cameras = gCameras;
    s32 isFacingLeft;

    if (playerStatus->flipYaw[CAM_DEFAULT] == 0.0f) {
        if (!(playerStatus->spriteFacingAngle >= 90.0f) || !(playerStatus->spriteFacingAngle < 270.0f)) {
            isFacingLeft = TRUE;
            playerStatus->targetYaw = clamp_angle(cameras[CAM_DEFAULT].curYaw - 90.0f);
        } else {
            isFacingLeft = FALSE;
            playerStatus->targetYaw = clamp_angle(cameras[CAM_DEFAULT].curYaw + 90.0f);
        }
    } else if (get_clamped_angle_diff(cameras[CAM_DEFAULT].curYaw, playerStatus->targetYaw) < 0.0f) {
        isFacingLeft = TRUE;
        playerStatus->targetYaw = clamp_angle(cameras[CAM_DEFAULT].curYaw - 90.0f);

    } else {
        isFacingLeft = FALSE;
        playerStatus->targetYaw = clamp_angle(cameras[CAM_DEFAULT].curYaw + 90.0f);
    }

    playerStatus->curYaw = playerStatus->targetYaw;
    return isFacingLeft;
}

void partner_enable_input(void) {
    PartnerStatus* partnerStatus = &gPartnerStatus;

    partnerStatus->inputDisabledCount--;
    if (partnerStatus->inputDisabledCount < 0) {
        partnerStatus->inputDisabledCount = 0;
    }
}

void partner_disable_input(void) {
    PartnerStatus* partnerStatus = &gPartnerStatus;

    partnerStatus->inputDisabledCount++;
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

    transform_point(gCameras[CAM_DEFAULT].perspectiveMatrix,
                    playerStatus->pos.x, playerStatus->pos.y, playerStatus->pos.z, 1.0f,
                    &playerScreenX, &playerScreenY, &playerScreenZ, &W);
    transform_point(gCameras[CAM_DEFAULT].perspectiveMatrix, partner->pos.x, partner->pos.y, partner->pos.z, 1.0f,
                    &partnerScreenX, &partnerScreenY, &partnerScreenZ, &W);
    playerScreenX = fabsf(playerScreenX - partnerScreenX);
    playerScreenY = fabsf(playerScreenY - partnerScreenY);
    playerScreenZ = fabsf(playerScreenZ - partnerScreenZ);
    if (playerScreenX <= (partner->collisionDiameter + playerStatus->colliderDiameter) * 0.9f &&
        playerScreenY <= partner->collisionHeight + playerStatus->colliderHeight && playerScreenZ <= 4.0)
    {
        npc_move_heading(partner, 1.0f,
                         atan2(playerStatus->pos.x, playerStatus->pos.z, partner->pos.x, partner->pos.z));
        add_vec2D_polar(&partner->pos.x, &partner->pos.z, 2.0f, gCameras[gCurrentCameraID].curYaw);
    }
}

void partner_move_to_goal(Npc* partner, s32 isFlying) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    f32 x, y, z, temp;
    s32 var_a1;

    switch (D_8010CFCE) {
        case 0:
            D_8010CFCE++;
            partner->moveToPos.y = playerStatus->pos.y;
            partner->moveToPos.x = wPartnerMoveGoalX;
            partner->moveToPos.z = wPartnerMoveGoalZ;
            D_800F8034 = atan2(partner->pos.x, partner->pos.z, partner->moveToPos.x, partner->moveToPos.z);
            partner->yaw = D_800F8034;
            add_vec2D_polar(&partner->moveToPos.x, &partner->moveToPos.z, 5.0f, D_800F8034);
            wPartnerMoveTime = 18;
            temp = dist2D(partner->pos.x, partner->pos.z, partner->moveToPos.x, partner->moveToPos.z);
            partner->moveSpeed = wPartnerMoveSpeed = temp / wPartnerMoveTime;
            partner->curAnim = gPartnerAnimations[wCurrentPartnerId].anims[
                (partner->moveSpeed >= 4.0) ? PARTNER_ANIM_INDEX_RUN : PARTNER_ANIM_INDEX_WALK];
        case 1:
            if (wPartnerMoveTime != 0) {
                wPartnerMoveTime--;
                if (!isFlying) {
                    if (!(partner->flags & NPC_FLAG_GROUNDED)) {
                        partner->pos.y = playerStatus->pos.y;
                    }
                    if (partner->jumpVel != 0.0f) {
                        partner->jumpVel -= partner->jumpScale;
                        partner->pos.y += partner->jumpVel;
                        if (partner->jumpVel <= 0.0f) {
                            partner->curAnim = gPartnerAnimations[wCurrentPartnerId].fall;
                        }

                        if (partner->jumpVel <= 0.0f) {
                            temp = fabsf(partner->jumpVel) + partner->collisionHeight;
                            y = partner->pos.y + partner->collisionHeight;
                            x = partner->pos.x;
                            z = partner->pos.z;

                            if (npc_raycast_down_around(partner->collisionChannel, &x, &y, &z, &temp,
                                                       partner->yaw, partner->collisionDiameter) &&
                                (temp <= fabsf(partner->jumpVel) + 22.0f))
                            {
                                partner->curAnim = gPartnerAnimations[wCurrentPartnerId].anims[
                                    (partner->moveSpeed >= 4.0) ? PARTNER_ANIM_INDEX_RUN : PARTNER_ANIM_INDEX_WALK];
                                partner->jumpScale = 0.0f;
                                partner->jumpVel = 0.0f;
                                partner->pos.y = y;
                                partner->flags &= ~NPC_FLAG_JUMPING;
                            }
                        }
                    }
                    partner->moveSpeed = wPartnerMoveSpeed;
                    partner->yaw = D_800F8034;
                    npc_move_heading(partner, partner->moveSpeed, partner->yaw);
                    partner->curAnim = gPartnerAnimations[wCurrentPartnerId].anims[
                        (partner->moveSpeed >= 4.0) ? PARTNER_ANIM_INDEX_RUN : PARTNER_ANIM_INDEX_WALK];
                    npc_do_world_collision(partner);
                } else {
                    if (fabs(partner->pos.y - playerStatus->pos.y) > 5.0) {
                        partner->pos.y += (playerStatus->pos.y - partner->pos.y) * 0.5f;
                    }
                    partner->moveSpeed = wPartnerMoveSpeed;
                    partner->yaw = D_800F8034;
                    npc_move_heading(partner, partner->moveSpeed, partner->yaw);
                }

                spawn_surface_effects(partner, (partner->moveSpeed < 4.0) ? SURFACE_INTERACT_WALK : SURFACE_INTERACT_RUN);
            } else {
                partner->flags &= ~NPC_FLAG_IGNORE_WORLD_COLLISION;
                partner->curAnim = gPartnerAnimations[wCurrentPartnerId].idle;
                D_8010CFCE++;
            }
            break;
        case 2:
            break;
    }
}
