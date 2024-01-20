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
    Call(GetPlayerPos, LVar0, LVar1, LVar2)
    Add(LVar0, 16)
    Call(UseSettingsFrom, CAM_DEFAULT, LVar0, LVar1, LVar2)
    Call(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
    Call(SetCamSpeed, CAM_DEFAULT, Float(1.0))
    Call(SetNpcVar, NPC_Koopatrol_01, 0, 1)
    Thread
        Call(GetPlayerPos, LVar0, LVar1, LVar2)
        Sub(LVar0, 26)
        Add(LVar2, 2)
        Call(SetNpcAnimation, NPC_Koopatrol_01, ANIM_WorldKoopatrol_Anim06)
        Call(SetNpcSpeed, NPC_Koopatrol_01, Float(5.0))
        Wait(10)
        Call(NpcMoveTo, NPC_Koopatrol_01, -130, -30, 0)
        Call(NpcMoveTo, NPC_Koopatrol_01, -130, 30, 0)
        Call(NpcMoveTo, NPC_Koopatrol_01, LVar0, LVar2, 0)
        Call(SetNpcAnimation, NPC_Koopatrol_01, ANIM_WorldKoopatrol_Anim01)
        Call(NpcFacePlayer, NPC_Koopatrol_01, 5)
        Call(SetNpcVar, NPC_Koopatrol_01, 0, 0)
    EndThread
    Thread
        Call(GetPlayerPos, LVar0, LVar1, LVar2)
        Add(LVar0, 26)
        Sub(LVar2, 2)
        Call(SetNpcAnimation, NPC_Koopatrol_02, ANIM_WorldKoopatrol_Anim06)
        Call(SetNpcSpeed, NPC_Koopatrol_02, Float(5.0))
        Call(NpcMoveTo, NPC_Koopatrol_02, -130, -30, 0)
        Call(NpcMoveTo, NPC_Koopatrol_02, -130, 30, 0)
        Call(NpcMoveTo, NPC_Koopatrol_02, -100, 30, 0)
        Call(NpcMoveTo, NPC_Koopatrol_02, LVar0, LVar2, 0)
        Call(SetNpcAnimation, NPC_Koopatrol_02, ANIM_WorldKoopatrol_Anim01)
        Call(NpcFacePlayer, NPC_Koopatrol_02, 5)
    EndThread
    Call(InterpPlayerYaw, 270, 0)
    Loop(0)
        Wait(1)
        Call(GetNpcVar, NPC_Koopatrol_01, 0, LVar0)
        IfEq(LVar0, 0)
            BreakLoop
        EndIf
    EndLoop
    Wait(10)
    Return
    End
};

EvtScript N(EVS_PickUpPeach) = {
    Thread
        Call(GetNpcPos, NPC_Koopatrol_01, LVar0, LVar1, LVar2)
        Add(LVar0, 5)
        Call(NpcMoveTo, NPC_Koopatrol_01, LVar0, LVar2, 5)
        Call(SetNpcAnimation, NPC_Koopatrol_01, ANIM_WorldKoopatrol_Anim12)
        Add(LVar0, 5)
        Call(NpcMoveTo, NPC_Koopatrol_01, LVar0, LVar2, 5)
    EndThread
    Thread
        Call(GetNpcPos, NPC_Koopatrol_02, LVar0, LVar1, LVar2)
        Sub(LVar0, 5)
        Call(NpcMoveTo, NPC_Koopatrol_02, LVar0, LVar2, 5)
        Call(SetNpcAnimation, NPC_Koopatrol_02, ANIM_WorldKoopatrol_Anim12)
        Sub(LVar0, 5)
        Call(NpcMoveTo, NPC_Koopatrol_02, LVar0, LVar2, 5)
    EndThread
    Call(GetPlayerPos, LVar0, LVar1, LVar2)
    Call(SetPlayerAnimation, ANIM_Peach2_Gasp)
    Wait(1)
    Loop(4)
        Add(LVar1, 2)
        Call(SetPlayerPos, LVar0, LVar1, LVar2)
        Wait(1)
    EndLoop
    Call(SetPlayerAnimation, ANIM_Peach2_Carried)
    Add(LVar0, 10)
    Loop(5)
        Add(LVar1, 4)
        Call(SetPlayerPos, LVar0, LVar1, LVar2)
        Wait(1)
    EndLoop
    Return
    End
};

