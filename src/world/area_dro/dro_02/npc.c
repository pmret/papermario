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
    Call(BasicAI_Main, Ref(N(AISettings_Archeologist)))
    Return
    End
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
    Call(N(LetterDelivery_Init),
        NPC_Dryite_01, ANIM_Dryite_Blue_Talk, ANIM_Dryite_Blue_Idle,
        ITEM_LETTER_CHAIN_MR_E, ITEM_LETTER_CHAIN_MISS_T,
        MSG_CH2_0095, MSG_CH2_0096, MSG_CH2_0097, MSG_CH2_0098,
        Ref(N(LetterList)))
    ExecWait(N(EVS_DoLetterDelivery))
    Return
    End
};

EvtScript N(EVS_NpcInteract_Archeologist) = {
    Switch(GB_StoryProgress)
        CaseLt(STORY_CH2_STAR_SPRIT_DEPARTED)
            IfEq(GF_SBK30_Kolorado_SharedRumorAboutMoustafa, TRUE)
                Call(SpeakToPlayer, NPC_SELF, ANIM_Archeologist_Talk, ANIM_Archeologist_Idle, 0, MSG_CH2_00B2)
            Else
                Switch(AB_DRO_3)
                    CaseEq(0)
                        Call(SpeakToPlayer, NPC_SELF, ANIM_Archeologist_Talk, ANIM_Archeologist_Idle, 0, MSG_CH2_00AF)
                        Set(AB_DRO_3, 1)
                    CaseEq(1)
                        Call(SpeakToPlayer, NPC_SELF, ANIM_Archeologist_Talk, ANIM_Archeologist_Idle, 0, MSG_CH2_00B0)
                        Set(AB_DRO_3, 2)
                    CaseEq(2)
                        Call(SpeakToPlayer, NPC_SELF, ANIM_Archeologist_Talk, ANIM_Archeologist_Idle, 0, MSG_CH2_00B1)
                        Set(AB_DRO_3, 1)
                EndSwitch
            EndIf
        CaseDefault
            Call(SpeakToPlayer, NPC_SELF, ANIM_Archeologist_Talk, ANIM_Archeologist_Idle, 0, MSG_CH2_00B3)
    EndSwitch
    Return
    End
};

EvtScript N(EVS_NpcInit_Archeologist) = {
    Call(BindNpcInteract, NPC_SELF, Ref(N(EVS_NpcInteract_Archeologist)))
    IfGe(GB_StoryProgress, STORY_UNUSED_FFFFFFCC)
        Call(RemoveNpc, NPC_SELF)
    EndIf
    Return
    End
};

EvtScript N(EVS_NpcInteract_MrE) = {
    Switch(GB_StoryProgress)
        CaseLt(STORY_CH2_STAR_SPRIT_DEPARTED)
            IfEq(GF_DRO02_Sheek_AskedAboutDesert, FALSE)
                Call(SpeakToPlayer, NPC_SELF, ANIM_Dryite_Blue_Talk, ANIM_Dryite_Blue_Idle, 0, MSG_CH2_0091)
            Else
                Call(SpeakToPlayer, NPC_SELF, ANIM_Dryite_Blue_Talk, ANIM_Dryite_Blue_Idle, 0, MSG_CH2_0092)
            EndIf
        CaseLt(STORY_CH5_STAR_SPRIT_DEPARTED)
            Call(SpeakToPlayer, NPC_SELF, ANIM_Dryite_Blue_Talk, ANIM_Dryite_Blue_Idle, 0, MSG_CH2_0093)
        CaseDefault
            Call(SpeakToPlayer, NPC_SELF, ANIM_Dryite_Blue_Talk, ANIM_Dryite_Blue_Idle, 0, MSG_CH2_0094)
    EndSwitch
    ExecWait(N(EVS_LetterPrompt_MrE))
    IfNe(LVarC, 0)
        Return
    EndIf
    Return
    End
};

EvtScript N(EVS_NpcInit_MrE) = {
    Call(BindNpcInteract, NPC_SELF, Ref(N(EVS_NpcInteract_MrE)))
    Return
    End
};

EvtScript N(EVS_NpcInteract_Dryite_02) = {
    Switch(GB_StoryProgress)
        CaseLt(STORY_CH2_STAR_SPRIT_DEPARTED)
            IfEq(AF_DRO_03, FALSE)
                Call(SpeakToPlayer, NPC_SELF, ANIM_Dryite_Green_Talk, ANIM_Dryite_Green_Idle, 0, MSG_CH2_00A1)
                Set(AF_DRO_03, TRUE)
            Else
                Call(SpeakToPlayer, NPC_SELF, ANIM_Dryite_Green_Talk, ANIM_Dryite_Green_Idle, 0, MSG_CH2_00A2)
                Set(AF_DRO_03, FALSE)
            EndIf
        CaseLt(STORY_CH5_STAR_SPRIT_DEPARTED)
            Call(SpeakToPlayer, NPC_SELF, ANIM_Dryite_Green_Talk, ANIM_Dryite_Green_Idle, 0, MSG_CH2_00A3)
        CaseDefault
            Call(SpeakToPlayer, NPC_SELF, ANIM_Dryite_Green_Talk, ANIM_Dryite_Green_Idle, 0, MSG_CH2_00A4)
    EndSwitch
    Return
    End
};

