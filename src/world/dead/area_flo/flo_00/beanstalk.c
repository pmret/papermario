#include "flo_00.h"
#include "sprite/player.h"

#define BEANSTALK_BASE_X -83
#define BEANSTALK_BASE_Z  87

API_CALLABLE(N(GetPlayerAngles)) {
    Bytecode* args = script->ptrReadPos;
    s32 var1 = *args++;
    s32 var2 = *args++;

    evt_set_variable(script, var1, gPlayerStatus.spriteFacingAngle);
    evt_set_variable(script, var2, gPlayerStatus.targetYaw);

    return ApiStatus_DONE2;
}

API_CALLABLE(N(PlayerRideBeanstalk)) {
    f32 temp = evt_get_variable(NULL, script->varTable[2]);
    f32 dist = dist2D(BEANSTALK_BASE_X, BEANSTALK_BASE_Z, script->varTable[9], script->varTable[11]);
    f32 angle = atan2(BEANSTALK_BASE_X, BEANSTALK_BASE_Z, script->varTable[9], script->varTable[11]);
    f32 clamped = clamp_angle(angle - temp);

    temp = sin_deg(clamped);
    gPlayerStatus.pos.x = BEANSTALK_BASE_X + (dist * temp);
    gPlayerStatus.pos.y = evt_get_variable(NULL, script->varTable[10]) + evt_get_variable(NULL, script->varTable[3]);
    temp = cos_deg(clamped);
    gPlayerStatus.pos.z = BEANSTALK_BASE_Z - (dist * temp);

    return ApiStatus_DONE2;
}

API_CALLABLE(N(PartnerRideBeanstalk)) {
    Npc* npc = get_npc_by_index(NPC_Dummy_Wisterwood);
    f32 temp = evt_get_variable(NULL, script->varTable[2]);
    f32 dist = dist2D(BEANSTALK_BASE_X, BEANSTALK_BASE_Z, script->varTable[12], script->varTable[14]);
    f32 angle = atan2(BEANSTALK_BASE_X, BEANSTALK_BASE_Z, script->varTable[12], script->varTable[14]);
    f32 clamped = clamp_angle(angle - temp);

    temp = sin_deg(clamped);
    npc->pos.x = BEANSTALK_BASE_X + (dist * temp);
    npc->pos.y = evt_get_variable(NULL, script->varTable[13]) + evt_get_variable(NULL, script->varTable[3]);
    temp = cos_deg(clamped);
    npc->pos.z = BEANSTALK_BASE_Z - (dist * temp);

    return ApiStatus_DONE2;
}

#include "common/CosInterpMinMax.inc.c"

#include "world/common/todo/SyncStatusBar.inc.c"

API_CALLABLE(N(DisableStatusBar)) {
    increment_status_bar_disabled();
    return ApiStatus_DONE2;
}

API_CALLABLE(N(EnableWorldStatusBar)) {
    decrement_status_bar_disabled();
    return ApiStatus_DONE2;
}