EvtScript N(EVS_CarryPeachAway) = {
    Call(InterpNpcYaw, NPC_Koopatrol_01, 270, 3)
    Wait(10)
    Thread
        Loop(0)
            Call(GetNpcPos, NPC_Koopatrol_01, LVar0, LVar1, LVar2)
            Add(LVar0, 22)
            Sub(LVar2, 2)
            Call(SetPlayerPos, LVar0, 30, LVar2)
            Wait(1)
        EndLoop
    EndThread
    Call(SetNpcVar, NPC_Koopatrol_01, 0, 1)
    Thread
        Call(SetNpcAnimation, NPC_Koopatrol_01, ANIM_WorldKoopatrol_Anim14)
        Call(SetNpcSpeed, NPC_Koopatrol_01, Float(5.0))
        Call(NpcMoveTo, NPC_Koopatrol_01, -136, 32, 0)
        Call(NpcMoveTo, NPC_Koopatrol_01, -136, -28, 0)
        Call(NpcMoveTo, NPC_Koopatrol_01, -266, -28, 0)
        Call(SetNpcVar, NPC_Koopatrol_01, 0, 0)
    EndThread
    Thread
        Call(SetNpcAnimation, NPC_Koopatrol_02, ANIM_WorldKoopatrol_Anim14)
        Call(SetNpcSpeed, NPC_Koopatrol_02, Float(5.0))
        Call(NpcMoveTo, NPC_Koopatrol_02, -104, 28, 0)
        Call(NpcMoveTo, NPC_Koopatrol_02, -104, -32, 0)
        Call(NpcMoveTo, NPC_Koopatrol_02, -234, -32, 0)
    EndThread
    Call(SetCamSpeed, CAM_DEFAULT, Float(90.0))
    Loop(0)
        Call(GetPlayerPos, LVar0, LVar1, LVar2)
        Call(SetPanTarget, CAM_DEFAULT, LVar0, 0, LVar2)
        Call(GetNpcVar, NPC_Koopatrol_01, 0, LVar0)
        Wait(1)
        IfEq(LVar0, 0)
            BreakLoop
        EndIf
    EndLoop
    Return
    End
};

EvtScript N(EVS_OpenAndCloseWindow) = {
    Call(PlaySoundAt, SOUND_WINDOW_OPEN_A, SOUND_SPACE_DEFAULT, 190, 78, -20)
    Call(MakeLerp, 0, 80, 14, EASING_QUADRATIC_OUT)
    Loop(0)
        Call(UpdateLerp)
        Call(RotateGroup, MODEL_g15, LVar0, 0, -1, 0)
        Call(RotateGroup, MODEL_g16, LVar0, 0, 1, 0)
        Wait(1)
        IfEq(LVar1, 0)
            BreakLoop
        EndIf
    EndLoop
    Wait(20)
    Call(MakeLerp, 80, 0, 14, EASING_QUADRATIC_OUT)
    Loop(0)
        Call(UpdateLerp)
        Call(RotateGroup, MODEL_g15, LVar0, 0, -1, 0)
        Call(RotateGroup, MODEL_g16, LVar0, 0, 1, 0)
        Wait(1)
        IfEq(LVar1, 0)
            BreakLoop
        EndIf
    EndLoop
    Call(PlaySoundAt, SOUND_WINDOW_CLOSE_A, SOUND_SPACE_DEFAULT, 190, 78, -20)
    Return
    End
};

EvtScript N(EVS_DropFork) = {
    Call(SetNpcFlagBits, NPC_GourmetGuy_Fork, NPC_FLAG_INVISIBLE, FALSE)
    Call(GetNpcPos, NPC_GourmetGuy_Fork, LVar0, LVar1, LVar2)
    Call(SetNpcJumpscale, NPC_GourmetGuy_Fork, Float(0.05))
    Call(NpcJump0, NPC_GourmetGuy_Fork, LVar0, -8, LVar2, 8 * DT)
    Call(SetNpcRotationPivot, NPC_GourmetGuy_Fork, 15)
    Set(LVar3, 0)
    Loop(5)
        Add(LVar3, 50)
        Call(SetNpcRotation, NPC_GourmetGuy_Fork, 0, 0, LVar3)
        Wait(1)
    EndLoop
    Add(LVar2, 20)
    Call(SetNpcJumpscale, NPC_GourmetGuy_Fork, Float(0.2))
    Call(NpcJump0, NPC_GourmetGuy_Fork, LVar0, -20, LVar2, 8)
    Wait(10 * DT)
    Call(RemoveNpc, NPC_GourmetGuy_Fork)
    Return
    End
};

EvtScript N(EVS_DropKnife) = {
    Call(SetNpcFlagBits, NPC_GourmetGuy_Knife, NPC_FLAG_INVISIBLE, FALSE)
    Call(GetNpcPos, NPC_GourmetGuy_Knife, LVar0, LVar1, LVar2)
    Call(SetNpcRotation, NPC_GourmetGuy_Knife, 0, 0, -25)
    Call(SetNpcJumpscale, NPC_GourmetGuy_Knife, Float(0.05))
    Call(NpcJump0, NPC_GourmetGuy_Knife, LVar0, -8, LVar2, 8 * DT)
    Call(SetNpcRotationPivot, NPC_GourmetGuy_Knife, 15)
    Set(LVar3, 0)
    Loop(5)
        Sub(LVar3, 50)
        Call(SetNpcRotation, NPC_GourmetGuy_Knife, 0, 0, LVar3)
        Wait(1)
    EndLoop
    Add(LVar2, 20)
    Call(SetNpcJumpscale, NPC_GourmetGuy_Knife, Float(0.2))
    Call(NpcJump0, NPC_GourmetGuy_Knife, LVar0, -20, LVar2, -100)
    Wait(10 * DT)
    Call(RemoveNpc, NPC_GourmetGuy_Knife)
    Return
    End
};

