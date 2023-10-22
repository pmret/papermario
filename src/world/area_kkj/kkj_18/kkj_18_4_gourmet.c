#include "kkj_18.h"
#include "sprite/player.h"

#include "world/common/complete/KeyItemChoice.inc.c"
MAP_STATIC_PAD(1,item_choice);
#include "world/common/complete/NormalItemChoice.inc.c"

API_CALLABLE(N(SetHeldBakingItem)) {
    Bytecode* args = script->ptrReadPos;

    // bizarre use of evt_get_float_variable here
    gPlayerStatus.peachItemHeld = evt_get_float_variable(script, *args++);
    gGameStatusPtr->peachBakingIngredient = gPlayerStatus.peachItemHeld;

    return ApiStatus_DONE2;
}

API_CALLABLE(N(SpinCameraAround)) {
    Camera* camera = &gCameras[CAM_DEFAULT];

    if (isInitialCall) {
        camera->flags |= CAMERA_FLAG_SHAKING;
        script->functionTempF[0] = 0.0f;
    }

    script->functionTempF[0] += 10.0f;
    guRotateF(camera->viewMtxShaking, script->functionTempF[0], 0.0f, 0.0f, -1.0f);

    if (script->functionTempF[0] >= 360.0) {
        return ApiStatus_DONE2;
    } else {
        return ApiStatus_BLOCK;
    }
}

Vec3f N(TwinkDepartPath)[] = {
    {  -23.0,    30.0,   36.0 },
    {   16.0,    62.0,  -10.0 },
    {   64.0,    55.0,    5.0 },
    {  112.0,    46.0,   20.0 },
    {  160.0,    60.0,  -25.0 },
};

