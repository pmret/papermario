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
    card->shadowID = create_shadow_type(0, card->pos.x, card->pos.y, card->pos.z);
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
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInteract_Bootler) = {
    EVT_CALL(GetCurrentPartnerID, LVar0)
    EVT_IF_EQ(LVar0, PARTNER_BOW)
        EVT_CALL(SpeakToNpc, NPC_Bootler, ANIM_Bootler_Talk, ANIM_Bootler_Talk, 0, NPC_PARTNER, MSG_CH3_0057)
        EVT_CALL(DisablePartnerAI, 0)
        EVT_CALL(SpeakToNpc, NPC_PARTNER, ANIM_WorldBow_Talk, ANIM_WorldBow_Idle, 0, NPC_Bootler, MSG_CH3_0058)
        EVT_CALL(EnablePartnerAI)
        EVT_CALL(SpeakToPlayer, NPC_Bootler, ANIM_Bootler_Dejected, ANIM_Bootler_Quaver, 0, MSG_CH3_0059)
    EVT_ELSE
        EVT_SWITCH(GB_StoryProgress)
            EVT_CASE_LT(STORY_CH3_DEFEATED_TUBBA_BLUBBA)
                EVT_CALL(SpeakToPlayer, NPC_Bootler, ANIM_Bootler_Dejected, ANIM_Bootler_Quaver, 0, MSG_CH3_0055)
            EVT_CASE_LT(STORY_CH5_STAR_SPRIT_DEPARTED)
                EVT_CALL(SpeakToPlayer, NPC_Bootler, ANIM_Bootler_Dejected, ANIM_Bootler_Quaver, 0, MSG_CH3_0056)
            EVT_CASE_GE(STORY_CH5_STAR_SPRIT_DEPARTED)
                EVT_CALL(SpeakToPlayer, NPC_Bootler, ANIM_Bootler_Dejected, ANIM_Bootler_Quaver, 0, MSG_CH3_005A)
                EVT_WAIT(20)
                EVT_CALL(SetPlayerAnimation, ANIM_Mario1_NodYes)
                EVT_WAIT(20)
                EVT_CALL(SpeakToPlayer, NPC_Bootler, ANIM_Bootler_Flail, ANIM_Bootler_Flail, 0, MSG_CH3_005B)
        EVT_END_SWITCH
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_Bootler) = {
    EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(EVS_NpcInteract_Bootler)))
    EVT_SWITCH(GB_StoryProgress)
        EVT_CASE_LT(STORY_CH3_BOW_JOINED_PARTY)
        EVT_CASE_GE(STORY_CH3_BOW_JOINED_PARTY)
            EVT_CALL(SetNpcPos, NPC_Bootler, 30, 70, -75)
            EVT_CALL(SetNpcYaw, NPC_Bootler, 270)
        EVT_CASE_DEFAULT
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcAux_Skolar) = {
    EVT_CALL(N(ImprisonedCardSetup))
    EVT_CALL(N(ImprisonedCardUpdate))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_Skolar) = {
    EVT_CALL(BindNpcAux, NPC_SELF, EVT_PTR(N(EVS_NpcAux_Skolar)))
    EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_WorldSkolar_IdleSad)
    EVT_CALL(SetNpcPos, NPC_SELF, 0, NPC_DISPOSE_POS_Y, -100)
    EVT_CALL(EnableNpcShadow, NPC_SELF, FALSE)
    EVT_CALL(SetNpcImgFXParams, NPC_SELF, IMGFX_SET_ALPHA, 170, 0, 0, 0)
    EVT_IF_GE(GB_StoryProgress, STORY_CH3_BOW_JOINED_PARTY)
        EVT_CALL(RemoveNpc, NPC_SELF)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_Bow_Epilogue) = {
    EVT_CALL(SetNpcPos, NPC_SELF, -196, 10, 121)
    EVT_CALL(SetNpcYaw, NPC_SELF, 90)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_Bootler_Epilogue) = {
    EVT_CALL(SetNpcPos, NPC_SELF, -82, 10, 212)
    EVT_CALL(SetNpcYaw, NPC_SELF, 270)
    EVT_RETURN
    EVT_END
};

NpcData N(NpcData_Default)[] = {
    {
        .id = NPC_Bow,
        .pos = { NPC_DISPOSE_LOCATION },
        .yaw = 0,
        .init = &N(EVS_NpcInit_Bow),
        .settings = &N(NpcSettings_Dummy),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_800,
        .drops = NO_DROPS,
        .animations = BOW_ANIMS,
    },
    {
        .id = NPC_Bootler,
        .pos = { NPC_DISPOSE_LOCATION },
        .yaw = 0,
        .init = &N(EVS_NpcInit_Bootler),
        .settings = &N(NpcSettings_Dummy),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_800,
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
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_800,
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
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_800,
        .drops = NO_DROPS,
        .animations = BOW_ANIMS,
    },
    {
        .id = NPC_Bootler,
        .pos = { NPC_DISPOSE_LOCATION },
        .yaw = 0,
        .init = &N(EVS_NpcInit_Bootler_Epilogue),
        .settings = &N(NpcSettings_Dummy),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_800,
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
