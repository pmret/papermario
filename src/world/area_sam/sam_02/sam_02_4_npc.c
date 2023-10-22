#include "sam_02.h"
#include "sprite/player.h"

#if VERSION_PAL
#include "sprite/npc/ShiverToad.h"
#define TOADHOUSE_ANIM_TALK ANIM_ShiverToad_Red_Talk
#define TOADHOUSE_ANIM_IDLE ANIM_ShiverToad_Red_Idle
#endif

#include "world/common/complete/ToadHouseBlanketAnim.inc.c"
#include "world/common/atomic/ToadHouse.inc.c"
#include "world/common/atomic/ToadHouse.data.inc.c"

#include "world/common/npc/Penguin_Wander.inc.c"
#include "world/common/npc/Penguin.inc.c"

#include "world/common/npc/ShiverToad.inc.c"

#define CHUCK_QUIZMO_NPC_ID NPC_ChuckQuizmo
#include "world/common/complete/Quizmo.inc.c"

EvtScript N(EVS_NpcInteract_Penguin_ShopOwner) = {
    EVT_SWITCH(GB_StoryProgress)
        EVT_CASE_LT(STORY_CH7_MAYOR_MURDER_MYSTERY)
            EVT_EXEC_WAIT(EVS_ShopOwnerDialog)
        EVT_CASE_LT(STORY_CH7_MAYOR_MURDER_SOLVED)
            EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Penguin_Talk, ANIM_Penguin_Idle, 0, MSG_CH7_006A)
        EVT_CASE_GE(STORY_CH7_MAYOR_MURDER_SOLVED)
            EVT_EXEC_WAIT(EVS_ShopOwnerDialog)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcIdle_Penguin_ShopOwner) = {
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_ToadHouse_SetDialogue) = {
    EVT_SET(LVar0, MSG_CH7_006B)
    EVT_SET(LVar8, MSG_CH7_006C)
    EVT_SET(LVar1, MSG_CH7_006D)
    EVT_SET(LVar2, MSG_CH7_006E)
    EVT_SET(LVar3, MSG_CH7_006F)
    EVT_IF_GE(GB_StoryProgress, STORY_CH7_UNLOCKED_SHIVER_MOUNTAIN)
        EVT_IF_LT(GB_StoryProgress, STORY_CH8_OPENED_PATH_TO_STAR_WAY)
            EVT_IF_EQ(GF_SAM02_MushroomPresents, FALSE)
                EVT_SET(LVar3, MSG_CH7_0070)
            EVT_END_IF
        EVT_END_IF
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_ToadHouse_GetInBed) = {
    EVT_EXEC(N(EVS_PlayRestingSong))
    EVT_CALL(SetPlayerSpeed, EVT_FLOAT(3.0))
    EVT_CALL(PlayerMoveTo, 294, -213, 0)
    EVT_THREAD
        EVT_WAIT(15)
        EVT_CALL(N(ToadHouse_CamSetFOV), 0, 40)
        EVT_CALL(SetCamType, CAM_DEFAULT, 4, FALSE)
        EVT_CALL(SetCamPitch, CAM_DEFAULT, 65, -36)
        EVT_CALL(SetCamDistance, CAM_DEFAULT, 111)
        EVT_CALL(SetCamPosA, CAM_DEFAULT, 549, -5)
        EVT_CALL(SetCamPosB, CAM_DEFAULT, 315, -171)
        EVT_CALL(SetCamPosC, CAM_DEFAULT, 0, 23)
        EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(90.0))
        EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_END_THREAD
    EVT_CALL(PlayerMoveTo, 274, -270, 0)
    EVT_CALL(InterpPlayerYaw, 229, 1)
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
    EVT_IF_EQ(GF_SAM02_Item_IcedPotato, TRUE)
        EVT_SET(MF_SkipIcedPotato, FALSE)
        EVT_SET(GF_SAM02_Item_IcedPotato, FALSE)
    EVT_END_IF
    EVT_IF_EQ(MF_SkipIcedPotato, FALSE)
        EVT_SET(MF_SkipIcedPotato, TRUE)
        EVT_CALL(MakeItemEntity, ITEM_ICED_POTATO, 349, 25, -280, ITEM_SPAWN_MODE_FIXED_NEVER_VANISH, GF_SAM02_Item_IcedPotato)
    EVT_END_IF
    EVT_IF_GE(GB_StoryProgress, STORY_CH7_UNLOCKED_SHIVER_MOUNTAIN)
        EVT_IF_LT(GB_StoryProgress, STORY_CH8_OPENED_PATH_TO_STAR_WAY)
            EVT_IF_EQ(GF_SAM02_MushroomPresents, FALSE)
                EVT_SET(GF_SAM02_MushroomPresents, TRUE)
                EVT_EXEC(N(EVS_MakeToadHouseGifts))
            EVT_END_IF
        EVT_END_IF
    EVT_END_IF
    EVT_CALL(HidePlayerShadow, FALSE)
    EVT_CALL(UpdatePlayerImgFX, ANIM_Mario1_Idle, IMGFX_CLEAR, 0, 0, 0, 0)
    EVT_CALL(SetPlayerPos, 277, 0, -256)
    EVT_CALL(SetPlayerSpeed, EVT_FLOAT(3.0))
    EVT_CALL(PlayerMoveTo, 336, -199, 0)
    EVT_EXEC(N(EVS_SetupMusic))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInteract_Penguin_02) = {
    EVT_SWITCH(GB_StoryProgress)
        EVT_CASE_LT(STORY_CH7_MAYOR_MURDER_MYSTERY)
            EVT_SWITCH(MV_DialogueState_Penguin2)
                EVT_CASE_EQ(0)
                    EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Penguin_Talk, ANIM_Penguin_Idle, 0, MSG_CH7_0071)
                    EVT_SET(MV_DialogueState_Penguin2, 1)
                EVT_CASE_EQ(1)
                    EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Penguin_Talk, ANIM_Penguin_Idle, 0, MSG_CH7_0072)
                    EVT_SET(MV_DialogueState_Penguin2, 0)
            EVT_END_SWITCH
        EVT_CASE_LT(STORY_CH7_MAYOR_MURDER_SOLVED)
        EVT_CASE_LT(STORY_CH7_STAR_SPIRIT_RESCUED)
            EVT_SWITCH(MV_DialogueState_Penguin2)
                EVT_CASE_EQ(0)
                    EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Penguin_Talk, ANIM_Penguin_Idle, 0, MSG_CH7_0073)
                    EVT_SET(MV_DialogueState_Penguin2, 1)
                EVT_CASE_EQ(1)
                    EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Penguin_Talk, ANIM_Penguin_Idle, 0, MSG_CH7_0074)
                    EVT_SET(MV_DialogueState_Penguin2, 0)
            EVT_END_SWITCH
        EVT_CASE_GE(STORY_CH7_STAR_SPIRIT_RESCUED)
            EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Penguin_Talk, ANIM_Penguin_Idle, 0, MSG_CH7_0075)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInteract_Penguin_03) = {
    EVT_SWITCH(GB_StoryProgress)
        EVT_CASE_LT(STORY_CH7_MAYOR_MURDER_MYSTERY)
            EVT_SWITCH(MV_DialogueState_Penguin3)
                EVT_CASE_EQ(0)
                    EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Penguin_Talk, ANIM_Penguin_Idle, 0, MSG_CH7_0076)
                    EVT_SET(MV_DialogueState_Penguin3, 1)
                EVT_CASE_EQ(1)
                    EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Penguin_Talk, ANIM_Penguin_Idle, 0, MSG_CH7_0077)
                    EVT_SET(MV_DialogueState_Penguin3, 0)
            EVT_END_SWITCH
        EVT_CASE_LT(STORY_CH7_MAYOR_MURDER_SOLVED)
        EVT_CASE_LT(STORY_CH7_STAR_SPIRIT_RESCUED)
            EVT_SWITCH(MV_DialogueState_Penguin3)
                EVT_CASE_EQ(0)
                    EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Penguin_Talk, ANIM_Penguin_Idle, 0, MSG_CH7_0078)
                    EVT_SET(MV_DialogueState_Penguin3, 1)
                EVT_CASE_EQ(1)
                    EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Penguin_Talk, ANIM_Penguin_Idle, 0, MSG_CH7_0079)
                    EVT_SET(MV_DialogueState_Penguin3, 0)
            EVT_END_SWITCH
        EVT_CASE_GE(STORY_CH7_STAR_SPIRIT_RESCUED)
            EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Penguin_Talk, ANIM_Penguin_Idle, 0, MSG_CH7_007A)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcIdle_Penguin_04) = {
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInteract_Penguin_04) = {
    EVT_SWITCH(GB_StoryProgress)
        EVT_CASE_LT(STORY_CH7_MAYOR_MURDER_MYSTERY)
            EVT_SWITCH(MV_DialogueState_Penguin4)
                EVT_CASE_EQ(0)
                    EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Penguin_Talk, ANIM_Penguin_Idle, 0, MSG_CH7_007B)
                    EVT_SET(MV_DialogueState_Penguin4, 1)
                EVT_CASE_EQ(1)
                    EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Penguin_Talk, ANIM_Penguin_Idle, 0, MSG_CH7_007C)
                    EVT_SET(MV_DialogueState_Penguin4, 0)
            EVT_END_SWITCH
        EVT_CASE_LT(STORY_CH7_MAYOR_MURDER_SOLVED)
            EVT_SWITCH(MV_DialogueState_Penguin4)
                EVT_CASE_EQ(0)
                    EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Penguin_Talk, ANIM_Penguin_Idle, 0, MSG_CH7_007D)
                    EVT_SET(MV_DialogueState_Penguin4, 1)
                EVT_CASE_EQ(1)
                    EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Penguin_Talk, ANIM_Penguin_Idle, 0, MSG_CH7_007E)
                    EVT_SET(MV_DialogueState_Penguin4, 0)
            EVT_END_SWITCH
        EVT_CASE_LT(STORY_CH7_STAR_SPIRIT_RESCUED)
            EVT_SWITCH(MV_DialogueState_Penguin4)
                EVT_CASE_EQ(0)
                    EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Penguin_Talk, ANIM_Penguin_Idle, 0, MSG_CH7_007F)
                    EVT_SET(MV_DialogueState_Penguin4, 1)
                EVT_CASE_EQ(1)
                    EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Penguin_Talk, ANIM_Penguin_Idle, 0, MSG_CH7_0080)
                    EVT_SET(MV_DialogueState_Penguin4, 0)
            EVT_END_SWITCH
        EVT_CASE_GE(STORY_CH7_STAR_SPIRIT_RESCUED)
            EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Penguin_Talk, ANIM_Penguin_Idle, 0, MSG_CH7_0081)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInteract_Penguin_05) = {
    EVT_SWITCH(GB_StoryProgress)
        EVT_CASE_LT(STORY_CH7_MAYOR_MURDER_MYSTERY)
            EVT_SWITCH(MV_DialogueState_Penguin5)
                EVT_CASE_EQ(0)
                    EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Penguin_Talk, ANIM_Penguin_Idle, 0, MSG_CH7_0082)
                    EVT_SET(MV_DialogueState_Penguin5, 1)
                EVT_CASE_EQ(1)
                    EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Penguin_Talk, ANIM_Penguin_Idle, 0, MSG_CH7_0083)
                    EVT_SET(MV_DialogueState_Penguin5, 0)
            EVT_END_SWITCH
        EVT_CASE_LT(STORY_CH7_MAYOR_MURDER_SOLVED)
            EVT_SWITCH(MV_DialogueState_Penguin5)
                EVT_CASE_EQ(0)
                    EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Penguin_Talk, ANIM_Penguin_Idle, 0, MSG_CH7_0084)
                    EVT_SET(MV_DialogueState_Penguin5, 1)
                EVT_CASE_EQ(1)
                    EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Penguin_Talk, ANIM_Penguin_Idle, 0, MSG_CH7_0085)
                    EVT_SET(MV_DialogueState_Penguin5, 0)
            EVT_END_SWITCH
        EVT_CASE_LT(STORY_CH7_STAR_SPIRIT_RESCUED)
            EVT_SWITCH(MV_DialogueState_Penguin5)
                EVT_CASE_EQ(0)
                    EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Penguin_Talk, ANIM_Penguin_Idle, 0, MSG_CH7_0086)
                    EVT_SET(MV_DialogueState_Penguin5, 1)
                EVT_CASE_EQ(1)
                    EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Penguin_Talk, ANIM_Penguin_Idle, 0, MSG_CH7_0087)
                    EVT_SET(MV_DialogueState_Penguin5, 0)
            EVT_END_SWITCH
        EVT_CASE_GE(STORY_CH7_STAR_SPIRIT_RESCUED)
            EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Penguin_Talk, ANIM_Penguin_Idle, 0, MSG_CH7_0088)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInteract_Penguin_06) = {
    EVT_SWITCH(GB_StoryProgress)
        EVT_CASE_LT(STORY_CH7_MAYOR_MURDER_MYSTERY)
            EVT_SWITCH(MV_DialogueState_Penguin6)
                EVT_CASE_EQ(0)
                    EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Penguin_Talk, ANIM_Penguin_Idle, 0, MSG_CH7_0089)
                    EVT_SET(MV_DialogueState_Penguin6, 1)
                EVT_CASE_EQ(1)
                    EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Penguin_Talk, ANIM_Penguin_Idle, 0, MSG_CH7_008A)
                    EVT_SET(MV_DialogueState_Penguin6, 0)
            EVT_END_SWITCH
        EVT_CASE_LT(STORY_CH7_MAYOR_MURDER_SOLVED)
            EVT_SWITCH(MV_DialogueState_Penguin6)
                EVT_CASE_EQ(0)
                    EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Penguin_Talk, ANIM_Penguin_Idle, 0, MSG_CH7_008B)
                    EVT_SET(MV_DialogueState_Penguin6, 1)
                EVT_CASE_EQ(1)
                    EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Penguin_Talk, ANIM_Penguin_Idle, 0, MSG_CH7_008C)
                    EVT_SET(MV_DialogueState_Penguin6, 0)
            EVT_END_SWITCH
        EVT_CASE_LT(STORY_CH7_STAR_SPIRIT_RESCUED)
            EVT_SWITCH(MV_DialogueState_Penguin6)
                EVT_CASE_EQ(0)
                    EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Penguin_Talk, ANIM_Penguin_Idle, 0, MSG_CH7_008D)
                    EVT_SET(MV_DialogueState_Penguin6, 1)
                EVT_CASE_EQ(1)
                    EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Penguin_Talk, ANIM_Penguin_Idle, 0, MSG_CH7_008E)
                    EVT_SET(MV_DialogueState_Penguin6, 0)
            EVT_END_SWITCH
        EVT_CASE_GE(STORY_CH7_STAR_SPIRIT_RESCUED)
            EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Penguin_Talk, ANIM_Penguin_Idle, 0, MSG_CH7_008F)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInteract_Penguin_07) = {
    EVT_CALL(FindKeyItem, ITEM_FIRST_DEGREE_CARD, LVar1)
    EVT_CALL(FindKeyItem, ITEM_SECOND_DEGREE_CARD, LVar2)
    EVT_CALL(FindKeyItem, ITEM_THIRD_DEGREE_CARD, LVar3)
    EVT_CALL(FindKeyItem, ITEM_FOURTH_DEGREE_CARD, LVar4)
    EVT_CALL(FindKeyItem, ITEM_DIPLOMA, LVar5)
    EVT_IF_NE(LVar1, -1)
        EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Penguin_Talk, ANIM_Penguin_Idle, 0, MSG_CH7_0091)
        EVT_RETURN
    EVT_END_IF
    EVT_IF_NE(LVar2, -1)
        EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Penguin_Talk, ANIM_Penguin_Idle, 0, MSG_CH7_0092)
        EVT_RETURN
    EVT_END_IF
    EVT_IF_NE(LVar3, -1)
        EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Penguin_Talk, ANIM_Penguin_Idle, 0, MSG_CH7_0093)
        EVT_RETURN
    EVT_END_IF
    EVT_IF_NE(LVar4, -1)
        EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Penguin_Talk, ANIM_Penguin_Idle, 0, MSG_CH7_0094)
        EVT_RETURN
    EVT_END_IF
    EVT_IF_NE(LVar5, -1)
        EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Penguin_Talk, ANIM_Penguin_Idle, 0, MSG_CH7_0095)
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Penguin_Talk, ANIM_Penguin_Idle, 0, MSG_CH7_0090)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_Penguin_ShopOwner) = {
    EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(EVS_NpcInteract_Penguin_ShopOwner)))
    EVT_CALL(BindNpcIdle, NPC_SELF, EVT_PTR(N(EVS_NpcIdle_Penguin_ShopOwner)))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_ShiverToad) = {
    EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(EVS_NpcInteract_ToadHouseKeeper)))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_Penguin_02) = {
    EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(EVS_NpcInteract_Penguin_02)))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_Penguin_03) = {
    EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(EVS_NpcInteract_Penguin_03)))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_Penguin_04) = {
    EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(EVS_NpcInteract_Penguin_04)))
    EVT_IF_GE(GB_StoryProgress, STORY_CH7_MAYOR_MURDER_MYSTERY)
        EVT_IF_LT(GB_StoryProgress, STORY_CH7_MAYOR_MURDER_SOLVED)
            EVT_CALL(SetNpcPos, NPC_SELF, 0, 30, 280)
            EVT_CALL(BindNpcIdle, NPC_SELF, EVT_PTR(N(EVS_NpcIdle_Penguin_04)))
        EVT_END_IF
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_Penguin_05) = {
    EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(EVS_NpcInteract_Penguin_05)))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_Penguin_06) = {
    EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(EVS_NpcInteract_Penguin_06)))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_Penguin_07) = {
    EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(EVS_NpcInteract_Penguin_07)))
    EVT_RETURN
    EVT_END
};