EvtScript N(EVS_SetExteriorVineGrowth) = {
    SetF(LVar1, LVar0) // input: expect range from -700 (no growth) to 0 (fully grown)
    SubF(LVar1, Float(-700.0))
    DivF(LVar1, Float(100.0))
    SetF(LVar2, LVar1)
    MulF(LVar2, Float(100.0))
    IfGt(LVar2, 100)
        SetF(LVar1, Float(1.0))
    EndIf
    Call(ScaleGroup, MODEL_g35, LVar1, 1, LVar1)
    Call(ScaleModel, MODEL_o117, LVar1, 1, LVar1)
    Call(ScaleModel, MODEL_o141, LVar1, 1, LVar1)
    Call(ScaleModel, MODEL_o140, LVar1, 1, LVar1)
    Call(ScaleModel, MODEL_o138, LVar1, 1, LVar1)
    Call(ScaleModel, MODEL_o139, LVar1, 1, LVar1)
    Call(ScaleModel, MODEL_o143, LVar1, 1, LVar1)
    Call(ScaleModel, MODEL_o144, LVar1, 1, LVar1)
    Call(ScaleModel, MODEL_o145, LVar1, 1, LVar1)
    Call(ScaleModel, MODEL_o146, LVar1, 1, LVar1)
    Call(ScaleModel, MODEL_o188, LVar1, 1, LVar1)
    Call(ScaleModel, MODEL_o187, LVar1, 1, LVar1)
    Call(ScaleModel, MODEL_o186, LVar1, 1, LVar1)
    Call(ScaleModel, MODEL_o185, LVar1, 1, LVar1)
    Call(ScaleModel, MODEL_o182, LVar1, 1, LVar1)
    Call(ScaleModel, MODEL_o183, LVar1, 1, LVar1)
    Call(ScaleModel, MODEL_o181, LVar1, 1, LVar1)
    Call(TranslateGroup, MODEL_g35, 0, LVar0, 0)
    Call(TranslateModel, MODEL_o117, 0, LVar0, 0)
    Call(TranslateModel, MODEL_o141, 0, LVar0, 0)
    Call(TranslateModel, MODEL_o140, 0, LVar0, 0)
    Call(TranslateModel, MODEL_o138, 0, LVar0, 0)
    Call(TranslateModel, MODEL_o139, 0, LVar0, 0)
    Call(TranslateModel, MODEL_o143, 0, LVar0, 0)
    Call(TranslateModel, MODEL_o144, 0, LVar0, 0)
    Call(TranslateModel, MODEL_o145, 0, LVar0, 0)
    Call(TranslateModel, MODEL_o146, 0, LVar0, 0)
    Call(TranslateModel, MODEL_o188, 0, LVar0, 0)
    Call(TranslateModel, MODEL_o187, 0, LVar0, 0)
    Call(TranslateModel, MODEL_o186, 0, LVar0, 0)
    Call(TranslateModel, MODEL_o185, 0, LVar0, 0)
    Call(TranslateModel, MODEL_o182, 0, LVar0, 0)
    Call(TranslateModel, MODEL_o183, 0, LVar0, 0)
    Call(TranslateModel, MODEL_o181, 0, LVar0, 0)
    SetF(LVar1, LVar0)
    MulF(LVar1, Float(-12.0))
    Call(RotateGroup, MODEL_g35, LVar1, 0, 1, 0)
    Call(RotateModel, MODEL_o117, LVar1, 0, 1, 0)
    Call(RotateModel, MODEL_o141, LVar1, 0, 1, 0)
    Call(RotateModel, MODEL_o140, LVar1, 0, 1, 0)
    Call(RotateModel, MODEL_o138, LVar1, 0, 1, 0)
    Call(RotateModel, MODEL_o139, LVar1, 0, 1, 0)
    Call(RotateModel, MODEL_o143, LVar1, 0, 1, 0)
    Call(RotateModel, MODEL_o144, LVar1, 0, 1, 0)
    Call(RotateModel, MODEL_o145, LVar1, 0, 1, 0)
    Call(RotateModel, MODEL_o146, LVar1, 0, 1, 0)
    Call(RotateModel, MODEL_o188, LVar1, 0, 1, 0)
    Call(RotateModel, MODEL_o187, LVar1, 0, 1, 0)
    Call(RotateModel, MODEL_o186, LVar1, 0, 1, 0)
    Call(RotateModel, MODEL_o185, LVar1, 0, 1, 0)
    Call(RotateModel, MODEL_o182, LVar1, 0, 1, 0)
    Call(RotateModel, MODEL_o183, LVar1, 0, 1, 0)
    Call(RotateModel, MODEL_o181, LVar1, 0, 1, 0)
    Call(TranslateModel, MODEL_o117, Float(8.122), Float(56.153), Float(1.166))
    Call(TranslateModel, MODEL_o141, Float(-6.8779296875), Float(91.153), Float(1.166))
    Call(TranslateModel, MODEL_o140, Float(13.122), Float(106.153), Float(1.166))
    Call(TranslateModel, MODEL_o138, Float(-9.8779296875), Float(136.153), Float(1.166))
    Call(TranslateModel, MODEL_o139, Float(-7.8779296875), Float(201.153), Float(1.166))
    Call(TranslateModel, MODEL_o143, Float(13.122), Float(221.153), Float(1.166))
    Call(TranslateModel, MODEL_o144, Float(8.127), Float(261.229), Float(1.166))
    Call(TranslateModel, MODEL_o145, Float(-12.8779296875), Float(266.153), Float(1.166))
    Call(TranslateModel, MODEL_o146, Float(8.122), Float(316.153), Float(-13.833984375))
    Call(TranslateModel, MODEL_o188, Float(-10.943359375), Float(391.153), Float(10.566))
    Call(TranslateModel, MODEL_o187, Float(-7.001953125), Float(456.153), Float(0.947))
    Call(TranslateModel, MODEL_o186, Float(12.998), Float(471.153), Float(0.947))
    Call(TranslateModel, MODEL_o185, Float(-10.001953125), Float(501.153), Float(0.947))
    Call(TranslateModel, MODEL_o182, Float(8.003), Float(536.229), Float(0.947))
    Call(TranslateModel, MODEL_o183, Float(12.998), Float(586.153), Float(0.947))
    Call(TranslateModel, MODEL_o181, Float(-13.001953125), Float(631.153), Float(0.947))
    SetF(LVar1, LVar0)
    SubF(LVar1, Float(-700.0))
    DivF(LVar1, Float(300.0))
    SetF(LVar2, LVar1)
    MulF(LVar2, Float(100.0))
    IfGt(LVar2, 100)
        SetF(LVar1, Float(1.0))
    EndIf
    Call(ScaleModel, MODEL_o117, LVar1, LVar1, LVar1)
    Call(ScaleModel, MODEL_o141, LVar1, LVar1, LVar1)
    Call(ScaleModel, MODEL_o140, LVar1, LVar1, LVar1)
    Call(ScaleModel, MODEL_o138, LVar1, LVar1, LVar1)
    Call(ScaleModel, MODEL_o139, LVar1, LVar1, LVar1)
    Call(ScaleModel, MODEL_o143, LVar1, LVar1, LVar1)
    Call(ScaleModel, MODEL_o144, LVar1, LVar1, LVar1)
    Call(ScaleModel, MODEL_o145, LVar1, LVar1, LVar1)
    Call(ScaleModel, MODEL_o146, LVar1, LVar1, LVar1)
    Call(ScaleModel, MODEL_o188, LVar1, LVar1, LVar1)
    Call(ScaleModel, MODEL_o187, LVar1, LVar1, LVar1)
    Call(ScaleModel, MODEL_o186, LVar1, LVar1, LVar1)
    Call(ScaleModel, MODEL_o185, LVar1, LVar1, LVar1)
    Call(ScaleModel, MODEL_o182, LVar1, LVar1, LVar1)
    Call(ScaleModel, MODEL_o183, LVar1, LVar1, LVar1)
    Call(ScaleModel, MODEL_o181, LVar1, LVar1, LVar1)
    Call(TranslateModel, MODEL_o117, Float(-8.12109375), Float(-56.15234375), Float(-1.1650390625))
    Call(TranslateModel, MODEL_o141, Float(6.879), Float(-91.15234375), Float(-1.1650390625))
    Call(TranslateModel, MODEL_o140, Float(-13.12109375), Float(-106.15234375), Float(-1.1650390625))
    Call(TranslateModel, MODEL_o138, Float(9.879), Float(-136.15234375), Float(-1.1650390625))
    Call(TranslateModel, MODEL_o139, Float(7.879), Float(-201.15234375), Float(-1.1650390625))
    Call(TranslateModel, MODEL_o143, Float(-13.12109375), Float(-221.15234375), Float(-1.1650390625))
    Call(TranslateModel, MODEL_o144, Float(-8.1259765625), Float(-261.228515625), Float(-1.1650390625))
    Call(TranslateModel, MODEL_o145, Float(12.879), Float(-266.15234375), Float(-1.1650390625))
    Call(TranslateModel, MODEL_o146, Float(-8.12109375), Float(-316.15234375), Float(13.835))
    Call(TranslateModel, MODEL_o188, Float(10.944), Float(-391.15234375), Float(-10.5654296875))
    Call(TranslateModel, MODEL_o187, Float(7.003), Float(-456.15234375), Float(-0.9462890625))
    Call(TranslateModel, MODEL_o186, Float(-12.9970703125), Float(-471.15234375), Float(-0.9462890625))
    Call(TranslateModel, MODEL_o185, Float(10.003), Float(-501.15234375), Float(-0.9462890625))
    Call(TranslateModel, MODEL_o182, Float(-8.001953125), Float(-536.228515625), Float(-0.9462890625))
    Call(TranslateModel, MODEL_o183, Float(-12.9970703125), Float(-586.15234375), Float(-0.9462890625))
    Call(TranslateModel, MODEL_o181, Float(13.003), Float(-631.15234375), Float(-0.9462890625))
    Return
    End
};

