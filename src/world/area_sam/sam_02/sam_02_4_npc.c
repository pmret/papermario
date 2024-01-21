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
    Switch(GB_StoryProgress)
        CaseLt(STORY_CH7_MAYOR_MURDER_MYSTERY)
            ExecWait(EVS_ShopOwnerDialog)
        CaseLt(STORY_CH7_MAYOR_MURDER_SOLVED)
            Call(SpeakToPlayer, NPC_SELF, ANIM_Penguin_Talk, ANIM_Penguin_Idle, 0, MSG_CH7_006A)
        CaseGe(STORY_CH7_MAYOR_MURDER_SOLVED)
            ExecWait(EVS_ShopOwnerDialog)
    EndSwitch
    Return
    End
};

EvtScript N(EVS_NpcIdle_Penguin_ShopOwner) = {
    Return
    End
};

EvtScript N(EVS_ToadHouse_SetDialogue) = {
    Set(LVar0, MSG_CH7_006B)
    Set(LVar8, MSG_CH7_006C)
    Set(LVar1, MSG_CH7_006D)
    Set(LVar2, MSG_CH7_006E)
    Set(LVar3, MSG_CH7_006F)
    IfGe(GB_StoryProgress, STORY_CH7_UNLOCKED_SHIVER_MOUNTAIN)
        IfLt(GB_StoryProgress, STORY_CH8_OPENED_PATH_TO_STAR_WAY)
            IfEq(GF_SAM02_MushroomPresents, FALSE)
                Set(LVar3, MSG_CH7_0070)
            EndIf
        EndIf
    EndIf
    Return
    End
};

EvtScript N(EVS_ToadHouse_GetInBed) = {
    Exec(N(EVS_PlayRestingSong))
    Call(SetPlayerSpeed, Float(3.0))
    Call(PlayerMoveTo, 294, -213, 0)
    Thread
        Wait(15)
        Call(N(ToadHouse_CamSetFOV), 0, 40)
        Call(SetCamType, CAM_DEFAULT, 4, FALSE)
        Call(SetCamPitch, CAM_DEFAULT, 65, -36)
        Call(SetCamDistance, CAM_DEFAULT, 111)
        Call(SetCamPosA, CAM_DEFAULT, 549, -5)
        Call(SetCamPosB, CAM_DEFAULT, 315, -171)
        Call(SetCamPosC, CAM_DEFAULT, 0, 23)
        Call(SetCamSpeed, CAM_DEFAULT, Float(90.0))
        Call(PanToTarget, CAM_DEFAULT, 0, 1)
    EndThread
    Call(PlayerMoveTo, 274, -270, 0)
    Call(InterpPlayerYaw, 229, 1)
    Call(HidePlayerShadow, TRUE)
    Call(SetPlayerAnimation, ANIM_Mario1_Idle)
    Call(SetPlayerImgFXFlags, IMGFX_FLAG_800)
    Call(UpdatePlayerImgFX, ANIM_Mario1_Idle, IMGFX_SET_ANIM, IMGFX_ANIM_GET_IN_BED, 1, 1, 0)
    Thread
        Wait(60)
        Call(SetPlayerAnimation, ANIM_MarioW2_SleepStanding)
    EndThread
    Wait(20)
    Thread
        Wait(81)
        Call(N(ToadHouse_CamSetFOV), 0, 25)
        Call(GetPlayerPos, LVar0, LVar1, LVar2)
        Call(UseSettingsFrom, CAM_DEFAULT, LVar0, LVar1, LVar2)
        Wait(1)
        Call(PanToTarget, CAM_DEFAULT, 0, 0)
    EndThread
    Return
    End
};