NpcData N(NpcData_Townsfolk)[] = {
    {
        .id = NPC_Penguin_ShopOwner,
        .pos = { 35.0f, 0.0f, -365.0f },
        .yaw = 180,
        .init = &N(EVS_NpcInit_Penguin_ShopOwner),
        .settings = &N(NpcSettings_Penguin),
        .flags = COMMON_PASSIVE_FLAGS | ENEMY_FLAG_400000,
        .drops = NO_DROPS,
        .animations = PENGUIN_ANIMS,
        .tattle = MSG_NpcTattle_SAM_ShopOwner,
    },
    {
        .id = NPC_ShiverToad,
        .pos = { 329.0f, 0.0f, -167.0f },
        .yaw = 180,
        .init = &N(EVS_NpcInit_ShiverToad),
        .settings = &N(NpcSettings_ShiverToad),
        .flags = COMMON_PASSIVE_FLAGS | ENEMY_FLAG_400000,
        .drops = NO_DROPS,
        .animations = SHIVER_TOAD_RED_ANIMS,
        .aiDetectFlags = AI_DETECT_SIGHT | AI_DETECT_FLAG_8,
        .tattle = MSG_NpcTattle_SAM02_ToadHouseToad,
    },
    {
        .id = NPC_Penguin_04,
        .pos = { 0.0f, 0.0f, 60.0f },
        .yaw = 0,
        .territory = {
            .wander = {
                .isFlying = TRUE,
                .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
                .wanderShape = SHAPE_CYLINDER,
                .centerPos  = { 0, 0, 60 },
                .wanderSize = { 50 },
                .detectShape = SHAPE_CYLINDER,
                .detectPos  = { 0, 0, 0 },
                .detectSize = { 0 },
            }
        },
        .init = &N(EVS_NpcInit_Penguin_04),
        .settings = &N(NpcSettings_Penguin_Wander),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_ENABLE_HIT_SCRIPT | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_400000,
        .drops = NO_DROPS,
        .animations = PENGUIN_ANIMS,
        .tattle = MSG_NpcTattle_SAM_CorroboratesRumors,
    },
    {
        .id = NPC_Penguin_05,
        .pos = { -400.0f, 0.0f, 60.0f },
        .yaw = 0,
        .territory = {
            .wander = {
                .isFlying = TRUE,
                .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
                .wanderShape = SHAPE_CYLINDER,
                .centerPos  = { -400, 0, 60 },
                .wanderSize = { 50 },
                .detectShape = SHAPE_CYLINDER,
                .detectPos  = { 0, 0, 0 },
                .detectSize = { 0 },
            }
        },
        .init = &N(EVS_NpcInit_Penguin_05),
        .settings = &N(NpcSettings_Penguin_Wander),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_ENABLE_HIT_SCRIPT | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_400000,
        .drops = NO_DROPS,
        .animations = PENGUIN_ANIMS,
        .tattle = MSG_NpcTattle_SAM_EasyGoing,
    },
    {
        .id = NPC_Penguin_06,
        .pos = { 400.0f, 0.0f, 60.0f },
        .yaw = 0,
        .territory = {
            .wander = {
                .isFlying = TRUE,
                .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
                .wanderShape = SHAPE_CYLINDER,
                .centerPos  = { 400, 0, 60 },
                .wanderSize = { 50 },
                .detectShape = SHAPE_CYLINDER,
                .detectPos  = { 0, 0, 0 },
                .detectSize = { 0 },
            }
        },
        .init = &N(EVS_NpcInit_Penguin_06),
        .settings = &N(NpcSettings_Penguin_Wander),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_ENABLE_HIT_SCRIPT | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_400000,
        .drops = NO_DROPS,
        .animations = PENGUIN_ANIMS,
        .tattle = MSG_NpcTattle_SAM_NeverLeavesTown,
    },
    {
        .id = NPC_Penguin_07,
        .pos = { -237.0f, 0.0f, 273.0f },
        .yaw = 0,
        .init = &N(EVS_NpcInit_Penguin_07),
        .settings = &N(NpcSettings_Penguin),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_ENABLE_HIT_SCRIPT | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_400000,
        .drops = NO_DROPS,
        .animations = PENGUIN_ANIMS,
        .tattle = MSG_NpcTattle_SAM_VisitedTheDojo,
    },
};

