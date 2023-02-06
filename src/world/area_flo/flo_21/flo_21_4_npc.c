#include "flo_21.h"
#include "effects.h"

#include "world/common/enemy/complete/HuffNPuff.h"
#include "world/common/enemy/complete/TuffPuff.h"

#include "world/common/todo/UnsetCamera0MoveFlag1.inc.c"

NpcSettings N(NpcSettings_TuffPuff) = {
    .height = 24,
    .radius = 28,
    .level = 16,
    .onHit = &EnemyNpcHit,
    .onDefeat = &EnemyNpcDefeat,
};

NpcSettings N(NpcSettings_HuffNPuff) = {
    .height = 24,
    .radius = 24,
    .level = 99,
};

#include "world/common/npc/StarSpirit.inc.c"

Vec3f N(Path_JumpOut)[] = {
    {  600.0,   104.0,    0.0 },
    {  575.0,   204.0,    0.0 },
    {  550.0,   104.0,    0.0 },
};

EvtScript N(EVS_PlayRumbleSounds) = {
    EVT_LABEL(0)
        EVT_CALL(PlaySound, SOUND_20B6)
        EVT_CALL(ShakeCam, CAM_DEFAULT, 0, 15, EVT_FLOAT(1.0))
        EVT_WAIT(15)
        EVT_GOTO(0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_HuffNPuff_JumpOut) = {
    EVT_CALL(PlaySoundAtNpc, NPC_HuffNPuff_01, SOUND_3C0, SOUND_SPACE_MODE_0)
    EVT_PLAY_EFFECT(EFFECT_SHOCKWAVE, 3, 650, 104, 0)
    EVT_WAIT(15)
    EVT_CALL(SetNpcJumpscale, NPC_HuffNPuff_02, EVT_FLOAT(0.0))
    EVT_CALL(NpcJump0, NPC_HuffNPuff_02, 650, 50, 0, 5)
    EVT_CALL(SetNpcPos, NPC_HuffNPuff_01, 650, 50, 5)
    EVT_CALL(SetNpcPos, NPC_HuffNPuff_02, 650, 50, 0)
    EVT_CALL(SetNpcPos, NPC_HuffNPuff_03, 650, 50, 0)
    EVT_CALL(SetNpcJumpscale, NPC_HuffNPuff_01, EVT_FLOAT(0.0))
    EVT_CALL(SetNpcJumpscale, NPC_HuffNPuff_02, EVT_FLOAT(0.0))
    EVT_CALL(SetNpcJumpscale, NPC_HuffNPuff_03, EVT_FLOAT(0.0))
    EVT_THREAD
        EVT_CALL(NpcJump0, NPC_HuffNPuff_01, 650, 150, 5, 10)
    EVT_END_THREAD
    EVT_THREAD
        EVT_CALL(NpcJump0, NPC_HuffNPuff_02, 650, 150, 0, 10)
    EVT_END_THREAD
    EVT_THREAD
        EVT_CALL(NpcJump0, NPC_HuffNPuff_03, 650, 150, 0, 10)
    EVT_END_THREAD
    EVT_THREAD
        EVT_CALL(SetPlayerAnimation, ANIM_Mario_80017)
        EVT_CALL(LoadPath, 30, EVT_PTR(N(Path_JumpOut)), ARRAY_COUNT(N(Path_JumpOut)), EASING_LINEAR)
        EVT_LABEL(0)
        EVT_CALL(GetNextPathPos)
        EVT_CALL(SetPlayerPos, LVar1, LVar2, LVar3)
        EVT_WAIT(1)
        EVT_IF_EQ(LVar0, 1)
            EVT_GOTO(0)
        EVT_END_IF
    EVT_END_THREAD
    EVT_CALL(SetPlayerAnimation, ANIM_Mario_1002B)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Scene_HuffNPuffAmbush) = {
    EVT_IF_GE(GB_StoryProgress, STORY_CH6_DEFEATED_HUFF_N_PUFF)
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(AwaitPlayerApproach, 650, 0, 30)
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(SetMusicTrack, 0, SONG_HUFF_N_PUFF_THEME, 0, 8)
    EVT_EXEC_GET_TID(N(EVS_PlayRumbleSounds), LVar9)
    EVT_CALL(GetPartnerInUse, LVar0)
    EVT_IF_NE(LVar0, PARTNER_NONE)
        EVT_CALL(InterruptUsePartner)
        EVT_WAIT(20)
    EVT_END_IF
    EVT_CALL(DisablePlayerPhysics, TRUE)
    EVT_CALL(InterpPlayerYaw, 90, 1)
    EVT_WAIT(5)
    EVT_CALL(SetPlayerAnimation, ANIM_Mario_1002B)
    EVT_CALL(SetNpcFlagBits, NPC_HuffNPuff_02, NPC_FLAG_100, TRUE)
    EVT_CALL(GetPlayerPos, LVar2, LVar3, LVar4)
    EVT_CALL(UseSettingsFrom, CAM_DEFAULT, LVar2, LVar3, LVar4)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, LVar2, LVar3, LVar4)
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(90.0))
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_CALL(MakeLerp, LVar2, 600, 20, EASING_LINEAR)
    EVT_SET(LVar2, LVar3)
    EVT_SET(LVar5, LVar3)
    EVT_ADD(LVar5, 15)
    EVT_LOOP(0)
        EVT_CALL(UpdateLerp)
        EVT_ADD(LVar3, 3)
        EVT_CALL(SetPlayerPos, LVar0, LVar3, LVar4)
        EVT_IF_GT(LVar3, LVar5)
            EVT_SET(LVar3, LVar2)
        EVT_END_IF
        EVT_WAIT(1)
        EVT_IF_EQ(LVar1, 0)
            EVT_BREAK_LOOP
        EVT_END_IF
        EVT_CALL(SetPanTarget, CAM_DEFAULT, LVar0, LVar2, LVar4)
    EVT_END_LOOP
    EVT_CALL(func_802D2C14, 1)
    EVT_CALL(SetPlayerPos, LVar0, LVar2, LVar4)
    EVT_CALL(SetNpcFlagBits, NPC_HuffNPuff_02, NPC_FLAG_100, FALSE)
    EVT_CALL(DisablePlayerPhysics, FALSE)
    EVT_WAIT(10)
    EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
    EVT_CALL(UseSettingsFrom, CAM_DEFAULT, LVar0, LVar1, LVar2)
    EVT_ADD(LVar0, 25)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
    EVT_CALL(SetCamDistance, CAM_DEFAULT, EVT_FLOAT(300.0))
    EVT_CALL(SetCamPitch, CAM_DEFAULT, EVT_FLOAT(17.0), EVT_FLOAT(-9.0))
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(4.0))
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_CALL(WaitForCam, CAM_DEFAULT, EVT_FLOAT(1.0))
    EVT_WAIT(10)
    EVT_CALL(ShowMessageAtWorldPos, MSG_CH6_00CA, 630, 120, 0)
    EVT_CALL(SetCamDistance, CAM_DEFAULT, EVT_FLOAT(600.0))
    EVT_CALL(SetCamPitch, CAM_DEFAULT, EVT_FLOAT(30.0), EVT_FLOAT(-9.0))
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(90.0))
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_WAIT(10)
    EVT_CALL(ShowMessageAtWorldPos, MSG_CH6_00CB, 630, 120, 0)
    EVT_CALL(SetCamDistance, CAM_DEFAULT, EVT_FLOAT(300.0))
    EVT_CALL(SetCamPitch, CAM_DEFAULT, EVT_FLOAT(17.0), EVT_FLOAT(-9.0))
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_CALL(func_802D2C14, 0)
    EVT_WAIT(10)
    EVT_CALL(GetCurrentPartnerID, LVar0)
    EVT_IF_NE(LVar0, PARTNER_LAKILESTER)
        EVT_CALL(ShowMessageAtWorldPos, MSG_CH6_00CC, 630, 120, 0)
    EVT_ELSE
        EVT_CALL(ShowMessageAtWorldPos, MSG_CH6_00CD, 630, 120, 0)
    EVT_END_IF
    EVT_CHILD_THREAD
        EVT_WAIT(15)
        EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
        EVT_ADD(LVar0, 25)
        EVT_CALL(UseSettingsFrom, CAM_DEFAULT, LVar0, LVar1, LVar2)
        EVT_CALL(SetCamPitch, CAM_DEFAULT, EVT_FLOAT(17.0), EVT_FLOAT(-6.0))
        EVT_SET(LVar3, 40)
        EVT_LOOP(5)
            EVT_CALL(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
            EVT_CALL(SetCamDistance, CAM_DEFAULT, EVT_FLOAT(400.0))
            EVT_CALL(SetCamSpeed, CAM_DEFAULT, LVar3)
            EVT_CALL(WaitForCam, CAM_DEFAULT, EVT_FLOAT(1.0))
            EVT_SUB(LVar3, 10)
            EVT_CALL(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
            EVT_CALL(SetCamDistance, CAM_DEFAULT, EVT_FLOAT(600.0))
            EVT_CALL(SetCamSpeed, CAM_DEFAULT, LVar3)
            EVT_CALL(WaitForCam, CAM_DEFAULT, EVT_FLOAT(1.0))
            EVT_ADD(LVar3, 7)
        EVT_END_LOOP
    EVT_END_CHILD_THREAD
    EVT_EXEC_WAIT(N(EVS_HuffNPuff_JumpOut))
    EVT_KILL_THREAD(LVar9)
    EVT_WAIT(30)
    EVT_CALL(SetNpcVar, NPC_HuffNPuff_01, 0, 1)
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_WAIT(15)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_HuffNPuff_AnimateBodyScale) = {
    EVT_SETF(LVar0, EVT_FLOAT(0.95))
    EVT_SETF(LVar1, EVT_FLOAT(1.1))
    EVT_LABEL(0)
        EVT_SWITCH(MV_BossFightState)
            EVT_CASE_EQ(0)
                EVT_SET(LVar3, 10)
                EVT_SET(LVar2, 2)
            EVT_CASE_EQ(1)
                EVT_SET(LVar3, 5)
                EVT_SET(LVar2, 1)
            EVT_CASE_DEFAULT
                EVT_RETURN
        EVT_END_SWITCH
        EVT_SET(LVar4, LVar3)
        EVT_LOOP(LVar4)
            EVT_CALL(SetNpcScale, NPC_HuffNPuff_01, LVar0, LVar1, 1)
            EVT_CALL(SetNpcScale, NPC_HuffNPuff_02, LVar0, LVar1, 1)
            EVT_CALL(SetNpcScale, NPC_HuffNPuff_03, LVar0, LVar1, 1)
            EVT_ADDF(LVar0, EVT_FLOAT(0.015))
            EVT_SUBF(LVar1, EVT_FLOAT(0.01))
            EVT_WAIT(LVar2)
        EVT_END_LOOP
        EVT_SET(LVar4, LVar3)
        EVT_LOOP(LVar4)
            EVT_CALL(SetNpcScale, NPC_HuffNPuff_01, LVar0, LVar1, 1)
            EVT_CALL(SetNpcScale, NPC_HuffNPuff_02, LVar0, LVar1, 1)
            EVT_CALL(SetNpcScale, NPC_HuffNPuff_03, LVar0, LVar1, 1)
            EVT_SUBF(LVar0, EVT_FLOAT(0.015))
            EVT_ADDF(LVar1, EVT_FLOAT(0.01))
            EVT_WAIT(LVar2)
        EVT_END_LOOP
        EVT_GOTO(0)
    EVT_RETURN
    EVT_END
};

// start and end positions for each of the Tuff Puffs when HuffNPuff explodes
Vec2i N(BlowUpPositions)[] = {
    { 635, 165}, { 450, 120 },
    { 640, 170}, { 520, 270 },
    { 650, 175}, { 650, 275 },
    { 660, 170}, { 730, 275 },
    { 665, 165}, { 850, 120 },
    { 630, 150}, { 450, 155 },
    { 637, 150}, { 600, 275 },
    { 650, 150}, { 850, 155 },
    { 663, 150}, { 750, 270 },
    { 670, 150}, { 850, 195 },
    { 635, 135}, { 450, 195 },
    { 640, 130}, { 450, 235 },
    { 650, 125}, { 450, 270 },
    { 660, 130}, { 850, 270 },
    { 665, 135}, { 850, 235 },
};

Vec3i N(BeginAnimScaleX)[] = {
    { 10, 14, 7 },
    { 14,  5, 6 },
    {  5, 12, 6 },
    { 12,  5, 5 },
    {  5, 10, 5 },
    { 10,  5, 4 },
};

Vec2i N(LoopAnimScaleX)[] = {
    {  8, 10 },
    { 10,  8 },
};

Vec3i N(BeginAnimScaleY)[] = {
    { 10,  5, 7 },
    {  5, 14, 6 },
    { 14,  5, 6 },
    {  5, 12, 5 },
    { 12,  5, 5 },
    {  5, 10, 4 },
};

Vec2i N(LoopAnimScaleY)[] = {
    { 10,  6 },
    {  6, 10 },
};

EvtScript N(EVS_HuffNPuff_Defeat_Flashing) = {
    EVT_SETF(LVar0, 10)
    EVT_SETF(LVar1, 1)
    EVT_CHILD_THREAD
        EVT_LOOP(8)
            EVT_CALL(SetNpcFlagBits, NPC_HuffNPuff_01, NPC_FLAG_2, FALSE)
            EVT_CALL(SetNpcFlagBits, NPC_HuffNPuff_02, NPC_FLAG_2, FALSE)
            EVT_CALL(SetNpcFlagBits, NPC_HuffNPuff_03, NPC_FLAG_2, FALSE)
            EVT_WAIT(LVar0)
            EVT_CALL(SetNpcFlagBits, NPC_HuffNPuff_01, NPC_FLAG_2, TRUE)
            EVT_CALL(SetNpcFlagBits, NPC_HuffNPuff_02, NPC_FLAG_2, TRUE)
            EVT_CALL(SetNpcFlagBits, NPC_HuffNPuff_03, NPC_FLAG_2, TRUE)
            EVT_WAIT(LVar1)
            EVT_SUBF(LVar0, 0)
            EVT_ADDF(LVar1, 0)
        EVT_END_LOOP
        EVT_LOOP(0)
            EVT_CALL(SetNpcFlagBits, NPC_HuffNPuff_01, NPC_FLAG_2, FALSE)
            EVT_CALL(SetNpcFlagBits, NPC_HuffNPuff_02, NPC_FLAG_2, FALSE)
            EVT_CALL(SetNpcFlagBits, NPC_HuffNPuff_03, NPC_FLAG_2, FALSE)
            EVT_WAIT(LVar0)
            EVT_CALL(SetNpcFlagBits, NPC_HuffNPuff_01, NPC_FLAG_2, TRUE)
            EVT_CALL(SetNpcFlagBits, NPC_HuffNPuff_02, NPC_FLAG_2, TRUE)
            EVT_CALL(SetNpcFlagBits, NPC_HuffNPuff_03, NPC_FLAG_2, TRUE)
            EVT_WAIT(LVar1)
        EVT_END_LOOP
    EVT_END_CHILD_THREAD
    EVT_CHILD_THREAD
        EVT_LOOP(0)
            EVT_CALL(MakeLerp, 0, 255, 10, EASING_QUADRATIC_OUT)
            EVT_LOOP(0)
                EVT_CALL(UpdateLerp)
                EVT_CALL(func_802CFD30, NPC_HuffNPuff_01, FOLD_TYPE_9, LVar0, LVar0, LVar0, 0)
                EVT_CALL(func_802CFD30, NPC_HuffNPuff_02, FOLD_TYPE_9, LVar0, LVar0, LVar0, 0)
                EVT_CALL(func_802CFD30, NPC_HuffNPuff_03, FOLD_TYPE_9, LVar0, LVar0, LVar0, 0)
                EVT_WAIT(1)
                EVT_IF_EQ(LVar1, 0)
                    EVT_BREAK_LOOP
                EVT_END_IF
            EVT_END_LOOP
        EVT_END_LOOP
    EVT_END_CHILD_THREAD
    EVT_WAIT(100)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_HuffNPuff_Defeat_AnimateScale) = {
    EVT_SETF(MV_HuffScaleX, EVT_FLOAT(1.0))
    EVT_SETF(MV_HuffScaleY, EVT_FLOAT(1.0))
    EVT_CHILD_THREAD
        EVT_USE_BUF(EVT_PTR(N(BeginAnimScaleX)))
        EVT_LOOP(ARRAY_COUNT(N(BeginAnimScaleX)))
            EVT_CALL(PlaySoundAtNpc, NPC_HuffNPuff_01, SOUND_20B6, SOUND_SPACE_MODE_0)
            EVT_BUF_READ3(LVar6, LVar7, LVar8)
            EVT_CALL(MakeLerp, LVar6, LVar7, LVar8, EASING_SIN_OUT)
            EVT_LOOP(0)
                EVT_CALL(UpdateLerp)
                EVT_DIVF(LVar0, 10)
                EVT_SETF(MV_HuffScaleX, LVar0)
                EVT_WAIT(1)
                EVT_IF_EQ(LVar1, 0)
                    EVT_BREAK_LOOP
                EVT_END_IF
            EVT_END_LOOP
            EVT_WAIT(1)
        EVT_END_LOOP
        EVT_LOOP(0)
            EVT_USE_BUF(EVT_PTR(N(LoopAnimScaleX)))
            EVT_LOOP(ARRAY_COUNT(N(LoopAnimScaleX)))
                EVT_CALL(PlaySoundAtNpc, NPC_HuffNPuff_01, SOUND_20B6, SOUND_SPACE_MODE_0)
                EVT_BUF_READ2(LVar6, LVar7)
                EVT_CALL(MakeLerp, LVar6, LVar7, 4, EASING_SIN_OUT)
                EVT_LOOP(0)
                    EVT_CALL(UpdateLerp)
                    EVT_DIVF(LVar0, 10)
                    EVT_SETF(MV_HuffScaleX, LVar0)
                    EVT_WAIT(1)
                    EVT_IF_EQ(LVar1, 0)
                        EVT_BREAK_LOOP
                    EVT_END_IF
                EVT_END_LOOP
            EVT_END_LOOP
        EVT_END_LOOP
    EVT_END_CHILD_THREAD
    EVT_CHILD_THREAD
        EVT_USE_BUF(EVT_PTR(N(BeginAnimScaleY)))
        EVT_LOOP(ARRAY_COUNT(N(BeginAnimScaleY)))
            EVT_BUF_READ3(LVar6, LVar7, LVar8)
            EVT_CALL(MakeLerp, LVar6, LVar7, LVar8, EASING_SIN_OUT)
            EVT_LOOP(0)
                EVT_CALL(UpdateLerp)
                EVT_DIVF(LVar0, 10)
                EVT_SETF(MV_HuffScaleY, LVar0)
                EVT_WAIT(1)
                EVT_IF_EQ(LVar1, 0)
                    EVT_BREAK_LOOP
                EVT_END_IF
            EVT_END_LOOP
            EVT_WAIT(1)
        EVT_END_LOOP
        EVT_LOOP(0)
            EVT_USE_BUF(EVT_PTR(N(LoopAnimScaleY)))
            EVT_LOOP(ARRAY_COUNT(N(LoopAnimScaleY)))
                EVT_BUF_READ2(LVar6, LVar7)
                EVT_CALL(MakeLerp, LVar6, LVar7, 4, EASING_SIN_OUT)
                EVT_LOOP(0)
                    EVT_CALL(UpdateLerp)
                    EVT_DIVF(LVar0, 10)
                    EVT_SETF(MV_HuffScaleY, LVar0)
                    EVT_WAIT(1)
                    EVT_IF_EQ(LVar1, 0)
                        EVT_BREAK_LOOP
                    EVT_END_IF
                EVT_END_LOOP
            EVT_END_LOOP
        EVT_END_LOOP
    EVT_END_CHILD_THREAD
    EVT_LOOP(100)
        EVT_CALL(SetNpcScale, NPC_HuffNPuff_01, MV_HuffScaleX, MV_HuffScaleY, 1)
        EVT_CALL(SetNpcScale, NPC_HuffNPuff_02, MV_HuffScaleX, MV_HuffScaleY, 1)
        EVT_CALL(SetNpcScale, NPC_HuffNPuff_03, MV_HuffScaleX, MV_HuffScaleY, 1)
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_HuffNPuff_Defeat_BlowUp) = {
    EVT_CHILD_THREAD
        EVT_SET(LVar1, 0)
        EVT_LOOP(0)
            EVT_SET(LVar0, 3)
            EVT_LOOP(15)
                EVT_CALL(SetNpcRotation, LVar0, 0, LVar1, 0)
                EVT_ADD(LVar0, 1)
            EVT_END_LOOP
            EVT_ADD(LVar1, 60)
            EVT_IF_GT(LVar1, 360)
                EVT_ADD(LVar1, -360)
            EVT_END_IF
            EVT_WAIT(1)
        EVT_END_LOOP
    EVT_END_CHILD_THREAD
    EVT_USE_BUF(EVT_PTR(N(BlowUpPositions)))
    EVT_SET(LVar8, 3)
    // all except the last one
    EVT_LOOP((ARRAY_COUNT(N(BlowUpPositions))/ 2) - 1)
        EVT_BUF_READ4(LVar1, LVar2, LVar3, LVar4)
        EVT_THREAD
            EVT_CALL(RandInt, 5, LVar5)
            EVT_WAIT(LVar5)
            EVT_CALL(SetNpcPos, LVar8, LVar1, LVar2, -30)
            EVT_CALL(RandInt, 2, LVar5)
            EVT_ADD(LVar5, 8)
            EVT_CALL(PlaySoundAtNpc, LVar8, SOUND_3D5, SOUND_SPACE_MODE_0)
            EVT_CALL(NpcJump0, LVar8, LVar3, LVar4, -15, LVar5)
            EVT_CALL(SetNpcPos, LVar8, NPC_DISPOSE_LOCATION)
        EVT_END_THREAD
        EVT_ADD(LVar8, 1)
    EVT_END_LOOP
    EVT_CALL(SetNpcPos, NPC_HuffNPuff_01, NPC_DISPOSE_LOCATION)
    EVT_CALL(SetNpcPos, NPC_HuffNPuff_02, NPC_DISPOSE_LOCATION)
    EVT_CALL(SetNpcPos, NPC_HuffNPuff_03, NPC_DISPOSE_LOCATION)
    // the last one
    EVT_BUF_READ4(LVar1, LVar2, LVar3, LVar4)
    EVT_WAIT(5)
    EVT_CALL(SetNpcPos, LVar8, LVar1, LVar2, -30)
    EVT_CALL(PlaySoundAtNpc, LVar8, SOUND_3D6, SOUND_SPACE_MODE_0)
    EVT_CALL(NpcJump0, LVar8, LVar3, LVar4, -15, 10)
    EVT_CALL(SetNpcPos, LVar8, NPC_DISPOSE_LOCATION)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Scene_BossDefeated) = {
    EVT_CALL(SetNpcAnimation, NPC_HuffNPuff_02, ANIM_HuffNPuff_Anim04)
    EVT_CALL(SetNpcAnimation, NPC_HuffNPuff_01, ANIM_HuffNPuff_Anim05)
    EVT_CALL(SetNpcAnimation, NPC_HuffNPuff_03, ANIM_HuffNPuff_Anim06)
    EVT_CALL(GetNpcPos, NPC_HuffNPuff_01, LVar0, LVar1, LVar2)
    EVT_CALL(UseSettingsFrom, CAM_DEFAULT, LVar0, LVar1, LVar2)
    EVT_ADD(LVar0, -15)
    EVT_ADD(LVar2, 40)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
    EVT_CALL(SetCamDistance, CAM_DEFAULT, EVT_FLOAT(350.0))
    EVT_CALL(SetCamPitch, CAM_DEFAULT, EVT_FLOAT(17.0), EVT_FLOAT(-5.5))
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(90.0))
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_CALL(WaitForCam, CAM_DEFAULT, EVT_FLOAT(1.0))
    EVT_CALL(SpeakToPlayer, NPC_HuffNPuff_01, ANIM_HuffNPuff_Anim30, ANIM_HuffNPuff_Anim05, 256, -30, 30, MSG_CH6_00CE)
    EVT_CALL(FadeOutMusic, 0, 1500)
    EVT_SET(MV_BossFightState, 2)
    EVT_CALL(GetNpcPos, NPC_HuffNPuff_01, LVar0, LVar1, LVar2)
    EVT_THREAD
        EVT_SET(LVar3, LVar0)
        EVT_SET(LVar4, LVar0)
        EVT_ADD(LVar3, -35)
        EVT_ADD(LVar4, 35)
        EVT_LOOP(3)
            EVT_PLAY_EFFECT(EFFECT_EXPLOSION, 0, LVar0, LVar1, LVar2)
            EVT_WAIT(12)
            EVT_PLAY_EFFECT(EFFECT_EXPLOSION, 0, LVar3, LVar1, LVar2)
            EVT_ADD(LVar3, 7)
            EVT_WAIT(8)
            EVT_PLAY_EFFECT(EFFECT_EXPLOSION, 0, LVar4, LVar1, LVar2)
            EVT_ADD(LVar4, -7)
            EVT_WAIT(14)
        EVT_END_LOOP
        EVT_PLAY_EFFECT(EFFECT_EXPLOSION, 2, LVar0, LVar1, LVar2)
        EVT_CALL(ShakeCam, CAM_DEFAULT, 0, 30, EVT_FLOAT(1.5))
    EVT_END_THREAD
    EVT_THREAD
        EVT_WAIT(30)
        EVT_LOOP(10)
            EVT_PLAY_EFFECT(EFFECT_SHIMMER_WAVE, 0, LVar0, LVar1, LVar2, 40, 65, 12, 15)
            EVT_WAIT(7)
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_EXEC(N(EVS_HuffNPuff_Defeat_Flashing))
    EVT_EXEC_WAIT(N(EVS_HuffNPuff_Defeat_AnimateScale))
    EVT_EXEC_WAIT(N(EVS_HuffNPuff_Defeat_BlowUp))
    EVT_WAIT(10)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcIdle_HuffNPuff_01) = {
    EVT_LABEL(0)
        EVT_CALL(SetSelfVar, 0, 0)
        EVT_LOOP(0)
            EVT_CALL(GetSelfVar, 0, LVar0)
            EVT_IF_NE(LVar0, 0)
                EVT_BREAK_LOOP
            EVT_END_IF
            EVT_WAIT(1)
        EVT_END_LOOP
        EVT_SET(MV_BossFightState, 1)
        EVT_CALL(StartBossBattle, SONG_HUFF_N_PUFF_BATTLE)
        EVT_GOTO(0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcDefeat_HuffNPuff_Main) = {
    EVT_CALL(GetBattleOutcome, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(OUTCOME_PLAYER_WON)
            EVT_CALL(SetEncounterStatusFlags, ENCOUNTER_STATUS_FLAG_1, TRUE)
            EVT_CALL(SetNpcYaw, NPC_PARTNER, 90)
            EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar3)
            EVT_CALL(GetNpcPos, NPC_PARTNER, LVar0, LVar1, LVar2)
            EVT_ADD(LVar3, -20)
            EVT_CALL(SetNpcPos, NPC_PARTNER, LVar0, LVar1, LVar3)
            EVT_EXEC_WAIT(N(EVS_Scene_BossDefeated))
            EVT_WAIT(50)
            EVT_SET(MV_BossDefeated, TRUE)
            EVT_EXEC(N(EVS_TrySpawningStarCard))
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcDefeat_HuffNPuff_Aux) = {
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_HuffNPuff_Face) = {
    EVT_IF_LT(GB_StoryProgress, STORY_CH6_DEFEATED_HUFF_N_PUFF)
        EVT_CALL(SetEnemyFlagBits, NPC_SELF, ENEMY_FLAG_400000, 1)
        EVT_CALL(BindNpcIdle, NPC_SELF, EVT_PTR(N(EVS_NpcIdle_HuffNPuff_01)))
        EVT_CALL(BindNpcDefeat, NPC_SELF, EVT_PTR(N(EVS_NpcDefeat_HuffNPuff_Main)))
        EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_HuffNPuff_Anim02)
    EVT_ELSE
        EVT_CALL(SetNpcPos, NPC_SELF, NPC_DISPOSE_LOCATION)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_HuffNPuff_Body) = {
    EVT_IF_LT(GB_StoryProgress, STORY_CH6_DEFEATED_HUFF_N_PUFF)
        EVT_CALL(SetEnemyFlagBits, NPC_SELF, ENEMY_FLAG_400000, 1)
        EVT_CALL(BindNpcDefeat, NPC_SELF, EVT_PTR(N(EVS_NpcDefeat_HuffNPuff_Aux)))
        EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_HuffNPuff_Anim01)
        EVT_EXEC(N(EVS_HuffNPuff_AnimateBodyScale))
    EVT_ELSE
        EVT_CALL(SetNpcPos, NPC_SELF, NPC_DISPOSE_LOCATION)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_HuffNPuff_Arms) = {
    EVT_IF_LT(GB_StoryProgress, STORY_CH6_DEFEATED_HUFF_N_PUFF)
        EVT_CALL(SetEnemyFlagBits, NPC_SELF, ENEMY_FLAG_400000, 1)
        EVT_CALL(BindNpcDefeat, NPC_SELF, EVT_PTR(N(EVS_NpcDefeat_HuffNPuff_Aux)))
        EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_HuffNPuff_Anim19)
    EVT_ELSE
        EVT_CALL(SetNpcPos, NPC_SELF, NPC_DISPOSE_LOCATION)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_TuffPuff) = {
    EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_TuffPuff_Dizzy)
    EVT_CALL(SetNpcJumpscale, NPC_SELF, 0)
    EVT_RETURN
    EVT_END
};

