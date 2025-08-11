#include "hos_04.h"

API_CALLABLE(N(ScreenOverlayFadeIn)) {
    if (isInitialCall) {
        script->functionTemp[1] = 0;
    }

    script->functionTemp[1] += 16;

    if (script->functionTemp[1] > 255) {
        script->functionTemp[1] = 255;
    }

    set_screen_overlay_params_front(OVERLAY_SCREEN_COLOR, script->functionTemp[1]);

    if (script->functionTemp[1] == 255) {
        return ApiStatus_DONE2;
    } else {
        return ApiStatus_BLOCK;
    }
}

// TODO: this was moved from the end of intro.c. This is a possible indication that
// file spitting in other versions might be off.
#if VERSION_JP
#include "world/common/npc/StarSpirit.inc.c"
#include "world/common/npc/Twink.h"

EvtScript N(EVS_NpcInit_Twink) = {
    Return
    End
};

NpcData N(NpcData_Twink) = {
    .id = NPC_Twink,
    .pos = { NPC_DISPOSE_LOCATION },
    .yaw = 270,
    .init = &N(EVS_NpcInit_Twink),
    .settings = &N(NpcSettings_StarSpirit),
    .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_FLYING,
    .drops = NO_DROPS,
    .animations = TWINK_ANIMS,
};

NpcGroupList N(DefaultNPCs) = {
    NPC_GROUP(N(NpcData_Twink)),
    {}
};

// TODO: required. File splitting?
u8 N(D_802422CC)[4] = { 0 };
#endif

EvtScript N(EVS_Starship_FlyingAway) = {
    Call(DisablePlayerInput, true)
    Call(DisablePlayerPhysics, true)
    Call(SetPlayerActionState, ACTION_STATE_LAND)
    Call(DisablePartnerAI, 0)
    Call(SetNpcFlagBits, NPC_PARTNER, NPC_FLAG_GRAVITY, false)
    Call(SetCamPerspective, CAM_DEFAULT, CAM_UPDATE_FROM_ZONE, 45, 16, 4096)
    Call(UseSettingsFrom, CAM_DEFAULT, -280, 0, 0)
    Call(SetPanTarget, CAM_DEFAULT, -280, 0, 0)
    Call(SetCamType, CAM_DEFAULT, 0, false)
    Call(SetCamDistance, CAM_DEFAULT, Float(550.0))
    Call(SetCamPosA, CAM_DEFAULT, Float(-688.0), Float(50.0))
    Call(SetCamPosB, CAM_DEFAULT, Float(-544.0), Float(50.0))
    Call(SetCamPitch, CAM_DEFAULT, Float(2.0), Float(-20.0))
    Call(SetCamSpeed, CAM_DEFAULT, Float(90.0))
    Call(PanToTarget, CAM_DEFAULT, 0, true)
    Call(WaitForCam, CAM_DEFAULT, Float(1.0))
    Wait(10)
    Thread
        Call(PlaySound, SOUND_STARSHIP_ASCEND)
        Call(MakeLerp, 0, 900, 45, EASING_QUADRATIC_IN)
        Loop(0)
            Call(UpdateLerp)
            Call(TranslateGroup, MODEL_g161, 0, LVar0, 0)
            Add(LVar0, 520)
            Call(SetPlayerPos, 315, LVar0, 5)
            Call(SetNpcPos, NPC_PARTNER, 313, LVar0, 5)
            Wait(1)
            IfEq(LVar1, 0)
                BreakLoop
            EndIf
        EndLoop
    EndThread
    Wait(55)
    Call(GotoMap, Ref("hos_20"), hos_20_ENTRY_0)
    Wait(100)
    Return
    End
};

EvtScript N(EVS_SetStarshipPosRot) = {
    Set(LVar4, 0)
    Set(LVar5, 100)
    Label(10)
        Set(LVar3, LVar4)
        Set(LVar4, LVar5)
        Set(LVar5, LVar3)
        Call(MakeLerp, LVar3, LVar4, 30, EASING_COS_IN_OUT)
        Loop(0)
            Call(UpdateLerp)
            SetF(LVar2, LVar0)
            MulF(LVar2, Float(0.1))
            AddF(LVar2, MV_Starship_PosY)
            Call(TranslateGroup, MODEL_g161, MV_Starship_PosX, LVar2, 0)
            Call(RotateGroup, MODEL_g161, MV_Starship_PosZ, 0, 1, 0)
            Wait(1)
            IfEq(LVar1, 0)
                BreakLoop
            EndIf
        EndLoop
        Goto(10)
    Return
    End
};

