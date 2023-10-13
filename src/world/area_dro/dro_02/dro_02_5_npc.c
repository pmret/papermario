#include "dro_02.h"
#include "effects.h"
#include "script_api/battle.h"
#include "entity.h"
#include "sprite.h"
#include "sprite/player.h"

#define CHUCK_QUIZMO_NPC_ID NPC_ChuckQuizmo

BSS f32 N(D_8024EF80);
BSS f32 N(D_8024EF84);
BSS s32 N(RitualStateTime);
BSS s8 N(pad_D_8024EF8C)[0x4];
BSS EffectInstance* N(D_8024EF90)[4];

#include "world/common/complete/Quizmo.inc.c"

MobileAISettings N(AISettings_Archeologist) = {
    .moveSpeed = 1.5f,
    .moveTime = 60,
    .waitTime = 30,
    .playerSearchInterval = -1,
    .unk_AI_2C = 1,
};

EvtScript N(EVS_NpcAI_Archeologist) = {
    EVT_CALL(BasicAI_Main, EVT_PTR(N(AISettings_Archeologist)))
    EVT_RETURN
    EVT_END
};

NpcSettings N(NpcSettings_Archeologist_Wander) = {
    .height = 35,
    .radius = 24,
    .ai = &N(EVS_NpcAI_Archeologist),
    .level = ACTOR_LEVEL_NONE,
    .actionFlags = ENEMY_AI_FLAG_10,
};

NpcSettings N(NpcSettings_Archeologist) = {
    .height = 42,
    .radius = 24,
    .ai = &N(EVS_NpcAI_Archeologist),
    .level = ACTOR_LEVEL_NONE,
};

#include "world/common/npc/Dryite_Wander.inc.c"
#include "world/common/npc/Dryite_Stationary.inc.c"
#include "world/common/npc/Mouser.inc.c"

#include "world/common/npc/Toad_Stationary.inc.c"

#include "npc_merlee.c"

#include "world/common/complete/KeyItemChoice.inc.c"
MAP_STATIC_PAD(1,key_item);
#include "world/common/complete/NormalItemChoice.inc.c"

#include "world/common/complete/ToadHouseBlanketAnim.inc.c"
#include "world/common/atomic/ToadHouse.inc.c"
#include "world/common/atomic/ToadHouse.data.inc.c"

#include "world/common/complete/LetterDelivery.inc.c"

s32 N(LetterList)[] = {
    ITEM_LETTER_CHAIN_MR_E,
    ITEM_NONE
};

