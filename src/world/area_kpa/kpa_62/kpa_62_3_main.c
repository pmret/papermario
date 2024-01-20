#include "kpa_62.h"

#include "world/common/atomic/TexturePan.inc.c"

EvtScript N(EVS_OpenAirshipDockDoor) = {
    Call(PlaySoundAtCollider, COLLIDER_deilitts, SOUND_AIRSHIP_DOCK_DOOR_OPEN, SOUND_SPACE_DEFAULT)
    Call(EnableModel, MODEL_o1616, FALSE)
    Call(MakeLerp, 0, -10, 20, EASING_CUBIC_IN)
    Loop(0)
        Call(UpdateLerp)
        Call(TranslateModel, MODEL_o1650, LVar0, 0, 0)
        Wait(1)
        IfEq(LVar1, 0)
            BreakLoop
        EndIf
    EndLoop
    Call(MakeLerp, 0, 45, 25, EASING_CUBIC_IN)
    Loop(0)
        Call(UpdateLerp)
        Call(TranslateModel, MODEL_o1650, -10, 0, LVar0)
        Wait(1)
        IfEq(LVar1, 0)
            BreakLoop
        EndIf
    EndLoop
    Return
    End
};

EvtScript N(EVS_CloseAirshipDockDoor) = {
    Call(PlaySoundAtCollider, COLLIDER_deilitts, SOUND_AIRSHIP_DOCK_DOOR_CLOSE, SOUND_SPACE_DEFAULT)
    Call(MakeLerp, 45, 0, 25, EASING_CUBIC_IN)
    Loop(0)
        Call(UpdateLerp)
        Call(TranslateModel, MODEL_o1650, -10, 0, LVar0)
        Wait(1)
        IfEq(LVar1, 0)
            BreakLoop
        EndIf
    EndLoop
    Call(MakeLerp, -10, 0, 20, EASING_CUBIC_IN)
    Loop(0)
        Call(UpdateLerp)
        Call(TranslateModel, MODEL_o1650, LVar0, 0, 0)
        Wait(1)
        IfEq(LVar1, 0)
            BreakLoop
        EndIf
    EndLoop
    Call(EnableModel, MODEL_o1616, TRUE)
    Return
    End
};

EvtScript N(EVS_ExitDoors_kpa_70_0) = {
    SetGroup(EVT_GROUP_1B)
    Call(DisablePlayerInput, TRUE)
    Call(UseDoorSounds, DOOR_SOUNDS_METAL)
    Set(LVar0, kpa_62_ENTRY_0)
    Set(LVar1, COLLIDER_deilittn)
    Set(LVar2, MODEL_o1647)
    Set(LVar3, MODEL_o1646)
    Exec(ExitDoubleDoor)
    Wait(17)
    Call(GotoMap, Ref("kpa_70"), kpa_70_ENTRY_0)
    Wait(100)
    Return
    End
};

EvtScript N(EVS_ExitWalk_kpa_1X_Upper) = {
    SetGroup(EVT_GROUP_1B)
    Call(UseExitHeading, 60, kpa_62_ENTRY_1)
    Exec(ExitWalk)
    IfEq(GF_KPA16_ShutOffLava, FALSE)
        Call(GotoMap, Ref("kpa_11"), kpa_11_ENTRY_0)
    Else
        Call(GotoMap, Ref("kpa_10"), kpa_10_ENTRY_0)
    EndIf
    Wait(100)
    Return
    End
};

EvtScript N(EVS_ExitWalk_kpa_1X_Lower) = {
    SetGroup(EVT_GROUP_1B)
    Call(UseExitHeading, 60, kpa_62_ENTRY_2)
    Exec(ExitWalk)
    IfEq(GF_KPA16_ShutOffLava, FALSE)
        Call(GotoMap, Ref("kpa_11"), kpa_11_ENTRY_3)
    Else
        Call(GotoMap, Ref("kpa_10"), kpa_10_ENTRY_3)
    EndIf
    Wait(100)
    Return
    End
};

EvtScript N(EVS_ExitDoor_kpa_63_0) = {
    SetGroup(EVT_GROUP_1B)
    Call(DisablePlayerInput, TRUE)
    ExecWait(N(EVS_OpenAirshipDockDoor))
    Wait(15)
    Call(UseExitHeading, 60, kpa_62_ENTRY_3)
    Exec(ExitWalk)
    Call(GotoMap, Ref("kpa_63"), kpa_63_ENTRY_0)
    Wait(100)
    Return
    End
};

EvtScript N(EVS_EnterFromAirshipDock) = {
    Call(DisablePlayerInput, TRUE)
    Call(DisablePartnerAI, 0)
    Call(SetPlayerPos, -30, 21, 590)
    Call(SetNpcPos, NPC_PARTNER, -30, 21, 590)
    Call(SetNpcFlagBits, NPC_PARTNER, NPC_FLAG_IGNORE_WORLD_COLLISION, TRUE)
    Call(EnableModel, MODEL_o1616, FALSE)
    Call(TranslateModel, MODEL_o1650, -10, 0, 45)
    Thread
        Call(SetPlayerSpeed, Float(3.0))
        Call(PlayerMoveTo, 75, 580, 0)
    EndThread
    Wait(15)
    Call(SetNpcSpeed, NPC_PARTNER, Float(3.0))
    Call(NpcMoveTo, NPC_PARTNER, 65, 600, 0)
    ExecWait(N(EVS_CloseAirshipDockDoor))
    Call(SetNpcFlagBits, NPC_PARTNER, NPC_FLAG_IGNORE_WORLD_COLLISION, FALSE)
    Call(EnablePartnerAI)
    Call(DisablePlayerInput, FALSE)
    Return
    End
};