EvtScript N(EVS_SetInteriorVineGrowth) = {
    SetF(LVar1, LVar0) // input: expect range from -700 (no growth) to 0 (fully grown)
    SubF(LVar1, Float(-700.0))
    DivF(LVar1, Float(100.0))
    SetF(LVar2, LVar1)
    MulF(LVar2, Float(100.0))
    IfGt(LVar2, 100)
        SetF(LVar1, Float(1.0))
    EndIf
    Call(ScaleGroup, MODEL_g37, LVar1, 1, LVar1)
    Call(TranslateGroup, MODEL_g37, 0, LVar0, 0)
    SetF(LVar1, LVar0)
    MulF(LVar1, Float(-12.0))
    Call(RotateGroup, MODEL_g37, LVar1, 0, 1, 0)
    Return
    End
};

EvtScript N(EVS_SetSproutGrowth) = {
    Call(TranslateModel, MODEL_o147, Float(9.5), Float(12.0), Float(15.0))
    Call(TranslateModel, MODEL_o149, Float(-9.5), Float(12.0), Float(15.0))
    Call(TranslateModel, MODEL_o148, Float(0.0), Float(0.0), Float(17.0))
    SetF(LVar1, LVar0)
    MulF(LVar1, Float(90.0))
    Call(RotateModel, MODEL_o147, LVar1, 0, 0, -1)
    Call(RotateModel, MODEL_o149, LVar1, 0, 0, 1)
    Call(TranslateModel, MODEL_o147, Float(-9.5), Float(-12.0), Float(-15.0))
    Call(TranslateModel, MODEL_o149, Float(9.5), Float(-12.0), Float(-15.0))
    Call(TranslateModel, MODEL_o148, Float(0.0), Float(0.0), Float(-17.0))
    Call(ScaleModel, MODEL_o147, LVar0, LVar0, LVar0)
    Call(ScaleModel, MODEL_o149, LVar0, LVar0, LVar0)
    Call(ScaleModel, MODEL_o148, LVar0, LVar0, LVar0)
    Return
    End
};