EvtScript N(EVS_ToadHouse_ReturnFromRest) = {
    IfEq(GF_SAM02_Item_IcedPotato, TRUE)
        Set(MF_SkipIcedPotato, FALSE)
        Set(GF_SAM02_Item_IcedPotato, FALSE)
    EndIf
    IfEq(MF_SkipIcedPotato, FALSE)
        Set(MF_SkipIcedPotato, TRUE)
        Call(MakeItemEntity, ITEM_ICED_POTATO, 349, 25, -280, ITEM_SPAWN_MODE_FIXED_NEVER_VANISH, GF_SAM02_Item_IcedPotato)
    EndIf
    IfGe(GB_StoryProgress, STORY_CH7_UNLOCKED_SHIVER_MOUNTAIN)
        IfLt(GB_StoryProgress, STORY_CH8_OPENED_PATH_TO_STAR_WAY)
            IfEq(GF_SAM02_MushroomPresents, FALSE)
                Set(GF_SAM02_MushroomPresents, TRUE)
                Exec(N(EVS_MakeToadHouseGifts))
            EndIf
        EndIf
    EndIf
    Call(HidePlayerShadow, FALSE)
    Call(UpdatePlayerImgFX, ANIM_Mario1_Idle, IMGFX_CLEAR, 0, 0, 0, 0)
    Call(SetPlayerPos, 277, 0, -256)
    Call(SetPlayerSpeed, Float(3.0))
    Call(PlayerMoveTo, 336, -199, 0)
    Exec(N(EVS_SetupMusic))
    Return
    End
};

EvtScript N(EVS_NpcInteract_Penguin_02) = {
    Switch(GB_StoryProgress)
        CaseLt(STORY_CH7_MAYOR_MURDER_MYSTERY)
            Switch(MV_DialogueState_Penguin2)
                CaseEq(0)
                    Call(SpeakToPlayer, NPC_SELF, ANIM_Penguin_Talk, ANIM_Penguin_Idle, 0, MSG_CH7_0071)
                    Set(MV_DialogueState_Penguin2, 1)
                CaseEq(1)
                    Call(SpeakToPlayer, NPC_SELF, ANIM_Penguin_Talk, ANIM_Penguin_Idle, 0, MSG_CH7_0072)
                    Set(MV_DialogueState_Penguin2, 0)
            EndSwitch
        CaseLt(STORY_CH7_MAYOR_MURDER_SOLVED)
        CaseLt(STORY_CH7_STAR_SPIRIT_RESCUED)
            Switch(MV_DialogueState_Penguin2)
                CaseEq(0)
                    Call(SpeakToPlayer, NPC_SELF, ANIM_Penguin_Talk, ANIM_Penguin_Idle, 0, MSG_CH7_0073)
                    Set(MV_DialogueState_Penguin2, 1)
                CaseEq(1)
                    Call(SpeakToPlayer, NPC_SELF, ANIM_Penguin_Talk, ANIM_Penguin_Idle, 0, MSG_CH7_0074)
                    Set(MV_DialogueState_Penguin2, 0)
            EndSwitch
        CaseGe(STORY_CH7_STAR_SPIRIT_RESCUED)
            Call(SpeakToPlayer, NPC_SELF, ANIM_Penguin_Talk, ANIM_Penguin_Idle, 0, MSG_CH7_0075)
    EndSwitch
    Return
    End
};

EvtScript N(EVS_NpcInteract_Penguin_03) = {
    Switch(GB_StoryProgress)
        CaseLt(STORY_CH7_MAYOR_MURDER_MYSTERY)
            Switch(MV_DialogueState_Penguin3)
                CaseEq(0)
                    Call(SpeakToPlayer, NPC_SELF, ANIM_Penguin_Talk, ANIM_Penguin_Idle, 0, MSG_CH7_0076)
                    Set(MV_DialogueState_Penguin3, 1)
                CaseEq(1)
                    Call(SpeakToPlayer, NPC_SELF, ANIM_Penguin_Talk, ANIM_Penguin_Idle, 0, MSG_CH7_0077)
                    Set(MV_DialogueState_Penguin3, 0)
            EndSwitch
        CaseLt(STORY_CH7_MAYOR_MURDER_SOLVED)
        CaseLt(STORY_CH7_STAR_SPIRIT_RESCUED)
            Switch(MV_DialogueState_Penguin3)
                CaseEq(0)
                    Call(SpeakToPlayer, NPC_SELF, ANIM_Penguin_Talk, ANIM_Penguin_Idle, 0, MSG_CH7_0078)
                    Set(MV_DialogueState_Penguin3, 1)
                CaseEq(1)
                    Call(SpeakToPlayer, NPC_SELF, ANIM_Penguin_Talk, ANIM_Penguin_Idle, 0, MSG_CH7_0079)
                    Set(MV_DialogueState_Penguin3, 0)
            EndSwitch
        CaseGe(STORY_CH7_STAR_SPIRIT_RESCUED)
            Call(SpeakToPlayer, NPC_SELF, ANIM_Penguin_Talk, ANIM_Penguin_Idle, 0, MSG_CH7_007A)
    EndSwitch
    Return
    End
};

