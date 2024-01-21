#include "obk_09.h"
#include "effects.h"
#include "sprite/player.h"

typedef struct ImprisonedCard {
    /* 0x00 */ Vec3f pos;
    /* 0x0C */ Vec3f rot;
    /* 0x18 */ s32 shadowID;
    /* 0x1C */ EffectInstance* effect;
} ImprisonedCard; // size = 0x20

API_CALLABLE(N(ImprisonedCardSetup)) {
    Npc* npc = get_npc_safe(script->owner2.npcID);
    ImprisonedCard* card = heap_malloc(sizeof(*card));

    script->userData = card;
    card->pos.x = npc->pos.x;
    card->pos.y = npc->pos.y;
    card->pos.z = npc->pos.z;
    card->rot.y = 0.0f;
    card->effect = fx_spirit_card(1, card->pos.x, card->pos.y, card->pos.z, 1.0f, 0);
    card->effect->data.spiritCard->chapter = 2;
    card->shadowID = create_shadow_type(SHADOW_VARYING_CIRCLE, card->pos.x, card->pos.y, card->pos.z);
    return ApiStatus_DONE2;
}

API_CALLABLE(N(ImprisonedCardUpdate)) {
    ImprisonedCard* card = script->userData;
    Npc* npc = get_npc_safe(script->owner2.npcID);
    Shadow* shadow = get_shadow_by_index(card->shadowID);
    EffectInstance* effect;

    card->pos.x = npc->pos.x - 2.0f;
    card->pos.y = npc->pos.y + 12.0f;
    card->pos.z = npc->pos.z - 30.0f;

    effect = card->effect;
    effect->data.spiritCard->pos.x = card->pos.x;
    effect->data.spiritCard->pos.y = card->pos.y;
    effect->data.spiritCard->pos.z = card->pos.z;

    card->rot.y = clamp_angle(card->rot.y + 6.6f);
    effect->data.spiritCard->yaw = card->rot.y;

    shadow->pos.x = card->pos.x;
    shadow->pos.y = card->pos.y - 40.0f;
    shadow->pos.z = card->pos.z;
    return ApiStatus_BLOCK;
}

#include "world/common/npc/Bow.h"
#include "world/common/npc/Bootler.h"
#include "world/common/npc/Dummy.inc.c"
#include "world/common/npc/StarSpirit.inc.c"

EvtScript N(EVS_NpcInit_Bow) = {
    Return
    End
};

EvtScript N(EVS_NpcInteract_Bootler) = {
    Call(GetCurrentPartnerID, LVar0)
    IfEq(LVar0, PARTNER_BOW)
        Call(SpeakToNpc, NPC_Bootler, ANIM_Bootler_Talk, ANIM_Bootler_Talk, 0, NPC_PARTNER, MSG_CH3_0057)
        Call(DisablePartnerAI, 0)
        Call(SpeakToNpc, NPC_PARTNER, ANIM_WorldBow_Talk, ANIM_WorldBow_Idle, 0, NPC_Bootler, MSG_CH3_0058)
        Call(EnablePartnerAI)
        Call(SpeakToPlayer, NPC_Bootler, ANIM_Bootler_Dejected, ANIM_Bootler_Quaver, 0, MSG_CH3_0059)
    Else
        Switch(GB_StoryProgress)
            CaseLt(STORY_CH3_DEFEATED_TUBBA_BLUBBA)
                Call(SpeakToPlayer, NPC_Bootler, ANIM_Bootler_Dejected, ANIM_Bootler_Quaver, 0, MSG_CH3_0055)
            CaseLt(STORY_CH5_STAR_SPRIT_DEPARTED)
                Call(SpeakToPlayer, NPC_Bootler, ANIM_Bootler_Dejected, ANIM_Bootler_Quaver, 0, MSG_CH3_0056)
            CaseGe(STORY_CH5_STAR_SPRIT_DEPARTED)
                Call(SpeakToPlayer, NPC_Bootler, ANIM_Bootler_Dejected, ANIM_Bootler_Quaver, 0, MSG_CH3_005A)
                Wait(20)
                Call(SetPlayerAnimation, ANIM_Mario1_NodYes)
                Wait(20)
                Call(SpeakToPlayer, NPC_Bootler, ANIM_Bootler_Flail, ANIM_Bootler_Flail, 0, MSG_CH3_005B)
        EndSwitch
    EndIf
    Return
    End
};