EvtScript N(EVS_SetBigLeafGrowth) = {
    Call(ScaleModel, MODEL_o142, LVar0, LVar0, LVar0)
    SetF(LVar1, LVar0)
    MulF(LVar1, Float(90.0))
    AddF(LVar1, Float(-90.0))
    Call(RotateModel, MODEL_o142, LVar1, 1, 0, 0)
    Return
    End
};

EvtScript N(EVS_SetBigLeafPosition) = {
    SetF(LVar1, LVar0)
    MulF(LVar1, Float(-3.0))
    Call(TranslateModel, MODEL_o142, Float(-0.26), LVar0, Float(1.477))
    Call(RotateModel, MODEL_o142, LVar1, 0, 1, 0)
    Call(UpdateColliderTransform, COLLIDER_o240)
    Return
    End
};

EvtScript N(EVS_Exit_Beanstalk) = {
    IfEq(AF_FLO_RidingBeanstalk, FALSE)
        Call(DisablePlayerInput, TRUE)
        Call(InterruptUsePartner)
        Wait(15)
        Call(DisablePartnerAI, 0)
        Set(AF_FLO_RidingBeanstalk, TRUE)
        Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o261, COLLIDER_FLAGS_UPPER_MASK)
        Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o351, COLLIDER_FLAGS_UPPER_MASK)
        EVT_VEC3I_SET(LVar9, Float(-59.0), Float(22.0), Float(125.0)) // target player pos
        EVT_VEC3I_SET(LVarC, Float(-55.0), Float(24.0), Float(145.0)) // target partner pos
        Call(PlayerMoveTo, LVar9, LVarB, 8)
        Call(SetNpcJumpscale, NPC_PARTNER, Float(0.0))
        Call(NpcJump0, NPC_PARTNER, LVarC, LVarD, LVarE, 5)
        Call(PlaySound, SOUND_FLO_RIDE_BEANSTALK_UP_LOOP)
        Call(SetMusicTrack, 0, SONG_MAGIC_BEANSTALK, 1, 8)
        Call(SetNpcAnimation, NPC_PARTNER, PARTNER_ANIM_IDLE)
        Call(SetPlayerAnimation, ANIM_Mario1_Walk)
        Call(N(GetPlayerAngles), LVar3, LVar4)
        Switch(LVar4)
            CaseLt(90)
                Set(AF_FLO_BeanstalkFacingRight, FALSE)
                Call(InterpPlayerYaw, 90, 0)
                Call(InterpNpcYaw, NPC_PARTNER, 90, 0)
            CaseGe(270)
                Set(AF_FLO_BeanstalkFacingRight, TRUE)
                Call(InterpPlayerYaw, 270, 0)
                Call(InterpNpcYaw, NPC_PARTNER, 270, 0)
        EndSwitch
        Call(TranslateModel, MODEL_o142, Float(-0.26), Float(2.0), Float(1.477))
        Call(UpdateColliderTransform, COLLIDER_o240)
        Set(MV_BeanstalkSceneSync, FALSE)
        Thread
            Set(LVarF, 0)
            Loop(0)
                Add(LVarF, 1)
                Call(N(CosInterpMinMax), LVarF, LVar0, 0, 700, 800, 0, 0)
                Exec(N(EVS_SetBigLeafPosition))
                SetF(LVar2, LVar0)
                MulF(LVar2, Float(-3.0))
                SetF(LVar3, LVar0)
                Call(N(PlayerRideBeanstalk))
                Call(N(PartnerRideBeanstalk))
                IfEq(LVarF, 350)
                    Set(MV_BeanstalkSceneSync, TRUE)
                EndIf
                Wait(1)
            EndLoop
        EndThread
        Label(10)
            IfEq(MV_BeanstalkSceneSync, FALSE)
                Wait(1)
                Goto(10)
            EndIf
        Call(GotoMap, Ref("flo_19"), flo_19_ENTRY_3)
        Wait(100)
    EndIf
    Return
    End
};