EvtScript N(EVS_LetterPrompt_MrE) = {
    EVT_CALL(N(LetterDelivery_Init),
        NPC_Dryite_01, ANIM_Dryite_Blue_Talk, ANIM_Dryite_Blue_Idle,
        ITEM_LETTER_CHAIN_MR_E, ITEM_LETTER_CHAIN_MISS_T,
        MSG_CH2_0095, MSG_CH2_0096, MSG_CH2_0097, MSG_CH2_0098,
        EVT_PTR(N(LetterList)))
    EVT_EXEC_WAIT(N(EVS_DoLetterDelivery))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInteract_Archeologist) = {
    EVT_SWITCH(GB_StoryProgress)
        EVT_CASE_LT(STORY_CH2_STAR_SPRIT_DEPARTED)
            EVT_IF_EQ(GF_SBK30_Kolorado_SharedRumorAboutMoustafa, TRUE)
                EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Archeologist_Talk, ANIM_Archeologist_Idle, 0, MSG_CH2_00B2)
            EVT_ELSE
                EVT_SWITCH(AB_DRO_3)
                    EVT_CASE_EQ(0)
                        EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Archeologist_Talk, ANIM_Archeologist_Idle, 0, MSG_CH2_00AF)
                        EVT_SET(AB_DRO_3, 1)
                    EVT_CASE_EQ(1)
                        EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Archeologist_Talk, ANIM_Archeologist_Idle, 0, MSG_CH2_00B0)
                        EVT_SET(AB_DRO_3, 2)
                    EVT_CASE_EQ(2)
                        EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Archeologist_Talk, ANIM_Archeologist_Idle, 0, MSG_CH2_00B1)
                        EVT_SET(AB_DRO_3, 1)
                EVT_END_SWITCH
            EVT_END_IF
        EVT_CASE_DEFAULT
            EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Archeologist_Talk, ANIM_Archeologist_Idle, 0, MSG_CH2_00B3)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_Archeologist) = {
    EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(EVS_NpcInteract_Archeologist)))
    EVT_IF_GE(GB_StoryProgress, STORY_UNUSED_FFFFFFCC)
        EVT_CALL(RemoveNpc, NPC_SELF)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInteract_MrE) = {
    EVT_SWITCH(GB_StoryProgress)
        EVT_CASE_LT(STORY_CH2_STAR_SPRIT_DEPARTED)
            EVT_IF_EQ(GF_DRO02_Sheek_AskedAboutDesert, FALSE)
                EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Dryite_Blue_Talk, ANIM_Dryite_Blue_Idle, 0, MSG_CH2_0091)
            EVT_ELSE
                EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Dryite_Blue_Talk, ANIM_Dryite_Blue_Idle, 0, MSG_CH2_0092)
            EVT_END_IF
        EVT_CASE_LT(STORY_CH5_STAR_SPRIT_DEPARTED)
            EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Dryite_Blue_Talk, ANIM_Dryite_Blue_Idle, 0, MSG_CH2_0093)
        EVT_CASE_DEFAULT
            EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Dryite_Blue_Talk, ANIM_Dryite_Blue_Idle, 0, MSG_CH2_0094)
    EVT_END_SWITCH
    EVT_EXEC_WAIT(N(EVS_LetterPrompt_MrE))
    EVT_IF_NE(LVarC, 0)
        EVT_RETURN
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_MrE) = {
    EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(EVS_NpcInteract_MrE)))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInteract_Dryite_02) = {
    EVT_SWITCH(GB_StoryProgress)
        EVT_CASE_LT(STORY_CH2_STAR_SPRIT_DEPARTED)
            EVT_IF_EQ(AF_DRO_03, FALSE)
                EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Dryite_Green_Talk, ANIM_Dryite_Green_Idle, 0, MSG_CH2_00A1)
                EVT_SET(AF_DRO_03, TRUE)
            EVT_ELSE
                EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Dryite_Green_Talk, ANIM_Dryite_Green_Idle, 0, MSG_CH2_00A2)
                EVT_SET(AF_DRO_03, FALSE)
            EVT_END_IF
        EVT_CASE_LT(STORY_CH5_STAR_SPRIT_DEPARTED)
            EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Dryite_Green_Talk, ANIM_Dryite_Green_Idle, 0, MSG_CH2_00A3)
        EVT_CASE_DEFAULT
            EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Dryite_Green_Talk, ANIM_Dryite_Green_Idle, 0, MSG_CH2_00A4)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_Dryite_02) = {
    EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(EVS_NpcInteract_Dryite_02)))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInteract_Dryite_03) = {
    EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Dryite_Green_Talk, ANIM_Dryite_Green_Idle, 0, MSG_CH2_00A0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_Dryite_03) = {
    EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(EVS_NpcInteract_Dryite_03)))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInteract_Mouser_01) = {
    EVT_SWITCH(GB_StoryProgress)
        EVT_CASE_LT(STORY_CH2_STAR_SPRIT_DEPARTED)
            EVT_IF_EQ(AF_DRO_04, FALSE)
                EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Mouser_Blue_Talk, ANIM_Mouser_Blue_Idle, 0, MSG_CH2_00A5)
                EVT_SET(AF_DRO_04, TRUE)
            EVT_ELSE
                EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Mouser_Blue_Talk, ANIM_Mouser_Blue_Idle, 0, MSG_CH2_00A6)
                EVT_SET(AF_DRO_04, FALSE)
            EVT_END_IF
        EVT_CASE_LT(STORY_CH5_STAR_SPRIT_DEPARTED)
            EVT_IF_EQ(AF_DRO_04, FALSE)
                EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Mouser_Blue_Talk, ANIM_Mouser_Blue_Idle, 0, MSG_CH2_00A7)
                EVT_SET(AF_DRO_04, TRUE)
            EVT_ELSE
                EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Mouser_Blue_Talk, ANIM_Mouser_Blue_Idle, 0, MSG_CH2_00A8)
                EVT_SET(AF_DRO_04, FALSE)
            EVT_END_IF
        EVT_CASE_DEFAULT
            EVT_IF_EQ(AF_DRO_04, FALSE)
                EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Mouser_Blue_Talk, ANIM_Mouser_Blue_Idle, 0, MSG_CH2_00A9)
                EVT_SET(AF_DRO_04, TRUE)
            EVT_ELSE
                EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Mouser_Blue_Talk, ANIM_Mouser_Blue_Idle, 0, MSG_CH2_00AA)
                EVT_SET(AF_DRO_04, FALSE)
            EVT_END_IF
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_Mouser_01) = {
    EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(EVS_NpcInteract_Mouser_01)))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInteract_Mouser_02) = {
    EVT_SWITCH(GB_StoryProgress)
        EVT_CASE_LT(STORY_CH2_STAR_SPRIT_DEPARTED)
            EVT_IF_EQ(AF_DRO_05, FALSE)
                EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Mouser_Blue_Talk, ANIM_Mouser_Blue_Idle, 0, MSG_CH2_00AB)
                EVT_SET(AF_DRO_05, TRUE)
            EVT_ELSE
                EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Mouser_Blue_Talk, ANIM_Mouser_Blue_Idle, 0, MSG_CH2_00AC)
                EVT_SET(AF_DRO_05, FALSE)
            EVT_END_IF
        EVT_CASE_LT(STORY_CH5_STAR_SPRIT_DEPARTED)
            EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Mouser_Blue_Talk, ANIM_Mouser_Blue_Idle, 0, MSG_CH2_00AD)
        EVT_CASE_DEFAULT
            EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Mouser_Blue_Talk, ANIM_Mouser_Blue_Idle, 0, MSG_CH2_00AE)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_Mouser_02) = {
    EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(EVS_NpcInteract_Mouser_02)))
    EVT_RETURN
    EVT_END
};

