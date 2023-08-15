#include "kkj_20.h"
#include "sprite/player.h"

#include "world/common/npc/Toad_Stationary.inc.c"

#include "world/common/complete/ToadHouseBlanketAnim.inc.c"
#include "world/common/atomic/ToadHouse.inc.c"
#include "world/common/atomic/ToadHouse.data.inc.c"

#include "world/common/todo/GetPeachDisguise.inc.c"

EvtScript N(EVS_OpenDresserDoors) = {
    EVT_CALL(PlaySoundAtCollider, COLLIDER_o80, SOUND_WOODEN_DOOR_OPEN, 0)
    EVT_CALL(MakeLerp, 0, 80, 14, EASING_QUADRATIC_OUT)
    EVT_LOOP(0)
        EVT_CALL(UpdateLerp)
        EVT_CALL(RotateGroup, MODEL_g16, LVar0, 0, 1, 0)
        EVT_CALL(RotateGroup, MODEL_g15, LVar0, 0, -1, 0)
        EVT_WAIT(1)
        EVT_IF_EQ(LVar1, 0)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_CloseDresserDoors) = {
    EVT_CALL(MakeLerp, 80, 0, 14, EASING_QUADRATIC_OUT)
    EVT_LOOP(0)
        EVT_CALL(UpdateLerp)
        EVT_CALL(RotateGroup, MODEL_g16, LVar0, 0, 1, 0)
        EVT_CALL(RotateGroup, MODEL_g15, LVar0, 0, -1, 0)
        EVT_WAIT(1)
        EVT_IF_EQ(LVar1, 0)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_CALL(PlaySoundAtCollider, COLLIDER_o80, SOUND_WOODEN_DOOR_CLOSE, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_ShakeDresser) = {
    EVT_LOOP(0)
        EVT_CALL(TranslateGroup, MODEL_g9, 1, 0, 0)
        EVT_WAIT(1)
        EVT_CALL(TranslateGroup, MODEL_g9, -1, 0, 0)
        EVT_WAIT(1)
        EVT_CALL(TranslateGroup, MODEL_g9, 0, 0, 0)
        EVT_WAIT(30)
        EVT_CALL(GetSelfVar, 0, LVar0)
        EVT_IF_EQ(LVar0, 0)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Inspect_Dresser_Peach) = {
    EVT_CALL(N(GetPeachDisguise), LVar0)
    EVT_IF_NE(LVar0, PEACH_DISGUISE_NONE)
        EVT_CALL(DisablePlayerInput, TRUE)
        EVT_CALL(SpeakToPlayer, NPC_Toad, ANIM_Toad_Red_Talk, ANIM_Toad_Red_Idle, 0, MSG_Peach_0185)
        EVT_CALL(DisablePlayerInput, FALSE)
        EVT_RETURN
    EVT_END_IF
    EVT_IF_NE(GF_KKJ20_PeachMet_ToadInHiding, FALSE)
        EVT_CALL(DisablePlayerInput, TRUE)
        EVT_CALL(SpeakToPlayer, NPC_Toad, ANIM_Toad_Red_Talk, ANIM_Toad_Red_Idle, 0, MSG_Peach_0185)
        EVT_CALL(DisablePlayerInput, FALSE)
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(SetNpcVar, NPC_Toad, 0, 0)
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(SetCamProperties, CAM_DEFAULT, EVT_FLOAT(4.0), -10, 0, 80, EVT_FLOAT(300.0), EVT_FLOAT(17.0), EVT_FLOAT(-10.0))
    EVT_THREAD
        EVT_CALL(SetPlayerSpeed, EVT_FLOAT(2.0))
        EVT_CALL(PlayerMoveTo, -50, 0, 0)
        EVT_CALL(InterpPlayerYaw, 90, 5)
        EVT_CALL(func_802CF56C, 2)
    EVT_END_THREAD
    EVT_WAIT(10)
    EVT_EXEC(N(EVS_OpenDresserDoors))
    EVT_WAIT(30)
    EVT_CALL(SetNpcJumpscale, NPC_Toad, EVT_FLOAT(1.0))
    EVT_CALL(NpcJump0, NPC_Toad, -10, 0, -40, 15)
    EVT_CALL(SetNpcAnimation, NPC_Toad, ANIM_Toad_Red_Walk)
    EVT_CALL(NpcMoveTo, NPC_Toad, 30, 0, 20)
    EVT_CALL(SetNpcAnimation, NPC_Toad, ANIM_Toad_Red_Idle)
    EVT_CALL(InterpNpcYaw, NPC_Toad, 270, 5)
    EVT_WAIT(10)
    EVT_CALL(SpeakToPlayer, NPC_Toad, ANIM_Toad_Red_Talk, ANIM_Toad_Red_Idle, 0, MSG_Peach_0182)
    EVT_CALL(SetPlayerAnimation, ANIM_Peach2_RaiseArms)
    EVT_WAIT(10)
    EVT_CALL(SetPlayerAnimation, ANIM_Peach2_TalkIdle)
    EVT_CALL(SpeakToPlayer, NPC_PLAYER, ANIM_Peach2_Talk, ANIM_Peach2_TalkIdle, 5, MSG_Peach_0183)
    EVT_CALL(SetPlayerAnimation, ANIM_Peach2_LowerArms)
    EVT_WAIT(10)
    EVT_CALL(SetPlayerAnimation, ANIM_Peach1_Idle)
    EVT_CALL(SpeakToPlayer, NPC_Toad, ANIM_Toad_Red_Talk, ANIM_Toad_Red_Idle, 0, MSG_Peach_0184)
    EVT_CALL(SetNpcAnimation, NPC_Toad, ANIM_Toad_Red_Walk)
    EVT_CALL(SetNpcSpeed, NPC_Toad, EVT_FLOAT(3.0))
    EVT_CALL(NpcMoveTo, NPC_Toad, -10, -60, 0)
    EVT_CALL(SetNpcAnimation, NPC_Toad, ANIM_Toad_Red_Idle)
    EVT_WAIT(10)
    EVT_CALL(NpcJump0, NPC_Toad, -10, 30, -132, 10)
    EVT_EXEC(N(EVS_CloseDresserDoors))
    EVT_WAIT(30)
    EVT_SET(GF_KKJ20_PeachMet_ToadInHiding, TRUE)
    EVT_CALL(ResetCam, CAM_DEFAULT, EVT_FLOAT(4.0))
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_ToadHouse_SetDialogue) = {
    EVT_IF_EQ(GF_KKJ20_Met_ToadInHiding, FALSE)
        EVT_SET(LVar0, MSG_Peach_0187)
        EVT_SET(LVar8, MSG_Peach_0188)
        EVT_SET(GF_KKJ20_Met_ToadInHiding, TRUE)
    EVT_ELSE
        EVT_SET(LVar0, MSG_Peach_0189)
        EVT_SET(LVar8, MSG_Peach_018A)
    EVT_END_IF
    EVT_SET(LVar1, MSG_Peach_018B)
    EVT_SET(LVar2, MSG_Peach_018C)
    EVT_SET(LVar3, MSG_Peach_018D)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_ToadHouse_GetInBed) = {
    EVT_EXEC(N(EVS_PlayRestingSong))
    EVT_CALL(SetPlayerSpeed, EVT_FLOAT(3.0))
    EVT_CALL(PlayerMoveTo, 50, -40, 0)
    EVT_THREAD
        EVT_WAIT(20)
        EVT_CALL(N(ToadHouse_CamSetFOV), 0, 40)
        EVT_CALL(SetCamType, CAM_DEFAULT, 4, FALSE)
        EVT_CALL(SetCamDistance, CAM_DEFAULT, EVT_FLOAT(200.0))
        EVT_CALL(SetCamPitch, CAM_DEFAULT, EVT_FLOAT(70.0), EVT_FLOAT(-30.0))
        EVT_CALL(SetCamPosA, CAM_DEFAULT, EVT_FLOAT(-260.0), EVT_FLOAT(270.0))
        EVT_CALL(SetCamPosB, CAM_DEFAULT, EVT_FLOAT(30.0), EVT_FLOAT(-85.0))
        EVT_CALL(SetCamPosC, CAM_DEFAULT, 0, EVT_FLOAT(-50.0))
        EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(90.0))
        EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_END_THREAD
    EVT_CALL(PlayerMoveTo, 95, -87, 0)
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
        EVT_WAIT(65)
        EVT_CALL(N(ToadHouse_CamSetFOV), 0, 25)
        EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
        EVT_CALL(UseSettingsFrom, CAM_DEFAULT, LVar0, LVar1, LVar2)
        EVT_CALL(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
        EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
        EVT_WAIT(1)
    EVT_END_THREAD
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_ToadHouse_ReturnFromRest) = {
    EVT_CALL(HidePlayerShadow, FALSE)
    EVT_CALL(UpdatePlayerImgFX, ANIM_Mario1_Idle, IMGFX_CLEAR, 0, 0, 0, 0)
    EVT_CALL(SetPlayerPos, 85, 0, -85)
    EVT_CALL(SetPlayerSpeed, EVT_FLOAT(3.0))
    EVT_CALL(PlayerMoveTo, 60, -50, 0)
    EVT_EXEC(N(EVS_PlayBowserSong))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_MeetToadHouseKeeper) = {
    EVT_CALL(N(ToadHouse_InitScreenOverlay), 0, 0, 0)
    EVT_EXEC_WAIT(N(EVS_ToadHouse_SetDialogue))
    EVT_SET(LVar9, LVar1)
    EVT_SET(LVarA, LVar2)
    EVT_SET(LVarB, LVar3)
    EVT_CALL(N(ToadHouse_DoesPlayerNeedSleep))
    EVT_IF_EQ(LVar1, 0)
        EVT_SET(LVar8, LVar0)
    EVT_END_IF
    EVT_CALL(SpeakToPlayer, NPC_Toad, ANIM_Toad_Red_Talk, ANIM_Toad_Red_Idle, 0, LVar8)
    EVT_CALL(ShowChoice, MSG_Choice_0006)
    EVT_WAIT(10)
    EVT_IF_EQ(LVar0, 1)
        EVT_CALL(ContinueSpeech, NPC_Toad, ANIM_Toad_Red_Talk, ANIM_Toad_Red_Idle, 0, LVar9)
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(ContinueSpeech, NPC_Toad, ANIM_Toad_Red_Talk, ANIM_Toad_Red_Idle, 0, LVarA)
    EVT_CALL(SetPlayerJumpscale, 1)
    EVT_CALL(DisablePlayerPhysics, TRUE)
    EVT_CALL(SetNpcFlagBits, NPC_Toad, NPC_FLAG_IGNORE_PLAYER_COLLISION, TRUE)
    EVT_CALL(N(ToadHouse_DisableStatusBar))
    EVT_IF_NE(LVar4, 0)
        EVT_EXEC(N(EVS_ToadHouse_Unk2))
    EVT_END_IF
    EVT_CALL(N(ToadHouse_PutPartnerAway), LVarA)
    EVT_WAIT(20)
    EVT_EXEC_GET_TID(N(EVS_ToadHouse_GetInBed), LVar9)
    EVT_CALL(N(ToadHouse_AwaitScriptComplete), LVar9)
    EVT_THREAD
        EVT_CALL(MakeLerp, 0, 255, 60, EASING_LINEAR)
        EVT_LOOP(0)
            EVT_CALL(UpdateLerp)
            EVT_CALL(N(ToadHouse_UpdateScreenOverlay), 3, LVar0)
            EVT_WAIT(1)
            EVT_IF_EQ(LVar1, 0)
                EVT_BREAK_LOOP
            EVT_END_IF
        EVT_END_LOOP
        EVT_CALL(FullyRestoreHPandFP)
        EVT_CALL(FullyRestoreSP)
        EVT_IF_NE(LVar4, 0)
            EVT_EXEC(N(EVS_ToadHouse_Unk1))
        EVT_END_IF
        EVT_CALL(N(ToadHouse_GetPartnerBackOut), LVarA)
        EVT_WAIT(30)
        EVT_CALL(MakeLerp, 255, 0, 30, EASING_LINEAR)
        EVT_LOOP(0)
            EVT_CALL(UpdateLerp)
            EVT_CALL(N(ToadHouse_UpdateScreenOverlay), 0, LVar0)
            EVT_WAIT(1)
            EVT_IF_EQ(LVar1, 0)
                EVT_BREAK_LOOP
            EVT_END_IF
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_WAIT(90)
    EVT_EXEC_GET_TID(N(EVS_ToadHouse_ReturnFromRest), LVar9)
    EVT_CALL(N(ToadHouse_AwaitScriptComplete), LVar9)
    EVT_CALL(DisablePlayerPhysics, FALSE)
    EVT_CALL(SetNpcFlagBits, NPC_Toad, NPC_FLAG_IGNORE_PLAYER_COLLISION, FALSE)
    EVT_CALL(SpeakToPlayer, NPC_Toad, ANIM_Toad_Red_Talk, ANIM_Toad_Red_Idle, 0, LVarB)
    EVT_CALL(N(ToadHouse_ShowWorldStatusBar))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Inspect_Dresser_Mario) = {
    EVT_CALL(SetNpcVar, NPC_Toad, 0, 0)
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_EXEC(N(EVS_OpenDresserDoors))
    EVT_WAIT(30)
    EVT_CALL(SetNpcJumpscale, NPC_Toad, EVT_FLOAT(1.0))
    EVT_CALL(NpcJump0, NPC_Toad, -10, 0, -40, 15)
    EVT_CALL(PlayerFaceNpc, NPC_Toad, FALSE)
    EVT_CALL(NpcFaceNpc, NPC_PARTNER, NPC_Toad, 0)
    EVT_EXEC(N(EVS_CloseDresserDoors))
    EVT_CALL(SetNpcAnimation, NPC_Toad, ANIM_Toad_Red_Walk)
    EVT_CALL(NpcMoveTo, NPC_Toad, 30, 0, 20)
    EVT_CALL(SetNpcAnimation, NPC_Toad, ANIM_Toad_Red_Idle)
    EVT_CALL(InterpNpcYaw, NPC_Toad, 270, 5)
    EVT_WAIT(10)
    EVT_CALL(UseSettingsFrom, CAM_DEFAULT, -10, 0, 80)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, -10, 0, 80)
    EVT_CALL(SetCamDistance, CAM_DEFAULT, 250)
    EVT_CALL(SetCamPitch, CAM_DEFAULT, EVT_FLOAT(18.0), EVT_FLOAT(-11.0))
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(4.0))
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_CALL(func_802D1270, -50, 0, EVT_FLOAT(2.5))
    EVT_CALL(InterpPlayerYaw, 90, 5)
    EVT_CALL(func_802CF56C, 2)
    EVT_WAIT(10)
    EVT_CALL(SpeakToPlayer, NPC_Toad, ANIM_Toad_Red_Talk, ANIM_Toad_Red_Idle, 0, MSG_Peach_0186)
    EVT_CALL(GetNpcPos, NPC_Toad, LVar0, LVar1, LVar2)
    EVT_CALL(NpcJump0, NPC_Toad, LVar0, LVar1, LVar2, 10)
    EVT_EXEC_WAIT(N(EVS_MeetToadHouseKeeper))
    EVT_CALL(ResetCam, CAM_DEFAULT, EVT_FLOAT(90.0))
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_UNBIND
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcIdle_Toad) = {
    EVT_CALL(WaitForPlayerInputEnabled)
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(DisablePartnerAI, 1)
    EVT_CALL(SetNpcJumpscale, NPC_PARTNER, EVT_FLOAT(0.5))
    EVT_CALL(NpcJump0, NPC_PARTNER, -86, 40, -25, 15)
    EVT_WAIT(10)
    EVT_CALL(SpeakToPlayer, NPC_PARTNER, ANIM_Twink_Talk, ANIM_Twink_Idle, 5, MSG_Peach_0181)
    EVT_CALL(NpcFlyTo, NPC_PARTNER, -165, 55, -25, 20, -5, EASING_LINEAR)
    EVT_CALL(InterpNpcYaw, NPC_PARTNER, 90, 0)
    EVT_CALL(EnablePartnerAI)
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInteract_Toad) = {
    EVT_EXEC_WAIT(N(EVS_NpcInteract_ToadHouseKeeper))
    EVT_CALL(ResetCam, CAM_DEFAULT, EVT_FLOAT(90.0))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_Toad) = {
    EVT_SWITCH(GB_StoryProgress)
        EVT_CASE_OR_EQ(STORY_CH4_BEGAN_PEACH_MISSION)
        EVT_CASE_OR_EQ(STORY_CH5_BEGAN_PEACH_MISSION)
        EVT_CASE_OR_EQ(STORY_CH6_BEGAN_PEACH_MISSION)
            EVT_CALL(SetNpcPos, NPC_SELF, -10, 30, -132)
            EVT_CALL(SetNpcYaw, NPC_SELF, 270)
            EVT_IF_EQ(GF_KKJ20_PeachMet_ToadInHiding, FALSE)
                EVT_CALL(SetSelfVar, 0, 1)
                EVT_EXEC(N(EVS_ShakeDresser))
                EVT_CALL(BindNpcIdle, NPC_SELF, EVT_PTR(N(EVS_NpcIdle_Toad)))
            EVT_END_IF
            EVT_BIND_TRIGGER(EVT_PTR(N(EVS_Inspect_Dresser_Peach)), TRIGGER_WALL_PRESS_A, COLLIDER_o80, 1, 0)
        EVT_END_CASE_GROUP
        EVT_CASE_DEFAULT
            EVT_IF_EQ(GF_KKJ20_Met_ToadInHiding, FALSE)
                EVT_CALL(SetNpcPos, NPC_SELF, -10, 30, -132)
                EVT_CALL(SetSelfVar, 0, 1)
                EVT_EXEC(N(EVS_ShakeDresser))
                EVT_BIND_TRIGGER(EVT_PTR(N(EVS_Inspect_Dresser_Mario)), TRIGGER_WALL_PRESS_A, COLLIDER_o80, 1, 0)
            EVT_ELSE
                EVT_CALL(SetNpcPos, NPC_SELF, 30, 0, 0)
            EVT_END_IF
            EVT_CALL(SetNpcYaw, NPC_SELF, 270)
            EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(EVS_NpcInteract_Toad)))
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

NpcData N(NpcData_Toad) = {
    .id = NPC_Toad,
    .pos = { NPC_DISPOSE_LOCATION },
    .yaw = 0,
    .init = &N(EVS_NpcInit_Toad),
    .settings = &N(NpcSettings_Toad_Stationary),
    .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_4 | ENEMY_FLAG_ENABLE_HIT_SCRIPT | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING,
    .drops = NO_DROPS,
    .animations = TOAD_RED_ANIMS,
    .tattle = MSG_NpcTattle_KKJ_ToadHouseToad,
};

NpcGroupList N(DefaultNPCs) = {
    NPC_GROUP(N(NpcData_Toad)),
    {}
};