EvtScript N(EVS_Enter_Beanstalk) = {
    Call(DisablePlayerInput, TRUE)
    Call(SetPlayerActionState, ACTION_STATE_LAND)
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o261, COLLIDER_FLAGS_UPPER_MASK)
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o351, COLLIDER_FLAGS_UPPER_MASK)
    Call(GetPlayerPos, LVar0, LVar1, LVar2)
    Call(UseSettingsFrom, CAM_DEFAULT, LVar0, LVar1, LVar2)
    Call(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
    Call(SetCamSpeed, CAM_DEFAULT, Float(90.0))
    Call(PanToTarget, CAM_DEFAULT, 0, 1)
    Set(LVar9, Float(-59.0))
    Set(LVarA, Float(22.0))
    Set(LVarB, Float(125.0))
    Set(LVarC, Float(-55.0))
    Set(LVarD, Float(23.0))
    Set(LVarE, Float(145.0))
    Thread
        Wait(5)
        Call(SetNpcAnimation, NPC_PARTNER, PARTNER_ANIM_IDLE)
        Call(SetPlayerAnimation, ANIM_Mario1_Walk)
        Switch(AF_FLO_BeanstalkFacingRight)
            CaseEq(0)
                Call(InterpPlayerYaw, 90, 0)
                Call(InterpNpcYaw, NPC_PARTNER, 90, 0)
            CaseEq(1)
                Call(InterpPlayerYaw, 270, 0)
                Call(InterpNpcYaw, NPC_PARTNER, 270, 0)
        EndSwitch
    EndThread
    Call(TranslateModel, MODEL_o142, Float(-0.26), Float(2.0), Float(1.477))
    Call(UpdateColliderTransform, COLLIDER_o240)
    Set(LVarF, 0)
    Loop(120)
        Add(LVarF, 1)
        Call(N(CosInterpMinMax), LVarF, LVar0, 70, 0, 120, 0, 0)
        Exec(N(EVS_SetBigLeafPosition))
        SetF(LVar2, LVar0)
        MulF(LVar2, Float(-3.0))
        SetF(LVar3, LVar0)
        Call(N(PlayerRideBeanstalk))
        Call(N(PartnerRideBeanstalk))
        Wait(1)
    EndLoop
    Call(EnablePartnerAI)
    Call(ClearPartnerMoveHistory, NPC_PARTNER)
    Call(SetPlayerJumpscale, 1)
    Call(PlayerJump, 10, 0, 110, 20)
    Call(SetPlayerActionState, ACTION_STATE_LAND)
    Call(InterpPlayerYaw, 90, 0)
    Wait(5)
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_CLEAR_BITS, COLLIDER_o261, COLLIDER_FLAGS_UPPER_MASK)
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_CLEAR_BITS, COLLIDER_o351, COLLIDER_FLAGS_UPPER_MASK)
    Set(AF_FLO_RidingBeanstalk, FALSE)
    Call(StopSound, SOUND_FLO_RIDE_BEANSTALK_DOWN_LOOP)
    ExecWait(N(EVS_SetupMusic))
    Call(ResetCam, CAM_DEFAULT, Float(1.0))
    Call(DisablePlayerInput, FALSE)
    Return
    End
};