EvtScript N(EVS_GourmetGuy_LovesCake) = {
    Thread
        Call(ShowMessageAtScreenPos, MSG_Peach_00AB, 160, 40)
    EndThread
    Exec(N(EVS_DropFork))
    Exec(N(EVS_DropKnife))
    Call(SetNpcAnimation, NPC_GourmetGuy, ANIM_GourmetGuy_Surprise)
    Wait(1)
    Call(UseSettingsFrom, CAM_DEFAULT, 90, 65, 10)
    Call(SetPanTarget, CAM_DEFAULT, 90, 65, 10)
    Call(SetCamDistance, CAM_DEFAULT, 170)
    Call(SetCamPitch, CAM_DEFAULT, 12, Float(-2.5))
    Call(SetCamPosB, CAM_DEFAULT, Float(110.0), Float(45.5))
    Call(SetCamSpeed, CAM_DEFAULT, Float(20.0 / DT))
    Call(PanToTarget, CAM_DEFAULT, 0, 1)
    Call(WaitForCam, CAM_DEFAULT, Float(1.0))
    Call(PlaySoundAtNpc, NPC_GourmetGuy, SOUND_GOURMET_GUY_SHOCK_1, SOUND_SPACE_DEFAULT)
    Wait(33 * DT)
    Call(SetCamDistance, CAM_DEFAULT, Float(65.0))
    Call(SetCamPitch, CAM_DEFAULT, Float(7.5), Float(-1.3))
    Call(PanToTarget, CAM_DEFAULT, 0, 1)
    Call(WaitForCam, CAM_DEFAULT, Float(1.0))
    Call(PlaySoundAtNpc, NPC_GourmetGuy, SOUND_GOURMET_GUY_SHOCK_2, SOUND_SPACE_DEFAULT)
    Wait(33 * DT)
    Call(SetCamDistance, CAM_DEFAULT, Float(1.0))
    Call(SetCamPitch, CAM_DEFAULT, Float(3.5), 0)
    Call(PanToTarget, CAM_DEFAULT, 0, 1)
    Call(WaitForCam, CAM_DEFAULT, Float(1.0))
    Call(PlaySoundAtNpc, NPC_GourmetGuy, SOUND_GOURMET_GUY_SHOCK_3, SOUND_SPACE_DEFAULT)
    Wait(18 * DT)
    Call(SetMusicTrack, 0, SONG_GOURMET_GUY_FREAKOUT, 0, 8)
    Wait(30 * DT)
    Call(SetMotionBlurParams, 0, 0, 0, 320, 240, 128, 10)
    Call(SetCamSpeed, CAM_DEFAULT, Float(12.0))
    Loop(7)
        Call(SetCamDistance, CAM_DEFAULT, 65)
        Call(PanToTarget, CAM_DEFAULT, 0, 1)
        Call(WaitForCam, CAM_DEFAULT, Float(1.0))
        Call(SetCamDistance, CAM_DEFAULT, 1)
        Call(PanToTarget, CAM_DEFAULT, 0, 1)
        Call(WaitForCam, CAM_DEFAULT, Float(1.0))
    EndLoop
    Call(N(SpinCameraAround))
    Call(N(SpinCameraAround))
    Call(N(SpinCameraAround))
    Call(SetMotionBlurParams, 0, 0, 0, 320, 240, 0, 10)
    Call(UseSettingsFrom, CAM_DEFAULT, 120, 0, 10)
    Call(SetPanTarget, CAM_DEFAULT, 120, 0, 10)
    Call(SetCamSpeed, CAM_DEFAULT, Float(90.0))
    Call(PanToTarget, CAM_DEFAULT, 0, 1)
    Return
    End
};