EvtScript N(EVS_NpcInit_Bootler) = {
    Call(BindNpcInteract, NPC_SELF, Ref(N(EVS_NpcInteract_Bootler)))
    Switch(GB_StoryProgress)
        CaseLt(STORY_CH3_BOW_JOINED_PARTY)
        CaseGe(STORY_CH3_BOW_JOINED_PARTY)
            Call(SetNpcPos, NPC_Bootler, 30, 70, -75)
            Call(SetNpcYaw, NPC_Bootler, 270)
        CaseDefault
    EndSwitch
    Return
    End
};

EvtScript N(EVS_NpcAux_Skolar) = {
    Call(N(ImprisonedCardSetup))
    Call(N(ImprisonedCardUpdate))
    Return
    End
};

EvtScript N(EVS_NpcInit_Skolar) = {
    Call(BindNpcAux, NPC_SELF, Ref(N(EVS_NpcAux_Skolar)))
    Call(SetNpcAnimation, NPC_SELF, ANIM_WorldSkolar_IdleSad)
    Call(SetNpcPos, NPC_SELF, 0, NPC_DISPOSE_POS_Y, -100)
    Call(EnableNpcShadow, NPC_SELF, FALSE)
    Call(SetNpcImgFXParams, NPC_SELF, IMGFX_SET_ALPHA, 170, 0, 0, 0)
    IfGe(GB_StoryProgress, STORY_CH3_BOW_JOINED_PARTY)
        Call(RemoveNpc, NPC_SELF)
    EndIf
    Return
    End
};

EvtScript N(EVS_NpcInit_Bow_Epilogue) = {
    Call(SetNpcPos, NPC_SELF, -196, 10, 121)
    Call(SetNpcYaw, NPC_SELF, 90)
    Return
    End
};

EvtScript N(EVS_NpcInit_Bootler_Epilogue) = {
    Call(SetNpcPos, NPC_SELF, -82, 10, 212)
    Call(SetNpcYaw, NPC_SELF, 270)
    Return
    End
};

NpcData N(NpcData_Default)[] = {
    {
        .id = NPC_Bow,
        .pos = { NPC_DISPOSE_LOCATION },
        .yaw = 0,
        .init = &N(EVS_NpcInit_Bow),
        .settings = &N(NpcSettings_Dummy),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_FLYING,
        .drops = NO_DROPS,
        .animations = BOW_ANIMS,
    },
    {
        .id = NPC_Bootler,
        .pos = { NPC_DISPOSE_LOCATION },
        .yaw = 0,
        .init = &N(EVS_NpcInit_Bootler),
        .settings = &N(NpcSettings_Dummy),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_FLYING,
        .drops = NO_DROPS,
        .animations = BOOTLER_ANIMS,
        .tattle = MSG_NpcTattle_Bootler,
    },
    {
        .id = NPC_Skolar,
        .pos = { NPC_DISPOSE_LOCATION },
        .yaw = 0,
        .init = &N(EVS_NpcInit_Skolar),
        .settings = &N(NpcSettings_Dummy),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_FLYING,
        .drops = NO_DROPS,
        .animations = SKOLAR_ANIMS,
    },
};

NpcData N(NpcData_Epilogue)[] = {
    {
        .id = NPC_Bow,
        .pos = { NPC_DISPOSE_LOCATION },
        .yaw = 0,
        .init = &N(EVS_NpcInit_Bow_Epilogue),
        .settings = &N(NpcSettings_Dummy),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_FLYING,
        .drops = NO_DROPS,
        .animations = BOW_ANIMS,
    },
    {
        .id = NPC_Bootler,
        .pos = { NPC_DISPOSE_LOCATION },
        .yaw = 0,
        .init = &N(EVS_NpcInit_Bootler_Epilogue),
        .settings = &N(NpcSettings_Dummy),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_FLYING,
        .drops = NO_DROPS,
        .animations = BOOTLER_ANIMS,
        .tattle = MSG_NpcTattle_Bootler,
    },
};

NpcGroupList N(DefaultNPCs) = {
    NPC_GROUP(N(NpcData_Default)),
    {}
};

NpcGroupList N(EpilogueNPCs) = {
    NPC_GROUP(N(NpcData_Epilogue)),
    {}
};