EvtScript N(EVS_Scene_BeanstalkGrowing) = {
    Call(PlaySoundAtCollider, COLLIDER_o261, SOUND_FLO_BEANSTALK_START_GROWING, SOUND_SPACE_DEFAULT)
    Set(LVarF, 0)
    Loop(100)
        Add(LVarF, 1)
        Call(N(CosInterpMinMax), LVarF, LVar0, 0, Float(1.0), 100, 0, 0)
        Exec(N(EVS_SetSproutGrowth))
        Wait(1)
    EndLoop
    Set(MV_BeanstalkSceneSync, FALSE)
    Thread
        Set(LVarF, 0)
        Loop(1200)
            Add(LVarF, 1)
            Call(N(CosInterpMinMax), LVarF, LVar0, -700, 0, 1200, 0, 0)
            SetF(LVar2, LVar0)
            MulF(LVar2, Float(1.0))
            SetF(LVar0, LVar2)
            Exec(N(EVS_SetExteriorVineGrowth))
            SetF(LVar2, LVar0)
            MulF(LVar2, Float(1.0))
            SetF(LVar0, LVar2)
            Exec(N(EVS_SetInteriorVineGrowth))
            Switch(LVarF)
                CaseEq(200)
                    Call(SetPlayerAnimation, ANIM_Mario1_LookUp)
                CaseEq(250)
                    Set(LVar0, -60)
                    Set(LVar1, 0)
                    Set(LVar2, 65)
                    Call(UseSettingsFrom, CAM_DEFAULT, LVar0, LVar1, LVar2)
                    Call(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
                    Call(SetCamSpeed, CAM_DEFAULT, Float(90.0))
                    Call(SetCamPitch, CAM_DEFAULT, Float(12.5), Float(-7.0))
                    Call(SetCamDistance, CAM_DEFAULT, 800)
                    Call(SetCamPosA, CAM_DEFAULT, -200, 0)
                    Call(SetCamPosB, CAM_DEFAULT, 0, -300)
                    Call(PanToTarget, CAM_DEFAULT, 0, 1)
                    Call(WaitForCam, CAM_DEFAULT, Float(1.0))
                CaseDefault
            EndSwitch
            IfGt(LVarF, 550)
                Set(MV_BeanstalkSceneSync, TRUE)
            EndIf
            Wait(1)
        EndLoop
    EndThread
    Label(10)
        IfEq(MV_BeanstalkSceneSync, FALSE)
            Wait(1)
            Goto(10)
        EndIf
    Call(FadeInMusic, 0, SONG_CLOUDY_CLIMB, 0, 3000, 0, 127)
    Call(FadeOutMusic, 1, 3000)
    Call(GotoMap, Ref("flo_19"), flo_19_ENTRY_2)
    Wait(100)
    Return
    End
};

EvtScript N(EVS_Scene_BeanstalkGrewRemark) = {
    Call(DisablePlayerInput, TRUE)
    Call(InterpPlayerYaw, 200, 0)
    Call(SetPlayerPos, -60, 0, 30)
    Call(NpcFacePlayer, NPC_PARTNER, 1)
    Call(SetNpcPos, NPC_PARTNER, -20, 0, 10)
    Set(LVar0, -60)
    Set(LVar1, 0)
    Set(LVar2, 65)
    Call(UseSettingsFrom, CAM_DEFAULT, LVar0, LVar1, LVar2)
    Call(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
    Call(SetCamSpeed, CAM_DEFAULT, Float(90.0))
    Call(SetCamPitch, CAM_DEFAULT, Float(12.5), Float(-7.0))
    Call(SetCamDistance, CAM_DEFAULT, 800)
    Call(SetCamPosA, CAM_DEFAULT, -200, 0)
    Call(SetCamPosB, CAM_DEFAULT, 0, -300)
    Call(PanToTarget, CAM_DEFAULT, 0, 1)
    Call(WaitForCam, CAM_DEFAULT, Float(1.0))
    Set(LVarF, 0)
    Loop(5)
        Add(LVarF, 20)
        Call(N(CosInterpMinMax), LVarF, LVar0, Float(0.0), Float(1.0), 100, 0, 0)
        Exec(N(EVS_SetBigLeafGrowth))
        Wait(1)
    EndLoop
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_CLEAR_BITS, COLLIDER_o240, COLLIDER_FLAGS_UPPER_MASK)
    Call(ShowMessageAtWorldPos, MSG_CH6_000A, 0, 50, -200)
    Call(ResetCam, CAM_DEFAULT, Float(90.0))
    Call(DisablePlayerInput, FALSE)
    Return
    End
};

s32 N(BeanstalkIngredients)[] = {
    ITEM_FERTILE_SOIL,
    ITEM_MAGICAL_BEAN,
    ITEM_MIRACLE_WATER,
    ITEM_NONE
};

EvtScript N(EVS_BeanPatch_ItemPrompt) = {
    Call(DisablePlayerInput, TRUE)
    Call(FacePlayerTowardPoint, -85, 85, 0)
    Call(func_802CF56C, 2)
    Call(DisablePlayerInput, FALSE)
    IfEq(GF_FLO00_PlacedFertileSoil, FALSE)
        SetGroup(EVT_GROUP_00)
        Call(SetTimeFreezeMode, TIME_FREEZE_PARTIAL)
        Label(10)
            Call(ShowKeyChoicePopup)
            Set(LVar2, LVar0)
            Switch(LVar2)
                CaseLe(ITEM_NONE)
                    Call(CloseChoicePopup)
                    Call(SetTimeFreezeMode, TIME_FREEZE_NORMAL)
                    Call(AwaitPlayerLeave, -85, 85, 28)
                    Return
                CaseEq(ITEM_FERTILE_SOIL)
                    Call(SetPlayerAnimation, ANIM_MarioW1_PlaceItem)
                    Wait(5)
                    Call(RemoveKeyItemAt, LVar1)
                    Call(MakeItemEntity, ITEM_FERTILE_SOIL, BEANSTALK_BASE_X, 0, BEANSTALK_BASE_Z, ITEM_SPAWN_MODE_DECORATION, 0)
                    Set(MV_BeanstalkItemEntity, LVar0)
                    Call(SetPlayerAnimation, ANIM_Mario1_Still)
                    Wait(20)
                CaseDefault
                    Switch(AF_FLO_PlatingInstructionsToggle)
                        CaseEq(0)
                            Call(ShowMessageAtWorldPos, MSG_CH6_0008, 0, 10, -200)
                            Set(AF_FLO_PlatingInstructionsToggle, TRUE)
                        CaseDefault
                            Call(ShowMessageAtWorldPos, MSG_CH6_0009, 0, 10, -200)
                    EndSwitch
            EndSwitch
            Call(DisablePlayerInput, FALSE)
            Call(DisablePlayerPhysics, FALSE)
            IfNe(LVar2, 89)
                Goto(10)
            EndIf
        Set(GF_FLO00_PlacedFertileSoil, TRUE)
    EndIf
    IfEq(GF_FLO00_PlacedMagicalBean, FALSE)
        SetGroup(EVT_GROUP_00)
        Call(SetTimeFreezeMode, TIME_FREEZE_PARTIAL)
        Label(20)
            Call(ShowKeyChoicePopup)
            Set(LVar2, LVar0)
            Switch(LVar2)
                CaseLe(ITEM_NONE)
                    Call(CloseChoicePopup)
                    Call(SetTimeFreezeMode, TIME_FREEZE_NORMAL)
                    Call(AwaitPlayerLeave, -85, 85, 28)
                    Return
                CaseEq(ITEM_MAGICAL_BEAN)
                    Call(RemoveItemEntity, MV_BeanstalkItemEntity)
                    Wait(5)
                    Call(SetPlayerAnimation, ANIM_MarioW1_PlaceItem)
                    Wait(5)
                    Call(RemoveKeyItemAt, LVar1)
                    Call(MakeItemEntity, ITEM_MAGICAL_BEAN, BEANSTALK_BASE_X, 0, BEANSTALK_BASE_Z, ITEM_SPAWN_MODE_DECORATION, 0)
                    Set(MV_BeanstalkItemEntity, LVar0)
                    Call(SetPlayerAnimation, ANIM_Mario1_Still)
                    Wait(20)
                CaseDefault
                    Switch(AF_FLO_PlatingInstructionsToggle)
                        CaseEq(0)
                            Call(ShowMessageAtWorldPos, MSG_CH6_0008, 0, 10, -200)
                            Set(AF_FLO_PlatingInstructionsToggle, TRUE)
                        CaseDefault
                            Call(ShowMessageAtWorldPos, MSG_CH6_0009, 0, 10, -200)
                    EndSwitch
            EndSwitch
            Call(DisablePlayerInput, FALSE)
            Call(DisablePlayerPhysics, FALSE)
            IfNe(LVar2, 88)
                Goto(20)
            EndIf
        Set(GF_FLO00_PlacedMagicalBean, TRUE)
    EndIf
    SetGroup(EVT_GROUP_00)
    Call(SetTimeFreezeMode, TIME_FREEZE_PARTIAL)
    Label(30)
        Call(ShowKeyChoicePopup)
        Set(LVar2, LVar0)
        Switch(LVar2)
            CaseLe(ITEM_NONE)
                Call(CloseChoicePopup)
                Call(SetTimeFreezeMode, TIME_FREEZE_NORMAL)
                Call(AwaitPlayerLeave, -85, 85, 28)
                Return
            CaseEq(ITEM_MIRACLE_WATER)
                Call(RemoveItemEntity, MV_BeanstalkItemEntity)
                Wait(5)
                Call(SetPlayerAnimation, ANIM_MarioW1_PlaceItem)
                Wait(5)
                Call(RemoveKeyItemAt, LVar1)
                Call(N(SyncStatusBar))
                Call(MakeItemEntity, ITEM_MIRACLE_WATER, BEANSTALK_BASE_X, 0, BEANSTALK_BASE_Z, ITEM_SPAWN_MODE_DECORATION, 0)
                Set(MV_BeanstalkItemEntity, LVar0)
                Call(SetPlayerAnimation, ANIM_Mario1_Still)
                Wait(30)
                Call(RemoveItemEntity, MV_BeanstalkItemEntity)
                Wait(30)
                Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o261, COLLIDER_FLAGS_UPPER_MASK)
                Call(PlayerMoveTo, -60, 30, 20)
                Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_CLEAR_BITS, COLLIDER_o261, COLLIDER_FLAGS_UPPER_MASK)
                Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_CLEAR_BITS, COLLIDER_o351, COLLIDER_FLAGS_UPPER_MASK)
                Call(InterpPlayerYaw, 200, 0)
                Call(func_802CF56C, 2)
                Wait(60)
                Call(FadeInMusic, 1, SONG_MAGIC_BEANSTALK, 0, 3000, 0, 127)
                Call(FadeOutMusic, 0, 3000)
                Call(UseSettingsFrom, CAM_DEFAULT, -85, 0, 75)
                Call(SetPanTarget, CAM_DEFAULT, -85, 0, 75)
                Call(SetCamSpeed, CAM_DEFAULT, Float(1.0))
                Call(SetCamPitch, CAM_DEFAULT, Float(17.0), Float(-6.0))
                Call(SetCamDistance, CAM_DEFAULT, 250)
                Call(PanToTarget, CAM_DEFAULT, 0, 1)
                Call(WaitForCam, CAM_DEFAULT, Float(1.0))
                ExecWait(N(EVS_Scene_BeanstalkGrowing))
        EndSwitch
        IfNe(LVar2, 90)
            Goto(30)
        EndIf
    Return
    End
};