EvtScript N(EVS_GourmetGuy_RunAround) = {
    Call(PlaySoundAtNpc, NPC_GourmetGuy, SOUND_GOURMET_GUY_RUN, SOUND_SPACE_DEFAULT)
    Call(SetNpcAnimation, NPC_GourmetGuy, ANIM_GourmetGuy_Leap)
    Call(SetNpcJumpscale, NPC_GourmetGuy, Float(0.001953125))
    Call(GetNpcPos, NPC_GourmetGuy, LVar0, LVar1, LVar2)
    Call(NpcJump0, NPC_GourmetGuy, LVar0, 200, LVar2, 15 * DT)
    Call(SetNpcAnimation, NPC_GourmetGuy, ANIM_GourmetGuy_Panic)
    Call(SetNpcFlagBits, NPC_GourmetGuy, NPC_FLAG_IGNORE_PLAYER_COLLISION, TRUE)
    Call(SetNpcSpeed, NPC_GourmetGuy, Float(20.0 / DT))
    Call(PlaySoundAtNpc, NPC_GourmetGuy, SOUND_GOURMET_GUY_RUN, SOUND_SPACE_DEFAULT)
    Call(SetNpcRotation, NPC_GourmetGuy, 0, 0, -45)
    Call(SetNpcYaw, NPC_GourmetGuy, 90)
    Call(MakeLerp, 0, 100, 30, EASING_LINEAR)
    Loop(0)
        Call(UpdateLerp)
        SetF(LVar2, Float(3.3))
        SetF(LVar3, Float(-2.3))
        MulF(LVar2, LVar0)
        MulF(LVar3, LVar0)
        AddF(LVar2, Float(-100.0))
        AddF(LVar3, Float(150.0))
        SetF(LVar4, Float(100.0))
        Call(SetNpcPos, NPC_GourmetGuy, LVar2, LVar3, LVar4)
        Wait(1)
        IfEq(LVar1, 0)
            BreakLoop
        EndIf
    EndLoop
    Wait(20 * DT)
    Call(SetNpcRotation, NPC_GourmetGuy, 0, 0, 0)
    Call(PlaySoundAtNpc, NPC_GourmetGuy, SOUND_GOURMET_GUY_RUN, SOUND_SPACE_DEFAULT)
    Call(SetNpcFlagBits, NPC_GourmetGuy, NPC_FLAG_UPSIDE_DOWN, TRUE)
    Call(SetNpcYaw, NPC_GourmetGuy, 270)
    Call(SetNpcPos, NPC_GourmetGuy, 250, 160, 50)
    Call(NpcMoveTo, NPC_GourmetGuy, -100, 50, 0)
    Call(SetNpcFlagBits, NPC_GourmetGuy, NPC_FLAG_UPSIDE_DOWN, FALSE)
    Wait(20 * DT)
    Call(PlaySoundAtNpc, NPC_GourmetGuy, SOUND_GOURMET_GUY_RUN, SOUND_SPACE_DEFAULT)
    Call(SetNpcYaw, NPC_GourmetGuy, 90)
    Call(SetNpcPos, NPC_GourmetGuy, -100, 0, 70)
    Call(NpcMoveTo, NPC_GourmetGuy, 140, 70, 0)
    Wait(20 * DT)
    Call(SetNpcVar, NPC_GourmetGuy, 0, 0)
    Return
    End
};

EvtScript N(EVS_RejectCake) = {
    Call(PlaySoundAtNpc, NPC_GourmetGuy, SOUND_SPIT_OUT, SOUND_SPACE_DEFAULT)
    Call(SetNpcAnimation, NPC_GourmetGuy, ANIM_GourmetGuy_SpitOut)
    Call(MakeItemEntity, MV_CakeItemIdx, 105, 30, 20, ITEM_SPAWN_MODE_DECORATION, 0)
    Call(MakeLerp, 0, 100, 4, EASING_LINEAR)
    Loop(0)
        Call(UpdateLerp)
        SetF(LVar2, Float(0.2))
        SetF(LVar3, Float(-0.3))
        SetF(LVar4, Float(0.5))
        MulF(LVar2, LVar0)
        MulF(LVar3, LVar0)
        MulF(LVar4, LVar0)
        AddF(LVar2, Float(105.0))
        AddF(LVar3, Float(30.0))
        AddF(LVar4, Float(20.0))
        Call(SetItemPos, LVarA, LVar2, LVar3, LVar4)
        Wait(1)
        IfEq(LVar1, 0)
            BreakLoop
        EndIf
    EndLoop
    Call(MakeLerp, 0, 100, 4, EASING_LINEAR)
    Loop(0)
        Call(UpdateLerp)
        SetF(LVar2, Float(0.2))
        SetF(LVar3, Float(0.3))
        SetF(LVar4, Float(0.5))
        MulF(LVar2, LVar0)
        MulF(LVar3, LVar0)
        MulF(LVar4, LVar0)
        AddF(LVar2, Float(125.0))
        AddF(LVar3, Float(0.0))
        AddF(LVar4, Float(70.0))
        Call(SetItemPos, LVarA, LVar2, LVar3, LVar4)
        Wait(1)
        IfEq(LVar1, 0)
            BreakLoop
        EndIf
    EndLoop
    Call(RemoveItemEntity, LVarA)
    Call(SetNpcAnimation, NPC_GourmetGuy, ANIM_GourmetGuy_Idle)
    Call(SpeakToPlayer, NPC_GourmetGuy, ANIM_GourmetGuy_Talk, ANIM_GourmetGuy_Idle, 5, MSG_Peach_00A5)
    Call(UseSettingsFrom, CAM_DEFAULT, 120, 0, 10)
    Call(SetPanTarget, CAM_DEFAULT, 120, 0, 10)
    Call(SetCamSpeed, CAM_DEFAULT, Float(90.0))
    Call(PanToTarget, CAM_DEFAULT, 0, 1)
    Call(WaitForCam, CAM_DEFAULT, Float(1.0))
    Switch(AB_KKJ_CompletedBakeStep)
        CaseEq(CAKE_TYPE_BAKED)
            Call(SpeakToPlayer, NPC_GourmetGuy, ANIM_GourmetGuy_Talk, ANIM_GourmetGuy_Idle, 5, MSG_Peach_00AA)
        CaseEq(CAKE_TYPE_READY_TO_BAKE)
            Call(SpeakToPlayer, NPC_GourmetGuy, ANIM_GourmetGuy_Talk, ANIM_GourmetGuy_Idle, 5, MSG_Peach_00A9)
        CaseEq(CAKE_TYPE_READY_TO_MIX)
            Call(SpeakToPlayer, NPC_GourmetGuy, ANIM_GourmetGuy_Talk, ANIM_GourmetGuy_Idle, 5, MSG_Peach_00A8)
        CaseOrEq(CAKE_TYPE_BEGUN)
        CaseOrEq(CAKE_TYPE_MIXED)
            Call(SpeakToPlayer, NPC_GourmetGuy, ANIM_GourmetGuy_Talk, ANIM_GourmetGuy_Idle, 5, MSG_Peach_00A7)
        EndCaseGroup
    EndSwitch
    Call(SetNpcAnimation, NPC_GourmetGuy, ANIM_GourmetGuy_Walk)
    Call(SetNpcJumpscale, NPC_GourmetGuy, 0)
    Call(NpcJump1, NPC_GourmetGuy, 120, 0, -20, 15 * DT)
    Call(SetNpcAnimation, NPC_GourmetGuy, ANIM_GourmetGuy_Idle)
    Call(ResetCam, CAM_DEFAULT, Float(1.0 / DT))
    Return
    End
};