EvtScript N(EVS_NpcInit_Dryite_02) = {
    Call(BindNpcInteract, NPC_SELF, Ref(N(EVS_NpcInteract_Dryite_02)))
    Return
    End
};

EvtScript N(EVS_NpcInteract_Dryite_03) = {
    Call(SpeakToPlayer, NPC_SELF, ANIM_Dryite_Green_Talk, ANIM_Dryite_Green_Idle, 0, MSG_CH2_00A0)
    Return
    End
};

EvtScript N(EVS_NpcInit_Dryite_03) = {
    Call(BindNpcInteract, NPC_SELF, Ref(N(EVS_NpcInteract_Dryite_03)))
    Return
    End
};

EvtScript N(EVS_NpcInteract_Mouser_01) = {
    Switch(GB_StoryProgress)
        CaseLt(STORY_CH2_STAR_SPRIT_DEPARTED)
            IfEq(AF_DRO_04, FALSE)
                Call(SpeakToPlayer, NPC_SELF, ANIM_Mouser_Blue_Talk, ANIM_Mouser_Blue_Idle, 0, MSG_CH2_00A5)
                Set(AF_DRO_04, TRUE)
            Else
                Call(SpeakToPlayer, NPC_SELF, ANIM_Mouser_Blue_Talk, ANIM_Mouser_Blue_Idle, 0, MSG_CH2_00A6)
                Set(AF_DRO_04, FALSE)
            EndIf
        CaseLt(STORY_CH5_STAR_SPRIT_DEPARTED)
            IfEq(AF_DRO_04, FALSE)
                Call(SpeakToPlayer, NPC_SELF, ANIM_Mouser_Blue_Talk, ANIM_Mouser_Blue_Idle, 0, MSG_CH2_00A7)
                Set(AF_DRO_04, TRUE)
            Else
                Call(SpeakToPlayer, NPC_SELF, ANIM_Mouser_Blue_Talk, ANIM_Mouser_Blue_Idle, 0, MSG_CH2_00A8)
                Set(AF_DRO_04, FALSE)
            EndIf
        CaseDefault
            IfEq(AF_DRO_04, FALSE)
                Call(SpeakToPlayer, NPC_SELF, ANIM_Mouser_Blue_Talk, ANIM_Mouser_Blue_Idle, 0, MSG_CH2_00A9)
                Set(AF_DRO_04, TRUE)
            Else
                Call(SpeakToPlayer, NPC_SELF, ANIM_Mouser_Blue_Talk, ANIM_Mouser_Blue_Idle, 0, MSG_CH2_00AA)
                Set(AF_DRO_04, FALSE)
            EndIf
    EndSwitch
    Return
    End
};

EvtScript N(EVS_NpcInit_Mouser_01) = {
    Call(BindNpcInteract, NPC_SELF, Ref(N(EVS_NpcInteract_Mouser_01)))
    Return
    End
};

EvtScript N(EVS_NpcInteract_Mouser_02) = {
    Switch(GB_StoryProgress)
        CaseLt(STORY_CH2_STAR_SPRIT_DEPARTED)
            IfEq(AF_DRO_05, FALSE)
                Call(SpeakToPlayer, NPC_SELF, ANIM_Mouser_Blue_Talk, ANIM_Mouser_Blue_Idle, 0, MSG_CH2_00AB)
                Set(AF_DRO_05, TRUE)
            Else
                Call(SpeakToPlayer, NPC_SELF, ANIM_Mouser_Blue_Talk, ANIM_Mouser_Blue_Idle, 0, MSG_CH2_00AC)
                Set(AF_DRO_05, FALSE)
            EndIf
        CaseLt(STORY_CH5_STAR_SPRIT_DEPARTED)
            Call(SpeakToPlayer, NPC_SELF, ANIM_Mouser_Blue_Talk, ANIM_Mouser_Blue_Idle, 0, MSG_CH2_00AD)
        CaseDefault
            Call(SpeakToPlayer, NPC_SELF, ANIM_Mouser_Blue_Talk, ANIM_Mouser_Blue_Idle, 0, MSG_CH2_00AE)
    EndSwitch
    Return
    End
};

EvtScript N(EVS_NpcInit_Mouser_02) = {
    Call(BindNpcInteract, NPC_SELF, Ref(N(EVS_NpcInteract_Mouser_02)))
    Return
    End
};

#include "npc_moustafa.c"