EvtScript N(EVS_BeanPatch_TryInteract) = {
    Label(0)
    Call(IsPlayerWithin, -85, 85, 20, LVar0)
    IfEq(LVar0, 0)
        Return
    Else
        Call(IsPlayerOnValidFloor, LVar0)
        IfEq(LVar0, FALSE)
            Wait(1)
            Goto(0)
        EndIf
        Call(GetPartnerInUse, LVar0)
        IfNe(LVar0, PARTNER_NONE)
            Return
        EndIf
    EndIf
    Call(N(DisableStatusBar))
    ExecWait(N(EVS_BeanPatch_ItemPrompt))
    Call(N(EnableWorldStatusBar))
    Return
    End
};

EvtScript N(EVS_SetupBeanPatch) = {
    IfLt(GB_StoryProgress, STORY_CH6_GREW_MAGIC_BEANSTALK)
        Loop(0)
            Wait(1)
            IfEq(GB_StoryProgress, STORY_CH6_WISTERWOOD_GAVE_HINT)
                BreakLoop
            EndIf
        EndLoop
        IfEq(GF_FLO00_PlacedFertileSoil, TRUE)
            IfEq(GF_FLO00_PlacedMagicalBean, FALSE)
                Call(MakeItemEntity, ITEM_FERTILE_SOIL, BEANSTALK_BASE_X, 0, BEANSTALK_BASE_Z, ITEM_SPAWN_MODE_DECORATION, 0)
            Else
                Call(MakeItemEntity, ITEM_MAGICAL_BEAN, BEANSTALK_BASE_X, 0, BEANSTALK_BASE_Z, ITEM_SPAWN_MODE_DECORATION, 0)
            EndIf
            Set(MV_BeanstalkItemEntity, LVar0)
        EndIf
        BindPadlock(Ref(N(EVS_BeanPatch_TryInteract)), TRIGGER_FORCE_ACTIVATE, 0, Ref(N(BeanstalkIngredients)), 0, 1)
    EndIf
    Return
    End
};