EvtScript N(EVS_SweatyPeach) = {
    Call(SetPlayerAnimation, ANIM_Peach2_Gasp)
    Wait(10)
    Call(InterpPlayerYaw, 90, 5)
    Call(SetPlayerAnimation, ANIM_Peach1_Idle)
    Call(GetPlayerPos, LVar0, LVar1, LVar2)
    Add(LVar1, 35)
    Loop(0)
        Call(ShowSweat, 0, 1, -45, EMOTER_POS, LVar0, LVar1, LVar2, 13, 20)
        Wait(20)
    EndLoop
    Return
    End
};

EvtScript N(EVS_Scene_GiveKitchenKey) = {
    Call(DisablePlayerInput, TRUE)
    Call(SpeakToPlayer, NPC_GourmetGuy, ANIM_GourmetGuy_Talk, ANIM_GourmetGuy_Idle, 0, MSG_Peach_009A)
    Wait(10 * DT)
    Call(SetPlayerSpeed, Float(4.0 / DT))
    Call(PlayerMoveTo, -125, 40, 0)
    Call(PlayerMoveTo, 50, 40, 0)
    Wait(10 * DT)
    Call(SpeakToPlayer, NPC_PLAYER, ANIM_Peach3_InformalTalk, ANIM_Peach1_Idle, 5, MSG_Peach_009B)
    Call(AdjustCam, CAM_DEFAULT, Float(4.0 / DT), 35, 300, Float(17.0), Float(-11.0))
    Call(SpeakToPlayer, NPC_GourmetGuy, ANIM_GourmetGuy_Talk, ANIM_GourmetGuy_Idle, 5, MSG_Peach_009C)
    Call(SetPlayerAnimation, ANIM_Peach2_RaiseArms)
    Wait(10 * DT)
    Call(SetPlayerAnimation, ANIM_Peach2_TalkIdle)
    Call(SpeakToPlayer, NPC_PLAYER, ANIM_Peach2_Talk, ANIM_Peach2_TalkIdle, 5, MSG_Peach_009D)
    Call(SetPlayerAnimation, ANIM_Peach2_LowerArms)
    Wait(10 * DT)
    Call(SetPlayerAnimation, ANIM_Peach1_Idle)
    Call(SpeakToPlayer, NPC_GourmetGuy, ANIM_GourmetGuy_Talk, ANIM_GourmetGuy_Idle, 5, MSG_Peach_009E)
    Call(SetNpcAnimation, NPC_GourmetGuy, ANIM_GourmetGuy_Walk)
    Call(NpcMoveTo, NPC_GourmetGuy, 100, -20, 10 * DT)
    Call(SetNpcAnimation, NPC_GourmetGuy, ANIM_GourmetGuy_Idle)
    Call(SpeakToPlayer, NPC_GourmetGuy, ANIM_GourmetGuy_Talk, ANIM_GourmetGuy_Idle, 5, MSG_Peach_009F)
    Call(SetNpcAnimation, NPC_GourmetGuy, ANIM_GourmetGuy_Inspect)
    Wait(30 * DT)
    Set(LVar0, ITEM_PEACH_KEY1)
    Call(ShowGotItem, LVar0, TRUE, 0)
    Call(AddKeyItem, LVar0)
    Set(GF_KKJ18_GourmetGuy_GaveKey, TRUE)
    Call(SetNpcAnimation, NPC_GourmetGuy, ANIM_GourmetGuy_Walk)
    Call(SetNpcJumpscale, NPC_GourmetGuy, 0)
    Call(NpcJump1, NPC_GourmetGuy, 120, 0, -20, 10)
    Call(SetNpcAnimation, NPC_GourmetGuy, ANIM_GourmetGuy_Idle)
    Call(SpeakToPlayer, NPC_GourmetGuy, ANIM_GourmetGuy_Talk, ANIM_GourmetGuy_Idle, 5, MSG_Peach_00A0)
    Call(ResetCam, CAM_DEFAULT, Float(4.0 / DT))
    Call(DisablePlayerInput, FALSE)
    Return
    End
};