EvtScript N(EVS_NpcIdle_Penguin_04) = {
    Return
    End
};

EvtScript N(EVS_NpcInteract_Penguin_04) = {
    Switch(GB_StoryProgress)
        CaseLt(STORY_CH7_MAYOR_MURDER_MYSTERY)
            Switch(MV_DialogueState_Penguin4)
                CaseEq(0)
                    Call(SpeakToPlayer, NPC_SELF, ANIM_Penguin_Talk, ANIM_Penguin_Idle, 0, MSG_CH7_007B)
                    Set(MV_DialogueState_Penguin4, 1)
                CaseEq(1)
                    Call(SpeakToPlayer, NPC_SELF, ANIM_Penguin_Talk, ANIM_Penguin_Idle, 0, MSG_CH7_007C)
                    Set(MV_DialogueState_Penguin4, 0)
            EndSwitch
        CaseLt(STORY_CH7_MAYOR_MURDER_SOLVED)
            Switch(MV_DialogueState_Penguin4)
                CaseEq(0)
                    Call(SpeakToPlayer, NPC_SELF, ANIM_Penguin_Talk, ANIM_Penguin_Idle, 0, MSG_CH7_007D)
                    Set(MV_DialogueState_Penguin4, 1)
                CaseEq(1)
                    Call(SpeakToPlayer, NPC_SELF, ANIM_Penguin_Talk, ANIM_Penguin_Idle, 0, MSG_CH7_007E)
                    Set(MV_DialogueState_Penguin4, 0)
            EndSwitch
        CaseLt(STORY_CH7_STAR_SPIRIT_RESCUED)
            Switch(MV_DialogueState_Penguin4)
                CaseEq(0)
                    Call(SpeakToPlayer, NPC_SELF, ANIM_Penguin_Talk, ANIM_Penguin_Idle, 0, MSG_CH7_007F)
                    Set(MV_DialogueState_Penguin4, 1)
                CaseEq(1)
                    Call(SpeakToPlayer, NPC_SELF, ANIM_Penguin_Talk, ANIM_Penguin_Idle, 0, MSG_CH7_0080)
                    Set(MV_DialogueState_Penguin4, 0)
            EndSwitch
        CaseGe(STORY_CH7_STAR_SPIRIT_RESCUED)
            Call(SpeakToPlayer, NPC_SELF, ANIM_Penguin_Talk, ANIM_Penguin_Idle, 0, MSG_CH7_0081)
    EndSwitch
    Return
    End
};