EvtScript N(EVS_SetupBeanstalk) = {
    BindTrigger(Ref(N(EVS_Exit_Beanstalk)), TRIGGER_FLOOR_TOUCH, COLLIDER_o240, 1, 0)
    Call(EnableGroup, MODEL_ha, TRUE)
    Call(EnableGroup, MODEL_tuta, TRUE)
    Switch(GB_StoryProgress)
        CaseEq(STORY_CH6_WISTERWOOD_GAVE_HINT)
            Set(LVar0, -700)
            Exec(N(EVS_SetExteriorVineGrowth))
            Exec(N(EVS_SetInteriorVineGrowth))
            Set(LVar0, 0)
            Exec(N(EVS_SetSproutGrowth))
            Set(LVar0, 0)
            Exec(N(EVS_SetBigLeafGrowth))
            Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o240, COLLIDER_FLAGS_UPPER_MASK)
            Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o261, COLLIDER_FLAGS_UPPER_MASK)
        CaseGe(STORY_CH6_GREW_MAGIC_BEANSTALK)
            Set(LVar0, 1)
            Exec(N(EVS_SetSproutGrowth))
            Set(LVar0, 1)
            Exec(N(EVS_SetBigLeafGrowth))
        CaseDefault
            Set(LVar0, -700)
            Exec(N(EVS_SetExteriorVineGrowth))
            Exec(N(EVS_SetInteriorVineGrowth))
            Set(LVar0, 0)
            Exec(N(EVS_SetSproutGrowth))
            Set(LVar0, 0)
            Exec(N(EVS_SetBigLeafGrowth))
            Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o240, COLLIDER_FLAGS_UPPER_MASK)
            Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o261, COLLIDER_FLAGS_UPPER_MASK)
    EndSwitch
    Return
    End
};