EvtScript N(EVS_BindExitTriggers) = {
    BindTrigger(Ref(N(EVS_ExitWalk_kpa_1X_Upper)), TRIGGER_FLOOR_ABOVE, COLLIDER_deilise, 1, 0)
    BindTrigger(Ref(N(EVS_ExitWalk_kpa_1X_Lower)), TRIGGER_FLOOR_ABOVE, COLLIDER_deilie, 1, 0)
    BindTrigger(Ref(N(EVS_ExitDoor_kpa_63_0)), TRIGGER_WALL_PRESS_A, COLLIDER_deilitts, 1, 0)
    Return
    End
};

EvtScript N(EVS_DisableLavaCollision) = {
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o1710, COLLIDER_FLAGS_UPPER_MASK)
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o1508, COLLIDER_FLAGS_UPPER_MASK)
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o1705, COLLIDER_FLAGS_UPPER_MASK)
    Return
    End
};

EvtScript N(EVS_EnterMap) = {
    Call(GetEntryID, LVar0)
    Switch(LVar0)
        CaseEq(kpa_62_ENTRY_0)
            ExecWait(N(EVS_DisableLavaCollision))
            Set(LVar2, MODEL_o1647)
            Set(LVar3, MODEL_o1646)
            ExecWait(EnterDoubleDoor)
            Exec(N(EVS_BindExitTriggers))
        CaseEq(kpa_62_ENTRY_1)
            ExecWait(N(EVS_DisableLavaCollision))
            Set(LVar0, Ref(N(EVS_BindExitTriggers)))
            Exec(EnterWalk)
            Wait(1)
        CaseEq(kpa_62_ENTRY_2)
            Set(LVar0, Ref(N(EVS_BindExitTriggers)))
            Exec(EnterWalk)
            Wait(1)
        CaseEq(kpa_62_ENTRY_3)
            ExecWait(N(EVS_DisableLavaCollision))
            Thread
                ExecWait(N(EVS_EnterFromAirshipDock))
                Exec(N(EVS_BindExitTriggers))
            EndThread
        CaseDefault
            Set(LVar0, Ref(N(EVS_BindExitTriggers)))
            Exec(EnterWalk)
            Wait(1)
    EndSwitch
    Return
    End
};

EvtScript N(EVS_TexPan_Lava) = {
    Thread
        TEX_PAN_PARAMS_ID(TEX_PANNER_0)
        TEX_PAN_PARAMS_STEP( -400,    0, -800,    0)
        TEX_PAN_PARAMS_FREQ(    1,    0,    1,    0)
        TEX_PAN_PARAMS_INIT(    0,    0,    0,    0)
        Exec(N(EVS_UpdateTexturePan))
    EndThread
    Call(SetTexPanner, MODEL_o1508, TEX_PANNER_0)
    Return
    End
};

LavaReset N(SafeFloorColliders)[] = {
    { .colliderID = COLLIDER_o1559, .pos = { -455.0,  -15.0,   35.0 }},
    { .colliderID = COLLIDER_o1560, .pos = { -545.0,   10.0,   15.0 }},
    { .colliderID = COLLIDER_o1692, .pos = { -426.0,  -35.0,   70.0 }},
    { .colliderID = -1 }
};

EvtScript N(EVS_Main) = {
    Set(GB_WorldLocation, LOCATION_BOWSERS_CASTLE)
    Call(SetSpriteShading, SHADING_NONE)
    SetUP_CAMERA_ALT_NO_LEAD()
    Set(GF_MAP_BowsersCastle, TRUE)
    ExecWait(N(EVS_MakeEntities))
    Exec(N(EVS_EnterMap))
    Exec(N(EVS_SetupMusic))
    IfEq(GF_KPA16_ShutOffLava, FALSE)
        Call(EnableGroup, MODEL_after, FALSE)
        Exec(N(EVS_TexPan_Lava))
    Else
        Call(EnableGroup, MODEL_before, FALSE)
    EndIf
    IfEq(GF_KPA16_ShutOffLava, FALSE)
        Thread
            Wait(3)
            Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_SURFACE, COLLIDER_o1508, SURFACE_TYPE_LAVA)
            Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_SURFACE, COLLIDER_deilie, SURFACE_TYPE_LAVA)
            Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_SURFACE, COLLIDER_o1705, SURFACE_TYPE_LAVA)
            Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_SURFACE, COLLIDER_o1706, SURFACE_TYPE_LAVA)
            Thread
                Call(ResetFromLava, Ref(N(SafeFloorColliders)))
            EndThread
        EndThread
    EndIf
    Return
    End
};


