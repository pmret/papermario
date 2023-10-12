#include "flo_15.h"
#include "sprite/player.h"

#include "world/common/npc/Sun.inc.c"

EvtScript N(EVS_Sun_AnimateBobbing) = {
    EVT_IF_LT(GB_StoryProgress, STORY_CH6_DESTROYED_PUFF_PUFF_MACHINE)
        EVT_SET(LVar3, 7)
        EVT_SET(LVar4, 5)
    EVT_ELSE
        EVT_SET(LVar3, 15)
        EVT_SET(LVar4, 1)
    EVT_END_IF
    EVT_LOOP(0)
        EVT_SET(LVar5, LVar3)
        EVT_LOOP(LVar5)
            EVT_CALL(GetNpcPos, NPC_Sun_01, LVar0, LVar1, LVar2)
            EVT_ADD(LVar1, 1)
            EVT_CALL(SetNpcPos, NPC_Sun_01, LVar0, LVar1, LVar2)
            EVT_CALL(SetNpcPos, NPC_Sun_02, LVar0, LVar1, LVar2)
            EVT_WAIT(LVar4)
        EVT_END_LOOP
        EVT_SET(LVar5, LVar3)
        EVT_LOOP(LVar5)
            EVT_CALL(GetNpcPos, NPC_Sun_01, LVar0, LVar1, LVar2)
            EVT_ADD(LVar1, -1)
            EVT_CALL(SetNpcPos, NPC_Sun_01, LVar0, LVar1, LVar2)
            EVT_CALL(SetNpcPos, NPC_Sun_02, LVar0, LVar1, LVar2)
            EVT_WAIT(LVar4)
        EVT_END_LOOP
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Scene_SunReturns) = {
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(DisablePlayerPhysics, TRUE)
    EVT_CALL(SetNpcPos, NPC_Sun_01, 0, 270, 0)
    EVT_CALL(SetNpcPos, NPC_Sun_02, NPC_DISPOSE_LOCATION)
    EVT_WAIT(1)
    EVT_CALL(GetNpcPos, NPC_Sun_01, LVar0, LVar1, LVar2)
    EVT_CALL(UseSettingsFrom, CAM_DEFAULT, LVar0, LVar1, LVar2)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
    EVT_CALL(SetCamDistance, CAM_DEFAULT, 1050)
    EVT_CALL(SetCamPitch, CAM_DEFAULT, EVT_FLOAT(10.0), EVT_FLOAT(4.0))
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(90.0))
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_CALL(WaitForCam, CAM_DEFAULT, EVT_FLOAT(1.0))
    EVT_CALL(SetCamDistance, CAM_DEFAULT, 300)
    EVT_CALL(SetCamPitch, CAM_DEFAULT, EVT_FLOAT(15.0), EVT_FLOAT(-10.0))
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(6.5))
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_CALL(WaitForCam, CAM_DEFAULT, EVT_FLOAT(1.0))
    EVT_CALL(SpeakToPlayer, NPC_Sun_01, ANIM_Sun_TalkJoy, ANIM_Sun_TalkJoy, SPEECH_FLAG_200 | 5, MSG_CH6_00C3)
    EVT_CALL(SetNpcAnimation, NPC_Sun_01, ANIM_Sun_TalkJoy)
    EVT_THREAD
        EVT_CALL(SetCamDistance, CAM_DEFAULT, 1000)
        EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(5.0))
        EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
        EVT_CALL(WaitForCam, CAM_DEFAULT, EVT_FLOAT(1.0))
    EVT_END_THREAD
    EVT_WAIT(15)
    EVT_CALL(SetNpcJumpscale, NPC_Sun_01, EVT_FLOAT(0.0))
    EVT_CALL(GetNpcPos, NPC_Sun_01, LVar0, LVar1, LVar2)
    EVT_ADD(LVar1, 400)
    EVT_CALL(NpcJump0, NPC_Sun_01, LVar0, LVar1, LVar2, 40)
    EVT_CALL(GotoMap, EVT_PTR("flo_00"), flo_00_ENTRY_9)
    EVT_WAIT(70)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcAux_Sun_02) = {
    EVT_CALL(SetNpcRotationPivot, NPC_Sun_02, 48)
    EVT_LOOP(0)
        EVT_CALL(MakeLerp, -30, 30, 20, EASING_SIN_OUT)
        EVT_LOOP(0)
            EVT_CALL(UpdateLerp)
            EVT_CALL(SetNpcRotation, NPC_Sun_02, 0, 0, LVar0)
            EVT_CALL(GetNpcPos, NPC_Sun_01, LVar2, LVar3, LVar4)
            EVT_CALL(SetNpcPos, NPC_Sun_02, LVar2, LVar3, LVar4)
            EVT_WAIT(1)
            EVT_IF_EQ(LVar1, 0)
                EVT_BREAK_LOOP
            EVT_END_IF
        EVT_END_LOOP
        EVT_CALL(MakeLerp, 30, -30, 20, EASING_SIN_OUT)
        EVT_LOOP(0)
            EVT_CALL(UpdateLerp)
            EVT_CALL(SetNpcRotation, NPC_Sun_02, 0, 0, LVar0)
            EVT_CALL(GetNpcPos, NPC_Sun_01, LVar2, LVar3, LVar4)
            EVT_CALL(SetNpcPos, NPC_Sun_02, LVar2, LVar3, LVar4)
            EVT_WAIT(1)
            EVT_IF_EQ(LVar1, 0)
                EVT_BREAK_LOOP
            EVT_END_IF
        EVT_END_LOOP
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Sun_DescendFromSky) = {
    EVT_LOOP(0)
        EVT_WAIT(1)
        EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
        EVT_IF_GT(LVar1, 220)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_THREAD
        EVT_WAIT(15)
        EVT_CALL(PlayerFaceNpc, NPC_Sun_01, FALSE)
    EVT_END_THREAD
    EVT_CALL(SetNpcJumpscale, NPC_Sun_01, EVT_FLOAT(0.0))
    EVT_CALL(GetNpcPos, NPC_Sun_01, LVar0, LVar1, LVar2)
    EVT_SUB(LVar1, 400)
    EVT_CALL(NpcJump0, NPC_Sun_01, LVar0, 275, LVar2, 30)
    EVT_EXEC_GET_TID(N(EVS_Sun_AnimateBobbing), LVar9)
    EVT_LOOP(0)
        EVT_WAIT(1)
        EVT_IF_EQ(AF_FLO_MetTheSun, TRUE)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_WAIT(10)
    EVT_KILL_THREAD(LVar9)
    EVT_CALL(SetNpcFlagBits, NPC_Sun_01, NPC_FLAG_IGNORE_PLAYER_COLLISION, TRUE)
    EVT_CALL(GetNpcPos, NPC_Sun_01, LVar0, LVar1, LVar2)
    EVT_CALL(NpcJump0, NPC_Sun_01, LVar0, 450, LVar2, 30)
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_UNBIND
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInteract_Sun_01) = {
    EVT_SWITCH(GB_StoryProgress)
        EVT_CASE_LT(STORY_CH6_SPOKE_WITH_THE_SUN)
            EVT_CALL(SpeakToPlayer, NPC_Sun_01, ANIM_Sun_TalkSad, ANIM_Sun_Idle, 517, MSG_CH6_009A)
            EVT_CALL(SetPlayerAnimation, ANIM_Mario1_Thinking)
            EVT_WAIT(20)
            EVT_CALL(SetPlayerAnimation, ANIM_MarioW2_SpeakUp)
            EVT_WAIT(20)
            EVT_CALL(SetPlayerAnimation, ANIM_Mario1_Idle)
            EVT_CALL(SpeakToPlayer, NPC_Sun_01, ANIM_Sun_TalkSad, ANIM_Sun_Idle, 517, MSG_CH6_009B)
            EVT_SET(GB_StoryProgress, STORY_CH6_SPOKE_WITH_THE_SUN)
        EVT_CASE_LT(STORY_CH6_DESTROYED_PUFF_PUFF_MACHINE)
            EVT_CALL(SpeakToPlayer, NPC_Sun_01, ANIM_Sun_TalkSad, ANIM_Sun_Idle, 517, MSG_CH6_009C)
        EVT_CASE_LT(STORY_CH6_STAR_SPIRIT_RESCUED)
            EVT_IF_EQ(GF_FLO15_SunThankedPlayer, FALSE)
                EVT_CALL(SpeakToPlayer, NPC_Sun_01, ANIM_Sun_TalkSad, ANIM_Sun_Idle, 517, MSG_CH6_009D)
                EVT_SET(GF_FLO15_SunThankedPlayer, TRUE)
            EVT_ELSE
                EVT_CALL(SpeakToPlayer, NPC_Sun_01, ANIM_Sun_TalkSad, ANIM_Sun_Idle, 517, MSG_CH6_009E)
            EVT_END_IF
        EVT_CASE_DEFAULT
            EVT_CALL(SpeakToPlayer, NPC_Sun_01, ANIM_Sun_TalkSad, ANIM_Sun_Idle, 517, MSG_CH6_009F)
    EVT_END_SWITCH
    EVT_SET(AF_FLO_MetTheSun, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_Sun_01) = {
    EVT_CALL(SetNpcCollisionSize, NPC_Sun_01, 64, 40)
    EVT_CALL(EnableNpcShadow, NPC_Sun_01, FALSE)
    EVT_IF_LT(GB_StoryProgress, STORY_CH6_DESTROYED_PUFF_PUFF_MACHINE)
        EVT_CALL(SetNpcPos, NPC_Sun_01, 0, 270, 0)
        EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(EVS_NpcInteract_Sun_01)))
        EVT_EXEC(N(EVS_Sun_AnimateBobbing))
    EVT_ELSE
        EVT_CALL(SetNpcPos, NPC_Sun_01, 0, 450, 0)
        EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(EVS_NpcInteract_Sun_01)))
        EVT_SET(AF_FLO_MetTheSun, FALSE)
        EVT_EXEC(N(EVS_Sun_DescendFromSky))
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_Sun_02) = {
    EVT_CALL(EnableNpcShadow, NPC_Sun_02, FALSE)
    EVT_CALL(SetNpcAnimation, NPC_Sun_02, ANIM_Sun_FireIdle)
    EVT_CALL(SetNpcPaletteSwapMode, NPC_Sun_01, NPC_PAL_ADJUST_BLEND_PALETTES_VARYING_INTERVALS)
    EVT_CALL(SetNpcPaletteSwapMode, NPC_Sun_02, NPC_PAL_ADJUST_BLEND_PALETTES_VARYING_INTERVALS)
    EVT_CALL(SetNpcPaletteSwapping, NPC_Sun_01, 0, 1, 5, 5, 13, 5, 0, 0)
    EVT_CALL(SetNpcPaletteSwapping, NPC_Sun_02, 0, 1, 5, 5, 13, 5, 0, 0)
    EVT_IF_LT(GB_StoryProgress, STORY_CH6_DESTROYED_PUFF_PUFF_MACHINE)
        EVT_CALL(SetNpcPos, NPC_Sun_02, 0, 270, -5)
    EVT_ELSE
        EVT_CALL(SetNpcPos, NPC_Sun_02, 0, 450, -5)
        EVT_CALL(BindNpcAux, NPC_SELF, EVT_PTR(N(EVS_NpcAux_Sun_02)))
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

NpcData N(NpcData_Sun)[] = {
    {
        .id = NPC_Sun_01,
        .pos = { 0.0f, 250.0f, 0.0f },
        .yaw = 270,
        .init = &N(EVS_NpcInit_Sun_01),
        .settings = &N(NpcSettings_Sun),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_400000,
        .drops = NO_DROPS,
        .animations = SUN_ANIMS,
        .tattle = MSG_NpcTattle_TheSun,
    },
    {
        .id = NPC_Sun_02,
        .pos = { 0.0f, 250.0f, 0.0f },
        .yaw = 270,
        .init = &N(EVS_NpcInit_Sun_02),
        .settings = &N(NpcSettings_Sun),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_8000,
        .drops = NO_DROPS,
        .animations = SUN_ANIMS,
        .tattle = MSG_NpcTattle_TheSun,
    },
};

NpcGroupList N(DefaultNPCs) = {
    NPC_GROUP(N(NpcData_Sun)),
    {}
};