// flight1 (same as hos_20 entry 0, without motion lines)
EvtScript N(EVS_BetaStarship_Flight1) = {
    Call(DisablePlayerInput, true)
    Call(DisablePlayerPhysics, true)
    Call(SetPlayerActionState, ACTION_STATE_LAND)
    Call(DisablePartnerAI, 0)
    Call(SetNpcFlagBits, NPC_PARTNER, NPC_FLAG_GRAVITY, false)
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_g1, COLLIDER_FLAGS_UPPER_MASK)
    Call(InterpPlayerYaw, 90, 0)
    Call(UseSettingsFrom, CAM_DEFAULT, -500, 0, 0)
    Call(SetPanTarget, CAM_DEFAULT, -5000, 0, 0)
    Call(SetCamDistance, CAM_DEFAULT, Float(350.0))
    Call(SetCamPosA, CAM_DEFAULT, -5000, 50)
    Call(SetCamPosB, CAM_DEFAULT, 5000, 50)
    Call(SetCamPitch, CAM_DEFAULT, Float(17.0), Float(-7.0))
    Call(SetCamSpeed, CAM_DEFAULT, Float(90.0))
    Call(PanToTarget, CAM_DEFAULT, 0, true)
    Set(MV_Starship_Yaw, 0)
    Set(MV_Starship_PosX, -5000)
    Set(MV_Starship_PosY, -525)
    Set(MV_Starship_PosZ, 180)
    Exec(N(EVS_SetStarshipPosRot))
    Wait(1)
    Thread
        Set(LVar7, 45)
        Loop(20)
            Add(MV_Starship_PosX, LVar7)
            Wait(1)
        EndLoop
        Set(LVar7, 50)
        Loop(0)
            Add(MV_Starship_PosX, LVar7)
            Wait(1)
            Call(GetModelCenter, MODEL_o480)
            Add(LVar0, 25)
            Call(SetPlayerPos, LVar0, LVar1, LVar2)
            Sub(LVar0, 10)
            Add(LVar2, 2)
            Call(SetNpcPos, NPC_PARTNER, LVar0, LVar1, LVar2)
            Call(GetCamPosition, CAM_DEFAULT, LVar3, LVar4, LVar5)
            IfGt(LVar0, LVar3)
                IfGt(LVar7, 45)
                    Sub(LVar7, 1)
                EndIf
            EndIf
            IfGt(MV_Starship_PosX, 2000)
                Set(MV_Starship_Yaw, 1)
            EndIf
        EndLoop
    EndThread
    Thread
        Set(LVar0, -5000)
        Loop(0)
            Add(LVar0, 45)
            Call(SetPanTarget, CAM_DEFAULT, LVar0, 0, 0)
            Call(PanToTarget, CAM_DEFAULT, 0, true)
            Wait(1)
        EndLoop
    EndThread
    Label(20)
    IfEq(MV_Starship_Yaw, 0)
        Wait(1)
        Goto(20)
    EndIf
    IfLt(GB_StoryProgress, STORY_UNUSED_0000005D)
        Call(GotoMap, Ref("hos_00"), hos_00_ENTRY_3)
    Else
        Set(LVar0, 2)
        Loop(10)
            Mul(LVar0, 2)
            Add(MV_Starship_PosX, LVar0)
            Wait(1)
        EndLoop
        Wait(20)
        Call(GotoMap, Ref("kpa_60"), kpa_60_ENTRY_4)
    EndIf
    Wait(100)
    Return
    End
};