#include "npc_moustafa.c"

EvtScript N(EVS_NpcIdle_Mouser_03) = {
    EVT_CALL(InterpNpcYaw, NPC_DisguisedMoustafa, 270, 0)
    EVT_LABEL(10)
        EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_Mouser_Purple_Gossip)
        EVT_CALL(SetNpcAnimation, NPC_DisguisedMoustafa, ANIM_DisguisedMoustafa_Idle)
        EVT_LOOP(50)
            EVT_CALL(IsPlayerWithin, 200, 50, 100, LVar0)
            EVT_IF_EQ(LVar0, 1)
                EVT_GOTO(20)
            EVT_END_IF
            EVT_WAIT(1)
        EVT_END_LOOP
        EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_Mouser_Purple_Idle)
        EVT_CALL(SetNpcAnimation, NPC_DisguisedMoustafa, ANIM_DisguisedMoustafa_TalkAlt)
        EVT_LOOP(50)
            EVT_CALL(IsPlayerWithin, 200, 50, 100, LVar0)
            EVT_IF_EQ(LVar0, 1)
                EVT_GOTO(20)
            EVT_END_IF
            EVT_WAIT(1)
        EVT_END_LOOP
        EVT_GOTO(10)
    EVT_LABEL(20)
    EVT_CALL(SetNpcAnimation, NPC_DisguisedMoustafa, ANIM_DisguisedMoustafa_Idle)
    EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_Mouser_Purple_Run)
    EVT_CALL(SetNpcFlagBits, NPC_SELF, NPC_FLAG_IGNORE_PLAYER_COLLISION, TRUE)
    EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_Mouser_Purple_Run)
    EVT_CALL(NpcMoveTo, NPC_SELF, 150, 18, 20)
    EVT_CALL(EnableNpcBlur, NPC_SELF, TRUE)
    EVT_CALL(PlaySoundAtNpc, NPC_SELF, SOUND_RUN_AWAY, SOUND_SPACE_DEFAULT)
    EVT_CALL(NpcMoveTo, NPC_SELF, -83, 11, 20 * DT)
    EVT_CALL(NpcMoveTo, NPC_SELF, -239, 5, 20 * DT)
    EVT_CALL(NpcMoveTo, NPC_SELF, -371, 5, 20 * DT)
    EVT_CALL(NpcMoveTo, NPC_SELF, -487, 5, 20 * DT)
    EVT_CALL(SetNpcPos, NPC_SELF, NPC_DISPOSE_LOCATION)
    EVT_SET(GB_StoryProgress, STORY_CH2_SPOKE_WITH_SHEEK)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_Mouser_03) = {
    EVT_CALL(BindNpcIdle, NPC_SELF, EVT_PTR(N(EVS_NpcIdle_Mouser_03)))
    EVT_IF_GE(GB_StoryProgress, STORY_CH2_SPOKE_WITH_SHEEK)
        EVT_CALL(RemoveNpc, NPC_SELF)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_ToadHouse_SetDialogue) = {
    EVT_SET(LVar0, MSG_CH2_00D1)
    EVT_SET(LVar8, MSG_CH2_00D2)
    EVT_SET(LVar1, MSG_CH2_00D3)
    EVT_SET(LVar2, MSG_CH2_00D4)
    EVT_SET(LVar3, MSG_CH2_00D5)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_ToadHouse_GetInBed) = {
    EVT_EXEC(N(EVS_PlayRestMusic))
    EVT_CALL(SetPlayerSpeed, EVT_FLOAT(3.0))
    EVT_CALL(PlayerMoveTo, -179, -198, 0)
    EVT_THREAD
        EVT_WAIT(15)
        EVT_CALL(N(ToadHouse_CamSetFOV), 0, 40)
        EVT_CALL(SetCamType, CAM_DEFAULT, 4, FALSE)
        EVT_CALL(SetCamPitch, CAM_DEFAULT, 95, -61)
        EVT_CALL(SetCamDistance, CAM_DEFAULT, 108)
        EVT_CALL(SetCamPosA, CAM_DEFAULT, 202, 62)
        EVT_CALL(SetCamPosB, CAM_DEFAULT, -89, -141)
        EVT_CALL(SetCamPosC, CAM_DEFAULT, 0, 0)
        EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(90.0))
        EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_END_THREAD
    EVT_CALL(PlayerMoveTo, -187, -267, 0)
    EVT_CALL(InterpPlayerYaw, 230, 1)
    EVT_CALL(HidePlayerShadow, TRUE)
    EVT_CALL(SetPlayerAnimation, ANIM_Mario1_Idle)
    EVT_CALL(SetPlayerImgFXFlags, IMGFX_FLAG_800)
    EVT_CALL(UpdatePlayerImgFX, ANIM_Mario1_Idle, IMGFX_SET_ANIM, IMGFX_ANIM_GET_IN_BED, 1, 1, 0)
    EVT_THREAD
        EVT_WAIT(60)
        EVT_CALL(SetPlayerAnimation, ANIM_MarioW2_SleepStanding)
    EVT_END_THREAD
    EVT_WAIT(20)
    EVT_THREAD
        EVT_WAIT(81)
        EVT_CALL(N(ToadHouse_CamSetFOV), 0, 25)
        EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
        EVT_CALL(UseSettingsFrom, CAM_DEFAULT, LVar0, LVar1, LVar2)
        EVT_WAIT(1)
        EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 0)
    EVT_END_THREAD
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_ToadHouse_ReturnFromRest) = {
    EVT_CALL(HidePlayerShadow, FALSE)
    EVT_CALL(UpdatePlayerImgFX, ANIM_Mario1_Idle, IMGFX_CLEAR, 0, 0, 0, 0)
    EVT_CALL(SetPlayerPos, -187, 0, -240)
    EVT_CALL(SetPlayerSpeed, EVT_FLOAT(3.0))
    EVT_CALL(PlayerMoveTo, -168, -195, 0)
    EVT_EXEC(N(EVS_SetupMusic))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_ToadHouseKeeper) = {
    EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(EVS_NpcInteract_ToadHouseKeeper)))
    EVT_RETURN
    EVT_END
};