s32 N(ExtraAnims_HuffNPuff)[] = {
    ANIM_HuffNPuff_Anim00,
    ANIM_HuffNPuff_Anim01,
    ANIM_HuffNPuff_Anim02,
    ANIM_HuffNPuff_Anim04,
    ANIM_HuffNPuff_Anim05,
    ANIM_HuffNPuff_Anim31,
    ANIM_HuffNPuff_Anim19,
    ANIM_HuffNPuff_Anim2D,
    ANIM_LIST_END
};

StaticNpc N(NpcData_HuffNPuff)[] = {
    {
        .id = NPC_HuffNPuff_01,
        .settings = &N(NpcSettings_HuffNPuff),
        .pos = { 650.0f, NPC_DISPOSE_POS_Y, 0.0f },
        .yaw = 270,
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_100 | ENEMY_FLAG_400 | ENEMY_FLAG_800 | ENEMY_FLAG_40000,
        .init = &N(EVS_NpcInit_HuffNPuff_Face),
        .drops = HUFF_N_PUFF_NO_DROPS,
        .animations = HUFF_N_PUFF_ANIMS,
        .extraAnimations = N(ExtraAnims_HuffNPuff),
    },
    {
        .id = NPC_HuffNPuff_02,
        .settings = &N(NpcSettings_HuffNPuff),
        .pos = { 650.0f, 100.0f, 0.0f },
        .yaw = 270,
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_100 | ENEMY_FLAG_200 | ENEMY_FLAG_400 | ENEMY_FLAG_800 | ENEMY_FLAG_40000,
        .init = &N(EVS_NpcInit_HuffNPuff_Body),
        .drops = HUFF_N_PUFF_NO_DROPS,
        .animations = HUFF_N_PUFF_ANIMS,
        .extraAnimations = N(ExtraAnims_HuffNPuff),
    },
    {
        .id = NPC_HuffNPuff_03,
        .settings = &N(NpcSettings_HuffNPuff),
        .pos = { 650.0f, NPC_DISPOSE_POS_Y, 0.0f },
        .yaw = 270,
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_100 | ENEMY_FLAG_200 | ENEMY_FLAG_400 | ENEMY_FLAG_800 | ENEMY_FLAG_40000,
        .init = &N(EVS_NpcInit_HuffNPuff_Arms),
        .drops = HUFF_N_PUFF_NO_DROPS,
        .animations = HUFF_N_PUFF_ANIMS,
        .extraAnimations = N(ExtraAnims_HuffNPuff),
    },
};