EvtScript N(EVS_NpcInteract_Penguin_05) = {
    Switch(GB_StoryProgress)
        CaseLt(STORY_CH7_MAYOR_MURDER_MYSTERY)
            Switch(MV_DialogueState_Penguin5)
                CaseEq(0)
                    Call(SpeakToPlayer, NPC_SELF, ANIM_Penguin_Talk, ANIM_Penguin_Idle, 0, MSG_CH7_0082)
                    Set(MV_DialogueState_Penguin5, 1)
                CaseEq(1)
                    Call(SpeakToPlayer, NPC_SELF, ANIM_Penguin_Talk, ANIM_Penguin_Idle, 0, MSG_CH7_0083)
                    Set(MV_DialogueState_Penguin5, 0)
            EndSwitch
        CaseLt(STORY_CH7_MAYOR_MURDER_SOLVED)
            Switch(MV_DialogueState_Penguin5)
                CaseEq(0)
                    Call(SpeakToPlayer, NPC_SELF, ANIM_Penguin_Talk, ANIM_Penguin_Idle, 0, MSG_CH7_0084)
                    Set(MV_DialogueState_Penguin5, 1)
                CaseEq(1)
                    Call(SpeakToPlayer, NPC_SELF, ANIM_Penguin_Talk, ANIM_Penguin_Idle, 0, MSG_CH7_0085)
                    Set(MV_DialogueState_Penguin5, 0)
            EndSwitch
        CaseLt(STORY_CH7_STAR_SPIRIT_RESCUED)
            Switch(MV_DialogueState_Penguin5)
                CaseEq(0)
                    Call(SpeakToPlayer, NPC_SELF, ANIM_Penguin_Talk, ANIM_Penguin_Idle, 0, MSG_CH7_0086)
                    Set(MV_DialogueState_Penguin5, 1)
                CaseEq(1)
                    Call(SpeakToPlayer, NPC_SELF, ANIM_Penguin_Talk, ANIM_Penguin_Idle, 0, MSG_CH7_0087)
                    Set(MV_DialogueState_Penguin5, 0)
            EndSwitch
        CaseGe(STORY_CH7_STAR_SPIRIT_RESCUED)
            Call(SpeakToPlayer, NPC_SELF, ANIM_Penguin_Talk, ANIM_Penguin_Idle, 0, MSG_CH7_0088)
    EndSwitch
    Return
    End
};

EvtScript N(EVS_NpcInteract_Penguin_06) = {
    Switch(GB_StoryProgress)
        CaseLt(STORY_CH7_MAYOR_MURDER_MYSTERY)
            Switch(MV_DialogueState_Penguin6)
                CaseEq(0)
                    Call(SpeakToPlayer, NPC_SELF, ANIM_Penguin_Talk, ANIM_Penguin_Idle, 0, MSG_CH7_0089)
                    Set(MV_DialogueState_Penguin6, 1)
                CaseEq(1)
                    Call(SpeakToPlayer, NPC_SELF, ANIM_Penguin_Talk, ANIM_Penguin_Idle, 0, MSG_CH7_008A)
                    Set(MV_DialogueState_Penguin6, 0)
            EndSwitch
        CaseLt(STORY_CH7_MAYOR_MURDER_SOLVED)
            Switch(MV_DialogueState_Penguin6)
                CaseEq(0)
                    Call(SpeakToPlayer, NPC_SELF, ANIM_Penguin_Talk, ANIM_Penguin_Idle, 0, MSG_CH7_008B)
                    Set(MV_DialogueState_Penguin6, 1)
                CaseEq(1)
                    Call(SpeakToPlayer, NPC_SELF, ANIM_Penguin_Talk, ANIM_Penguin_Idle, 0, MSG_CH7_008C)
                    Set(MV_DialogueState_Penguin6, 0)
            EndSwitch
        CaseLt(STORY_CH7_STAR_SPIRIT_RESCUED)
            Switch(MV_DialogueState_Penguin6)
                CaseEq(0)
                    Call(SpeakToPlayer, NPC_SELF, ANIM_Penguin_Talk, ANIM_Penguin_Idle, 0, MSG_CH7_008D)
                    Set(MV_DialogueState_Penguin6, 1)
                CaseEq(1)
                    Call(SpeakToPlayer, NPC_SELF, ANIM_Penguin_Talk, ANIM_Penguin_Idle, 0, MSG_CH7_008E)
                    Set(MV_DialogueState_Penguin6, 0)
            EndSwitch
        CaseGe(STORY_CH7_STAR_SPIRIT_RESCUED)
            Call(SpeakToPlayer, NPC_SELF, ANIM_Penguin_Talk, ANIM_Penguin_Idle, 0, MSG_CH7_008F)
    EndSwitch
    Return
    End
};