NpcData N(NpcData_MysteryOnly)[] = {
    {
        .id = NPC_Penguin_02,
        .pos = { -380.0f, 0.0f, -140.0f },
        .yaw = 0,
        .init = &N(EVS_NpcInit_Penguin_02),
        .settings = &N(NpcSettings_Penguin),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_ENABLE_HIT_SCRIPT | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_400000,
        .drops = NO_DROPS,
        .animations = PENGUIN_ANIMS,
        .tattle = MSG_NpcTattle_SAM_RumorLovingPenguins,
    },
    {
        .id = NPC_Penguin_03,
        .pos = { 200.0f, 0.0f, 60.0f },
        .yaw = 0,
        .territory = {
            .wander = {
                .isFlying = TRUE,
                .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
                .wanderShape = SHAPE_CYLINDER,
                .centerPos  = { 200, 0, 60 },
                .wanderSize = { 50 },
                .detectShape = SHAPE_CYLINDER,
                .detectPos  = { 0, 0, 0 },
                .detectSize = { 0 },
            }
        },
        .init = &N(EVS_NpcInit_Penguin_03),
        .settings = &N(NpcSettings_Penguin_Wander),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_ENABLE_HIT_SCRIPT | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_400000,
        .drops = NO_DROPS,
        .animations = PENGUIN_ANIMS,
        .tattle = MSG_NpcTattle_SAM_NotAdventurous,
    },
};

