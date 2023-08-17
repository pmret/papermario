
#include "sbk_30.h"

#include "world/common/enemy/ai/GuardAI.inc.c"

#include "world/common/npc/Kolorado.inc.c"

NpcSettings N(NpcSettings_Unused) = {
    .height = 35,
    .radius = 24,
    .level = ACTOR_LEVEL_NONE,
};

NpcSettings N(NpcSettings_Archeologist_01) = {
    .height = 42,
    .radius = 24,
    .level = ACTOR_LEVEL_NONE,
};

#include "world/common/complete/GiveReward.inc.c"
#include "world/common/complete/KeyItemChoice.inc.c"
MAP_STATIC_PAD(1,normal_item);
#include "world/common/complete/NormalItemChoice.inc.c"

#include "world/common/complete/LetterDelivery.inc.c"

s32 N(LetterList)[] = {
    ITEM_LETTER_TO_KOLORADO,
    ITEM_NONE
};

EvtScript N(EVS_DeliveryPrompt) = {
    EVT_CALL(N(LetterDelivery_Init),
        NPC_Kolorado, ANIM_Kolorado_Talk, ANIM_Kolorado_Idle,
        ITEM_LETTER_TO_KOLORADO, ITEM_NONE,
        MSG_CH2_004A, MSG_CH2_004B, MSG_CH2_004C, MSG_CH2_004D,
        EVT_PTR(N(LetterList)))
        EVT_EXEC_WAIT(N(EVS_DoLetterDelivery))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_DeliveryReward) = {
    EVT_IF_EQ(LVarC, DELIVERY_ACCEPTED)
        EVT_GIVE_STAR_PIECE()
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

s32 N(ArtifactList)[] = {
    ITEM_ARTIFACT,
    ITEM_NONE
};

EvtScript N(EVS_ArtifactPrompt) = {
    EVT_SET(GF_SBK_GaveArtifactToKolorado, TRUE)
    EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Kolorado_Talk, ANIM_Kolorado_Idle, 0, MSG_CH2_0044)
    EVT_GIVE_STAR_PIECE()
    EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Kolorado_Talk, ANIM_Kolorado_Idle, 0, MSG_CH2_0045)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInteract_Kolorado) = {
    EVT_CALL(GetNpcAnimation, NPC_SELF, LVar9)
    EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_Kolorado_Idle)
    EVT_IF_EQ(GF_SBK30_Met_Kolorado, FALSE)
        EVT_CALL(AdjustCam, CAM_DEFAULT, EVT_FLOAT(4.0), 0, EVT_FLOAT(300.0), EVT_FLOAT(15.0), EVT_FLOAT(-7.5))
        EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Kolorado_Talk, ANIM_Kolorado_Idle, 0, MSG_CH2_0037)
        EVT_CALL(ResetCam, CAM_DEFAULT, 4)
        EVT_SET(GF_SBK30_Met_Kolorado, TRUE)
        EVT_GOTO(50)
    EVT_END_IF
    EVT_IF_EQ(GF_SBK_GaveArtifactToKolorado, TRUE)
        EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Kolorado_Talk, ANIM_Kolorado_Idle, 0, MSG_CH2_0046)
        EVT_GOTO(50)
    EVT_END_IF
    EVT_CALL(HasKeyItem, ITEM_ARTIFACT, LVar0)
    EVT_IF_EQ(LVar0, 1)
        EVT_IF_EQ(GF_SBK_KeptArtifactFromKolorado, TRUE)
            EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Kolorado_Talk, ANIM_Kolorado_Idle, 0, MSG_CH2_0043)
        EVT_ELSE
            EVT_SET(GF_SBK_KeptArtifactFromKolorado, TRUE)
            EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Kolorado_Talk, ANIM_Kolorado_Idle, 0, MSG_CH2_0040)
        EVT_END_IF
        EVT_CHOOSE_KEY_ITEM_FROM(N(ArtifactList))
        EVT_SWITCH(LVar0)
            EVT_CASE_GE(1)
                EVT_EXEC_WAIT(N(EVS_ArtifactPrompt))
                EVT_GOTO(50)
            EVT_CASE_DEFAULT
                EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Kolorado_Talk, ANIM_Kolorado_Idle, 0, MSG_CH2_0041)
                EVT_CHOOSE_KEY_ITEM_FROM(N(ArtifactList))
                EVT_SWITCH(LVar0)
                    EVT_CASE_GE(1)
                        EVT_EXEC_WAIT(N(EVS_ArtifactPrompt))
                    EVT_CASE_DEFAULT
                        EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Kolorado_Talk, ANIM_Kolorado_Idle, 0, MSG_CH2_0042)
                        EVT_GOTO(50)
                EVT_END_SWITCH
        EVT_END_SWITCH
    EVT_END_IF
    EVT_IF_GE(GB_StoryProgress, STORY_CH2_ARRIVED_AT_DRY_DRY_OUTPOST)
        EVT_IF_EQ(GF_DRO02_Sheek_SpokeTo, FALSE)
            EVT_IF_EQ(AF_SBK_04, FALSE)
                EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Kolorado_Talk, ANIM_Kolorado_Idle, 0, MSG_CH2_0039)
                EVT_SET(AF_SBK_04, TRUE)
                EVT_GOTO(50)
            EVT_ELSE
                EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Kolorado_Talk, ANIM_Kolorado_Idle, 0, MSG_CH2_003A)
                EVT_GOTO(50)
            EVT_END_IF
        EVT_END_IF
        EVT_IF_EQ(GF_DRO02_Sheek_AskedAboutRuins, FALSE)
            EVT_IF_EQ(AF_SBK_05, FALSE)
                EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Kolorado_Talk, ANIM_Kolorado_Idle, 0, MSG_CH2_003B)
                EVT_SET(GF_SBK30_Kolorado_SharedRumorAboutMoustafa, TRUE)
                EVT_SET(AF_SBK_05, TRUE)
                EVT_GOTO(50)
            EVT_ELSE
                EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Kolorado_Talk, ANIM_Kolorado_Idle, 0, MSG_CH2_003C)
                EVT_GOTO(50)
            EVT_END_IF
        EVT_END_IF
        EVT_IF_EQ(GF_SBK30_Kolorado_SharedRumorAboutMoustafa, TRUE)
            EVT_IF_EQ(GF_DRO02_Sheek_AskedAboutMoustafa, FALSE)
                EVT_IF_EQ(AF_SBK_06, FALSE)
                    EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Kolorado_Talk, ANIM_Kolorado_Idle, 0, MSG_CH2_003D)
                    EVT_SET(AF_SBK_06, TRUE)
                    EVT_GOTO(50)
                EVT_ELSE
                    EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Kolorado_Talk, ANIM_Kolorado_Idle, 0, MSG_CH2_003E)
                    EVT_GOTO(50)
                EVT_END_IF
            EVT_END_IF
        EVT_END_IF
        EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Kolorado_Talk, ANIM_Kolorado_Idle, 0, MSG_CH2_003F)
        EVT_GOTO(50)
    EVT_END_IF
    EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Kolorado_Talk, ANIM_Kolorado_Idle, 0, MSG_CH2_0038)
    EVT_LABEL(50)
    EVT_LABEL(90)
    EVT_CALL(GetCurrentPartnerID, LVar0)
    EVT_IF_EQ(LVar0, PARTNER_KOOPER)
        EVT_IF_EQ(GF_SBK30_KooperMetKolorado, FALSE)
            EVT_SET(GF_SBK30_KooperMetKolorado, TRUE)
            EVT_CALL(DisablePartnerAI, 0)
            EVT_CALL(SpeakToNpc, NPC_PARTNER, ANIM_WorldKooper_CelebrateLoop, ANIM_WorldKooper_Idle, 0, NPC_SELF, MSG_CH2_0047)
            EVT_CALL(SpeakToNpc, NPC_SELF, ANIM_Kolorado_Talk, ANIM_Kolorado_Idle, 0, NPC_PARTNER, MSG_CH2_0048)
            EVT_CALL(SpeakToNpc, NPC_PARTNER, ANIM_WorldKooper_CelebrateLoop, ANIM_WorldKooper_Idle, 0, NPC_SELF, MSG_CH2_0049)
            EVT_CALL(EnablePartnerAI)
        EVT_END_IF
    EVT_END_IF
    EVT_CALL(SetNpcAnimation, NPC_SELF, LVar9)
    EVT_EXEC_WAIT(N(EVS_DeliveryPrompt))
    EVT_EXEC_WAIT(N(EVS_DeliveryReward))
    EVT_IF_NE(LVarC, 0)
        EVT_RETURN
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcIdle_Kolorado) = {
    EVT_LOOP(0)
        EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_Kolorado_Idle)
        EVT_WAIT(15)
        EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_Kolorado_Walk)
        EVT_CALL(NpcMoveTo, NPC_SELF, 97, -179, 120)
        EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_Kolorado_Idle)
        EVT_WAIT(15)
        EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_Kolorado_Walk)
        EVT_CALL(NpcMoveTo, NPC_SELF, 200, -100, 120)
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcIdle_KoloradoPanic) = {
    EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_Kolorado_Panic)
    EVT_CALL(SetNpcSpeed, NPC_SELF, EVT_FLOAT(4.0))
    EVT_CALL(NpcMoveTo, NPC_SELF, 145, -145, 0)
    EVT_LABEL(0)
    EVT_CALL(RandInt, 30, LVar0)
    EVT_ADD(LVar0, 1)
    EVT_WAIT(LVar0)
    EVT_CALL(GetNpcYaw, NPC_SELF, LVar0)
    EVT_ADD(LVar0, 180)
    EVT_CALL(InterpNpcYaw, NPC_SELF, LVar0, 5)
    EVT_GOTO(0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_Kolorado) = {
    EVT_CALL(GetEntryID, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_OR_EQ(sbk_30_ENTRY_4)
        EVT_CASE_OR_EQ(sbk_30_ENTRY_5)
            EVT_CALL(SetNpcPos, NPC_SELF, 210, 0, -210)
            EVT_CALL(BindNpcIdle, NPC_SELF, EVT_PTR(N(EVS_NpcIdle_KoloradoPanic)))
        EVT_END_CASE_GROUP
        EVT_CASE_DEFAULT
            EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(EVS_NpcInteract_Kolorado)))
            EVT_CALL(BindNpcIdle, NPC_SELF, EVT_PTR(N(EVS_NpcIdle_Kolorado)))
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcIdle_Archeologist_01) = {
    EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_Archeologist_Talk)
    EVT_LABEL(0)
    EVT_CALL(RandInt, 50, LVar0)
    EVT_ADD(LVar0, 1)
    EVT_WAIT(LVar0)
    EVT_CALL(GetNpcYaw, NPC_SELF, LVar0)
    EVT_ADD(LVar0, 180)
    EVT_CALL(InterpNpcYaw, NPC_SELF, LVar0, 5)
    EVT_GOTO(0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInteract_Archeologist_01) = {
    EVT_SWITCH(GB_StoryProgress)
        EVT_CASE_LT(STORY_CH2_GOT_PULSE_STONE)
            EVT_IF_EQ(AF_SBK_02, FALSE)
                EVT_SET(LVar0, MSG_CH2_004E)
                EVT_SET(AF_SBK_02, TRUE)
            EVT_ELSE
                EVT_SET(LVar0, MSG_CH2_004F)
                EVT_SET(AF_SBK_02, FALSE)
            EVT_END_IF
        EVT_CASE_DEFAULT
            EVT_IF_EQ(GF_SBK_GaveArtifactToKolorado, FALSE)
                EVT_SET(LVar0, MSG_CH2_0050)
            EVT_ELSE
                EVT_SET(LVar0, MSG_CH2_0051)
            EVT_END_IF
    EVT_END_SWITCH
    EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Archeologist_Talk, ANIM_Archeologist_Idle, 0, LVar0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_Archeologist_01) = {
    EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(EVS_NpcInteract_Archeologist_01)))
    EVT_CALL(GetEntryID, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_OR_EQ(sbk_30_ENTRY_4)
        EVT_CASE_OR_EQ(sbk_30_ENTRY_5)
            EVT_CALL(BindNpcIdle, NPC_SELF, EVT_PTR(N(EVS_NpcIdle_Archeologist_01)))
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInteract_Archeologist_02) = {
    EVT_SWITCH(GB_StoryProgress)
        EVT_CASE_LT(STORY_CH2_GOT_PULSE_STONE)
            EVT_IF_EQ(AF_SBK_03, FALSE)
                EVT_SET(LVar0, MSG_CH2_0052)
                EVT_SET(AF_SBK_03, TRUE)
            EVT_ELSE
                EVT_SET(LVar0, MSG_CH2_0053)
                EVT_SET(AF_SBK_03, FALSE)
            EVT_END_IF
        EVT_CASE_DEFAULT
            EVT_IF_EQ(GF_SBK_GaveArtifactToKolorado, FALSE)
                EVT_SET(LVar0, MSG_CH2_0054)
            EVT_ELSE
                EVT_SET(LVar0, MSG_CH2_0055)
            EVT_END_IF
    EVT_END_SWITCH
    EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Archeologist_Talk, ANIM_Archeologist_Idle, 0, LVar0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_Archeologist_02) = {
    EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(EVS_NpcInteract_Archeologist_02)))
    EVT_CALL(GetEntryID, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_OR_EQ(sbk_30_ENTRY_4)
        EVT_CASE_OR_EQ(sbk_30_ENTRY_5)
            EVT_CALL(BindNpcIdle, NPC_SELF, EVT_PTR(N(EVS_NpcIdle_Archeologist_01)))
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

NpcData N(NpcData_Archeologist_02)[] = {
    {
        .id = NPC_Kolorado,
        .pos = { 200.0f, 0.0f, -100.0f },
        .yaw = 90,
        .init = &N(EVS_NpcInit_Kolorado),
        .settings = &N(NpcSettings_Kolorado),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_NO_SHADOW_RAYCAST,
        .drops = NO_DROPS,
        .animations = KOLORADO_ANIMS,
        .tattle = MSG_NpcTattle_SBK_Kolorado,
    },
    {
        .id = NPC_Archeologist_01,
        .pos = { 238.0f, 0.0f, -112.0f },
        .yaw = 270,
        .territory = {
            .wander = {
                .isFlying = TRUE,
                .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
                .wanderShape = SHAPE_CYLINDER,
                .centerPos  = { 0, 0, 0 },
                .wanderSize = { 100 },
                .detectShape = SHAPE_CYLINDER,
                .detectPos  = { 0, 0, 0 },
                .detectSize = { 0 },
            }
        },
        .init = &N(EVS_NpcInit_Archeologist_01),
        .settings = &N(NpcSettings_Archeologist_01),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_NO_SHADOW_RAYCAST,
        .drops = NO_DROPS,
        .animations = ARCHEOLOGIST_ANIMS,
        .tattle = MSG_NpcTattle_SBK_ExcavatorA,
    },
    {
        .id = NPC_Archeologist_02,
        .pos = { 170.0f, 0.0f, -190.0f },
        .yaw = 90,
        .territory = {
            .wander = {
                .isFlying = TRUE,
                .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
                .wanderShape = SHAPE_CYLINDER,
                .centerPos  = { 0, 0, 0 },
                .wanderSize = { 100 },
                .detectShape = SHAPE_CYLINDER,
                .detectPos  = { 0, 0, 0 },
                .detectSize = { 0 },
            }
        },
        .init = &N(EVS_NpcInit_Archeologist_02),
        .settings = &N(NpcSettings_Archeologist_01),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_NO_SHADOW_RAYCAST,
        .drops = NO_DROPS,
        .animations = ARCHEOLOGIST_ANIMS,
        .tattle = MSG_NpcTattle_SBK_ExcavatorB,
    },
};

NpcGroupList N(DefaultNPCs) = {
    NPC_GROUP(N(NpcData_Archeologist_02)),
    {}
};