EvtScript N(EVS_ApproachPeach) = {
    EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
    EVT_ADD(LVar0, 16)
    EVT_CALL(UseSettingsFrom, CAM_DEFAULT, LVar0, LVar1, LVar2)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(1.0))
    EVT_CALL(SetNpcVar, NPC_Koopatrol_01, 0, 1)
    EVT_THREAD
        EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
        EVT_SUB(LVar0, 26)
        EVT_ADD(LVar2, 2)
        EVT_CALL(SetNpcAnimation, NPC_Koopatrol_01, ANIM_WorldKoopatrol_Anim06)
        EVT_CALL(SetNpcSpeed, NPC_Koopatrol_01, EVT_FLOAT(5.0))
        EVT_WAIT(10)
        EVT_CALL(NpcMoveTo, NPC_Koopatrol_01, -130, -30, 0)
        EVT_CALL(NpcMoveTo, NPC_Koopatrol_01, -130, 30, 0)
        EVT_CALL(NpcMoveTo, NPC_Koopatrol_01, LVar0, LVar2, 0)
        EVT_CALL(SetNpcAnimation, NPC_Koopatrol_01, ANIM_WorldKoopatrol_Anim01)
        EVT_CALL(NpcFacePlayer, NPC_Koopatrol_01, 5)
        EVT_CALL(SetNpcVar, NPC_Koopatrol_01, 0, 0)
    EVT_END_THREAD
    EVT_THREAD
        EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
        EVT_ADD(LVar0, 26)
        EVT_SUB(LVar2, 2)
        EVT_CALL(SetNpcAnimation, NPC_Koopatrol_02, ANIM_WorldKoopatrol_Anim06)
        EVT_CALL(SetNpcSpeed, NPC_Koopatrol_02, EVT_FLOAT(5.0))
        EVT_CALL(NpcMoveTo, NPC_Koopatrol_02, -130, -30, 0)
        EVT_CALL(NpcMoveTo, NPC_Koopatrol_02, -130, 30, 0)
        EVT_CALL(NpcMoveTo, NPC_Koopatrol_02, -100, 30, 0)
        EVT_CALL(NpcMoveTo, NPC_Koopatrol_02, LVar0, LVar2, 0)
        EVT_CALL(SetNpcAnimation, NPC_Koopatrol_02, ANIM_WorldKoopatrol_Anim01)
        EVT_CALL(NpcFacePlayer, NPC_Koopatrol_02, 5)
    EVT_END_THREAD
    EVT_CALL(InterpPlayerYaw, 270, 0)
    EVT_LOOP(0)
        EVT_WAIT(1)
        EVT_CALL(GetNpcVar, NPC_Koopatrol_01, 0, LVar0)
        EVT_IF_EQ(LVar0, 0)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_WAIT(10)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_PickUpPeach) = {
    EVT_THREAD
        EVT_CALL(GetNpcPos, NPC_Koopatrol_01, LVar0, LVar1, LVar2)
        EVT_ADD(LVar0, 5)
        EVT_CALL(NpcMoveTo, NPC_Koopatrol_01, LVar0, LVar2, 5)
        EVT_CALL(SetNpcAnimation, NPC_Koopatrol_01, ANIM_WorldKoopatrol_Anim12)
        EVT_ADD(LVar0, 5)
        EVT_CALL(NpcMoveTo, NPC_Koopatrol_01, LVar0, LVar2, 5)
    EVT_END_THREAD
    EVT_THREAD
        EVT_CALL(GetNpcPos, NPC_Koopatrol_02, LVar0, LVar1, LVar2)
        EVT_SUB(LVar0, 5)
        EVT_CALL(NpcMoveTo, NPC_Koopatrol_02, LVar0, LVar2, 5)
        EVT_CALL(SetNpcAnimation, NPC_Koopatrol_02, ANIM_WorldKoopatrol_Anim12)
        EVT_SUB(LVar0, 5)
        EVT_CALL(NpcMoveTo, NPC_Koopatrol_02, LVar0, LVar2, 5)
    EVT_END_THREAD
    EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
    EVT_CALL(SetPlayerAnimation, ANIM_Peach2_Gasp)
    EVT_WAIT(1)
    EVT_LOOP(4)
        EVT_ADD(LVar1, 2)
        EVT_CALL(SetPlayerPos, LVar0, LVar1, LVar2)
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_CALL(SetPlayerAnimation, ANIM_Peach2_Carried)
    EVT_ADD(LVar0, 10)
    EVT_LOOP(5)
        EVT_ADD(LVar1, 4)
        EVT_CALL(SetPlayerPos, LVar0, LVar1, LVar2)
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_CarryPeachAway) = {
    EVT_CALL(InterpNpcYaw, NPC_Koopatrol_01, 270, 3)
    EVT_WAIT(10)
    EVT_THREAD
        EVT_LOOP(0)
            EVT_CALL(GetNpcPos, NPC_Koopatrol_01, LVar0, LVar1, LVar2)
            EVT_ADD(LVar0, 22)
            EVT_SUB(LVar2, 2)
            EVT_CALL(SetPlayerPos, LVar0, 30, LVar2)
            EVT_WAIT(1)
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_CALL(SetNpcVar, NPC_Koopatrol_01, 0, 1)
    EVT_THREAD
        EVT_CALL(SetNpcAnimation, NPC_Koopatrol_01, ANIM_WorldKoopatrol_Anim14)
        EVT_CALL(SetNpcSpeed, NPC_Koopatrol_01, EVT_FLOAT(5.0))
        EVT_CALL(NpcMoveTo, NPC_Koopatrol_01, -136, 32, 0)
        EVT_CALL(NpcMoveTo, NPC_Koopatrol_01, -136, -28, 0)
        EVT_CALL(NpcMoveTo, NPC_Koopatrol_01, -266, -28, 0)
        EVT_CALL(SetNpcVar, NPC_Koopatrol_01, 0, 0)
    EVT_END_THREAD
    EVT_THREAD
        EVT_CALL(SetNpcAnimation, NPC_Koopatrol_02, ANIM_WorldKoopatrol_Anim14)
        EVT_CALL(SetNpcSpeed, NPC_Koopatrol_02, EVT_FLOAT(5.0))
        EVT_CALL(NpcMoveTo, NPC_Koopatrol_02, -104, 28, 0)
        EVT_CALL(NpcMoveTo, NPC_Koopatrol_02, -104, -32, 0)
        EVT_CALL(NpcMoveTo, NPC_Koopatrol_02, -234, -32, 0)
    EVT_END_THREAD
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(90.0))
    EVT_LOOP(0)
        EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
        EVT_CALL(SetPanTarget, CAM_DEFAULT, LVar0, 0, LVar2)
        EVT_CALL(GetNpcVar, NPC_Koopatrol_01, 0, LVar0)
        EVT_WAIT(1)
        EVT_IF_EQ(LVar0, 0)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_OpenAndCloseWindow) = {
    EVT_CALL(PlaySoundAt, SOUND_WINDOW_OPEN_A, SOUND_SPACE_DEFAULT, 190, 78, -20)
    EVT_CALL(MakeLerp, 0, 80, 14, EASING_QUADRATIC_OUT)
    EVT_LOOP(0)
        EVT_CALL(UpdateLerp)
        EVT_CALL(RotateGroup, MODEL_g15, LVar0, 0, -1, 0)
        EVT_CALL(RotateGroup, MODEL_g16, LVar0, 0, 1, 0)
        EVT_WAIT(1)
        EVT_IF_EQ(LVar1, 0)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_WAIT(20)
    EVT_CALL(MakeLerp, 80, 0, 14, EASING_QUADRATIC_OUT)
    EVT_LOOP(0)
        EVT_CALL(UpdateLerp)
        EVT_CALL(RotateGroup, MODEL_g15, LVar0, 0, -1, 0)
        EVT_CALL(RotateGroup, MODEL_g16, LVar0, 0, 1, 0)
        EVT_WAIT(1)
        EVT_IF_EQ(LVar1, 0)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_CALL(PlaySoundAt, SOUND_WINDOW_CLOSE_A, SOUND_SPACE_DEFAULT, 190, 78, -20)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_DropFork) = {
    EVT_CALL(SetNpcFlagBits, NPC_GourmetGuy_Fork, NPC_FLAG_INVISIBLE, FALSE)
    EVT_CALL(GetNpcPos, NPC_GourmetGuy_Fork, LVar0, LVar1, LVar2)
    EVT_CALL(SetNpcJumpscale, NPC_GourmetGuy_Fork, EVT_FLOAT(0.05))
    EVT_CALL(NpcJump0, NPC_GourmetGuy_Fork, LVar0, -8, LVar2, 8 * DT)
    EVT_CALL(SetNpcRotationPivot, NPC_GourmetGuy_Fork, 15)
    EVT_SET(LVar3, 0)
    EVT_LOOP(5)
        EVT_ADD(LVar3, 50)
        EVT_CALL(SetNpcRotation, NPC_GourmetGuy_Fork, 0, 0, LVar3)
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_ADD(LVar2, 20)
    EVT_CALL(SetNpcJumpscale, NPC_GourmetGuy_Fork, EVT_FLOAT(0.2))
    EVT_CALL(NpcJump0, NPC_GourmetGuy_Fork, LVar0, -20, LVar2, 8)
    EVT_WAIT(10 * DT)
    EVT_CALL(RemoveNpc, NPC_GourmetGuy_Fork)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_DropKnife) = {
    EVT_CALL(SetNpcFlagBits, NPC_GourmetGuy_Knife, NPC_FLAG_INVISIBLE, FALSE)
    EVT_CALL(GetNpcPos, NPC_GourmetGuy_Knife, LVar0, LVar1, LVar2)
    EVT_CALL(SetNpcRotation, NPC_GourmetGuy_Knife, 0, 0, -25)
    EVT_CALL(SetNpcJumpscale, NPC_GourmetGuy_Knife, EVT_FLOAT(0.05))
    EVT_CALL(NpcJump0, NPC_GourmetGuy_Knife, LVar0, -8, LVar2, 8 * DT)
    EVT_CALL(SetNpcRotationPivot, NPC_GourmetGuy_Knife, 15)
    EVT_SET(LVar3, 0)
    EVT_LOOP(5)
        EVT_SUB(LVar3, 50)
        EVT_CALL(SetNpcRotation, NPC_GourmetGuy_Knife, 0, 0, LVar3)
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_ADD(LVar2, 20)
    EVT_CALL(SetNpcJumpscale, NPC_GourmetGuy_Knife, EVT_FLOAT(0.2))
    EVT_CALL(NpcJump0, NPC_GourmetGuy_Knife, LVar0, -20, LVar2, -100)
    EVT_WAIT(10 * DT)
    EVT_CALL(RemoveNpc, NPC_GourmetGuy_Knife)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_GourmetGuy_LovesCake) = {
    EVT_THREAD
        EVT_CALL(ShowMessageAtScreenPos, MSG_Peach_00AB, 160, 40)
    EVT_END_THREAD
    EVT_EXEC(N(EVS_DropFork))
    EVT_EXEC(N(EVS_DropKnife))
    EVT_CALL(SetNpcAnimation, NPC_GourmetGuy, ANIM_GourmetGuy_Surprise)
    EVT_WAIT(1)
    EVT_CALL(UseSettingsFrom, CAM_DEFAULT, 90, 65, 10)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, 90, 65, 10)
    EVT_CALL(SetCamDistance, CAM_DEFAULT, 170)
    EVT_CALL(SetCamPitch, CAM_DEFAULT, 12, EVT_FLOAT(-2.5))
    EVT_CALL(SetCamPosB, CAM_DEFAULT, EVT_FLOAT(110.0), EVT_FLOAT(45.5))
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(20.0 / DT))
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_CALL(WaitForCam, CAM_DEFAULT, EVT_FLOAT(1.0))
    EVT_CALL(PlaySoundAtNpc, NPC_GourmetGuy, SOUND_GOURMET_GUY_SHOCK_1, SOUND_SPACE_DEFAULT)
    EVT_WAIT(33 * DT)
    EVT_CALL(SetCamDistance, CAM_DEFAULT, EVT_FLOAT(65.0))
    EVT_CALL(SetCamPitch, CAM_DEFAULT, EVT_FLOAT(7.5), EVT_FLOAT(-1.3))
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_CALL(WaitForCam, CAM_DEFAULT, EVT_FLOAT(1.0))
    EVT_CALL(PlaySoundAtNpc, NPC_GourmetGuy, SOUND_GOURMET_GUY_SHOCK_2, SOUND_SPACE_DEFAULT)
    EVT_WAIT(33 * DT)
    EVT_CALL(SetCamDistance, CAM_DEFAULT, EVT_FLOAT(1.0))
    EVT_CALL(SetCamPitch, CAM_DEFAULT, EVT_FLOAT(3.5), 0)
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_CALL(WaitForCam, CAM_DEFAULT, EVT_FLOAT(1.0))
    EVT_CALL(PlaySoundAtNpc, NPC_GourmetGuy, SOUND_GOURMET_GUY_SHOCK_3, SOUND_SPACE_DEFAULT)
    EVT_WAIT(18 * DT)
    EVT_CALL(SetMusicTrack, 0, SONG_GOURMET_GUY_FREAKOUT, 0, 8)
    EVT_WAIT(30 * DT)
    EVT_CALL(SetMotionBlurParams, 0, 0, 0, 320, 240, 128, 10)
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(12.0))
    EVT_LOOP(7)
        EVT_CALL(SetCamDistance, CAM_DEFAULT, 65)
        EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
        EVT_CALL(WaitForCam, CAM_DEFAULT, EVT_FLOAT(1.0))
        EVT_CALL(SetCamDistance, CAM_DEFAULT, 1)
        EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
        EVT_CALL(WaitForCam, CAM_DEFAULT, EVT_FLOAT(1.0))
    EVT_END_LOOP
    EVT_CALL(N(SpinCameraAround))
    EVT_CALL(N(SpinCameraAround))
    EVT_CALL(N(SpinCameraAround))
    EVT_CALL(SetMotionBlurParams, 0, 0, 0, 320, 240, 0, 10)
    EVT_CALL(UseSettingsFrom, CAM_DEFAULT, 120, 0, 10)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, 120, 0, 10)
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(90.0))
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_GourmetGuy_RunAround) = {
    EVT_CALL(PlaySoundAtNpc, NPC_GourmetGuy, SOUND_GOURMET_GUY_RUN, SOUND_SPACE_DEFAULT)
    EVT_CALL(SetNpcAnimation, NPC_GourmetGuy, ANIM_GourmetGuy_Leap)
    EVT_CALL(SetNpcJumpscale, NPC_GourmetGuy, EVT_FLOAT(0.001953125))
    EVT_CALL(GetNpcPos, NPC_GourmetGuy, LVar0, LVar1, LVar2)
    EVT_CALL(NpcJump0, NPC_GourmetGuy, LVar0, 200, LVar2, 15 * DT)
    EVT_CALL(SetNpcAnimation, NPC_GourmetGuy, ANIM_GourmetGuy_Panic)
    EVT_CALL(SetNpcFlagBits, NPC_GourmetGuy, NPC_FLAG_IGNORE_PLAYER_COLLISION, TRUE)
    EVT_CALL(SetNpcSpeed, NPC_GourmetGuy, EVT_FLOAT(20.0 / DT))
    EVT_CALL(PlaySoundAtNpc, NPC_GourmetGuy, SOUND_GOURMET_GUY_RUN, SOUND_SPACE_DEFAULT)
    EVT_CALL(SetNpcRotation, NPC_GourmetGuy, 0, 0, -45)
    EVT_CALL(SetNpcYaw, NPC_GourmetGuy, 90)
    EVT_CALL(MakeLerp, 0, 100, 30, EASING_LINEAR)
    EVT_LOOP(0)
        EVT_CALL(UpdateLerp)
        EVT_SETF(LVar2, EVT_FLOAT(3.3))
        EVT_SETF(LVar3, EVT_FLOAT(-2.3))
        EVT_MULF(LVar2, LVar0)
        EVT_MULF(LVar3, LVar0)
        EVT_ADDF(LVar2, EVT_FLOAT(-100.0))
        EVT_ADDF(LVar3, EVT_FLOAT(150.0))
        EVT_SETF(LVar4, EVT_FLOAT(100.0))
        EVT_CALL(SetNpcPos, NPC_GourmetGuy, LVar2, LVar3, LVar4)
        EVT_WAIT(1)
        EVT_IF_EQ(LVar1, 0)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_WAIT(20 * DT)
    EVT_CALL(SetNpcRotation, NPC_GourmetGuy, 0, 0, 0)
    EVT_CALL(PlaySoundAtNpc, NPC_GourmetGuy, SOUND_GOURMET_GUY_RUN, SOUND_SPACE_DEFAULT)
    EVT_CALL(SetNpcFlagBits, NPC_GourmetGuy, NPC_FLAG_UPSIDE_DOWN, TRUE)
    EVT_CALL(SetNpcYaw, NPC_GourmetGuy, 270)
    EVT_CALL(SetNpcPos, NPC_GourmetGuy, 250, 160, 50)
    EVT_CALL(NpcMoveTo, NPC_GourmetGuy, -100, 50, 0)
    EVT_CALL(SetNpcFlagBits, NPC_GourmetGuy, NPC_FLAG_UPSIDE_DOWN, FALSE)
    EVT_WAIT(20 * DT)
    EVT_CALL(PlaySoundAtNpc, NPC_GourmetGuy, SOUND_GOURMET_GUY_RUN, SOUND_SPACE_DEFAULT)
    EVT_CALL(SetNpcYaw, NPC_GourmetGuy, 90)
    EVT_CALL(SetNpcPos, NPC_GourmetGuy, -100, 0, 70)
    EVT_CALL(NpcMoveTo, NPC_GourmetGuy, 140, 70, 0)
    EVT_WAIT(20 * DT)
    EVT_CALL(SetNpcVar, NPC_GourmetGuy, 0, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_RejectCake) = {
    EVT_CALL(PlaySoundAtNpc, NPC_GourmetGuy, SOUND_SPIT_OUT, SOUND_SPACE_DEFAULT)
    EVT_CALL(SetNpcAnimation, NPC_GourmetGuy, ANIM_GourmetGuy_SpitOut)
    EVT_CALL(MakeItemEntity, MV_CakeItemIdx, 105, 30, 20, ITEM_SPAWN_MODE_DECORATION, 0)
    EVT_CALL(MakeLerp, 0, 100, 4, EASING_LINEAR)
    EVT_LOOP(0)
        EVT_CALL(UpdateLerp)
        EVT_SETF(LVar2, EVT_FLOAT(0.2))
        EVT_SETF(LVar3, EVT_FLOAT(-0.3))
        EVT_SETF(LVar4, EVT_FLOAT(0.5))
        EVT_MULF(LVar2, LVar0)
        EVT_MULF(LVar3, LVar0)
        EVT_MULF(LVar4, LVar0)
        EVT_ADDF(LVar2, EVT_FLOAT(105.0))
        EVT_ADDF(LVar3, EVT_FLOAT(30.0))
        EVT_ADDF(LVar4, EVT_FLOAT(20.0))
        EVT_CALL(SetItemPos, LVarA, LVar2, LVar3, LVar4)
        EVT_WAIT(1)
        EVT_IF_EQ(LVar1, 0)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_CALL(MakeLerp, 0, 100, 4, EASING_LINEAR)
    EVT_LOOP(0)
        EVT_CALL(UpdateLerp)
        EVT_SETF(LVar2, EVT_FLOAT(0.2))
        EVT_SETF(LVar3, EVT_FLOAT(0.3))
        EVT_SETF(LVar4, EVT_FLOAT(0.5))
        EVT_MULF(LVar2, LVar0)
        EVT_MULF(LVar3, LVar0)
        EVT_MULF(LVar4, LVar0)
        EVT_ADDF(LVar2, EVT_FLOAT(125.0))
        EVT_ADDF(LVar3, EVT_FLOAT(0.0))
        EVT_ADDF(LVar4, EVT_FLOAT(70.0))
        EVT_CALL(SetItemPos, LVarA, LVar2, LVar3, LVar4)
        EVT_WAIT(1)
        EVT_IF_EQ(LVar1, 0)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_CALL(RemoveItemEntity, LVarA)
    EVT_CALL(SetNpcAnimation, NPC_GourmetGuy, ANIM_GourmetGuy_Idle)
    EVT_CALL(SpeakToPlayer, NPC_GourmetGuy, ANIM_GourmetGuy_Talk, ANIM_GourmetGuy_Idle, 5, MSG_Peach_00A5)
    EVT_CALL(UseSettingsFrom, CAM_DEFAULT, 120, 0, 10)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, 120, 0, 10)
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(90.0))
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_CALL(WaitForCam, CAM_DEFAULT, EVT_FLOAT(1.0))
    EVT_SWITCH(AB_KKJ_CompletedBakeStep)
        EVT_CASE_EQ(CAKE_TYPE_BAKED)
            EVT_CALL(SpeakToPlayer, NPC_GourmetGuy, ANIM_GourmetGuy_Talk, ANIM_GourmetGuy_Idle, 5, MSG_Peach_00AA)
        EVT_CASE_EQ(CAKE_TYPE_READY_TO_BAKE)
            EVT_CALL(SpeakToPlayer, NPC_GourmetGuy, ANIM_GourmetGuy_Talk, ANIM_GourmetGuy_Idle, 5, MSG_Peach_00A9)
        EVT_CASE_EQ(CAKE_TYPE_READY_TO_MIX)
            EVT_CALL(SpeakToPlayer, NPC_GourmetGuy, ANIM_GourmetGuy_Talk, ANIM_GourmetGuy_Idle, 5, MSG_Peach_00A8)
        EVT_CASE_OR_EQ(CAKE_TYPE_BEGUN)
        EVT_CASE_OR_EQ(CAKE_TYPE_MIXED)
            EVT_CALL(SpeakToPlayer, NPC_GourmetGuy, ANIM_GourmetGuy_Talk, ANIM_GourmetGuy_Idle, 5, MSG_Peach_00A7)
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_CALL(SetNpcAnimation, NPC_GourmetGuy, ANIM_GourmetGuy_Walk)
    EVT_CALL(SetNpcJumpscale, NPC_GourmetGuy, 0)
    EVT_CALL(NpcJump1, NPC_GourmetGuy, 120, 0, -20, 15 * DT)
    EVT_CALL(SetNpcAnimation, NPC_GourmetGuy, ANIM_GourmetGuy_Idle)
    EVT_CALL(ResetCam, CAM_DEFAULT, EVT_FLOAT(1.0 / DT))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_SweatyPeach) = {
    EVT_CALL(SetPlayerAnimation, ANIM_Peach2_Gasp)
    EVT_WAIT(10)
    EVT_CALL(InterpPlayerYaw, 90, 5)
    EVT_CALL(SetPlayerAnimation, ANIM_Peach1_Idle)
    EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
    EVT_ADD(LVar1, 35)
    EVT_LOOP(0)
        EVT_CALL(ShowSweat, 0, 1, -45, EMOTER_POS, LVar0, LVar1, LVar2, 13, 20)
        EVT_WAIT(20)
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Scene_GiveKitchenKey) = {
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(SpeakToPlayer, NPC_GourmetGuy, ANIM_GourmetGuy_Talk, ANIM_GourmetGuy_Idle, 0, MSG_Peach_009A)
    EVT_WAIT(10 * DT)
    EVT_CALL(SetPlayerSpeed, EVT_FLOAT(4.0 / DT))
    EVT_CALL(PlayerMoveTo, -125, 40, 0)
    EVT_CALL(PlayerMoveTo, 50, 40, 0)
    EVT_WAIT(10 * DT)
    EVT_CALL(SpeakToPlayer, NPC_PLAYER, ANIM_Peach3_InformalTalk, ANIM_Peach1_Idle, 5, MSG_Peach_009B)
    EVT_CALL(AdjustCam, CAM_DEFAULT, EVT_FLOAT(4.0 / DT), 35, 300, EVT_FLOAT(17.0), EVT_FLOAT(-11.0))
    EVT_CALL(SpeakToPlayer, NPC_GourmetGuy, ANIM_GourmetGuy_Talk, ANIM_GourmetGuy_Idle, 5, MSG_Peach_009C)
    EVT_CALL(SetPlayerAnimation, ANIM_Peach2_RaiseArms)
    EVT_WAIT(10 * DT)
    EVT_CALL(SetPlayerAnimation, ANIM_Peach2_TalkIdle)
    EVT_CALL(SpeakToPlayer, NPC_PLAYER, ANIM_Peach2_Talk, ANIM_Peach2_TalkIdle, 5, MSG_Peach_009D)
    EVT_CALL(SetPlayerAnimation, ANIM_Peach2_LowerArms)
    EVT_WAIT(10 * DT)
    EVT_CALL(SetPlayerAnimation, ANIM_Peach1_Idle)
    EVT_CALL(SpeakToPlayer, NPC_GourmetGuy, ANIM_GourmetGuy_Talk, ANIM_GourmetGuy_Idle, 5, MSG_Peach_009E)
    EVT_CALL(SetNpcAnimation, NPC_GourmetGuy, ANIM_GourmetGuy_Walk)
    EVT_CALL(NpcMoveTo, NPC_GourmetGuy, 100, -20, 10 * DT)
    EVT_CALL(SetNpcAnimation, NPC_GourmetGuy, ANIM_GourmetGuy_Idle)
    EVT_CALL(SpeakToPlayer, NPC_GourmetGuy, ANIM_GourmetGuy_Talk, ANIM_GourmetGuy_Idle, 5, MSG_Peach_009F)
    EVT_CALL(SetNpcAnimation, NPC_GourmetGuy, ANIM_GourmetGuy_Inspect)
    EVT_WAIT(30 * DT)
    EVT_SET(LVar0, ITEM_PEACH_KEY1)
    EVT_CALL(ShowGotItem, LVar0, TRUE, 0)
    EVT_CALL(AddKeyItem, LVar0)
    EVT_SET(GF_KKJ18_GourmetGuy_GaveKey, TRUE)
    EVT_CALL(SetNpcAnimation, NPC_GourmetGuy, ANIM_GourmetGuy_Walk)
    EVT_CALL(SetNpcJumpscale, NPC_GourmetGuy, 0)
    EVT_CALL(NpcJump1, NPC_GourmetGuy, 120, 0, -20, 10)
    EVT_CALL(SetNpcAnimation, NPC_GourmetGuy, ANIM_GourmetGuy_Idle)
    EVT_CALL(SpeakToPlayer, NPC_GourmetGuy, ANIM_GourmetGuy_Talk, ANIM_GourmetGuy_Idle, 5, MSG_Peach_00A0)
    EVT_CALL(ResetCam, CAM_DEFAULT, EVT_FLOAT(4.0 / DT))
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Scene_JudgeCake) = {
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_IF_EQ(AB_KKJ19_AddedBerries, FALSE)
        EVT_SET(MV_CakeItemIdx, ITEM_CAKE_WITH_ICING)
        EVT_SET(LVar0, ANIM_Peach3_PresentBerryCake)
        EVT_SET(LVar1, ANIM_Peach1_HoldIcingCake)
    EVT_ELSE
        EVT_IF_EQ(AB_KKJ19_AddedIcing, FALSE)
            EVT_SET(MV_CakeItemIdx, ITEM_CAKE_WITH_BERRIES)
            EVT_SET(LVar0, ANIM_Peach3_PresentIcingCake)
            EVT_SET(LVar1, ANIM_Peach1_HoldBerryCake)
        EVT_ELSE
            EVT_SET(MV_CakeItemIdx, ITEM_CAKE_DONE)
            EVT_SET(LVar0, ANIM_Peach3_PresentCompleteCake)
            EVT_SET(LVar1, ANIM_Peach1_HoldCompleteCake)
        EVT_END_IF
    EVT_END_IF
    EVT_CALL(SpeakToPlayer, NPC_PLAYER, LVar0, LVar1, 5, MSG_Peach_00A2)
    EVT_CALL(UseSettingsFrom, CAM_DEFAULT, 120, 0, 10)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, 120, 0, 10)
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(1.0 / DT))
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_CALL(WaitForCam, CAM_DEFAULT, EVT_FLOAT(1.0))
    EVT_CALL(SpeakToPlayer, NPC_GourmetGuy, ANIM_GourmetGuy_Talk, ANIM_GourmetGuy_Idle, 5, MSG_Peach_00A3)
    EVT_CALL(ResetCam, CAM_DEFAULT, EVT_FLOAT(90.0))
    EVT_CALL(SetPlayerSpeed, EVT_FLOAT(2.0 / DT))
    EVT_CALL(PlayerMoveTo, -125, 40, 0)
    EVT_CALL(PlayerMoveTo, 15, 40, 0)
    EVT_WAIT(10 * DT)
    EVT_CALL(MakeItemEntity, MV_CakeItemIdx, 25, 25, -20, ITEM_SPAWN_MODE_DECORATION, 0)
    EVT_CALL(SetNpcVar, NPC_GourmetGuy, 7, LVar0)
    EVT_SET(AF_KKJ_FinishedBakingCake, FALSE)
    EVT_CALL(N(SetHeldBakingItem), PEACH_BAKING_NONE)
    EVT_THREAD
        EVT_CALL(DisablePartnerAI, 0)
        EVT_CALL(NpcFlyTo, NPC_PARTNER, -23, 30, 36, 5 * DT, 0, EASING_LINEAR)
        EVT_CALL(InterpNpcYaw, NPC_PARTNER, 90, 5)
    EVT_END_THREAD
    EVT_CALL(PlayerMoveTo, 17, 36, 5 * DT)
    EVT_CALL(InterpPlayerYaw, 90, 5)
    EVT_CALL(SpeakToPlayer, NPC_GourmetGuy, ANIM_GourmetGuy_Talk, ANIM_GourmetGuy_Idle, 5, MSG_Peach_00A4)
    EVT_CALL(SetNpcAnimation, NPC_GourmetGuy, ANIM_GourmetGuy_Walk)
    EVT_CALL(NpcMoveTo, NPC_GourmetGuy, 90, -20, 20 * DT)
    EVT_CALL(SetNpcAnimation, NPC_GourmetGuy, ANIM_GourmetGuy_Idle)
    EVT_CALL(UseSettingsFrom, CAM_DEFAULT, 90, 0, 10)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, 90, 0, 10)
    EVT_CALL(SetCamDistance, CAM_DEFAULT, 250)
    EVT_CALL(SetCamPitch, CAM_DEFAULT, 17, -14)
    EVT_CALL(SetCamPosB, CAM_DEFAULT, EVT_FLOAT(110.0), EVT_FLOAT(45.5))
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(3.0 / DT))
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_CALL(WaitForCam, CAM_DEFAULT, EVT_FLOAT(1.0))
    EVT_CALL(GetNpcVar, NPC_GourmetGuy, 7, LVarA)
    EVT_CALL(RemoveItemEntity, LVarA)
    EVT_CALL(SetNpcAnimation, NPC_GourmetGuy, ANIM_GourmetGuy_Eat)
    EVT_LOOP(6)
        EVT_WAIT(10 * DT)
        EVT_CALL(PlaySoundAtNpc, NPC_GourmetGuy, SOUND_EAT_OR_DRINK, SOUND_SPACE_DEFAULT)
    EVT_END_LOOP
    EVT_IF_NE(AB_KKJ_CompletedBakeStep, CAKE_TYPE_DONE)
        EVT_EXEC_WAIT(N(EVS_RejectCake))
        EVT_CALL(EnablePartnerAI)
        EVT_CALL(DisablePlayerPhysics, FALSE)
        EVT_CALL(DisablePlayerInput, FALSE)
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(SetEnemyFlagBits, NPC_GourmetGuy, ENEMY_FLAG_CANT_INTERACT, 1)
    EVT_EXEC_WAIT(N(EVS_GourmetGuy_LovesCake))
    EVT_CALL(SetNpcVar, NPC_GourmetGuy, 0, 1)
    EVT_EXEC(N(EVS_GourmetGuy_RunAround))
    EVT_LOOP(0)
        EVT_CALL(PlayerFaceNpc, NPC_GourmetGuy, FALSE)
        EVT_CALL(NpcFaceNpc, NPC_PARTNER, NPC_GourmetGuy, 0)
        EVT_WAIT(1)
        EVT_CALL(GetNpcVar, NPC_GourmetGuy, 0, LVar0)
        EVT_IF_EQ(LVar0, 0)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_EXEC(N(EVS_SetupMusic))
    EVT_CALL(SetNpcAnimation, NPC_GourmetGuy, ANIM_GourmetGuy_Idle)
    EVT_CALL(InterpNpcYaw, NPC_GourmetGuy, 270, 5)
    EVT_CALL(SpeakToPlayer, NPC_GourmetGuy, ANIM_GourmetGuy_Talk, ANIM_GourmetGuy_Idle, 0, MSG_Peach_00AC)
    EVT_CALL(SetNpcAnimation, NPC_GourmetGuy, ANIM_GourmetGuy_Walk)
    EVT_CALL(SetNpcSpeed, NPC_GourmetGuy, EVT_FLOAT(2.0 / DT))
    EVT_CALL(NpcMoveTo, NPC_GourmetGuy, 80, 70, 0)
    EVT_CALL(SetNpcAnimation, NPC_GourmetGuy, ANIM_GourmetGuy_Idle)
    EVT_CALL(SpeakToPlayer, NPC_GourmetGuy, ANIM_GourmetGuy_Talk, ANIM_GourmetGuy_Idle, 0, MSG_Peach_00AD)
    EVT_THREAD
        EVT_LOOP(100)
            EVT_CALL(PlayerFaceNpc, NPC_GourmetGuy, FALSE)
            EVT_CALL(NpcFaceNpc, NPC_PARTNER, NPC_GourmetGuy, 0)
            EVT_WAIT(1)
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_CALL(SetNpcAnimation, NPC_GourmetGuy, ANIM_GourmetGuy_Walk)
    EVT_CALL(NpcMoveTo, NPC_GourmetGuy, -250, 70, 0)
    EVT_CALL(AdjustCam, CAM_DEFAULT, EVT_FLOAT(2.0 / DT), -20, 300, EVT_FLOAT(17.0), EVT_FLOAT(-10.0))
    EVT_CALL(InterpPlayerYaw, 270, 5)
    EVT_CALL(SetPlayerAnimation, ANIM_Peach2_RaiseArms)
    EVT_WAIT(10 * DT)
    EVT_CALL(SetPlayerAnimation, ANIM_Peach2_TalkIdle)
    EVT_CALL(SpeakToPlayer, NPC_PLAYER, ANIM_Peach2_Talk, ANIM_Peach2_TalkIdle, 5, MSG_Peach_00AE)
    EVT_CALL(SpeakToPlayer, NPC_PARTNER, ANIM_Twink_Talk, ANIM_Twink_Idle, 0, MSG_Peach_00AF)
    EVT_CALL(SpeakToPlayer, NPC_PLAYER, ANIM_Peach2_Talk, ANIM_Peach2_TalkIdle, 5, MSG_Peach_00B0)
    EVT_CALL(SetPlayerAnimation, ANIM_Peach2_LowerArms)
    EVT_WAIT(10 * DT)
    EVT_CALL(SetPlayerAnimation, ANIM_Peach1_Idle)
    EVT_CALL(SpeakToPlayer, NPC_PARTNER, ANIM_Twink_Talk, ANIM_Twink_Idle, 0, MSG_Peach_00B1)
    EVT_CALL(UseSettingsFrom, CAM_DEFAULT, 120, 0, 10)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, 150, 0, 10)
    EVT_CALL(SetCamDistance, CAM_DEFAULT, 400)
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(1.2 / DT))
    EVT_CALL(LoadPath, 60 * DT, EVT_PTR(N(TwinkDepartPath)), ARRAY_COUNT(N(TwinkDepartPath)), EASING_LINEAR)
    EVT_LOOP(0)
        EVT_CALL(GetNextPathPos)
        EVT_CALL(SetNpcPos, NPC_PARTNER, LVar1, LVar2, LVar3)
        EVT_WAIT(1)
        EVT_IF_EQ(LVar0, 0)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_CALL(SetNpcFlagBits, NPC_PARTNER, NPC_FLAG_IGNORE_WORLD_COLLISION, TRUE)
    EVT_CALL(SpeakToPlayer, NPC_PARTNER, ANIM_Twink_Talk, ANIM_Twink_Idle, 16, MSG_Peach_00B2)
    EVT_EXEC(N(EVS_OpenAndCloseWindow))
    EVT_WAIT(14 * DT)
    EVT_CALL(NpcFlyTo, NPC_PARTNER, 250, 70, -25, 30 * DT, 0, EASING_LINEAR)
    EVT_WAIT(30 * DT)
    EVT_CALL(SetNpcPos, NPC_Koopatrol_01, -250, 0, -30)
    EVT_CALL(SetNpcPos, NPC_Koopatrol_02, -250, 0, -30)
    EVT_CALL(SetNpcPos, NPC_Kammy, -250, 0, -30)
    EVT_CALL(SpeakToPlayer, NPC_Kammy, ANIM_WorldKammy_Anim04, ANIM_WorldKammy_Anim01, 0, MSG_Peach_00B3)
    EVT_CALL(SetMusicTrack, 0, SONG_KAMMY_KOOPA_THEME, 0, 8)
    EVT_CALL(UseSettingsFrom, CAM_DEFAULT, -180, 0, -30)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, -180, 0, -30)
    EVT_CALL(SetCamDistance, CAM_DEFAULT, EVT_FLOAT(300.0))
    EVT_CALL(SetCamPosA, CAM_DEFAULT, EVT_FLOAT(-110.0), EVT_FLOAT(45.5))
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(5.0 / DT))
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_CALL(WaitForCam, CAM_DEFAULT, EVT_FLOAT(1.0))
    EVT_CALL(PlaySoundAtCollider, COLLIDER_ttw, SOUND_BASIC_DOOR_OPEN, 0)
    EVT_CALL(MakeLerp, 0, -120, 14, EASING_QUADRATIC_OUT)
    EVT_LOOP(0)
        EVT_CALL(UpdateLerp)
        EVT_CALL(RotateModel, MODEL_o9, LVar0, 0, 1, 0)
        EVT_WAIT(1)
        EVT_IF_EQ(LVar1, 0)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_THREAD
        EVT_WAIT(60 * DT)
        EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
        EVT_ADD(LVar0, -30)
        EVT_CALL(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
        EVT_CALL(SetCamDistance, CAM_DEFAULT, 400)
        EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(1.0 / DT))
    EVT_END_THREAD
    EVT_CALL(SetNpcAnimation, NPC_Kammy, ANIM_WorldKammy_Anim02)
    EVT_CALL(SetNpcSpeed, NPC_Kammy, EVT_FLOAT(2.0 / DT))
    EVT_CALL(NpcMoveTo, NPC_Kammy, -130, -30, 0)
    EVT_CALL(NpcMoveTo, NPC_Kammy, -120, 80, 0)
    EVT_CALL(NpcMoveTo, NPC_Kammy, -70, 80, 0)
    EVT_CALL(SetNpcAnimation, NPC_Kammy, ANIM_WorldKammy_Anim01)
    EVT_EXEC_GET_TID(N(EVS_SweatyPeach), LVarA)
    EVT_CALL(SpeakToPlayer, NPC_Kammy, ANIM_WorldKammy_Anim04, ANIM_WorldKammy_Anim01, 0, MSG_Peach_00B4)
    EVT_CALL(EndSpeech, NPC_Kammy, ANIM_WorldKammy_Anim05, ANIM_WorldKammy_Anim05, 5)
    EVT_CALL(SpeakToNpc, NPC_Kammy, ANIM_WorldKammy_Anim05, ANIM_WorldKammy_Anim01, 0, NPC_Koopatrol_01, MSG_Peach_00B5)
    EVT_KILL_THREAD(LVarA)
    EVT_CALL(DisablePlayerPhysics, TRUE)
    EVT_EXEC_WAIT(N(EVS_ApproachPeach))
    EVT_EXEC_WAIT(N(EVS_PickUpPeach))
    EVT_CALL(SpeakToPlayer, NPC_PLAYER, ANIM_Peach2_Carried, ANIM_Peach2_Carried, 5, MSG_Peach_00B6)
    EVT_THREAD
        EVT_WAIT(30)
        EVT_CALL(InterpNpcYaw, NPC_Kammy, 270, 5)
    EVT_END_THREAD
    EVT_EXEC_WAIT(N(EVS_CarryPeachAway))
    EVT_CALL(FadeOutMusic, 0, 1000 * DT)
    EVT_EXEC_WAIT(N(EVS_EndPeachChapter4))
    EVT_CALL(EnablePartnerAI)
    EVT_CALL(DisablePlayerPhysics, FALSE)
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_ManageGourmetGuyScenes) = {
    EVT_CALL(SetCamLeadPlayer, CAM_DEFAULT, FALSE)
    EVT_IF_EQ(GF_KKJ18_GourmetGuy_GaveKey, FALSE)
        EVT_EXEC_WAIT(N(EVS_Scene_GiveKitchenKey))
    EVT_END_IF
    EVT_IF_EQ(AF_KKJ_FinishedBakingCake, TRUE)
        EVT_EXEC_WAIT(N(EVS_Scene_JudgeCake))
    EVT_END_IF
    EVT_RETURN
    EVT_END
};