EvtScript N(EVS_NpcIdle_Mouser_03) = {
    Call(InterpNpcYaw, NPC_DisguisedMoustafa, 270, 0)
    Label(10)
        Call(SetNpcAnimation, NPC_SELF, ANIM_Mouser_Purple_Gossip)
        Call(SetNpcAnimation, NPC_DisguisedMoustafa, ANIM_DisguisedMoustafa_Idle)
        Loop(50)
            Call(IsPlayerWithin, 200, 50, 100, LVar0)
            IfEq(LVar0, 1)
                Goto(20)
            EndIf
            Wait(1)
        EndLoop
        Call(SetNpcAnimation, NPC_SELF, ANIM_Mouser_Purple_Idle)
        Call(SetNpcAnimation, NPC_DisguisedMoustafa, ANIM_DisguisedMoustafa_TalkAlt)
        Loop(50)
            Call(IsPlayerWithin, 200, 50, 100, LVar0)
            IfEq(LVar0, 1)
                Goto(20)
            EndIf
            Wait(1)
        EndLoop
        Goto(10)
    Label(20)
    Call(SetNpcAnimation, NPC_DisguisedMoustafa, ANIM_DisguisedMoustafa_Idle)
    Call(SetNpcAnimation, NPC_SELF, ANIM_Mouser_Purple_Run)
    Call(SetNpcFlagBits, NPC_SELF, NPC_FLAG_IGNORE_PLAYER_COLLISION, TRUE)
    Call(SetNpcAnimation, NPC_SELF, ANIM_Mouser_Purple_Run)
    Call(NpcMoveTo, NPC_SELF, 150, 18, 20)
    Call(EnableNpcBlur, NPC_SELF, TRUE)
    Call(PlaySoundAtNpc, NPC_SELF, SOUND_RUN_AWAY, SOUND_SPACE_DEFAULT)
    Call(NpcMoveTo, NPC_SELF, -83, 11, 20 * DT)
    Call(NpcMoveTo, NPC_SELF, -239, 5, 20 * DT)
    Call(NpcMoveTo, NPC_SELF, -371, 5, 20 * DT)
    Call(NpcMoveTo, NPC_SELF, -487, 5, 20 * DT)
    Call(SetNpcPos, NPC_SELF, NPC_DISPOSE_LOCATION)
    Set(GB_StoryProgress, STORY_CH2_SPOKE_WITH_SHEEK)
    Return
    End
};

EvtScript N(EVS_NpcInit_Mouser_03) = {
    Call(BindNpcIdle, NPC_SELF, Ref(N(EVS_NpcIdle_Mouser_03)))
    IfGe(GB_StoryProgress, STORY_CH2_SPOKE_WITH_SHEEK)
        Call(RemoveNpc, NPC_SELF)
    EndIf
    Return
    End
};

EvtScript N(EVS_ToadHouse_SetDialogue) = {
    Set(LVar0, MSG_CH2_00D1)
    Set(LVar8, MSG_CH2_00D2)
    Set(LVar1, MSG_CH2_00D3)
    Set(LVar2, MSG_CH2_00D4)
    Set(LVar3, MSG_CH2_00D5)
    Return
    End
};

EvtScript N(EVS_ToadHouse_GetInBed) = {
    Exec(N(EVS_PlayRestMusic))
    Call(SetPlayerSpeed, Float(3.0))
    Call(PlayerMoveTo, -179, -198, 0)
    Thread
        Wait(15)
        Call(N(ToadHouse_CamSetFOV), 0, 40)
        Call(SetCamType, CAM_DEFAULT, 4, FALSE)
        Call(SetCamPitch, CAM_DEFAULT, 95, -61)
        Call(SetCamDistance, CAM_DEFAULT, 108)
        Call(SetCamPosA, CAM_DEFAULT, 202, 62)
        Call(SetCamPosB, CAM_DEFAULT, -89, -141)
        Call(SetCamPosC, CAM_DEFAULT, 0, 0)
        Call(SetCamSpeed, CAM_DEFAULT, Float(90.0))
        Call(PanToTarget, CAM_DEFAULT, 0, 1)
    EndThread
    Call(PlayerMoveTo, -187, -267, 0)
    Call(InterpPlayerYaw, 230, 1)
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
    Call(HidePlayerShadow, FALSE)
    Call(UpdatePlayerImgFX, ANIM_Mario1_Idle, IMGFX_CLEAR, 0, 0, 0, 0)
    Call(SetPlayerPos, -187, 0, -240)
    Call(SetPlayerSpeed, Float(3.0))
    Call(PlayerMoveTo, -168, -195, 0)
    Exec(N(EVS_SetupMusic))
    Return
    End
};

EvtScript N(EVS_NpcInit_ToadHouseKeeper) = {
    Call(BindNpcInteract, NPC_SELF, Ref(N(EVS_NpcInteract_ToadHouseKeeper)))
    Return
    End
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