NpcData N(PassiveNPCs)[] = {
    {
        .id = NPC_Archeologist,
        .pos = { -320.0f, 0.0f, -14.0f },
        .yaw = 90,
        .territory = { .temp = { -303, 0, 22, 146, 38, -32767, 1, 0, 0, 0, 0, 0, 0, 1 }},
        .init = &N(EVS_NpcInit_Archeologist),
        .settings = &N(NpcSettings_Archeologist),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_NO_SHADOW_RAYCAST,
        .drops = NO_DROPS,
        .animations = {
            ANIM_Archeologist_Idle,
            ANIM_Archeologist_Walk,
            ANIM_Archeologist_Run,
            ANIM_Archeologist_Run,
            ANIM_Archeologist_Idle,
            ANIM_Archeologist_Idle,
            ANIM_Archeologist_Idle,
            ANIM_Archeologist_Idle,
            ANIM_Archeologist_Idle,
            ANIM_Archeologist_Idle,
            ANIM_Archeologist_Idle,
            ANIM_Archeologist_Idle,
            ANIM_Archeologist_Idle,
            ANIM_Archeologist_Idle,
            ANIM_Archeologist_Idle,
            ANIM_Archeologist_Idle,
        },
        .tattle = MSG_NpcTattle_Archeologist,
    },
    {
        .id = NPC_Dryite_01,
        .pos = { -20.0f, 0.0f, 40.0f },
        .yaw = 270,
        .territory = { .temp = { -20, 0, 40, 60, 0, -32767, 0, 0, 0, 0, 0, 0, 0, 1 }},
        .init = &N(EVS_NpcInit_MrE),
        .settings = &N(NpcSettings_Dryite_Wander),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_NO_SHADOW_RAYCAST,
        .drops = NO_DROPS,
        .animations = DRYITE_BLUE_ANIMS,
        .tattle = MSG_NpcTattle_DRO_DryiteE,
    },
    {
        .id = NPC_DisguisedMoustafa,
        .pos = { 245.0f, 0.0f, -35.0f },
        .yaw = 90,
        .init = &N(EVS_NpcInit_DisguisedMoustafa),
        .settings = &N(NpcSettings_Mouser),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_NO_SHADOW_RAYCAST,
        .drops = NO_DROPS,
        .animations = DISGUISED_MOUSTAFA_ANIMS,
        .tattle = MSG_NpcTattle_Sheek,
    },
    {
        .id = NPC_Toad,
        .pos = { -143.0f, 0.0f, -170.0f },
        .yaw = 180,
        .init = &N(EVS_NpcInit_ToadHouseKeeper),
        .settings = &N(NpcSettings_Toad_Stationary),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_NO_SHADOW_RAYCAST,
        .drops = NO_DROPS,
        .animations = TOAD_RED_ANIMS,
        .tattle = MSG_NpcTattle_DRO_ToadHouseToad,
    },
    {
        .id = NPC_Merlee,
        .pos = { -130.0f, 0.0f, -400.0f },
        .yaw = 180,
        .init = &N(EVS_NpcAuxAI_Merlee),
        .settings = &N(NpcSettings_Merlee),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_NO_SHADOW_RAYCAST,
        .drops = NO_DROPS,
        .animations = {
            ANIM_WorldMerlee_Idle,
            ANIM_WorldMerlee_Walk,
            ANIM_WorldMerlee_Run,
            ANIM_WorldMerlee_Run,
            ANIM_WorldMerlee_Idle,
            ANIM_WorldMerlee_Idle,
            ANIM_WorldMerlee_Idle,
            ANIM_WorldMerlee_Idle,
            ANIM_WorldMerlee_Idle,
            ANIM_WorldMerlee_Idle,
            ANIM_WorldMerlee_Idle,
            ANIM_WorldMerlee_Idle,
            ANIM_WorldMerlee_Idle,
            ANIM_WorldMerlee_Idle,
            ANIM_WorldMerlee_Idle,
            ANIM_WorldMerlee_Idle,
        },
        .tattle = MSG_NpcTattle_Merlee,
    },
    {
        .id = NPC_Moustafa,
        .pos = { NPC_DISPOSE_LOCATION },
        .yaw = 0,
        .init = &N(EVS_NpcInit_Moustafa),
        .settings = &N(NpcSettings_Mouser),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_NO_SHADOW_RAYCAST,
        .drops = NO_DROPS,
        .animations = MOUSTAFA_ANIMS,
        .tattle = MSG_NpcTattle_Moustafa,
    },
    {
        .id = NPC_Dryite_02,
        .pos = { 25.0f, 0.0f, -38.0f },
        .yaw = 270,
        .init = &N(EVS_NpcInit_Dryite_02),
        .settings = &N(NpcSettings_Dryite),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_NO_SHADOW_RAYCAST,
        .drops = NO_DROPS,
        .animations = DRYITE_GREEN_ANIMS,
        .tattle = MSG_NpcTattle_DRO_DryiteF,
    },
    {
        .id = NPC_Dryite_03,
        .pos = { -375.0f, 0.0f, -10.0f },
        .yaw = 270,
        .init = &N(EVS_NpcInit_Dryite_03),
        .settings = &N(NpcSettings_Dryite),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_NO_SHADOW_RAYCAST,
        .drops = NO_DROPS,
        .animations = DRYITE_GREEN_ANIMS,
        .tattle = MSG_NpcTattle_DRO_VisitedShootingStarSummit,
    },
    {
        .id = NPC_Mouser_01,
        .pos = { -50.0f, 0.0f, -470.0f },
        .yaw = 180,
        .init = &N(EVS_NpcInit_Mouser_01),
        .settings = &N(NpcSettings_Mouser),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_NO_SHADOW_RAYCAST,
        .drops = NO_DROPS,
        .animations = MOUSER_BLUE_ANIMS,
        .tattle = MSG_NpcTattle_DRO_CrushingOnMerlee,
    },
    {
        .id = NPC_Mouser_02,
        .pos = { -270.0f, 0.0f, 91.0f },
        .yaw = 270,
        .init = &N(EVS_NpcInit_Mouser_02),
        .settings = &N(NpcSettings_Mouser),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_NO_SHADOW_RAYCAST,
        .drops = NO_DROPS,
        .animations = MOUSER_BLUE_ANIMS,
        .tattle = MSG_NpcTattle_DRO_TellsTales,
    },
    {
        .id = NPC_Mouser_03,
        .pos = { 210.0f, 0.0f, -35.0f },
        .yaw = 90,
        .init = &N(EVS_NpcInit_Mouser_03),
        .settings = &N(NpcSettings_Mouser),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_NO_SHADOW_RAYCAST,
        .drops = NO_DROPS,
        .animations = MOUSER_PURPLE_ANIMS,
    },
    {
        .id = NPC_ChuckQuizmo,
        .pos = { -335.0f, 0.0f, 90.0f },
        .yaw = 270,
        .initVarCount = 1,
        .initVar = { .bytes = { 0, QUIZ_AREA_DRO, QUIZ_COUNT_DRO, QUIZ_MAP_DRO_02 } },
        .settings = &N(NpcSettings_ChuckQuizmo),
        .flags = COMMON_PASSIVE_FLAGS | ENEMY_FLAG_NO_SHADOW_RAYCAST,
        .drops = NO_DROPS,
        .animations = QUIZMO_ANIMS,
        .tattle = MSG_NpcTattle_ChuckQuizmo,
    },
};

NpcGroupList N(DefaultNPCs) = {
    NPC_GROUP(N(PassiveNPCs)),
    {},
};