EvtScript N(EVS_Scene_JudgeCake) = {
    Call(DisablePlayerInput, TRUE)
    IfEq(AB_KKJ19_AddedBerries, FALSE)
        Set(MV_CakeItemIdx, ITEM_CAKE_WITH_ICING)
        Set(LVar0, ANIM_Peach3_PresentBerryCake)
        Set(LVar1, ANIM_Peach1_HoldIcingCake)
    Else
        IfEq(AB_KKJ19_AddedIcing, FALSE)
            Set(MV_CakeItemIdx, ITEM_CAKE_WITH_BERRIES)
            Set(LVar0, ANIM_Peach3_PresentIcingCake)
            Set(LVar1, ANIM_Peach1_HoldBerryCake)
        Else
            Set(MV_CakeItemIdx, ITEM_CAKE_DONE)
            Set(LVar0, ANIM_Peach3_PresentCompleteCake)
            Set(LVar1, ANIM_Peach1_HoldCompleteCake)
        EndIf
    EndIf
    Call(SpeakToPlayer, NPC_PLAYER, LVar0, LVar1, 5, MSG_Peach_00A2)
    Call(UseSettingsFrom, CAM_DEFAULT, 120, 0, 10)
    Call(SetPanTarget, CAM_DEFAULT, 120, 0, 10)
    Call(SetCamSpeed, CAM_DEFAULT, Float(1.0 / DT))
    Call(PanToTarget, CAM_DEFAULT, 0, 1)
    Call(WaitForCam, CAM_DEFAULT, Float(1.0))
    Call(SpeakToPlayer, NPC_GourmetGuy, ANIM_GourmetGuy_Talk, ANIM_GourmetGuy_Idle, 5, MSG_Peach_00A3)
    Call(ResetCam, CAM_DEFAULT, Float(90.0))
    Call(SetPlayerSpeed, Float(2.0 / DT))
    Call(PlayerMoveTo, -125, 40, 0)
    Call(PlayerMoveTo, 15, 40, 0)
    Wait(10 * DT)
    Call(MakeItemEntity, MV_CakeItemIdx, 25, 25, -20, ITEM_SPAWN_MODE_DECORATION, 0)
    Call(SetNpcVar, NPC_GourmetGuy, 7, LVar0)
    Set(AF_KKJ_FinishedBakingCake, FALSE)
    Call(N(SetHeldBakingItem), PEACH_BAKING_NONE)
    Thread
        Call(DisablePartnerAI, 0)
        Call(NpcFlyTo, NPC_PARTNER, -23, 30, 36, 5 * DT, 0, EASING_LINEAR)
        Call(InterpNpcYaw, NPC_PARTNER, 90, 5)
    EndThread
    Call(PlayerMoveTo, 17, 36, 5 * DT)
    Call(InterpPlayerYaw, 90, 5)
    Call(SpeakToPlayer, NPC_GourmetGuy, ANIM_GourmetGuy_Talk, ANIM_GourmetGuy_Idle, 5, MSG_Peach_00A4)
    Call(SetNpcAnimation, NPC_GourmetGuy, ANIM_GourmetGuy_Walk)
    Call(NpcMoveTo, NPC_GourmetGuy, 90, -20, 20 * DT)
    Call(SetNpcAnimation, NPC_GourmetGuy, ANIM_GourmetGuy_Idle)
    Call(UseSettingsFrom, CAM_DEFAULT, 90, 0, 10)
    Call(SetPanTarget, CAM_DEFAULT, 90, 0, 10)
    Call(SetCamDistance, CAM_DEFAULT, 250)
    Call(SetCamPitch, CAM_DEFAULT, 17, -14)
    Call(SetCamPosB, CAM_DEFAULT, Float(110.0), Float(45.5))
    Call(SetCamSpeed, CAM_DEFAULT, Float(3.0 / DT))
    Call(PanToTarget, CAM_DEFAULT, 0, 1)
    Call(WaitForCam, CAM_DEFAULT, Float(1.0))
    Call(GetNpcVar, NPC_GourmetGuy, 7, LVarA)
    Call(RemoveItemEntity, LVarA)
    Call(SetNpcAnimation, NPC_GourmetGuy, ANIM_GourmetGuy_Eat)
    Loop(6)
        Wait(10 * DT)
        Call(PlaySoundAtNpc, NPC_GourmetGuy, SOUND_EAT_OR_DRINK, SOUND_SPACE_DEFAULT)
    EndLoop
    IfNe(AB_KKJ_CompletedBakeStep, CAKE_TYPE_DONE)
        ExecWait(N(EVS_RejectCake))
        Call(EnablePartnerAI)
        Call(DisablePlayerPhysics, FALSE)
        Call(DisablePlayerInput, FALSE)
        Return
    EndIf
    Call(SetEnemyFlagBits, NPC_GourmetGuy, ENEMY_FLAG_CANT_INTERACT, 1)
    ExecWait(N(EVS_GourmetGuy_LovesCake))
    Call(SetNpcVar, NPC_GourmetGuy, 0, 1)
    Exec(N(EVS_GourmetGuy_RunAround))
    Loop(0)
        Call(PlayerFaceNpc, NPC_GourmetGuy, FALSE)
        Call(NpcFaceNpc, NPC_PARTNER, NPC_GourmetGuy, 0)
        Wait(1)
        Call(GetNpcVar, NPC_GourmetGuy, 0, LVar0)
        IfEq(LVar0, 0)
            BreakLoop
        EndIf
    EndLoop
    Exec(N(EVS_SetupMusic))
    Call(SetNpcAnimation, NPC_GourmetGuy, ANIM_GourmetGuy_Idle)
    Call(InterpNpcYaw, NPC_GourmetGuy, 270, 5)
    Call(SpeakToPlayer, NPC_GourmetGuy, ANIM_GourmetGuy_Talk, ANIM_GourmetGuy_Idle, 0, MSG_Peach_00AC)
    Call(SetNpcAnimation, NPC_GourmetGuy, ANIM_GourmetGuy_Walk)
    Call(SetNpcSpeed, NPC_GourmetGuy, Float(2.0 / DT))
    Call(NpcMoveTo, NPC_GourmetGuy, 80, 70, 0)
    Call(SetNpcAnimation, NPC_GourmetGuy, ANIM_GourmetGuy_Idle)
    Call(SpeakToPlayer, NPC_GourmetGuy, ANIM_GourmetGuy_Talk, ANIM_GourmetGuy_Idle, 0, MSG_Peach_00AD)
    Thread
        Loop(100)
            Call(PlayerFaceNpc, NPC_GourmetGuy, FALSE)
            Call(NpcFaceNpc, NPC_PARTNER, NPC_GourmetGuy, 0)
            Wait(1)
        EndLoop
    EndThread
    Call(SetNpcAnimation, NPC_GourmetGuy, ANIM_GourmetGuy_Walk)
    Call(NpcMoveTo, NPC_GourmetGuy, -250, 70, 0)
    Call(AdjustCam, CAM_DEFAULT, Float(2.0 / DT), -20, 300, Float(17.0), Float(-10.0))
    Call(InterpPlayerYaw, 270, 5)
    Call(SetPlayerAnimation, ANIM_Peach2_RaiseArms)
    Wait(10 * DT)
    Call(SetPlayerAnimation, ANIM_Peach2_TalkIdle)
    Call(SpeakToPlayer, NPC_PLAYER, ANIM_Peach2_Talk, ANIM_Peach2_TalkIdle, 5, MSG_Peach_00AE)
    Call(SpeakToPlayer, NPC_PARTNER, ANIM_Twink_Talk, ANIM_Twink_Idle, 0, MSG_Peach_00AF)
    Call(SpeakToPlayer, NPC_PLAYER, ANIM_Peach2_Talk, ANIM_Peach2_TalkIdle, 5, MSG_Peach_00B0)
    Call(SetPlayerAnimation, ANIM_Peach2_LowerArms)
    Wait(10 * DT)
    Call(SetPlayerAnimation, ANIM_Peach1_Idle)
    Call(SpeakToPlayer, NPC_PARTNER, ANIM_Twink_Talk, ANIM_Twink_Idle, 0, MSG_Peach_00B1)
    Call(UseSettingsFrom, CAM_DEFAULT, 120, 0, 10)
    Call(SetPanTarget, CAM_DEFAULT, 150, 0, 10)
    Call(SetCamDistance, CAM_DEFAULT, 400)
    Call(SetCamSpeed, CAM_DEFAULT, Float(1.2 / DT))
    Call(LoadPath, 60 * DT, Ref(N(TwinkDepartPath)), ARRAY_COUNT(N(TwinkDepartPath)), EASING_LINEAR)
    Loop(0)
        Call(GetNextPathPos)
        Call(SetNpcPos, NPC_PARTNER, LVar1, LVar2, LVar3)
        Wait(1)
        IfEq(LVar0, 0)
            BreakLoop
        EndIf
    EndLoop
    Call(SetNpcFlagBits, NPC_PARTNER, NPC_FLAG_IGNORE_WORLD_COLLISION, TRUE)
    Call(SpeakToPlayer, NPC_PARTNER, ANIM_Twink_Talk, ANIM_Twink_Idle, 16, MSG_Peach_00B2)
    Exec(N(EVS_OpenAndCloseWindow))
    Wait(14 * DT)
    Call(NpcFlyTo, NPC_PARTNER, 250, 70, -25, 30 * DT, 0, EASING_LINEAR)
    Wait(30 * DT)
    Call(SetNpcPos, NPC_Koopatrol_01, -250, 0, -30)
    Call(SetNpcPos, NPC_Koopatrol_02, -250, 0, -30)
    Call(SetNpcPos, NPC_Kammy, -250, 0, -30)
    Call(SpeakToPlayer, NPC_Kammy, ANIM_WorldKammy_Anim04, ANIM_WorldKammy_Anim01, 0, MSG_Peach_00B3)
    Call(SetMusicTrack, 0, SONG_KAMMY_KOOPA_THEME, 0, 8)
    Call(UseSettingsFrom, CAM_DEFAULT, -180, 0, -30)
    Call(SetPanTarget, CAM_DEFAULT, -180, 0, -30)
    Call(SetCamDistance, CAM_DEFAULT, Float(300.0))
    Call(SetCamPosA, CAM_DEFAULT, Float(-110.0), Float(45.5))
    Call(SetCamSpeed, CAM_DEFAULT, Float(5.0 / DT))
    Call(PanToTarget, CAM_DEFAULT, 0, 1)
    Call(WaitForCam, CAM_DEFAULT, Float(1.0))
    Call(PlaySoundAtCollider, COLLIDER_ttw, SOUND_BASIC_DOOR_OPEN, 0)
    Call(MakeLerp, 0, -120, 14, EASING_QUADRATIC_OUT)
    Loop(0)
        Call(UpdateLerp)
        Call(RotateModel, MODEL_o9, LVar0, 0, 1, 0)
        Wait(1)
        IfEq(LVar1, 0)
            BreakLoop
        EndIf
    EndLoop
    Thread
        Wait(60 * DT)
        Call(GetPlayerPos, LVar0, LVar1, LVar2)
        Add(LVar0, -30)
        Call(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
        Call(SetCamDistance, CAM_DEFAULT, 400)
        Call(SetCamSpeed, CAM_DEFAULT, Float(1.0 / DT))
    EndThread
    Call(SetNpcAnimation, NPC_Kammy, ANIM_WorldKammy_Anim02)
    Call(SetNpcSpeed, NPC_Kammy, Float(2.0 / DT))
    Call(NpcMoveTo, NPC_Kammy, -130, -30, 0)
    Call(NpcMoveTo, NPC_Kammy, -120, 80, 0)
    Call(NpcMoveTo, NPC_Kammy, -70, 80, 0)
    Call(SetNpcAnimation, NPC_Kammy, ANIM_WorldKammy_Anim01)
    ExecGetTID(N(EVS_SweatyPeach), LVarA)
    Call(SpeakToPlayer, NPC_Kammy, ANIM_WorldKammy_Anim04, ANIM_WorldKammy_Anim01, 0, MSG_Peach_00B4)
    Call(EndSpeech, NPC_Kammy, ANIM_WorldKammy_Anim05, ANIM_WorldKammy_Anim05, 5)
    Call(SpeakToNpc, NPC_Kammy, ANIM_WorldKammy_Anim05, ANIM_WorldKammy_Anim01, 0, NPC_Koopatrol_01, MSG_Peach_00B5)
    KillThread(LVarA)
    Call(DisablePlayerPhysics, TRUE)
    ExecWait(N(EVS_ApproachPeach))
    ExecWait(N(EVS_PickUpPeach))
    Call(SpeakToPlayer, NPC_PLAYER, ANIM_Peach2_Carried, ANIM_Peach2_Carried, 5, MSG_Peach_00B6)
    Thread
        Wait(30)
        Call(InterpNpcYaw, NPC_Kammy, 270, 5)
    EndThread
    ExecWait(N(EVS_CarryPeachAway))
    Call(FadeOutMusic, 0, 1000 * DT)
    ExecWait(N(EVS_EndPeachChapter4))
    Call(EnablePartnerAI)
    Call(DisablePlayerPhysics, FALSE)
    Call(DisablePlayerInput, FALSE)
    Return
    End
};

EvtScript N(EVS_ManageGourmetGuyScenes) = {
    Call(SetCamLeadPlayer, CAM_DEFAULT, FALSE)
    IfEq(GF_KKJ18_GourmetGuy_GaveKey, FALSE)
        ExecWait(N(EVS_Scene_GiveKitchenKey))
    EndIf
    IfEq(AF_KKJ_FinishedBakingCake, TRUE)
        ExecWait(N(EVS_Scene_JudgeCake))
    EndIf
    Return
    End
};