EvtScript N(EVS_NpcInteract_Penguin_07) = {
    Call(FindKeyItem, ITEM_FIRST_DEGREE_CARD, LVar1)
    Call(FindKeyItem, ITEM_SECOND_DEGREE_CARD, LVar2)
    Call(FindKeyItem, ITEM_THIRD_DEGREE_CARD, LVar3)
    Call(FindKeyItem, ITEM_FOURTH_DEGREE_CARD, LVar4)
    Call(FindKeyItem, ITEM_DIPLOMA, LVar5)
    IfNe(LVar1, -1)
        Call(SpeakToPlayer, NPC_SELF, ANIM_Penguin_Talk, ANIM_Penguin_Idle, 0, MSG_CH7_0091)
        Return
    EndIf
    IfNe(LVar2, -1)
        Call(SpeakToPlayer, NPC_SELF, ANIM_Penguin_Talk, ANIM_Penguin_Idle, 0, MSG_CH7_0092)
        Return
    EndIf
    IfNe(LVar3, -1)
        Call(SpeakToPlayer, NPC_SELF, ANIM_Penguin_Talk, ANIM_Penguin_Idle, 0, MSG_CH7_0093)
        Return
    EndIf
    IfNe(LVar4, -1)
        Call(SpeakToPlayer, NPC_SELF, ANIM_Penguin_Talk, ANIM_Penguin_Idle, 0, MSG_CH7_0094)
        Return
    EndIf
    IfNe(LVar5, -1)
        Call(SpeakToPlayer, NPC_SELF, ANIM_Penguin_Talk, ANIM_Penguin_Idle, 0, MSG_CH7_0095)
        Return
    EndIf
    Call(SpeakToPlayer, NPC_SELF, ANIM_Penguin_Talk, ANIM_Penguin_Idle, 0, MSG_CH7_0090)
    Return
    End
};

EvtScript N(EVS_NpcInit_Penguin_ShopOwner) = {
    Call(BindNpcInteract, NPC_SELF, Ref(N(EVS_NpcInteract_Penguin_ShopOwner)))
    Call(BindNpcIdle, NPC_SELF, Ref(N(EVS_NpcIdle_Penguin_ShopOwner)))
    Return
    End
};

EvtScript N(EVS_NpcInit_ShiverToad) = {
    Call(BindNpcInteract, NPC_SELF, Ref(N(EVS_NpcInteract_ToadHouseKeeper)))
    Return
    End
};

EvtScript N(EVS_NpcInit_Penguin_02) = {
    Call(BindNpcInteract, NPC_SELF, Ref(N(EVS_NpcInteract_Penguin_02)))
    Return
    End
};

EvtScript N(EVS_NpcInit_Penguin_03) = {
    Call(BindNpcInteract, NPC_SELF, Ref(N(EVS_NpcInteract_Penguin_03)))
    Return
    End
};

EvtScript N(EVS_NpcInit_Penguin_04) = {
    Call(BindNpcInteract, NPC_SELF, Ref(N(EVS_NpcInteract_Penguin_04)))
    IfGe(GB_StoryProgress, STORY_CH7_MAYOR_MURDER_MYSTERY)
        IfLt(GB_StoryProgress, STORY_CH7_MAYOR_MURDER_SOLVED)
            Call(SetNpcPos, NPC_SELF, 0, 30, 280)
            Call(BindNpcIdle, NPC_SELF, Ref(N(EVS_NpcIdle_Penguin_04)))
        EndIf
    EndIf
    Return
    End
};

EvtScript N(EVS_NpcInit_Penguin_05) = {
    Call(BindNpcInteract, NPC_SELF, Ref(N(EVS_NpcInteract_Penguin_05)))
    Return
    End
};

EvtScript N(EVS_NpcInit_Penguin_06) = {
    Call(BindNpcInteract, NPC_SELF, Ref(N(EVS_NpcInteract_Penguin_06)))
    Return
    End
};

EvtScript N(EVS_NpcInit_Penguin_07) = {
    Call(BindNpcInteract, NPC_SELF, Ref(N(EVS_NpcInteract_Penguin_07)))
    Return
    End
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