NpcData N(NpcData_ChuckQuizmo) = {
    .id = NPC_ChuckQuizmo,
    .pos = { -230.0f, 0.0f, 160.0f },
    .yaw = 90,
    .initVarCount = 1,
    .initVar = { .bytes = { 0, QUIZ_AREA_SAM, QUIZ_COUNT_SAM, QUIZ_MAP_SAM_02 }},
    .settings = &N(NpcSettings_ChuckQuizmo),
    .flags = COMMON_PASSIVE_FLAGS | ENEMY_FLAG_NO_SHADOW_RAYCAST,
    .drops = NO_DROPS,
    .animations = QUIZMO_ANIMS,
    .tattle = MSG_NpcTattle_ChuckQuizmo,
};

NpcGroupList N(DefaultNPCs) = {
    NPC_GROUP(N(NpcData_Townsfolk), BTL_KMR_1_FORMATION_00, BTL_KMR_1_STAGE_00),
    NPC_GROUP(N(NpcData_MysteryOnly), BTL_KMR_1_FORMATION_00, BTL_KMR_1_STAGE_00),
    NPC_GROUP(N(NpcData_ChuckQuizmo)),
    {}
};

NpcGroupList N(MysteryNPCs) = {
    NPC_GROUP(N(NpcData_Townsfolk), BTL_KMR_1_FORMATION_00, BTL_KMR_1_STAGE_00),
    NPC_GROUP(N(NpcData_ChuckQuizmo)),
    {}
};