// flight2 (same as hos_20 entry 1, without motion lines)
EvtScript N(EVS_BetaStarship_Flight2) = {
    Call(DisablePlayerInput, true)
    Call(DisablePlayerPhysics, true)
    Call(SetPlayerActionState, ACTION_STATE_LAND)
    Call(DisablePartnerAI, 0)
    Call(SetNpcFlagBits, NPC_PARTNER, NPC_FLAG_GRAVITY, false)
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_g1, COLLIDER_FLAGS_UPPER_MASK)
    Call(UseSettingsFrom, CAM_DEFAULT, -500, 0, 0)
    Call(SetPanTarget, CAM_DEFAULT, -5000, 0, 0)
    Call(SetCamDistance, CAM_DEFAULT, Float(350.0))
    Call(SetCamPosA, CAM_DEFAULT, -5000, 50)
    Call(SetCamPosB, CAM_DEFAULT, 5000, 50)
    Call(SetCamPitch, CAM_DEFAULT, Float(17.0), Float(-7.0))
    Call(SetCamSpeed, CAM_DEFAULT, Float(90.0))
    Call(PanToTarget, CAM_DEFAULT, 0, true)
    Set(MV_Starship_Yaw, 0)
    Set(MV_Starship_PosX, -4673)
    Set(MV_Starship_PosY, -525)
    Set(MV_Starship_PosZ, 180)
    Exec(N(EVS_SetStarshipPosRot))
    Wait(1)
    Thread
        Loop(0)
            Add(MV_Starship_PosX, 45)
            Wait(1)
            Call(GetModelCenter, MODEL_o480)
            Add(LVar0, 25)
            Call(SetPlayerPos, LVar0, LVar1, LVar2)
            Sub(LVar0, 10)
            Add(LVar2, 2)
            Call(SetNpcPos, NPC_PARTNER, LVar0, LVar1, LVar2)
        EndLoop
    EndThread
    Thread
        Set(LVar0, -5000)
        Loop(0)
            Add(LVar0, 45)
            Call(SetPanTarget, CAM_DEFAULT, LVar0, 0, 0)
            Call(PanToTarget, CAM_DEFAULT, 0, true)
            Wait(1)
            IfGt(LVar0, 0)
                Set(MV_Starship_Yaw, 1)
            EndIf
        EndLoop
    EndThread
    Label(20)
    IfEq(MV_Starship_Yaw, 0)
        Wait(1)
        Goto(20)
    EndIf
    Set(LVar0, 2)
    Loop(10)
        Mul(LVar0, 2)
        Add(MV_Starship_PosX, LVar0)
        Wait(1)
    EndLoop
    Wait(20)
    Call(GotoMap, Ref("osr_03"), osr_03_ENTRY_3)
    Wait(100)
    Return
    End
};

// return flight (same as hos_20 entry 2, without motion lines)
EvtScript N(EVS_BetaStarship_Return) = {
    Call(DisablePlayerInput, true)
    Call(DisablePlayerPhysics, true)
    Call(SetPlayerActionState, ACTION_STATE_LAND)
    Call(DisablePartnerAI, 0)
    Call(SetNpcFlagBits, NPC_PARTNER, NPC_FLAG_GRAVITY, false)
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_g1, COLLIDER_FLAGS_UPPER_MASK)
    Call(SetNpcYaw, NPC_PARTNER, 90)
    Call(UseSettingsFrom, CAM_DEFAULT, -500, 0, 0)
    Call(SetPanTarget, CAM_DEFAULT, 5000, 0, 0)
    Call(SetCamDistance, CAM_DEFAULT, Float(350.0))
    Call(SetCamPosA, CAM_DEFAULT, -5000, 50)
    Call(SetCamPosB, CAM_DEFAULT, 5000, 50)
    Call(SetCamPitch, CAM_DEFAULT, Float(17.0), Float(-7.0))
    Call(SetCamSpeed, CAM_DEFAULT, Float(90.0))
    Call(PanToTarget, CAM_DEFAULT, 0, true)
    Set(MV_Starship_Yaw, 0)
    Set(MV_Starship_PosX, 5000)
    Set(MV_Starship_PosY, -525)
    Set(MV_Starship_PosZ, 0)
    Exec(N(EVS_SetStarshipPosRot))
    Wait(2)
    Thread
        Call(InterpPlayerYaw, 225, 0)
        Set(LVar7, -50)
        Loop(0)
            Add(MV_Starship_PosX, LVar7)
            Call(GetModelCenter, MODEL_o480)
            Add(LVar0, -25)
            Add(LVar2, -5)
            Call(SetPlayerPos, LVar0, LVar1, LVar2)
            Add(LVar2, 10)
            Call(SetNpcPos, NPC_PARTNER, LVar0, LVar1, LVar2)
            Wait(1)
            Call(GetCamPosition, CAM_DEFAULT, LVar3, LVar4, LVar5)
            IfLt(LVar0, LVar3)
                IfLt(LVar7, -45)
                    Add(LVar7, 1)
                EndIf
            EndIf
        EndLoop
    EndThread
    Thread
        Set(LVar0, 5000)
        Loop(0)
            Add(LVar0, -45)
            Call(SetPanTarget, CAM_DEFAULT, LVar0, 0, 0)
            Call(PanToTarget, CAM_DEFAULT, 0, true)
            Wait(1)
            IfLt(LVar0, -1000)
                Set(MV_Starship_Yaw, 1)
            EndIf
        EndLoop
    EndThread
    Label(20)
    IfEq(MV_Starship_Yaw, 0)
        Wait(1)
        Goto(20)
    EndIf
    Set(LVar0, -2)
    Loop(10)
        Mul(LVar0, 2)
        Add(MV_Starship_PosX, LVar0)
        Wait(1)
    EndLoop
    Call(GotoMap, Ref("hos_05"), hos_05_ENTRY_1)
    Wait(100)
    Return
    End
};