s32 N(ExtraAnims_TuffPuff)[] = {
    ANIM_TuffPuff_Dizzy,
    ANIM_LIST_END
};

StaticNpc N(NpcData_TuffPuffs)[] = {
    {
        .id = NPC_TuffPuff_01,
        .settings = &N(NpcSettings_TuffPuff),
        .pos = { NPC_DISPOSE_LOCATION },
        .yaw = 270,
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_100 | ENEMY_FLAG_200 | ENEMY_FLAG_400 | ENEMY_FLAG_800,
        .init = &N(EVS_NpcInit_TuffPuff),
        .drops = TUFF_PUFF_NO_DROPS,
        .animations = TUFF_PUFF_ANIMS,
        .extraAnimations = N(ExtraAnims_TuffPuff),
    },
    {
        .id = NPC_TuffPuff_02,
        .settings = &N(NpcSettings_TuffPuff),
        .pos = { NPC_DISPOSE_LOCATION },
        .yaw = 270,
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_100 | ENEMY_FLAG_200 | ENEMY_FLAG_400 | ENEMY_FLAG_800,
        .init = &N(EVS_NpcInit_TuffPuff),
        .drops = TUFF_PUFF_NO_DROPS,
        .animations = TUFF_PUFF_ANIMS,
        .extraAnimations = N(ExtraAnims_TuffPuff),
    },
    {
        .id = NPC_TuffPuff_03,
        .settings = &N(NpcSettings_TuffPuff),
        .pos = { NPC_DISPOSE_LOCATION },
        .yaw = 270,
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_100 | ENEMY_FLAG_200 | ENEMY_FLAG_400 | ENEMY_FLAG_800,
        .init = &N(EVS_NpcInit_TuffPuff),
        .drops = TUFF_PUFF_NO_DROPS,
        .animations = TUFF_PUFF_ANIMS,
        .extraAnimations = N(ExtraAnims_TuffPuff),
    },
    {
        .id = NPC_TuffPuff_04,
        .settings = &N(NpcSettings_TuffPuff),
        .pos = { NPC_DISPOSE_LOCATION },
        .yaw = 270,
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_100 | ENEMY_FLAG_200 | ENEMY_FLAG_400 | ENEMY_FLAG_800,
        .init = &N(EVS_NpcInit_TuffPuff),
        .drops = TUFF_PUFF_NO_DROPS,
        .animations = TUFF_PUFF_ANIMS,
        .extraAnimations = N(ExtraAnims_TuffPuff),
    },
    {
        .id = NPC_TuffPuff_05,
        .settings = &N(NpcSettings_TuffPuff),
        .pos = { NPC_DISPOSE_LOCATION },
        .yaw = 270,
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_100 | ENEMY_FLAG_200 | ENEMY_FLAG_400 | ENEMY_FLAG_800,
        .init = &N(EVS_NpcInit_TuffPuff),
        .drops = TUFF_PUFF_NO_DROPS,
        .animations = TUFF_PUFF_ANIMS,
        .extraAnimations = N(ExtraAnims_TuffPuff),
    },
    {
        .id = NPC_TuffPuff_06,
        .settings = &N(NpcSettings_TuffPuff),
        .pos = { NPC_DISPOSE_LOCATION },
        .yaw = 270,
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_100 | ENEMY_FLAG_200 | ENEMY_FLAG_400 | ENEMY_FLAG_800,
        .init = &N(EVS_NpcInit_TuffPuff),
        .drops = TUFF_PUFF_NO_DROPS,
        .animations = TUFF_PUFF_ANIMS,
        .extraAnimations = N(ExtraAnims_TuffPuff),
    },
    {
        .id = NPC_TuffPuff_07,
        .settings = &N(NpcSettings_TuffPuff),
        .pos = { NPC_DISPOSE_LOCATION },
        .yaw = 270,
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_100 | ENEMY_FLAG_200 | ENEMY_FLAG_400 | ENEMY_FLAG_800,
        .init = &N(EVS_NpcInit_TuffPuff),
        .drops = TUFF_PUFF_NO_DROPS,
        .animations = TUFF_PUFF_ANIMS,
        .extraAnimations = N(ExtraAnims_TuffPuff),
    },
    {
        .id = NPC_TuffPuff_08,
        .settings = &N(NpcSettings_TuffPuff),
        .pos = { NPC_DISPOSE_LOCATION },
        .yaw = 270,
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_100 | ENEMY_FLAG_200 | ENEMY_FLAG_400 | ENEMY_FLAG_800,
        .init = &N(EVS_NpcInit_TuffPuff),
        .drops = TUFF_PUFF_NO_DROPS,
        .animations = TUFF_PUFF_ANIMS,
        .extraAnimations = N(ExtraAnims_TuffPuff),
    },
    {
        .id = NPC_TuffPuff_09,
        .settings = &N(NpcSettings_TuffPuff),
        .pos = { NPC_DISPOSE_LOCATION },
        .yaw = 270,
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_100 | ENEMY_FLAG_200 | ENEMY_FLAG_400 | ENEMY_FLAG_800,
        .init = &N(EVS_NpcInit_TuffPuff),
        .drops = TUFF_PUFF_NO_DROPS,
        .animations = TUFF_PUFF_ANIMS,
        .extraAnimations = N(ExtraAnims_TuffPuff),
    },
    {
        .id = NPC_TuffPuff_10,
        .settings = &N(NpcSettings_TuffPuff),
        .pos = { NPC_DISPOSE_LOCATION },
        .yaw = 270,
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_100 | ENEMY_FLAG_200 | ENEMY_FLAG_400 | ENEMY_FLAG_800,
        .init = &N(EVS_NpcInit_TuffPuff),
        .drops = TUFF_PUFF_NO_DROPS,
        .animations = TUFF_PUFF_ANIMS,
        .extraAnimations = N(ExtraAnims_TuffPuff),
    },
    {
        .id = NPC_TuffPuff_11,
        .settings = &N(NpcSettings_TuffPuff),
        .pos = { NPC_DISPOSE_LOCATION },
        .yaw = 270,
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_100 | ENEMY_FLAG_200 | ENEMY_FLAG_400 | ENEMY_FLAG_800,
        .init = &N(EVS_NpcInit_TuffPuff),
        .drops = TUFF_PUFF_NO_DROPS,
        .animations = TUFF_PUFF_ANIMS,
        .extraAnimations = N(ExtraAnims_TuffPuff),
    },
    {
        .id = NPC_TuffPuff_12,
        .settings = &N(NpcSettings_TuffPuff),
        .pos = { NPC_DISPOSE_LOCATION },
        .yaw = 270,
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_100 | ENEMY_FLAG_200 | ENEMY_FLAG_400 | ENEMY_FLAG_800,
        .init = &N(EVS_NpcInit_TuffPuff),
        .drops = TUFF_PUFF_NO_DROPS,
        .animations = TUFF_PUFF_ANIMS,
        .extraAnimations = N(ExtraAnims_TuffPuff),
    },
    {
        .id = NPC_TuffPuff_13,
        .settings = &N(NpcSettings_TuffPuff),
        .pos = { NPC_DISPOSE_LOCATION },
        .yaw = 270,
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_100 | ENEMY_FLAG_200 | ENEMY_FLAG_400 | ENEMY_FLAG_800,
        .init = &N(EVS_NpcInit_TuffPuff),
        .drops = TUFF_PUFF_NO_DROPS,
        .animations = TUFF_PUFF_ANIMS,
        .extraAnimations = N(ExtraAnims_TuffPuff),
    },
    {
        .id = NPC_TuffPuff_14,
        .settings = &N(NpcSettings_TuffPuff),
        .pos = { NPC_DISPOSE_LOCATION },
        .yaw = 270,
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_100 | ENEMY_FLAG_200 | ENEMY_FLAG_400 | ENEMY_FLAG_800,
        .init = &N(EVS_NpcInit_TuffPuff),
        .drops = TUFF_PUFF_NO_DROPS,
        .animations = TUFF_PUFF_ANIMS,
        .extraAnimations = N(ExtraAnims_TuffPuff),
    },
    {
        .id = NPC_TuffPuff_15,
        .settings = &N(NpcSettings_TuffPuff),
        .pos = { NPC_DISPOSE_LOCATION },
        .yaw = 270,
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_100 | ENEMY_FLAG_200 | ENEMY_FLAG_400 | ENEMY_FLAG_800,
        .init = &N(EVS_NpcInit_TuffPuff),
        .drops = TUFF_PUFF_NO_DROPS,
        .animations = TUFF_PUFF_ANIMS,
        .extraAnimations = N(ExtraAnims_TuffPuff),
    },
};

NpcGroupList N(DefaultNPCs) = {
    NPC_GROUP(N(NpcData_HuffNPuff), BTL_FLO2_FORMATION_00, BTL_FLO2_STAGE_07),
    NPC_GROUP(N(NpcData_TuffPuffs), BTL_FLO_FORMATION_1F, BTL_FLO_STAGE_07),
    {}
};
